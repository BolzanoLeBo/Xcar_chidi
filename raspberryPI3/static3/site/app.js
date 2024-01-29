const express = require('express');
const bodyParser = require('body-parser');
const bcrypt = require('bcrypt');
const session = require('express-session');
const path = require('path');

const app = express();
const port = 9443;

// Utilisez un tableau pour stocker les informations d'authentification
const userCredentials = {
    'user': { 'passwordHash': '$2b$12$Q3phXvHh0kSug.guGvM1TehqKSYsqcn1GDgSgOpkLC87rJQLEhrXS', 'action': 'redirect_test' },
    'admin': { 'passwordHash': '$2b$12$OfwWVcrigEGBXuFW8zTwxeHJNzN1p5ijWgwGe/6j8awZ02Uz5Vpvi', 'action': 'redirect_rickroll' },
};

// Utilisez express-session pour gérer les sessions
app.use(session({
    secret: 'your-secret-key', // Changez ceci par une clé secrète forte
    resave: false,
    saveUninitialized: true,
}));

app.use(bodyParser.json());
app.use(express.static('public'));

app.get('/', (req, res) => {
    res.sendFile(__dirname + '/public/index.html');
});

app.post('/login', (req, res) => {
    const { username, password } = req.body;

    if (username in userCredentials) {
        const storedPasswordHash = userCredentials[username]['passwordHash'];

        if (bcrypt.compareSync(password, storedPasswordHash)) {
            req.session.user = username; // Enregistrez l'utilisateur dans la session
            const action = userCredentials[username]['action'];
            res.status(200).json({ success: true, action });
            return;
        } else {
            res.status(401).json({ success: false });
        }
    } else {
        res.status(401).json({ success: false });
    }
});

app.get('/home.html', (req, res) => {
    // Vérifiez si l'utilisateur est connecté avant d'autoriser l'accès
    if (req.session.user) {
        // Utilisez path.join pour construire le chemin du fichier dans le répertoire 'private'
        const privateFilePath = path.join(__dirname, 'private', 'home.html');
        res.sendFile(privateFilePath);
    } else {
        res.redirect('/');
    }
});

app.get('/rickroll.html', (req, res) => {
  // Vérifiez si l'utilisateur est connecté avant d'autoriser l'accès
  if (req.session.user) {
      // Utilisez path.join pour construire le chemin du fichier dans le répertoire 'private'
      const privateFilePath = path.join(__dirname, 'private', 'rickroll.html');
      res.sendFile(privateFilePath);
  } else {
      res.redirect('/');
  }
});


app.listen(port, () => {
    console.log(`Serveur démarré sur le port ${port}...`);
});
