class Porte
{
    //les attribue
public:
    int vertBlan;
    int verte;
    int orangeBlan;
    int bleu;
    int bleuBlan;
    int orange;
    int maronBlan;
    int maron;

    //constructeur
    Porte(int VB, int V, int OB, int B, int BB, int O, int MB, int M){
    vertBlan = VB;
    verte    = V;
    orangeBlan  = OB;
    bleu     = B;
    bleuBlan = BB;
    orange   = O;
    maronBlan = MB;
    maron    = M;
    }
    
    //j'ai declarais cette fonction pour envoyer un signale avec les brouche de outPut 
    void allume(){  
        digitalWrite(vertBlan, HIGH);
        digitalWrite(verte, HIGH);
        digitalWrite(orangeBlan, HIGH);
        digitalWrite(bleu, HIGH);
        digitalWrite(bleuBlan, HIGH);
        digitalWrite(orange, HIGH);
        digitalWrite(maronBlan, HIGH);
        digitalWrite(maron, HIGH);
    }
    //cette fonction pour essayer est ce que le caple ca marche ou ca marche pas 
    // pour esssayer j'ai fais un tableau de 8 casier et j'ai rediger le contenu de chaque casier 
    bool teste(){
        int TabGauche[8] = {};
        int somme = 0; 
        TabGauche[0] = digitalRead(vertBlan);
        //Serial.println(TabGauche[0]);
        TabGauche[1] = digitalRead(verte);
        //Serial.println(TabGauche[1]);
        TabGauche[2] = digitalRead(orangeBlan);
        //Serial.println(TabGauche[2]);
        TabGauche[3] = digitalRead(bleu);
        //Serial.println(TabGauche[3]);
        TabGauche[4] = digitalRead(bleuBlan);
        //Serial.println(TabGauche[4]);
        TabGauche[5] = digitalRead(orange);
        //Serial.println(TabGauche[5]);
        TabGauche[6] = digitalRead(maronBlan);
        //Serial.println(TabGauche[6]);
        TabGauche[7] = digitalRead(maron);
        //Serial.println(TabGauche[7]);
    //quan le centenu de i (les 8)s'arrive plus la somme donc le cable fonction il y a un signale entre les 16 brouche 
        for (int i = 0; i < 8; i++)
        {
            somme = somme + TabGauche[i];
        }

        if (somme == 8)
        {
            Serial.print("le cable fonnction ");
            return true;
        }
        else {
            Serial.print("le cable fonnction pas");
            return false;
        }
    }
    // fonction pour lire le signale est ce que arriver au non 
    void arreter(){
        digitalWrite(vertBlan, LOW);
        digitalWrite(verte, LOW);
        digitalWrite(orangeBlan, LOW);
        digitalWrite(bleu, LOW);
        digitalWrite(bleuBlan, LOW);
        digitalWrite(orange, LOW);
        digitalWrite(maronBlan, LOW);
        digitalWrite(maron, LOW);
        
    }
    //cette fontion pour enregistre les centenu des Porte1.mode 1 et Porte2.mode 2 cas de fichier main.cpp
    void mode(int m){
        if (m == 1)
        {
            pinMode(vertBlan, OUTPUT);
            pinMode(verte, OUTPUT);
            pinMode(orangeBlan, OUTPUT);
            pinMode(bleu, OUTPUT);
            pinMode(bleuBlan, OUTPUT);
            pinMode(orange, OUTPUT);
            pinMode(maronBlan, OUTPUT);
            pinMode(maron, OUTPUT);
        }

        if (m == 2)
        {
            pinMode(vertBlan, INPUT);
            pinMode(verte, INPUT);
            pinMode(orangeBlan, INPUT);
            pinMode(bleu, INPUT);
            pinMode(bleuBlan, INPUT);
            pinMode(orange, INPUT);
            pinMode(maronBlan, INPUT);
            pinMode(maron, INPUT);
        }
        
        
    }
};    
//j'ai fais une fonction pour les 3 cas 
void nature(Porte p1, Porte p2){

    int somme_d = 0;
    int somme_c = 0;
    //declaration de les trois fonctionne envoi, recevoir_d, recevoir_c 
    int envoi[8]      = {p1.vertBlan ,p1.verte, p1.orangeBlan, p1.bleu, p1.bleuBlan, p1.orange, p1.maronBlan, p1.maron};
    int recevoir_d[8] = {p2.vertBlan ,p2.verte, p2.orangeBlan, p2.bleu, p2.bleuBlan, p2.orange, p2.maronBlan, p2.maron};
    int recevoir_c[8] = {p2.orangeBlan , p2.orange, p2.vertBlan, p2.bleu, p2.bleuBlan, p2.verte, p2.maronBlan, p2.maron};
    //j'ai fais une seule boucle pour les trois fonctionne la premiere declaration pour la premiere fonnction 
    
    for (int i = 0; i < 8; i++)
    {
        //allume tout le contenu de 1ere tableau 
        //lire tout le contenu qui recevoi le 2eme tableau et fair +1 a la somme 
        
        digitalWrite(envoi[i], HIGH);
        if (digitalRead(recevoir_d[i]) == HIGH)
        {
            somme_d = somme_d + 1;
        }
        else
        {
            somme_c =  somme_c + 1;
        }
    }
    //si la somme le 2eme tableau = 8 donc le cable c'est un cable drois 
    //sinon la somme de 3eme tableau = 8 donc le cable est croisee
    if (somme_d == 8)
    {
        Serial.println(" droit");
    }else if(somme_c == 8){
        Serial.println("croisee");
    }
    else{
        Serial.println("ni droit ni croisee");
    }
}




    
