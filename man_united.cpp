#include<iostream>
#include<fstream>            // if you have fstream header try omitting iostream header file
#include<string>
#include<cstdio>             // cstdio header file is used for remove and rename function 
#include<cstdlib>
using namespace std;

class manUnited{
    private:
    int kit_no;
    string name;
    int age;
    string position;
    int goals_scored;
    int assists;
    int tackles;
    int saves_made;
    int goals_conceded;

    public:
    void get_details();          
    void display();
    void modify();
    void update_stats();

    int get_kitno()              // accessor function
    {                            // small functions can be inline i.e., when we define member functions inside class they are by default inline
        return kit_no;
    }

    string get_name()            // accessor function
    {
        return name;
    }

    string get_pos()             // accessor function
    {
        return position;
    }
};

void manUnited::get_details()         
{
    cout<<"\nEnter the name of the player: ";
    cin.ignore();
    getline(cin,name);
    cout<<"\nEnter the kit number: ";              // try to make a function which checks the kit number clash before assigning it to any new player
    cin>>kit_no;
    cout<<"\nEnter the age of the player: "; 
    cin>>age;
    cout<<"\nEnter the role of the player(CF,LW,RW,CM,LM,RM,CB,LB,RB,GK): ";
    cin>>position;
    goals_scored = 0;                                     // can we create a constructor function and call it from a member function
    assists = 0;                    
    saves_made = 0;
    goals_conceded = 0;
    tackles = 0;
}

void manUnited::display()
{
    cout<<"\nNAME: "<<name; 
    cout<<"\nKIT NO.: "<<kit_no;
    cout<<"\nAGE: "<<age;
    cout<<"\nPOSITION: "<<position;
    cout<<"\nGOALS SCORED: "<<goals_scored;
    cout<<"\nASSISTS: "<<assists;
    cout<<"\nTACKLES: "<<tackles;
    if(position == "GK" || position == "gk")
    {
        cout<<"\nGOALS CONCEDED: "<<goals_conceded;
        cout<<"\nSAVES MADE: "<<saves_made;
    }
    else
    {
        cout<<"\nGOALS CONCEDED: NOT APPLICABLE";
        cout<<"\nSAVES MADE: NOT APPLICABLE";
    }
}

void manUnited::modify()
{
    display();
    int choice;
    char ch='y';
    cout<<"\n\n\tMENU";
    cout<<"\n1.NAME";
    cout<<"\n2.KIT NUMBER";
    cout<<"\n3.AGE";
    cout<<"\n4.POSITION";
    while(ch=='y' || ch=='Y')
    {
        cout<<"\nEnter your choice(1-4): ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"\nEnter the new Name: ";
                cin.ignore();
                getline(cin,name);    
                break;
            
            case 2: 
                cout<<"\nEnter the new kit number: ";
                cin>>kit_no;
                break;

            case 3: 
                cout<<"\nEnter the current age: ";
                cin>>age;
                break;

            case 4: 
                cout<<"\nEnter the new position: ";
                cin>>position;
                break;

            default:
                cout<<"\nWRONG CHOICE!!!";
                break;
        }

        cout<<"\nDo you want to modify anything else ?(Y/N)";
        cin>>ch;
    }
}

void manUnited::update_stats()
{
    char ch = 'y';
    cout<<"\n\n\tMENU";
    cout<<"\n1.GOALS SCORED";
    cout<<"\n2.ASSISTS";
    cout<<"\n3.TACKLES MADE";
    cout<<"\n4.SAVES MADE";
    cout<<"\n5.GOALS CONCEDED";

    do
    {
        int choice;
        int ele;
        cout<<"\nWhich stat do you want to modify ?";
        cin>>choice;
        switch (choice)
        {
            case 1: 
                cout<<"\nTotal goals scored: ";
                cin>>ele;
                goals_scored = ele;
                break;

            case 2: 
                cout<<"\nTotal assists provided: ";
                cin>>ele;
                assists = ele;
                break; 
                    
            case 3: 
                cout<<"\nTotal tackles made: ";
                cin>>ele;
                tackles = ele;
                break; 

            case 4: 
                if(position == "GK" || position == "gk")
                {
                    cout<<"\nTotal saves made: ";
                    cin>>ele;
                    saves_made = ele;
                }
                break; 
                    
            case 5: 
                if(position == "GK" || position == "gk")
                {
                    cout<<"\nTotal goals conceded: ";
                    cin>>ele;
                    goals_conceded = ele;
                }
                break; 

            default:
                cout<<"\nWrong choice!!!";
                break;
            }
        cout<<"\nDo you want to modify any other stats ?(y/n): ";
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');
}

manUnited player;

// void writeplayer()                                                       // function to write in the file in sorted order wrt kit number
// {
//     system("cls");
//     cout<<"\n\tINSERT PLAYER DETAILS\n";

//     manUnited new_player;

//     ifstream fi;                                                         // problem with this insert function is that you can insert only 1 player at a time
//     fi.open("manUnited.dat", ios::in | ios::binary);
//     ofstream fo;
//     fo.open("temp.dat", ios::out | ios::binary);                         // no need for ios::app as temp is a new file

//     // cout<<"\nEnter details of the player"<<endl;
//     new_player.get_details();

//     char ch = 'y';
//     while(!fi.eof())                                                 
//     {
//         fi.read((char *)&player, sizeof(player));
//         if(player.get_kitno() > new_player.get_kitno())
//         {
//             fo.write((char *)&new_player, sizeof(new_player));
//             ch = 'n';
//             break;
//         }

//         else
//             fo.write((char *)&player, sizeof(player));
//     }

//     if(ch == 'y')
//         fo.write((char *)&new_player, sizeof(new_player));
//     else if(!fi.eof())
//     {
//         while(!fi.eof())
//         {
//             fi.read((char *)&player, sizeof(player));
//             fo.write((char *)&player, sizeof(player));
//         }
//     }

//     fi.close();
//     fo.close();

//     remove("manUnited.dat");
//     rename("temp.dat","manUnited.dat");
// }

void writeplayer()
{
    system("cls");
    cout<<"\n\tINSERT PLAYER DETAILS\n";
    ofstream fo;
    fo.open("manUnited.dat", ios::app | ios::binary);

    char ch;
    do
    {
        player.get_details();
        fo.write((char *)&player, sizeof(player));
        cout<<"\nDo you want any other player(y/n)? : ";
        cin>>ch;
    }while (ch == 'y' | ch == 'Y');
    
    fo.close();
}

void updateplayerstats()
{
    system("cls");
    cout<<"\n\tUPDATE PLAYER STATS\n";

    fstream fio;
    fio.open("manUnited.dat", ios::in | ios::out | ios::binary);
    
    string nm;
    cout<<"\nEnter the name of the player whose stats you want to update: ";
    cin.ignore();
    getline(cin,nm);
    char found = 'f';
    while(!fio.eof())
    {
        long pos = fio.tellg();
        fio.read((char *)&player, sizeof(player));
        if(player.get_name() == nm)
        {
            player.display();
            player.update_stats();
            found = 't';   
            fio.seekg(pos,ios::beg);
            fio.write((char *)&player, sizeof(player));
            break;
        }
    }
    if(found == 'f')
    cout<<"\nRecord not found";
    fio.close();
}

void modifyplayer()
{
    system("cls");
    cout<<"\n\tMODIFY PLAYER DETAILS\n";

    fstream fio;
    fio.open("manUnited.dat", ios::in | ios::out | ios::binary);
    
    string nm;
    cout<<"\nEnter the name of the player whose details you wish to modify: ";
    cin.ignore();
    getline(cin,nm);
    
    char found = 'f';
    while(!fio.eof())
    {
        long pos = fio.tellg();
        fio.read((char *)&player, sizeof(player));
        if(player.get_name() == nm)
        {
            found = 't';
            player.modify();
            fio.seekg(pos,ios::beg);
            fio.write((char *)&player, sizeof(player));
            cout<<"\nRecord Updated";
            break;
        }
    }
    if(found == 'f')
    cout<<"\nRecord not found!!!";
    fio.close();
}

void deleteplayer()
{
    system("cls");
    cout<<"\n\tDELETE PLAYER DETAILS\n";

    ifstream fi;
    fi.open("manUnited.dat", ios::in | ios::binary);
    ofstream fo;
    fo.open("temp.dat", ios::out | ios::binary);

    string nm;
    cout<<"\nEnter the name of player you want to remove from your squad: ";
    cin.ignore();
    getline(cin,nm);

    char ch = 'y';
    char found = 'f';
    while(!fi.eof())                                                              // we haven't use fi.seekg(0,ios::beg) because by default the
    {                                                                             // file pointer will be placed at the beginning in ios::in mode
        fi.read((char *)&player, sizeof(player));
        if(player.get_name() == nm)
        {
            found = 't';
            player.display();
            cout<<"\nAre you sure, you want to delete this player's details(y/n): ";
            cin>>ch;
            if(ch == 'n' || ch == 'N')
            fo.write((char *)&player, sizeof(player));
        }

        else
            fo.write((char *)&player, sizeof(player));
    }

    if(found == 'f')
    cout<<"\nRecord not found";
    fi.close();
    fo.close();
    remove("manUnited.dat");
    rename("temp.dat","manUnited.dat");
}

void displaySpecificplayer()
{
    system("cls");
    cout<<"\n\tSPECIFIC PLAYER DETAILS\n";

    ifstream fi;
    fi.open("manUnited.dat", ios::in | ios::binary);

    string nm;
    cout<<"\nEnter the name of the player whose details you wish to see: ";
    cin>>nm;
    char found = 'f';
    while(!fi.eof())
    {
        fi.read((char *)&player, sizeof(player));
        if(player.get_name() == nm)
        {
            found = 't';
            player.display();
            break;
        }
    }
    if(found == 'f')
    cout<<"\nRecord not found!!!";
    fi.close();
}

void displayforwards()
{
    system("cls");
    cout<<"\n\tFORWARDS\n";

    ifstream fi;
    fi.open("manUnited.dat", ios::in | ios::binary);
    char found = 'f';
    while(!fi.eof())
    {
        fi.read((char *)&player, sizeof(player));
        string p = player.get_pos();
        if(p == "CF" || p == "LW" || p == "RW")
        {
            found = 't';
            player.display();
        }
    }
    if(found == 'f')
    cout<<"\nReds are working on recruiting forwards!!!";
    fi.close();
}

void displaymidfielders()
{
    system("cls");
     cout<<"\n\tMID-FIELDERS\n";

    ifstream fi;
    fi.open("manUnited.dat", ios::in | ios::binary);
    char found = 'f';
    while(!fi.eof())
    {
        fi.read((char *)&player, sizeof(player));
        string p = player.get_pos();
        if(p == "CM" || p == "LM" || p == "RM")
        {
            found = 't';
            player.display();
        }
    }
    if(found == 'f')
    cout<<"\nReds are working on recruiting mid-fielders!!!";
    fi.close();
}

void displaydefenders()
{
    system("cls");
    cout<<"\n\tDEFENDERS\n";

    ifstream fi;
    fi.open("manUnited.dat", ios::in | ios::binary);
    char found = 'f';
    while(!fi.eof())
    {
        fi.read((char *)&player, sizeof(player));
        string p = player.get_pos();
        if(p == "CB" || p == "LB" || p == "RB")
        {
            found = 't';
            player.display();
        }
    }
    if(found == 'f')
    cout<<"\nReds are working on recruiting defenders!!!";
    fi.close();
}

void displaygoalkeepers()
{
    system("cls");
    cout<<"\n\tGOALKEEPERS\n";

    ifstream fi;
    fi.open("manUnited.dat", ios::in | ios::binary);
    char found = 'f';
    while(!fi.eof())
    {
        fi.read((char *)&player, sizeof(player));
        string p = player.get_pos();
        if(p == "GK")
        {
            found = 't';
            player.display();
        }
    }
    if(found == 'f')
    cout<<"\nReds are working on recruiting goalkeepers!!!";
    fi.close();
}

void displayAllplayers()
{
    system("cls");
    cout<<"\n\tENTIRE SQUAD\n";

    ifstream fi;
    fi.open("manUnited.dat", ios::in | ios::binary);
    int i=1;
    while(!fi.eof())
    {
        fi.read((char *)&player, sizeof(player));
        cout<<"\nPLAYER "<<i;
        player.display();
        i++;
    }
    fi.close();
}

int main()
{
    char ch;
    do
    {
        system("cls");
        int choice;
        cout<<"\n\tMAIN MENU";
        cout<<"\n1. ADD NEW PLAYER";
        cout<<"\n2. UPDATE PLAYER STATS";
        cout<<"\n3. MODIFY PLAYER STATS";
        cout<<"\n4. REMOVE PLAYER";
        cout<<"\n5. DISPLAY PLAYER";
        cout<<"\n\nEnter you choice(1-5): ";
        cin>>choice;
        switch(choice)
        {
            case 1: 
                writeplayer();
                break;
            
            case 2:
                updateplayerstats();
                break;

            case 3:
                modifyplayer();
                break;

            case 4:
                deleteplayer();
                break;

            case 5:
                system("cls");
                int a;
                cout<<"\n\tMAIN MENU";
                cout<<"\n1. DISPLAY SPECIFIC PLAYER DETAILS";
                cout<<"\n2. DISPLAY FORWARDS";
                cout<<"\n3. DISPLAY MID-FIELDERS";
                cout<<"\n4. DISPLAY DEFENDERS";
                cout<<"\n5. DISPLAY GOALKEEPERS";
                cout<<"\n6. DISPLAY ENTIRE SQUAD";
                cout<<"\nEnter your choice(1-6): ";
                cin>>a;
                switch(a)
                {
                    case 1:
                        displaySpecificplayer();
                        break;

                    case 2:
                        displayforwards();
                        break;

                    case 3:
                        displaymidfielders();
                        break;

                    case 4:
                        displaydefenders();
                        break;

                    case 5:
                        displaygoalkeepers();
                        break;

                    case 6:
                        displayAllplayers();
                        break;

                    default:
                        cout<<"\nWrong Choice!!!";
                        break;  
                }
                break;

            default:
                cout<<"\nWrong Choice!!!";
                break;
        }

        cout<<"\nDo you want to continue ?(y/n): ";
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');
    
    return 0;
}





