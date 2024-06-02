#include <iostream>
#include <fstream>
using namespace std;
class shopping
{
private:
    int pcode;
    float price;
    float discount;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void del();
    void list();
    void receipt();
};
void shopping::menu()
{

m:
    int choice;
    string email;
    string password;
    cout << "\t\t\t\t\t ____________________________________________ \n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|           SUPERMARKET MAIN MENU            |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|____________________________________________|\n";
    cout << "\t\t\t\t\t                                              \n";
    cout << "\t\t\t\t\t|--------------------------------------------|\n";
    cout << "\t\t\t\t\t|          1)Administrator                   |\n";
    cout << "\t\t\t\t\t|--------------------------------------------|\n";
    cout << "\t\t\t\t\t|          2)Buyer                           |\n";
    cout << "\t\t\t\t\t|--------------------------------------------|\n";
    cout << "\t\t\t\t\t|          3)Exit('-')                       |\n";
    cout << "\t\t\t\t\t|--------------------------------------------|\n";
    cout << "\n\t\t\t\t         <<< PLEASE SELECT YOUR CHOICE :)>>>   ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        // Ask the user if he/she is adminstrator for its login credentials
        cout << "\t\t\t\t\t             Please Login  (^-^) \n";
        cout << "\t\t\t\t\t             Enter Email         \n";
        cin >> email;
        cout << "\t\t\t\t\t             Enter Password      \n";
        cin >> password;
        // setting login credentials for admin ,so that only admin can login
        if (email == "teenasajwan09@gmail.com" && password == "teena123")
        {
            cout << "\t\t\t\t\t        Login succesfully !*-*! \n";
            administrator();
        }
        else
        {
            cout << "\t\t\t\t\t !!Login failed,Invalid EMAIL or PASSWORD!!\n";
        }
        break;
    case 2:
    {
        buyer();
    }
    case 3:
    {
        exit(0);
    }
    default:
        cout << "\t\t\t\t\t  Please Enter valid choice !! \n";
          // goto m;
    }
  
}
void shopping::administrator()
{
back:
    int choice;
    cout << "\t\t\t\t\t ____________________________________________ \n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|            ADMINSTRATOR MENU               |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|____________________________________________|\n";
    cout << "\t\t\t\t\t|--------------------------------------------|\n";
    cout << "\t\t\t\t\t|          1)Add Product                     |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|          2)Modify Product                  |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|          3)Delete Product                  |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|          4)Back To Main Menu               |\n";
    cout << "\t\t\t\t\t|--------------------------------------------|\n";
    cout << "\n\t\t\t\t         <<< PLEASE SELECT YOUR CHOICE :)>>>   ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        del();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "\t\t\t\t\t  Please Enter valid choice !! \n";
        
     goto back;
    }
    
}
void shopping::buyer()
{
m:
    int choice;
    cout << "\t\t\t\t\t ____________________________________________ \n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|               BUYER  MENU                  |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|____________________________________________|\n";
    cout << "\t\t\t\t\t|--------------------------------------------|\n";
    cout << "\t\t\t\t\t|          1)Buy Product                     |\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|          2)Go back to Main Menu            |\n";
    cout << "\t\t\t\t\t|--------------------------------------------|\n";
    cout << "\n\t\t\t\t         <<< PLEASE SELECT YOUR CHOICE :)>>>   ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
    default:
        cout << "\t\t\t\t\t  Please Enter valid choice !! \n";
    }
    // 1 goto m;
}
void shopping::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;
    cout << "\t\t\t\t\t|--------------------------------------------|\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|________________Add New Product_____________|\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|--------------------------------------------|\n";
    cout << "\t\t\t\t\t  Enter Product code of the Product :";
    cin >> pcode;
    cout << "\t\t\t\t\t  Enter Name of the Product :";
    cin >> pname;
    cout << "\t\t\t\t\t  Enter Price of the Product :";
    cin >> price;
    cout << "\t\t\t\t\t  Enter Discount on the Product :";
    cin >> discount;
    cout<<endl;
    data.open("database.txt", ios::in); // OPEN FILE CONTAINING LIST OF ITEMS IN READING MODE ONLY
    if (!data)
    { // IF FILE DOESNOT EXIST
        data.open("database.txt", ios::app | ios::out);
        // app STANDS FOR APPEND MODE out STANDS FOR WRITE MODE
        data << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
        data.close();
    }
    else
    {
        // IF THE FILE ALREADY EXIST
        data >> c >> n >> p >> d; // INTIALISING INDEX
        while (!data.eof())       // CHECK EVERY CONTENT OF FILE
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d; // ITERATION
        }
        data.close();

        if (token == 1)
        { // A DUPLICATE PRODUCT HAS BEEN TRIED TO ADD HENCE GO TO
            goto m;
        }
        else
        {
            // NOT A DUPLICATE CODE
            // ADD THE DATA
            data.open("database.txt", ios::app | ios::out);
            // app STANDS FOR APPEND MODE out STANDS FOR WRITE MODE
            data << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
            data.close();
        }
    }
    cout << "\t\t\t\t\t    Product added Successfully !!\n";
    administrator();
}
void shopping::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;
    cout << "\t\t\t\t\t|--------------------------------------------|\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|________________Modify theProduct___________|\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|--------------------------------------------|\n";
    cout << "\t\t\t\t\t   Enter the Product code";
    cin >> pkey; // ENTERING PRODUCT CODE TO CHECK IN FILE
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\t\t\t\t\t   FILE DOESNOT EXIST!!";
    }
    else
    {
        // SAVING THE EDITED DATA IN THE DATABASE1 FILE
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> discount;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t    Product new code:";
                cin >> c;
                cout << "\n\t\t    Product Name:";
                cin >> n;
                cout << "\n\t\t    Product Price:";
                cin >> p;
                cout << "\n\t\t    Product Discoun:";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\t\t\t\t\t    Product Edited Successfully !!\n";
                token++;
                administrator();
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
            }
            data >> pcode >> pname >> price >> discount;
        }
        data.close();
        data1.close();
        remove("database.txt");                  // DELETE FILE
        rename("database1.txt", "database.txt"); // RENAME TO ORIGINAL FILE
        if (token == 0)
        {
            cout << "\t\t\t\t\t  oops!! Record not found !!";
        }
    }
}
void shopping::del()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\t\t\t\t\t|--------------------------------------------|\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|______________Delete the Product____________|\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|--------------------------------------------|\n";
    cout << "\t\t\t\t\t   Enter the Product code";
    cin >> pkey;
    data.open("database.txt", ios::in); // OPENING THE FILE
    // cHECKS FILE EXIST OR NOT
    if (!data)
    {
        cout << "FILE  NOT EXIST OR DATA ITEM  \n";
    }
    else
    {

        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> discount; // READING DATA FROM THE FILE
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << " Product deleted succesfully ! \n";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
            }
            data >> pcode >> pname >> price >> discount;
        }
        data.close();
        data1.close();
        remove("database.txt");                  // DELETE FILE
        rename("database1.txt", "database.txt"); // RENAME TO ORIGINAL FILE
        if (token == 0)
        {
            cout << "\t\t\t\t\t  oops!! Record not found !!";
        }
    }
    administrator();
}
void shopping::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\t\t\t\t\t|--------------------------------------------|\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|_____________List of Products_______________|\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|--------------------------------------------|\n";
    cout<<"\n";
    cout << "\t\t\t\t\tProductNo\tName\t\tPrice\tDiscount\n";
    data >> pcode >> pname >> price >> discount; // READING DATA
    while (!data.eof())
    {
        cout << "\t\t\t\t\t" << pcode << "\t\t" << pname << "\t\t" << price << "\t\t" << discount << "\n";
        data >> pcode >> pname >> price >> discount;
    }
    data.close();
}
void shopping::receipt()
{

    // THIS MODULE WILL PERFORM ALL THE BUYER FUNCTION
    fstream data;
    int arrCode[100];
    int arrQunt[100];
    char choice;
    float totalQuantity = 0;
    float total = 0;
    int counter = 0;
    float amount = 0;
    float disc = 0;
    cout << "\t\t\t\t\t|--------------------------------------------|\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|_________________Menu Items_________________|\n";
    cout << "\t\t\t\t\t|                                            |\n";
    cout << "\t\t\t\t\t|--------------------------------------------|\n";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "Empty database !!!" << endl;
    }
    else
    {
        data.close();
        list();
        
        cout<<"\n";
        cout << "\t\t\t\t\t|==============================================|\n";
        cout << "\t\t\t\t\t|             hurry!!! Place Order             |\n";
        cout << "\t\t\t\t\t|==============================================|_\n";
         cout<<"\n";
        do
        {
        m:
            cout << "\t\t\t\t\t Enter product code :";
            cin >> arrCode[counter];
            cout << "\t\t\t\t\t Enter product quantity :";
            cin >> arrQunt[counter];
            for (int i = 0; i < counter; i++)
            {
                if (arrCode[counter] == arrCode[i])
                {
                    cout << "\t\t\t\t\tduplicate product code";
                    goto m;
                }
            }
            counter++;
            cout << "\t\t\t Do you want to buy another product! if yes then press y else n for no: ";
            cin >> choice;
        } while ((choice == 'y'));

        cout << "\t\t\t\t\t|==============================================|\n";
        cout << "\t\t\t\t\t|                    RECEIPT                   |\n";
        cout << "\t\t\t\t\t|==============================================|\n";
        cout << "ProductNo\t\tName\t\tProduct Quantity\t\tPrice\t\tAmount\t\tAmount with discount\n";
        for (int i = 0; i < counter; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> discount;
            while (!data.eof())
            {
                // if MATCHES WITH PRODUCT CODE THE WE WILL CALCULATE THE AMOUNT
                if (pcode == arrCode[i])
                {
                    amount = price * arrQunt[i];
                    disc = (amount) - (amount * discount / 100);
                    totalQuantity += arrQunt[i];
                    total += disc;

                    cout << "\n"
                         << pcode << "\t\t\t" << pname << "\t\t\t" << totalQuantity << "\t\t\t" << price << "\t\t\t" << amount << "\t\t\t" << disc << "\n";
                }
                data >> pcode >> pname >> price >> discount;
            }
            data.close();
        }
    }
    cout << "\t\t\t\t\t|===================================================|\n";
    cout << "\t\t\t\t\t|________________TOTAL AMOUNT :" << total << "________________|\n";
    cout << "\t\t\t\t\t|===================================================|\n";
}
int main()
{
    shopping s;
    s.menu();
    return 0;
}