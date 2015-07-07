#include <iostream>
#include <ctime>     //Detta bibliotek används för att kunna använda en randomfunktion.
#include <iomanip>   //Detta bibliotek används för att kunna göra indrag i texten.
using namespace std;


main()

{
   setlocale(LC_ALL, "swedish"); //Gör att åäö fungerar i terminalen.

   bool regelloop=true;
   bool spelloop=true;
   bool depositloop=true;
   bool pengaloop=true;
   bool svarloop=true;
   bool insatsloop=true;
   bool tioloop=true;
   bool tusenloop=true;
   bool forsoksloop=true;
   bool spelaigen=true;
   
   char svar;
   
   int saldo=0;    //Spelkontots saldo.
   int belopp=0;   //Belopp som man väljer att sätta in på sitt spelkonto.
   int insats;
   int intervall;
   int tal;        //Det slumpade talet som skall gissas.
   int forsok;     //Försöksräknare.
   int gissning;
   
   cout  <<endl <<endl <<setw(64) <<"- - * Välkommen till spelet 'Gissa talet'! * - -" <<endl <<endl;
   cout  <<"________________________________________________________________________________" <<endl;
   cout  <<endl <<"Vill du läsa spelreglerna?(j/n): ";
   
   while(regelloop) //Kontroll av om du vill läsa regler.
   {
      cin    >>svar;
      
      if(svar=='j' || svar=='J') //Reglerna listas.
      {
         cout  <<endl <<endl <<setw(41) <<"Regler" <<endl <<endl;
         cout  <<"Spelet går ut på att du ska gissa på ett slumpat tal. Om du gissar rätt vinner " <<endl;
         cout  <<"du dubbla insatsen, men om du gissar fel så förlorar du din insats." <<endl <<endl;
         cout  <<"- Först ombeds du att sätta in ett valfritt belopp mellan 1 och 5000." <<endl;
         cout  <<"- Därefter får du välja belopp att satsa. Du kan välja mellan 100, 300 och 500." <<endl;
         cout  <<"- Beroende på vad du valt att satsa kommer du nu att få olika sifferintervall" <<endl;
         cout  <<"  att välja mellan." <<endl;
         cout  <<"~ 100 kr ger dig möjlighet att gissa på ett tal mellan 1 och 10, alt. mellan 1" <<endl;
         cout  <<"  och 100." <<endl;
         cout  <<"~ 300 eller 500 kr ger dig möjlighet att gissa på ett tal mellan 1" <<endl;
         cout  <<"  och 100, alt. mellan 1 och 1000." <<endl;
         cout  <<"- Om du väljer intervallet 1-10 har du 3 försök på dig att lista ut talet." <<endl;
         cout  <<"- Om du väljer intervallet 1-100 har du 5 försök på dig att lista ut talet." <<endl;
         cout  <<"- Om du väljer intervallet 1-1000 har du 7 försök på dig att lista ut talet." <<endl <<endl;
         cout  <<endl;
         regelloop=false; //Loopen görs till falsk vilket innebär att den avslutas.
      }
      
      else if(svar=='n' || svar=='N') //Du går vidare till spelet.
      {
         cout  <<endl;
         regelloop=false; //Loopen görs till falsk vilket innebär att den avslutas.
      }
      
      else //Om du inte svarat med korrekt tecken loopas du om.
         cout  <<"Ogiltigt val. Var god försök igen.(j/n) ";
   }
   
   while(spelloop) //Denna loop gör det möjligt att spela om igen efter vinst eller förlust.
   {
      depositloop=true;
      
      while(depositloop)//Du ombes att satsa pengar.
      {
         if(saldo<100) //Om ditt saldo inte räcker till spel omdirigeras du till insättning.
            cout  <<"Ditt saldo är " <<saldo <<" kr. Du behöver minst 100 kr för att kunna spela." <<endl;
         
         else //Om ditt saldo räcker till spel frågas du om du ändå vill sätta in mer.
         {
            cout  <<"Ditt saldo är " <<saldo <<" kr." <<endl;
            cout  <<"Vill du sätta in mer pengar?(j/n) ";
         
            svarloop=true;
         
            while(svarloop) //Svaret kontrolleras.
            {
               cin   >>svar;
   
               if(svar=='j' || svar=='J') //Om ja, omdirigeras du till insättning
                  svarloop=false;
   
               else if(svar=='n' || svar=='N') //Om du svarat nej går du vidare i spelet.
               {
                  cout  <<endl;
                  svarloop=false;
                  depositloop=false;  
               }
               
               else //Om du inte svarat med korrekt tecken loopas du om.
                  cout  <<endl <<"Ogiltigt val. Var god försök igen.(j/n) ";
            }
         }
         if(svar=='j' || svar=='J' || saldo<100)
         {
            pengaloop=true;
         
            while(pengaloop) //Du ombes att sätta in pengar på ditt spelkonto.
            {
               cout  <<"Skriv in valfritt belopp mellan 1 och 5000: ";
               cin   >>belopp;
               
               if(belopp<=0 || belopp>5000) //Om beloppet är utanför giltigt värde loopas du om.
                  cout  <<"Ogiltigt belopp. Var god försök igen." <<endl;
            
               else //Om beloppet är giltigt går du vidare.
                  pengaloop=false;
            }
            saldo = saldo + belopp; //Insättningen adderas till saldot.
         }
      }
      
      insatsloop=true;
      
      while(insatsloop) //Du ombes att lägga din insats.
      {
         cout  <<"Välj belopp att satsa(100/300/500): ";
         cin   >>insats;
         
         if(insats==100 || insats==300 || insats==500)
         {
   
            if(insats<=saldo) //Om du skriver giltig insats dras det från ditt saldo och spelet går vidare.
            {
               cout  <<endl;  
               saldo=saldo-insats;
               insatsloop=false;
            }
         
            else //Om du försöker satsa mer än du har loopas du om.
            {
               cout  <<"Du försöker satsa mer än du har. Ditt saldo är " <<saldo <<" kr. Var god försök igen.";
               cout  <<endl;
            }
         }
         
         else //Om du skriver in felaktig insats loopas du om.
            cout  <<"Ogiltig insats. Var god försök igen." <<endl;
      }
      
      if(insats==100)
      {
         tioloop=true;
         
         while(tioloop) //Du ombes välja intervall.
         {
            cout  <<"Välj intervall. Skriv 10 för intervallet 1-10, alt. skriv 100 för intervallet 1-100: ";
            cin   >>intervall;
            
            if(intervall==10 || intervall==100) //Om du skriver giltigt intervall går du vidare.
            {
               cout  <<endl;
               tioloop=false;
            }
            
            else //Om du skriver in felaktigt intervall loppas du om.
               cout  <<"Ogiltigt intervall. Var god försök igen." <<endl;
         }
      }
      
      else if(insats==300)
      {
         tusenloop=true;
         
         while(tusenloop) //Du ombes välja intervall.
         {
            cout  <<"Välj intervall. Skriv 100 för intervallet 1-100, alt. 1000 för intervallet" <<endl;
            cout  <<"1-1000: ";
            cin   >>intervall;
         
            if(intervall==100 || intervall==1000) //Om du skriver giltigt intervall går du vidare.
            {
               cout  <<endl;
               tusenloop=false;
            }
            
            else //Om du skriver in felaktigt intervall loppas du om.
               cout  <<"Ogiltigt intervall. Var god försök igen." <<endl;
         }
      }
      
      else //Om insatsen är 500 blir intervallet automatiskt 1-1000.
      {
         cout  <<endl;
         intervall=1000;
      } 
      
      srand(time(0)); //Randomfunktionen nollställs.
      forsok=0;       //Försöksräknaren nollställs.
      
      if(intervall==10)
      {
         tal=rand()%10+1; //Slumpar ett värde mellan 1 och 10.
         forsok=3;
         cout  <<"Du skall nu gissa på ett tal från 1 till 10. Du har 3 försök på dig: ";
      }
         
      else if(intervall==100)
      {
         tal=rand()%100+1; //Slumpar ett värde mellan 1 och 100.
         forsok=5;
         cout  <<"Du skall nu gissa på ett tal från 1 till 100. Du har 5 försök på dig: ";
      }
      
      else //Om intervallet är 1-1000.
      {
         tal=rand()%1000+1; //Slumpar ett värde mellan 1 och 1000.
         forsok=7;
         cout  <<"Du skall nu gissa på ett tal från 1 till 1000. Du har 7 försök på dig: ";
      }
      
      forsoksloop=true;
      
      while(forsoksloop) //Du ombes nu att börja gissa.
      {
         cin   >>gissning;
         
         if(gissning==tal) //Om gissningen var rätt.
         {
            cout  <<endl <<setw(50) <<"* * * * * * * * * * *" <<endl;
            cout  <<setw(50) <<"*                   *" <<endl;
            cout  <<setw(50) <<"*     GRATTIS!!     *" <<endl;
            cout  <<setw(50) <<"*                   *" <<endl;
            cout  <<setw(50) <<"* * * * * * * * * * *" <<endl;
            cout  <<endl <<"Ditt svar var korrekt. Du vinner " <<insats*2 <<" kr. ";
            saldo=saldo+(insats*2); //Dubbla insatsen läggs till på spelkontot.
            cout  <<"Ditt nya saldo är " <<saldo <<" kr." <<endl <<endl;
            
            forsoksloop=false;
         }
         
         else
         {
            forsok--; //Om du gissar fel dras ett försök från försöksräknaren.
            
            if(forsok==0) //Om försöksräknaren = 0 förlorar du.
            {
               cout  <<endl <<setw(49) <<"      *****      " <<endl;
               cout  <<setw(49) <<"    **     **    " <<endl;
               cout  <<setw(49) <<"  **         **  " <<endl;
               cout  <<setw(49) <<" *    *   *    * " <<endl;
               cout  <<setw(49) <<"*     *   *     *" <<endl;
               cout  <<setw(49) <<"*               *" <<endl;
               cout  <<setw(49) <<"*     *****     *" <<endl;
               cout  <<setw(49) <<" *  **     **  * " <<endl;
               cout  <<setw(49) <<" * *         * * " <<endl;
               cout  <<setw(49) <<"  **         **  " <<endl;
               cout  <<setw(49) <<"    **     **    " <<endl;
               cout  <<setw(49) <<"      *****      " <<endl;
               cout  <<endl <<"Ditt svar var tyvärr fel och du förlorar din insats. ";
               cout  <<"Talet jag tänkte på var " <<tal <<"." <<endl;
               cout  <<"Ditt nya saldo är " <<saldo <<" kr." <<endl <<endl;
               forsoksloop=false;
            }
               
            else //Om du har försök kvar får du gissa igen.
            {
               cout  <<"Ditt svar var fel. ";
               
               if(gissning>tal)
                  cout  <<"Gissa lägre: ";
               
               else
                  cout  <<"Gissa högre: ";
            }
         }
      }
      
      spelaigen=true;
      
      while(spelaigen) //När spelomgången är slut frågas du om du vill spela igen.
      {
         cout  <<"Vill du spela igen?(j/n): ";
         
         svarloop=true;
         
         while(svarloop) //Svaret kontrolleras.
         {
            cin   >>svar;
   
            if(svar=='j' || svar=='J' || svar=='n' || svar=='N') //Om ja eller nej går du vidare.
               svarloop=false;
               
            else //Om du inte svarat med korrekt tecken loopas du om.
               cout  <<endl <<"Ogiltigt val. Var god försök igen.(j/n): ";
         }
         
         if(svar=='n' || svar=='N') //Om svaret var nej dubbelkollas det om du verkligen vill avsluta.
         {
            cout  <<"Är du verkligen säker?(j/n): ";
               
            svarloop=true;
               
            while(svarloop) //Svaret kontrolleras.
            {
               cin   >>svar;
   
               if(svar=='j' || svar=='J') //Om svaret är ja avslutas spelet.
               {
                  cout  <<endl;
                  svarloop=false;
                  spelaigen=false;
                  spelloop=false;
               }
                  
               else if(svar=='n' || svar=='N') //Om svaret är nej loopas du om till frågan om du vill spela igen.
                     svarloop=false;
                  
               else //Om du inte svarat med korrekt tecken loopas du om.
                     cout  <<"Ogiltigt val. Var god försök igen.(j/n): ";
            }
         }
         
         else
         {
            cout  <<endl;
            spelaigen=false;
         }
      }
   }
   cout  <<"Tack för att du har spelat! Ditt saldo som är " <<saldo <<" kr kommer att sättas in på " <<endl;
   cout  <<"ditt bankkonto inom 3 dagar. Tryck ENTER för att avsluta." <<endl;
   
   cin.ignore();
   cin.get(); // Kräver att användaren slår in en tangent för att gå vidare. Detta gör att systemet "pausas".
}
