// Jeu de mémorie avec carte Arduino
// @DemangeJeremy

// Les déclarations 
// Les lampes 
const int led1 = 2;
const int led2 = 3;
const int led3 = 4;

// Les boutons
const int bouton1 = 11;
const int bouton2 = 12;
const int bouton3 = 13;

// La mécanique du jeu
int score = 0;
int nombreHasard = 0;
int etatJeu = 0;

// Stockage des données du jeu
int memoireJeu[50];
int coup = 0;

// Le setup
void setup() {
  // Les lampes 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  // Les boutons
  pinMode(bouton1, INPUT);
  pinMode(bouton2, INPUT);
  pinMode(bouton3, INPUT);

  // Sortie du programme - Affichage du score
  Serial.begin(9600);
}


// La boucle
void loop() {
  
  // Écran début de jeu
  if (etatJeu == 0 && score == 0) {
    Serial.print("\n\nDébut de jeu.\nScore : ");
    Serial.print(score);
    Serial.print("\n");
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(2000);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    etatJeu = 1;
    delay(1000);
  }

  // Début du jeu
  if (etatJeu == 1) {
    for (int i = 0; i <= score; i++) {

      // Choix du nombre
      nombreHasard = random(1,4);

      // Affichage du choix machine
      if (nombreHasard == 1) {
        digitalWrite(led1, HIGH);
        delay(1000);
        digitalWrite(led1, LOW);
        delay(500);
      }
    
      if (nombreHasard == 2) {
        digitalWrite(led2, HIGH);
        delay(1000);
        digitalWrite(led2, LOW);
        delay(500);
      }
    
      if (nombreHasard == 3) {
        digitalWrite(led3, HIGH);
        delay(1000);
        digitalWrite(led3, LOW);
        delay(500);
      }

      // Stockage du schéma
      memoireJeu[i] = nombreHasard;
    
    }
    
    // On passe à la phase 2
    etatJeu = 2;
    
  }


  // Choix de l'utilisateur
  if (etatJeu == 2) {
    
    // Bouton 1
    if (digitalRead(bouton1) == HIGH) {
      if (memoireJeu[coup] == 1) {
        coup++;
      } else {
        etatJeu = 0;
        coup = 0;
        score = 0;
      }
      digitalWrite(led1, HIGH);
      delay(1000);
      digitalWrite(led1, LOW);
    }

    // Bouton 2
    if (digitalRead(bouton2) == HIGH) {
      if (memoireJeu[coup] == 2) {
        coup++;
      } else {
        etatJeu = 0;
        coup = 0;
        score = 0;
      }
      digitalWrite(led2, HIGH);
      delay(1000);
      digitalWrite(led2, LOW);
    }

    // Bouton 3
    if (digitalRead(bouton3) == HIGH) {
      if (memoireJeu[coup] == 3) {
        coup++;
      } else {
        etatJeu = 0;
        coup = 0;
        score = 0;
      }
      digitalWrite(led3, HIGH);
      delay(1000);
      digitalWrite(led3, LOW);
    }

    if (coup > score) {
      coup = 0;
      score++;
      etatJeu = 1;
      Serial.print("Score : ");
      Serial.print(score);
      Serial.print("\n");
      delay(1000);
    }
  }
}
