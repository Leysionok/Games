#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <stdio.h> 
#include <direct.h>
using namespace std;
struct Magazine
{int IDs,Cena,PG;string Title,Genre,Platforms;
Magazine* AE;
};
class DB
{private:
        string PutDB;
        string Exter;
        Magazine* FRST;
        Magazine* Rb;
    public:
        DB(string Pyt, string Yolo)
        {PutDB=Pyt; Exter=Yolo;
        }
        ~DB()
        {
            chistka();
        }

        string PutKDB(string Titles)
        {
            return PutDB + Titles + Exter;
        }
        
        void Zapolnenie(string Titles)
        {
            chistka();

            ifstream uFout;

            uFout.open(PutKDB(Titles).c_str());

            if ( ! uFout.is_open())
            { cout << "Íå óäàëîñü îòêðûòü ÁÄ!" << endl;  return;}
            int uCountOfRecords = ChisloZapizey(uFout);
            if ( ! uCountOfRecords)
            {cout << "Çàïèñè â ÁÄ îòñóòñòâóþò!" << endl;return;}
            uFout.clear();
            uFout.seekg(0, ios_base::beg);
            for (int uI = 0; uI < uCountOfRecords; uI++)
            {Magazine*NewGame = new Magazine; NewGame->IDs = uI + 1;
               uFout>> NewGame->Title
                    >> NewGame->Genre
                    >> NewGame->Platforms
                    >> NewGame->Cena
                    >> NewGame->PG;

                NewGame->AE = NULL;

                if (FRST == NULL)
                {
                    FRST = NewGame;
                }
                else
                {
                    Rb->AE = NewGame;
                }

                Rb = NewGame;
            }

            uFout.close();
        }
        void PlusGame(string Titles)
        {
            ofstream uFout(PutKDB(Titles).c_str(), ios_base::app);
            if (!uFout.is_open())
            { cout << "Íå óäàëîñü îòêðûòü ÁÄ!" << endl; return;
            }

            do
            {uFout << getInput("Ââåäèòå íàçâàíèå"); uFout <<  " " + getInput("Ââåäèòå æàíð èãðû"); uFout <<  " " + getInput("Ââåäèòå èãðîâóþ ïëàòôîðìó"); 
			uFout << " " + getInput("Ââåäèòå öåíó");
                uFout << " " + getInput("Ââåäèòå âîçðàñòíîå îãðàíè÷åíèå") << endl;
            }
            while (getInput("Õîòèòå äîáàâèòü åùå îäíó çàïèñü? 1 - Äà, 0 - Íåò") != "0");

            cout << "Îòëè÷íî! Âû óñïåøíî çàïîëíèëè ÁÄ." << endl;

            uFout.close();
        }

        void Deleting(string Titles, int uLine)
        {
            int uI = 0;
            string uS_1,
                   uS_2;
            ifstream uFout_1;
            ofstream uFout_2;

            uFout_1.open(PutKDB(Titles).c_str());

            if ( ! uFout_1.is_open())
            {
                cout << "Íå óäàëîñü îòêðûòü ÁÄ!" << endl;

                return;
            }

            while (getline(uFout_1, uS_1))
            {
                if (uI++ != uLine)
                {
                    uS_2 += uS_1 + "\n";
                }
            }

            uFout_1.close();

            uFout_2.open(PutKDB(Titles).c_str());
            uFout_2 << uS_2.erase(uS_2.find_last_not_of(" \n\r\t") + 1);
            uFout_2.close();

            cout << "Îòëè÷íî! Âû óñïåøíî óäàëèëè çàïèñü." << endl;
        }

        void Editing(string Titles, int uLine)
        {
            int uI = 0;
            string uS_1,
                   uS_2;
            ifstream uFout_1;
            ofstream uFout_2;

            uFout_1.open(PutKDB(Titles).c_str());

            if ( ! uFout_1.is_open())
            {
                cout << "Íå óäàëîñü îòêðûòü ÁÄ!" << endl;

                return;
            }

            while (getline(uFout_1, uS_1))
            {
                if (uI++ != uLine)
                {
                    uS_2 += uS_1 + "\n";
                }
                else
                {
                    uS_2 += getInput("Ââåäèòå íàçâàíèå");
                    uS_2 += " " + getInput("Ââåäèòå æàíð èãðû");
                    uS_2 += " " + getInput("Ââåäèòå èãðîâóþ ïëàòôîðìó");
                    uS_2 += " " + getInput("Ââåäèòå öåíó");
                    uS_2 += " " + getInput("Ââåäèòå âîçðàñòíîå îãðàíè÷åíèå") + "\n";
                }
            }
uFout_1.close();uFout_2.open(PutKDB(Titles).c_str()); uFout_2 << uS_2.erase(uS_2.find_last_not_of(" \n\r\t") + 1);
            uFout_2.close();

            cout << "Âû îòðåäàêòèðîâàëè çàïèñü" << endl;
        }

        void Sorting(string Titles, int uType_1, int uType_2)
        {
            Zapolnenie(Titles);

            Magazine *Game1,
                  *Game2;

            bool uCheck;

            for(Game1 = FRST; Game1; Game1 = Game1->AE)
            {
                for(Game2 = FRST; Game2; Game2 = Game2->AE)
                {
                    uCheck = false;

                    if (uType_1 == 1)
                    {
                        if (uType_2 == 1)
                        {
                            uCheck = Game1->IDs > Game2->IDs;
                        }
                        else if (uType_2 == 2)
                        {
                            uCheck = Game1->Cena > Game2->Cena;
                        }
                        else if (uType_2 == 3)
                        {
                            uCheck = Game1->PG > Game2->PG;
                        }
                        else if (uType_2 == 4)
                        {
                            uCheck = Game1->Title > Game2->Title;
                        }
                        else if (uType_2 == 5)
                        {
                            uCheck = Game1->Genre > Game2->Genre;
                        }
                        else if (uType_2 == 6)
                        {
                            uCheck = Game1->Platforms > Game2->Platforms;
                        }
                    }
                    else if (uType_1 == 2)
                    {
                        if (uType_2 == 1)
                        {
                            uCheck = Game1->IDs < Game2->IDs;
                        }
                        else if (uType_2 == 2)
                        {
                            uCheck = Game1->Cena < Game2->Cena;
                        }
                        else if (uType_2 == 3)
                        {
                            uCheck = Game1->PG < Game2->PG;
                        }
                        else if (uType_2 == 4)
                        {
                            uCheck = Game1->Title < Game2->Title;
                        }
                        else if (uType_2 == 5)
                        {
                            uCheck = Game1->Genre < Game2->Genre;
                        }
                        else if (uType_2 == 6)
                        {
                            uCheck = Game1->Platforms < Game2->Platforms;
                        }
                    }

                    if(uCheck)
                    {
                        int IDs = Game1->IDs,
                            Cena = Game1->Cena,
                            PG = Game1->PG;

                        string Title = Game1->Title,
                               Genre = Game1->Genre,
                               Platforms = Game1->Platforms;

                        Game1->IDs = Game2->IDs;
                        Game1->Cena = Game2->Cena;
                        Game1->PG = Game2->PG;
                        Game1->Title = Game2->Title;
                        Game1->Genre = Game2->Genre;
                        Game1->Platforms = Game2->Platforms;
                        Game2->IDs = IDs;
                        Game2->Cena = Cena;
                        Game2->PG = PG;
                        Game2->Title = Title;
                        Game2->Genre = Genre;
                        Game2->Platforms = Platforms;
                    }
                }
            }

            PrintRecords(Titles);

            if (getInput("Õîòèòå ñîõðàíèòü â îòäåëüíûé ôàéë ðåçóëüòàò ñîðòèðîâêè? 1 - Íåò, 0 - Äà") == "0")
            {
                saveDumpStructurePhone(Titles, getInput("Ââåäèòå èìÿ íîâîé ÁÄ"));
            }
        }

        void saveDumpStructurePhone(string Titles, string uPrefix)
        {
            ofstream uFout(PutKDB(uPrefix).c_str(), ios_base::app);

            if ( ! uFout.is_open())
            {
                cout << "Íå óäàëîñü îòêðûòü ÁÄ!" << endl;

                return;
            }

           Magazine*uTemp = FRST;

            while(uTemp)
            {
                uFout
                    << uTemp->Title
                    << " "
                    << uTemp->Genre
                    << " "
                    << uTemp->Platforms
                    << " "
                    << uTemp->Cena
                    << " "
                    << uTemp->PG
                    << endl;

                uTemp = uTemp->AE;
            }

            cout << "Îòëè÷íî! Âû óñïåøíî ñîçäàëè îòñîðòèðîâàííóþ ÁÄ." << endl;

            uFout.close();
        }

        void Poisk(string Titles)
        {
            string SearchName,
            	   SearchN = "0",
                   uGolf;

			SearchName = getInput("Ââåäèòå íàçâàíèå èãðû");

            Zapolnenie(Titles);

           Magazine*uTemp = FRST;

            bool uCheck;
            
            bool uCheck_4;

            char *uPch;

            while(uTemp)
            {
uCheck_4 = SearchName != "" && ((strstr(uTemp->Title.c_str(), SearchName.c_str()) != NULL) || strstr(SearchN.c_str(), SearchName.c_str()));

                if ( ! uCheck && uCheck_4)
                {
                    uCheck = true;
                    PrintTable();
            	}
            	
            	if (uCheck && uCheck_4)
            	{
            		 PrintRecordsGames(uTemp);
            	}
            	
                uTemp = uTemp->AE;
            }

            if ( ! uCheck)
            {
                cout << "Ïî çàïðîñó íå íàéäåíî íè îäíîé çàïèñè" << endl;
            }
        }
        
        void Poisk1(string Titles)
        {
            string SearchName,
            	   SearchGenre,
            	   
            	   SearchN = "0",
                   uGolf;

			SearchName = getInput("Ââåäèòå íàçâàíèå èãðû");
			SearchGenre = getInput("Ââåäèòå æàíð èãðû");
		

            Zapolnenie(Titles);

           Magazine*uTemp = FRST;

            bool uCheck;
            bool uCheck_2;
          
            bool uCheck_4;

            char *uPch;

            while(uTemp)
            {
                uCheck_2 = SearchName != "" && ((strstr(uTemp->Title.c_str(), SearchName.c_str()) != NULL) || strstr(SearchN.c_str(), SearchName.c_str()));
                uCheck_4 = SearchGenre != "" && ((strstr(uTemp->Genre.c_str(), SearchGenre.c_str()) != NULL) || strstr(SearchN.c_str(), SearchGenre.c_str()));

                if ( ! uCheck && uCheck_2 && uCheck_4)
                {
                    uCheck = true;
                    PrintTable();
            	}
            	
            	if (uCheck_2 && uCheck_4)
            	{
            		 PrintRecordsGames(uTemp);
            	}
            	
                uTemp = uTemp->AE;
            }

            if ( ! uCheck)
            {
                cout << "Ïî çàïðîñó íå íàéäåíî íè îäíîé çàïèñè" << endl;
            }
        }

        

        void PrintRecords(string Titles)
        {
           Magazine*uTemp = FRST;

            PrintTable();

            while(uTemp)
            {
                PrintRecordsGames(uTemp);
                uTemp = uTemp->AE;
            }
        }

        void PrintTable()
        {
            cout
                << left
                << setw(5)
                << "ID"
                << setw(20)
                << "Íàçâàíèå"
                << setw(10)
                << "Æàíð"
                << setw(15)
                << "Ïëàòôîðìà"
                << setw(10)
                << "Öåíà"
                << setw(10)
                << "Âîçðàñò"
                << endl;
        }

        void PrintRecordsGames(Magazine *uTemp)
        {
            cout
                << setw(5)
                << uTemp->IDs
                << setw(20)
                << uTemp->Title
                << setw(10)
                << uTemp->Genre
                << setw(15)
                << uTemp->Platforms
                << setw(10)
                << uTemp->Cena
                << setw(10)
                << uTemp->PG
                << endl;
        }

        int ChisloZapizey(ifstream &uFout)
        {
            int chislo = 0;
            string uS;

            while (getline(uFout, uS))
            {
                ++chislo;
            }

            return chislo;
        }

       
        void chistka()
        {
            FRST = NULL;
            Rb  = NULL;
        }

        string getInput(string uMessage)
        {
            string uInput;

            cout << uMessage + " ";
            cin >> uInput;
        

            return uInput;
        }
};

int main()
{   setlocale(LC_ALL, "rus"); 
    DB DB("Ñ:\\Base\\", ".txt");
    int ID;
        cout<<"Ââåäèòå áàçó äàííûõ: \n";
        system("cls");
                bool uCheck = false;
string Titles = DB.getInput("");


                while(true)
                {   
                    if (uCheck)
                    {
                        break;
                    }

                    cout
                        << "\n Ïðîãðàììà ó÷¸òà ìàãàçèíà êîìïüþòåðíûõ èãð"
						<< endl
						<< endl
                        << "Âûáåðèòå äåéñòâèå:"
                        << endl
                        << endl
                        << "1) Ïîêàçàòü òàáëèöó"
                        << endl
                        << "2) Äîáàâèòü íîâóþ çàïèñü"
                        << endl
                        << "3) Óäàëèòü çàïèñü"
                        << endl
                        << "4) Ïîèñê çàïèñè"
                        << endl
                        << "5) Ñîðòèðîâêà çàïèñåé"
                        << endl
                        << "6) Ðåäàêòèðîâàíèå çàïèñè"
                        << endl
                        << "7) Âûõîä èç ïðîãðàììû"
                        << endl
                        << endl
                        << "Âàø âûáîð (1-7): ";

                    cin >> ID;

                    cout << endl;

                    system("cls");

                    switch(ID)
                    {
                        case 1:
                        {
                            DB.Zapolnenie(Titles);
                            DB.PrintRecords(Titles);
                            break;
                        }

                        case 2:
                        {
                            DB.PlusGame(Titles);
                            break;
                        }

                        case 3:
                        {
                            DB.Deleting(Titles, atoi(DB.getInput("Ââåäèòå ID çàïèñè").c_str()) - 1);
                            break;
                        }

                        case 4:
                        {   int ch;
                        cout<<"Âûáåðèòå êîëè÷åñòâî ïîëåé äëÿ ïîèñêà \n 1.Ïî îäíîìó ïîëþ \n 2.Ïî äâóì ïîëÿì \n";
                        cin>>ch;
                        if(ch==1){ DB.Poisk(Titles);}
                        if(ch==2){ DB.Poisk1(Titles);}
                            
                            break;
                        }

                        case 5:
                        {
                            DB.Sorting(
                                Titles,
                                atoi(DB.getInput("Ââåäèòå òèï ñîðòèðîâêè. 1 - Óáûâ. 2 - Âîçð.").c_str()),
                                atoi(DB.getInput("Ââåäèòå ïîëå. 1 - ID. 2 - Öåíà. 3 - Âîçðàñòíûå îãðàíè÷åíèÿ. 4 - Íàçâàíèå.  5 - Æàíð. 6 - Èãðîâàÿ ïëàòôîðìà.").c_str())
                            );

                            break;
                        }

                        case 6:
                        {
                            DB.Editing(Titles, atoi(DB.getInput("Ââåäèòå ID çàïèñè").c_str()) - 1);
                            break;
                        }

                        case 7:
                        {
                            exit(0);
                            break;
                        }

                        default:
                        {
                            cout << "Îøèáêà. Ïîâòîðèòå!" << endl;
                            break;
                        }} }
return 0; }
