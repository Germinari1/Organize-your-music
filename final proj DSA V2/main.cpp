/*-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= 
//* Author: Lucas Germinari Carreira
//* Date last updated: 04/28/2024
//* Description (main program): Program that allows a user to manage a music collection of CD and vynil artifacts. The user is able to view the colection, add and remove items from it, calculate its price, and more
//* Tested: yes, passed
//* Notes:
    - All the data structures used in this program are custom implementations
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

//* HEADER FILES
//#include "musicArtifact.h"
#include "musicArtifact.cpp"
#include <iostream>
#include <string>
#include "date.h"
#include "date.cpp"
#include "vinyl.h"
#include "vinyl.cpp"
#include "CD.h"
#include "CD.cpp"
#include "shelf.h"
#include "shelf.cpp"
#include "myMap_v2.h"
#include "common.h"
#include "myQueueLL.h"
#include "hashTableV2.h"
#include "avlBT.h"

//* FUNCTION PROTOTYPES

std::string getMenus(std::string menuIdentifier);
void actions(int userInput, bool& terminator, Shelf& collections, QueueLL<std::string>& cdHashTable, QueueLL<std::string>& VHashTable, AVLTree<std::string>& supplierTree);
void editCollectionItems(Shelf& collections, char collectionIdentifier);
bool confirmUserAction();
void visualizeCollectionItem(Shelf& collections);

//MAIN LOGIC/ENTRY POINT
int main()
{   
    //LOCAL DECLARATIONS
    //instanciate shelf 
    Shelf collections = Shelf();

    QueueLL<std::string> cdHashTable = QueueLL<std::string>();
    QueueLL<std::string> VHashTable = QueueLL<std::string>();
    AVLTree<std::string> supplierTree;

    //indicates when program should hault
    bool terminator = false;
    //stores action currentlt chosen by user
    int userCurrentAction;

    //display initial menu for the program 
    std::cout<<getMenus("intro");

    //keep program running until user quits
    while(!terminator)
    {
        //display menu of actions for user and get action
        std::cout<<getMenus("main_menu");
        do
        {
            std::cin>>userCurrentAction;
        } while (!check_numeric_input(0, 15, userCurrentAction, "", "Choose a number from the menu.", false, false));
        //act upon user input
        std::cin.ignore();
        actions(userCurrentAction, terminator, collections, cdHashTable, VHashTable, supplierTree);
    }

    return 0;
}


//* FUNCTION DEFINITIONS
bool confirmUserAction(){
    std::string inputError = "Enter 'y' or 'n'";
    char userInputConfirmation;

    std::cout<<"Do you confirm [y/n]?";
    do
    {
        std::cin>>userInputConfirmation;
        
        if(!std::cin){
            std::cout<<inputError<<std::endl;
            reset_input_stream();
            continue;
        }
        else if(userInputConfirmation != 'y' && userInputConfirmation != 'n'){
            std::cout<<inputError<<std::endl;
            continue;
        }
        else{
            if(userInputConfirmation == 'y'){
                return true;
            }
            else{
                return false;
            }
            break;
        }
    } while (true);
    
}
void editCollectionItems(Shelf& collections, char collectionIdentifier)
{
    int userEditInput,
    userInput;
    
    if(collectionIdentifier == 'c'){
        

        //display collection so user can select item
        std::cout<<"Choosen which CD you would like to edit:\n";
        collections.displayCDCollection();
        do{
            std::cin>>userInput;
        }while(!check_numeric_input(1, collections.getCollectionSize('c'), userInput, "", "", false, false));

        //display editing actions menu and edit cd 
        std::cout<<getMenus("edit_cd");
        do{
            std::cin>>userEditInput;
        }while(!check_numeric_input(0, 8, userEditInput, "", "", false, false));
        
        if(confirmUserAction()){
        collections.editCD(userInput-1, userEditInput);
        }

        std::cout<<"Take a look at your new CD!\n";
        std::cout<<"\n";
        std::cout<<*(collections.getCDItem(userInput-1));
        std::cout<<"\n";
    }
    else{
        //display collection so user can select item
        std::cout<<"Choosen which vinyl disk you would like to edit:\n";
        collections.displayVinylCollection();
        do{
            std::cin>>userInput;
        }while(!check_numeric_input(1, collections.getCollectionSize('v'), userInput, "", "", false, false));

        //display editing actions menu and edit cd 
        std::cout<<getMenus("edit_vinyl");
        do{
            std::cin>>userEditInput;
        }while(!check_numeric_input(0, 8, userEditInput, "", "", false, false));
        
        if(confirmUserAction()){
        collections.editVinyl(userInput-1, userEditInput);
        }

        std::cout<<"Take a look at your new vinyl disk!\n";
        std::cout<<"\n";
        std::cout<<*(collections.getVinylItem(userInput-1));
        std::cout<<"\n";
    }
}

void visualizeCollectionItem(Shelf& collections)
{
    // Displays a single item from a collection (along with all its attributes)
    
    //input string and variable to store input value
    int itemUserInput;
    char collectionItentifier;
    std::string itemTypePrompt = 
    "\n What type of item would you like to visualize?\n"
    "0) Cancel\n"
    "1) A CD\n"
    "2) A Vinyl disk\n";
    
    //prompt user for which item will he/she wants to visualize and get input
    std::cout<<itemTypePrompt;
    do{
        std::cin>>itemUserInput;
    }while(!check_numeric_input(0, 2, itemUserInput, "", "Choose a valid number from the menu shown",false, false));

    std::cout<<"Choose your item to be displayed:\n";
    if(itemUserInput ==0){
        return;
    }
    else if(itemUserInput == 1){
        collections.displayCDCollection();
        collectionItentifier = 'c';
    }
    else{
        collections.displayVinylCollection();
        collectionItentifier = 'v';
    }
    do
    {
        std::cin>>itemUserInput;
    } while (!check_numeric_input(1, collections.getCollectionSize(collectionItentifier), itemUserInput, "", "Choose an item from the menu", false, false));
    
    //display required item
    if(collectionItentifier == 'c'){
        CD cdToDisplay = *(collections.getCDItem(itemUserInput-1));
        std::cout<<cdToDisplay;
    }
    else{
        Vinyl vinylToDisplay = *(collections.getVinylItem(itemUserInput-1));
        std::cout<<vinylToDisplay;
    }
}


void addQeue(Shelf& collections, QueueLL<std::string>& itemQueue, bool cd=true){
    std::string userConfirmation;
    int userInput;
    std::string itemTitle;
    int collectionSize;

    if(cd){
       collectionSize = collections.getCollectionSize('c');
    }
    else{
       collectionSize = collections.getCollectionSize('v');
    }

    do{
        std::cout<<"Enter your item:\n";
        if(cd){
            collections.displayCDCollection();
        }
        else{
            collections.displayVinylCollection();
        }

        do
        {
            std::cin>>userInput;
        } while (!check_numeric_input(1, collectionSize, userInput, "", "", false, false));
        
        if(cd){
            itemTitle = collections.getCDItem(userInput-1)->getTitle();
        }
        else{
            itemTitle = collections.getVinylItem(userInput-1)->getTitle();
        }

        itemQueue.enqueue(itemTitle);
        
        std::cout<<"Would you like to add another item [y/n]?\n";
        do
        {
            std::cin>>userConfirmation;
        } while (userConfirmation != "y" && userConfirmation != "n");
    }while(userConfirmation != "n");
}

void playQeue(QueueLL<std::string>& VHashTable, QueueLL<std::string>& cdHashTable){
    int userMAType;
    int indexChoice;

    VHashTable.displayQueue("Your CD playlist");
    cdHashTable.displayQueue("Your Vynil playlist");
}

void addSupplier(AVLTree<std::string>& supplierTree)
{
    std::string supplierName;
    std::cout<<"Enter the name of the supplier:\n";
    std::getline(std::cin, supplierName);

    supplierTree.insert(supplierName);  
}

void actions(int userInput, bool& terminator, Shelf& collections, QueueLL<std::string>& cdHashTable, QueueLL<std::string>& VHashTable, AVLTree<std::string>& supplierTree)
{
    char userConfirmation;
    
    //perform action chosen by user
    switch (userInput)
    {
    //quit application
    case 0:
        terminator = true;
        return;
        break;
    //add CD
    case 1:
        {
        std::cout<<"\n";

        std::cout<<"Enter your CD:\n";
        CD cd = CD();
        std::cin>>cd;
        collections.addCD(cd);

        std::cout<<"\n";
        break;
        }
    //add vinyl
    case 2:
        {
        std::cout<<"\n";

        std::cout<<"Enter your vinyl disk:\n";
        Vinyl vinyl_disk = Vinyl();
        std::cin>>vinyl_disk;
        collections.addVinyl(vinyl_disk);

        std::cout<<"\n";
        break;
        }
    //edit CD
    case 3:
        {
        std::cout<<"\n";

        editCollectionItems(collections, 'c');

        std::cout<<"\n";
        break;
        }
    //edit vinyl
    case 4:
        std::cout<<"\n";
        
        editCollectionItems(collections, 'v');
        
        std::cout<<"\n";
        break;
    //delete CD
    case 5:
        {
        std::cout<<"\n";
        
        //get index of item to be deleted
        int userCDInput;

        std::cout<<"Choosen which CD you would like to delete:\n";
        collections.displayCDCollection();
        do{
            std::cin>>userCDInput;
        }while(!check_numeric_input(1, collections.getCollectionSize('c'), userCDInput, "", "", false, false));
        //delete CD
        if(confirmUserAction()){
        collections.removeCD(userCDInput);
        }
        std::cout<<"\n";
        break;
        }
    //delete vinyl
    case 6:
        {
        std::cout<<"\n";
        
        //get index of item to be deleted
        int userVinylInput;
        std::cout<<"Choosen which vinyl disk you would like to delete:\n";
        collections.displayVinylCollection();
        do{
            std::cin>>userVinylInput; 
        }while(!check_numeric_input(1, collections.getCollectionSize('v'), userVinylInput, "", "", false, false));

        //delete CD
        if(confirmUserAction()){
        collections.removeVinyl(userVinylInput);
        }

        std::cout<<"\n";
        break;
        }
        break;
    //display collection
    case 7:
        std::cout<<"\n";
        
        collections.displayCollection(true, true);

        std::cout<<"\n";
        break;
    //export colleciton
    case 8:
        std::cout<<"\n";
        
        confirmUserAction();
        collections.exportCollectionToFile(true, true);

        std::cout<<"\n";
        break;
    //visualize single item
    case 9:
        std::cout<<"\n";

        visualizeCollectionItem(collections);

        std::cout<<"\n";
        break;

    //load collection from file
    case 10:
        std::cout<<"\n";
        {
            std::vector<std::vector<std::pair<std::string, std::string>>> data = collections.parseCollectionFile("exported_collection.txt");
            collections.loadCollectionFromFile(data);
        }
        std::cout<<"\n";
        break;
    //add queue of CDs
    case 11:
        std::cout<<"\n";
        addQeue(collections, cdHashTable);
        std::cout<<"\n";
        break;
    //add queue of Vinyls
    case 12:
        std::cout<<"\n";
        addQeue(collections, VHashTable, false);
        std::cout<<"\n";
        break;
    //"play" queue
    case 13:
        std::cout<<"\n";
        playQeue(VHashTable, cdHashTable);
        std::cout<<"\n";
        break;
    //add supplier
    case 14:
        std::cout<<"\n";
        addSupplier(supplierTree);
        std::cout<<"\n";
    case 15:
        std::cout<<"\n";
        std::cout<<"Suppliers: \n";
        supplierTree.inOrder();
        std::cout<<"\n";
        std::cout<<"\n";
        break;
    default:
        break;
    }
}


std::string getMenus(std::string menuIdentifier)
{
    ///// Returns the string corresponding to the menu identified by menuIdentifier
    
    //Strings containing the text to be returned
    //intro to the program
    std::string intro = 
    "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
                        "WELCOME TO YOUR MUSIC MANAGER!\n"
    "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n"
    "This program allows you to manage your music collections of CD and Vynils. No more lack of organization for you! To ensure a smooth experience, follow the menus to understand what you can do.\n\n";

    std::string mainActionMenu = 
    "0) Quit application\n"
    "1) Add a CD to collection\n"
    "2) Add a vinyl disk to collection\n"
    "3) Edit a CD from collection\n"
    "4) Edit a vinyl disk from collection\n"
    "5) Delete a CD from collection \n"
    "6) Delete a vinyl disk from collection\n"
    "7) Display collection\n"
    "8) Export collection to file\n"
    "9) Visualize an item\n"
    "10) Load collection from file\n"
    "11) Add playlist of CDs\n"
    "12) Add playlist of Vinyls\n"
    "13) Play a queue\n"
    "14) Add Music Artifacts supplier\n"
    "15) Display suppliers\n\n";

    std::string editCDPrompt = 
    "0) Cancel\n"
    "1) Title\n"
    "2) Artist\n"
    "3) Release date\n"
    "4) Genre\n"
    "5) Duration\n"
    "6) Price\n"
    "7) Conservation state\n"
    "8) Disc format\n\n";

    std::string editVinylPrompt = 
    "0) Cancel\n"
    "1) Title\n"
    "2) Artist\n"
    "3) Release date\n"
    "4) Genre\n"
    "5) Duration\n"
    "6) Price\n"
    "7) Conservation state\n"
    "8) RPM\n"
    "8) Diameter\n\n";

    std::string musicGenre = "Rock, Pop, HipHop, RnB, Country, Jazz, Blues, Classical, Metal, Punk, Reggae, Folk, Techno, House, Trance, Dubstep, Latin, Salsa, Samba, Kpop, Jpop, Indie, Alternative, Grunge, Soul, Funk, Gospel, Broadway, Soundtrack, World";

    //based on identifier, return the correct string
    if(menuIdentifier == "intro"){
        return intro;
    }
    else if(menuIdentifier == "main_menu"){
        return mainActionMenu;
    }
    else if(menuIdentifier == "edit_cd"){
        return editCDPrompt;
    }
    else if(menuIdentifier == "edit_vinyl"){
        return editVinylPrompt;
    }
    else if (menuIdentifier == "music_genre"){
        return musicGenre;
    }
    
    return "";
}