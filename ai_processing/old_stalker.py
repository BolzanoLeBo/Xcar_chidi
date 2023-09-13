# Video capture
cap = cv2.VideoCapture(0)
ret, frame = cap.read()

#Capture the first person detected
results = model.track(frame, persist=True, classes=0)
for box in results:
    coords = box.boxes.xyxy[0].tolist()
    x_min, y_min, x_max, y_max = map(int, coords)

    # Crop the image of the first detected person
    img_target = frame[y_min:y_max, x_min:x_max]
    cv2.imwrite("target1.jpg", img_target)
    old_nb_id= len(box.boxes.id)
    break  # Exit after capturing the first person

#Extract features from target1.jpg
target1_img = Image.open("target1.jpg").convert('RGB')
target1_tensor = preprocess(target1_img).unsqueeze(0)
target1_tensor = target1_tensor.to(device)
with torch.no_grad():
    target1_features = model2(target1_tensor)

#initialization
track_id = 1
init_change_id = False


while ret:
    ret, frame = cap.read()
    results = model.track(frame, persist=True, classes=0)
    
#############################
    threshold = 0.50  # Adjust this threshold
    new_id = 1
    best_rect=[]
    ########################

    #if someone is detected
    if results[0] != None and results[0].boxes.id != None:        
        box = results[0]
        
        for i in range(len(box.boxes.id)) : 

            #get coordinate of the current box
            coords = box.boxes.xyxy[i].tolist()
            x_min, y_min, x_max, y_max = map(int, coords)

            # Draw rectangles on detections
            cv2.putText(frame, f"ID: {box.boxes.id[i]}", (x_min, y_min - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0,255,255), 2)
            cv2.rectangle(frame, (x_min, y_min), (x_max, y_max), (0, 0, 255), 2)  # Red rectangle

            #if we are at the tracked_id 
            if box.boxes.id[i] == track_id : 
                #remember the rectangle of the track_id to print it later 
                best_rect = [(x_min, y_min), (x_max, y_max)]
            
  
            # Crop and process the image of the detected person
            img_target = frame[y_min:y_max, x_min:x_max]
            img_pil = Image.fromarray(img_target).convert('RGB')
            img_tensor = preprocess(img_pil).unsqueeze(0)
            img_tensor = img_tensor.to(device)

            # Extract features and compare
            with torch.no_grad():
                current_features = model2(img_tensor)
            similarity = cosine_similarity(target1_features, current_features)
            #if it looks like the tracked person
            if similarity > threshold:
                #the best id is new_id (for the moment)
                new_id = box.boxes.id[i] # Adjust this based on your box object
                print(f"Match found with ID: {new_id} {similarity}")
                best_rect = [(x_min, y_min), (x_max, y_max)]
                #increase the treshold to find the best id 
                threshold=similarity
            else : 
                print(f"{box.boxes.id[i]} Don't match {similarity}")


        #if we found the tracked person or if we successfully change id 
        if best_rect != [] :
            cv2.rectangle(frame, best_rect[0], best_rect[1], (255, 0, 0), 2)  # Blue rectangle for matching person

            #if we have changed id
            if new_id != 0: 
                track_id = new_id
                print(print(f"new ID: {track_id}"))
                
 
    # Display the frame
    cv2.putText(frame, f"track ID: {track_id}", (10, 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0,255,255), 2)
    cv2.imwrite("./results.png", frame)