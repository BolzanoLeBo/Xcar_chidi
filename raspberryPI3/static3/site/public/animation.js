titles = document.getElementsByClassName("subtitle");
for(var i = 0; i < titles.length; i++){
    titles[i].addEventListener("click", function(e){
        id = this.getAttribute("data-bloc")
        content = document.getElementById(id);

        if(content.classList.contains("hide")){
            content.classList.remove("hide")
            this.classList.remove("border_round")
            this.children[0].classList.add("hide")
            this.children[1].classList.remove("hide")
        }else{
            content.classList.add("hide")
            this.classList.add("border_round")
            this.children[0].classList.remove("hide")
            this.children[1].classList.add("hide")
        }

        
    })
    
};

function redirect(page) {
    window.location.href = page;
}
