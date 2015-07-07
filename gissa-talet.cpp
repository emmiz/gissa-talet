#include <iostream>
#include <ctime>     //Detta bibliotek anv�nds f�r att kunna anv�nda en randomfunktion.
#include <iomanip>   //Detta bibliotek anv�nds f�r att kunna g�ra indrag i texten.
using namespace std;


main()

{
   setlocale(LC_ALL, "swedish"); //G�r att ��� fungerar i terminalen.

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
   int belopp=0;   //Belopp som man v�ljer att s�tta in p� sitt spelkonto.
   int insats;
   int intervall;
   int tal;        //Det slumpade talet som skall gissas.
   int forsok;     //F�rs�ksr�knare.
   int gissning;
   
   cout  <<endl <<endl <<setw(64) <<"- - * V�lkommen till spelet 'Gissa talet'! * - -" <<endl <<endl;
   cout  <<"________________________________________________________________________________" <<endl;
   cout  <<endl <<"Vill du l�sa spelreglerna?(j/n): ";
   
   while(regelloop) //Kontroll av om du vill l�sa regler.
   {
      cin    >>svar;
      
      if(svar=='j' || svar=='J') //Reglerna listas.
      {
         cout  <<endl <<endl <<setw(41) <<"Regler" <<endl <<endl;
         cout  <<"Spelet g�r ut p� att du ska gissa p� ett slumpat tal. Om du gissar r�tt vinner " <<endl;
         cout  <<"du dubbla insatsen, men om du gissar fel s� f�rlorar du din insats." <<endl <<endl;
         cout  <<"- F�rst ombeds du att s�tta in ett valfritt belopp mellan 1 och 5000." <<endl;
         cout  <<"- D�refter f�r du v�lja belopp att satsa. Du kan v�lja mellan 100, 300 och 500." <<endl;
         cout  <<"- Beroende p� vad du valt att satsa kommer du nu att f� olika sifferintervall" <<endl;
         cout  <<"  att v�lja mellan." <<endl;
         cout  <<"~ 100 kr ger dig m�jlighet att gissa p� ett tal mellan 1 och 10, alt. mellan 1" <<endl;
         cout  <<"  och 100." <<endl;
         cout  <<"~ 300 eller 500 kr ger dig m�jlighet att gissa p� ett tal mellan 1" <<endl;
         cout  <<"  och 100, alt. mellan 1 och 1000." <<endl;
         cout  <<"- Om du v�ljer intervallet 1-10 har du 3 f�rs�k p� dig att lista ut talet." <<endl;
         cout  <<"- Om du v�ljer intervallet 1-100 har du 5 f�rs�k p� dig att lista ut talet." <<endl;
         cout  <<"- Om du v�ljer intervallet 1-1000 har du 7 f�rs�k p� dig att lista ut talet." <<endl <<endl;
         cout  <<endl;
         regelloop=false; //Loopen g�rs till falsk vilket inneb�r att den avslutas.
      }
      
      else if(svar=='n' || svar=='N') //Du g�r vidare till spelet.
      {
         cout  <<endl;
         regelloop=false; //Loopen g�rs till falsk vilket inneb�r att den avslutas.
      }
      
      else //Om du inte svarat med korrekt tecken loopas du om.
         cout  <<"Ogiltigt val. Var god f�rs�k igen.(j/n) ";
   }
   
   while(spelloop) //Denna loop g�r det m�jligt att spela om igen efter vinst eller f�rlust.
   {
      depositloop=true;
      
      while(depositloop)//Du ombes att satsa pengar.
      {
         if(saldo<100) //Om ditt saldo inte r�cker till spel omdirigeras du till ins�ttning.
            cout  <<"Ditt saldo �r " <<saldo <<" kr. Du beh�ver minst 100 kr f�r att kunna spela." <<endl;
         
         else //Om ditt saldo r�cker till spel fr�gas du om du �nd� vill s�tta in mer.
         {
            cout  <<"Ditt saldo �r " <<saldo <<" kr." <<endl;
            cout  <<"Vill du s�tta in mer pengar?(j/n) ";
         
            svarloop=true;
         
            while(svarloop) //Svaret kontrolleras.
            {
               cin   >>svar;
   
               if(svar=='j' || svar=='J') //Om ja, omdirigeras du till ins�ttning
                  svarloop=false;
   
               else if(svar=='n' || svar=='N') //Om du svarat nej g�r du vidare i spelet.
               {
                  cout  <<endl;
                  svarloop=false;
                  depositloop=false;  
               }
               
               else //Om du inte svarat med korrekt tecken loopas du om.
                  cout  <<endl <<"Ogiltigt val. Var god f�rs�k igen.(j/n) ";
            }
         }
         if(svar=='j' || svar=='J' || saldo<100)
         {
            pengaloop=true;
         
            while(pengaloop) //Du ombes att s�tta in pengar p� ditt spelkonto.
            {
               cout  <<"Skriv in valfritt belopp mellan 1 och 5000: ";
               cin   >>belopp;
               
               if(belopp<=0 || belopp>5000) //Om beloppet �r utanf�r giltigt v�rde loopas du om.
                  cout  <<"Ogiltigt belopp. Var god f�rs�k igen." <<endl;
            
               else //Om beloppet �r giltigt g�r du vidare.
                  pengaloop=false;
            }
            saldo = saldo + belopp; //Ins�ttningen adderas till saldot.
         }
      }
      
      insatsloop=true;
      
      while(insatsloop) //Du ombes att l�gga din insats.
      {
         cout  <<"V�lj belopp att satsa(100/300/500): ";
         cin   >>insats;
         
         if(insats==100 || insats==300 || insats==500)
         {
   
            if(insats<=saldo) //Om du skriver giltig insats dras det fr�n ditt saldo och spelet g�r vidare.
            {
               cout  <<endl;  
               saldo=saldo-insats;
               insatsloop=false;
            }
         
            else //Om du f�rs�ker satsa mer �n du har loopas du om.
            {
               cout  <<"Du f�rs�ker satsa mer �n du har. Ditt saldo �r " <<saldo <<" kr. Var god f�rs�k igen.";
               cout  <<endl;
            }
         }
         
         else //Om du skriver in felaktig insats loopas du om.
            cout  <<"Ogiltig insats. Var god f�rs�k igen." <<endl;
      }
      
      if(insats==100)
      {
         tioloop=true;
         
         while(tioloop) //Du ombes v�lja intervall.
         {
            cout  <<"V�lj intervall. Skriv 10 f�r intervallet 1-10, alt. skriv 100 f�r intervallet 1-100: ";
            cin   >>intervall;
            
            if(intervall==10 || intervall==100) //Om du skriver giltigt intervall g�r du vidare.
            {
               cout  <<endl;
               tioloop=false;
            }
            
            else //Om du skriver in felaktigt intervall loppas du om.
               cout  <<"Ogiltigt intervall. Var god f�rs�k igen." <<endl;
         }
      }
      
      else if(insats==300)
      {
         tusenloop=true;
         
         while(tusenloop) //Du ombes v�lja intervall.
         {
            cout  <<"V�lj intervall. Skriv 100 f�r intervallet 1-100, alt. 1000 f�r intervallet" <<endl;
            cout  <<"1-1000: ";
            cin   >>intervall;
         
            if(intervall==100 || intervall==1000) //Om du skriver giltigt intervall g�r du vidare.
            {
               cout  <<endl;
               tusenloop=false;
            }
            
            else //Om du skriver in felaktigt intervall loppas du om.
               cout  <<"Ogiltigt intervall. Var god f�rs�k igen." <<endl;
         }
      }
      
      else //Om insatsen �r 500 blir intervallet automatiskt 1-1000.
      {
         cout  <<endl;
         intervall=1000;
      } 
      
      srand(time(0)); //Randomfunktionen nollst�lls.
      forsok=0;       //F�rs�ksr�knaren nollst�lls.
      
      if(intervall==10)
      {
         tal=rand()%10+1; //Slumpar ett v�rde mellan 1 och 10.
         forsok=3;
         cout  <<"Du skall nu gissa p� ett tal fr�n 1 till 10. Du har 3 f�rs�k p� dig: ";
      }
         
      else if(intervall==100)
      {
         tal=rand()%100+1; //Slumpar ett v�rde mellan 1 och 100.
         forsok=5;
         cout  <<"Du skall nu gissa p� ett tal fr�n 1 till 100. Du har 5 f�rs�k p� dig: ";
      }
      
      else //Om intervallet �r 1-1000.
      {
         tal=rand()%1000+1; //Slumpar ett v�rde mellan 1 och 1000.
         forsok=7;
         cout  <<"Du skall nu gissa p� ett tal fr�n 1 till 1000. Du har 7 f�rs�k p� dig: ";
      }
      
      forsoksloop=true;
      
      while(forsoksloop) //Du ombes nu att b�rja gissa.
      {
         cin   >>gissning;
         
         if(gissning==tal) //Om gissningen var r�tt.
         {
            cout  <<endl <<setw(50) <<"* * * * * * * * * * *" <<endl;
            cout  <<setw(50) <<"*                   *" <<endl;
            cout  <<setw(50) <<"*     GRATTIS!!     *" <<endl;
            cout  <<setw(50) <<"*                   *" <<endl;
            cout  <<setw(50) <<"* * * * * * * * * * *" <<endl;
            cout  <<endl <<"Ditt svar var korrekt. Du vinner " <<insats*2 <<" kr. ";
            saldo=saldo+(insats*2); //Dubbla insatsen l�ggs till p� spelkontot.
            cout  <<"Ditt nya saldo �r " <<saldo <<" kr." <<endl <<endl;
            
            forsoksloop=false;
         }
         
         else
         {
            forsok--; //Om du gissar fel dras ett f�rs�k fr�n f�rs�ksr�knaren.
            
            if(forsok==0) //Om f�rs�ksr�knaren = 0 f�rlorar du.
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
               cout  <<endl <<"Ditt svar var tyv�rr fel och du f�rlorar din insats. ";
               cout  <<"Talet jag t�nkte p� var " <<tal <<"." <<endl;
               cout  <<"Ditt nya saldo �r " <<saldo <<" kr." <<endl <<endl;
               forsoksloop=false;
            }
               
            else //Om du har f�rs�k kvar f�r du gissa igen.
            {
               cout  <<"Ditt svar var fel. ";
               
               if(gissning>tal)
                  cout  <<"Gissa l�gre: ";
               
               else
                  cout  <<"Gissa h�gre: ";
            }
         }
      }
      
      spelaigen=true;
      
      while(spelaigen) //N�r spelomg�ngen �r slut fr�gas du om du vill spela igen.
      {
         cout  <<"Vill du spela igen?(j/n): ";
         
         svarloop=true;
         
         while(svarloop) //Svaret kontrolleras.
         {
            cin   >>svar;
   
            if(svar=='j' || svar=='J' || svar=='n' || svar=='N') //Om ja eller nej g�r du vidare.
               svarloop=false;
               
            else //Om du inte svarat med korrekt tecken loopas du om.
               cout  <<endl <<"Ogiltigt val. Var god f�rs�k igen.(j/n): ";
         }
         
         if(svar=='n' || svar=='N') //Om svaret var nej dubbelkollas det om du verkligen vill avsluta.
         {
            cout  <<"�r du verkligen s�ker?(j/n): ";
               
            svarloop=true;
               
            while(svarloop) //Svaret kontrolleras.
            {
               cin   >>svar;
   
               if(svar=='j' || svar=='J') //Om svaret �r ja avslutas spelet.
               {
                  cout  <<endl;
                  svarloop=false;
                  spelaigen=false;
                  spelloop=false;
               }
                  
               else if(svar=='n' || svar=='N') //Om svaret �r nej loopas du om till fr�gan om du vill spela igen.
                     svarloop=false;
                  
               else //Om du inte svarat med korrekt tecken loopas du om.
                     cout  <<"Ogiltigt val. Var god f�rs�k igen.(j/n): ";
            }
         }
         
         else
         {
            cout  <<endl;
            spelaigen=false;
         }
      }
   }
   cout  <<"Tack f�r att du har spelat! Ditt saldo som �r " <<saldo <<" kr kommer att s�ttas in p� " <<endl;
   cout  <<"ditt bankkonto inom 3 dagar. Tryck ENTER f�r att avsluta." <<endl;
   
   cin.ignore();
   cin.get(); // Kr�ver att anv�ndaren sl�r in en tangent f�r att g� vidare. Detta g�r att systemet "pausas".
}
