#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;
int condition = 0;
long id_number_globel;
void manyTimePrintRecord(string, string, string, string, string, int, int);
void currentAndSavingOption(string);
void allFunctionHading(string);
void accountCreater(char);
void allFunctionCalled(char, string);
void displayAllData(char);
void checkRecord(char);
void depositAndWithdrawAmount(char, string);
void widhdraAndDeposit(char, long, string);
void deleteAllData(char);
void updateRecord(char);
int function_checking(string, string);
void about();

void realUpdate(char, string, string, long);
int recordSearch(char option, long account);

ofstream put_data, put_temp_data;
ifstream fetch_data, fetch_temp_data;

int main()
{
    while (true)

    {
        system("cls");
        system("color 3f");
        allFunctionHading("WELCOME TO ZATA BANK");
        cout << "\n\t1 ..>     ABOUT BANK \n";
        cout << "\n\t2 ..>     OPEN NEW ACCOUNT \n";
        cout << "\n\t3 ..>     CHECK RECORD \n";
        cout << "\n\t4 ..>     DEPOSIT AMMOUNT  \n";
        cout << "\n\t5 ..>     WITHDRAW AMOUNT\n";
        cout << "\n\t6 ..>     SHOW ALL RECORD \n";
        cout << "\n\t7 ..>     UPDATE RECORD\n";
        cout << "\n\t8 ..>     DELETE RECORD \n";
        cout << "\n\t9 ..>     EXIT PROGRAM \n";
        cout << "\n\tSELECT OPTION .. ";
        char option = getch();
        if (option == '1')
        {
            about();
        }
        else if (option == '2')
        {
            currentAndSavingOption("CREATE RECORD");
        }
        else if (option == '3')
        {
            currentAndSavingOption("CHECK RECORD");
        }
        else if (option == '4')
        {
            currentAndSavingOption("DEPOSIT AMOUNT");
        }
        else if (option == '5')
        {
            currentAndSavingOption("WITHDRAW AMOUNT");
        }
        else if (option == '6')
        {
            currentAndSavingOption("SHOW ALL RECORD");
        }
        else if (option == '7')
        {
            currentAndSavingOption("UPDATE RECORD");
        }
        else if (option == '8')
        {
            currentAndSavingOption("DELETE RECORD");
        }
        else if (option == '9')
        {
            system("cls");
            cout << "\n\n\n\n\n\n\t\tTHANKS FOR USING\n\n\n\n\n\n\n\n\n\n\n";
            break;
        }
        else
        {
            system("cls");
            cout << "\n\n\n\n\n\n\n\n\n\n\t\tYOU ENTER INVALID OPTION PLEASE TRY AGAIN PRESS ANY KEY..";
            getch();
        }
    }
}

void allFunctionCalled(char option, string optionChoise)
{ // this function take the name of function and also take the option mean current account and saving account //
    if (optionChoise == "CREATE RECORD")
    {
        accountCreater(option);
        getch();
    }
    else if (optionChoise == "CHECK RECORD")
    {
        checkRecord(option);
    }

    else if (optionChoise == "DEPOSIT AMOUNT")
    {
        depositAndWithdrawAmount(option, "add");
    }
    else if (optionChoise == "WITHDRAW AMOUNT")
    {
        depositAndWithdrawAmount(option, "sub");
    }
    else if (optionChoise == "SHOW ALL RECORD")
    {
        displayAllData(option);
        cout << "\n\tPRESS ANY KEY FOR BACK MENU ";
        getch();
    }
    else if (optionChoise == "DELETE RECORD")
    {
        deleteAllData(option);
        getch();
    }
    else if (optionChoise == "UPDATE RECORD")
    {
        updateRecord(option);
    }

} //// this function take the name of function and also take the option mean current account and saving account //
int recordSearch(char option, long account, int intry)
{
    int found = 0;
    string name[5];
    long account_number, paiment;
    if (option == '1')
    {
        fetch_data.open("current.txt", ios::in);
    }
    else
    {
        fetch_data.open("saving.txt", ios::in);
    }
    while (!fetch_data.eof())
    { //                  name     fname    birth     address     cnic   account-number    paiment
        fetch_data >> name[0] >> name[1] >> name[2] >> name[3] >> name[4] >> account_number >> paiment;
        if (account == account_number)
        {
            if (intry != 4)
            {
                account_number = account;
                manyTimePrintRecord(name[0], name[1], name[2], name[3], name[4], account_number, paiment);
            }
            found = 1;
            break;
        }
    }
    fetch_data.close();
    return found;
}

void updateRecord(char option)
{
    int i = 0;
    char change;
    string heading, nameOption, newname;
    system("cls");
    if (option == '1')
    {
        heading = "CURRENT ACCOUNT";
    }
    else
    {
        heading = "SAVING ACCOUNT";
    }
    allFunctionHading(heading);
    if (condition == 0)
    {

        cout << "\n\tENTER ID NUMBER ";
        cin >> id_number_globel;
        condition = 1;
    }
    if (1 == recordSearch(option, id_number_globel, 1))
    {
        cout << "\n\n\tENTER OPTION NAME ";
        cin >> nameOption;

        if (5 == function_checking(nameOption, "name"))
        {
            cout << "\n\tENTER NEW NAME ";
            cin >> newname;
        }
        else if (5 == function_checking(nameOption, "father_name"))
        {
            cout << "\n\tENTER NEW FATHER NAME ";
            cin >> newname;
        }
        else if (5 == function_checking(nameOption, "birth"))
        {
            cout << "\n\tENTER NEW DATE OF BIRTH ";
            cin >> newname;
        }
        else if (5 == function_checking(nameOption, "address"))
        {

            cout << "\n\tENTER NEW ADDRESS ";
            cin >> newname;
        }
        else if (5 == function_checking(nameOption, "cnic"))
        {

            cout << "\n\tENTER NEW CNIC NO ";
            cin >> newname;
        }
        else
        {

            system("cls");
            cout << "\n\n\n\n\n\n\n\n\t\tCHECK THE SPELLING AND ENETR CORRECT OPTION PRES ANY KEY. ";
            getch();
        }
        realUpdate(option, newname, nameOption, id_number_globel);
    tryoption:
        cout << "\n\tPRESS 1 BACK MENU PRESS 2 UPDATE  ";
        change = getch();
        if (change == '1')
        {
            condition = 0;
        }
        else if (change == '2')
        {
            updateRecord(option);
        }
        else
        {
            cout << "\n\tYOU ENETRED INVALID OPTION TRY AGAIN ";
            goto tryoption;
        }
    }
    else
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\tNUMBER NOT FOUND PLEASE TRY AGAIN ";
        condition = 0;
        getch();
    }
}

void realUpdate(char option, string update, string nameOption, long id_number)
{
    string name[5], heding;
    long account_number;
    long long paiment;
    put_temp_data.open("temp.txt", ios::app);
    if (option == '1')
    {
        fetch_data.open("current.txt", ios::in);
        heding = "CURRENT ACCOUNT";
    }
    else
    {
        fetch_data.open("saving.txt", ios::in);
        heding = "SAVING ACCOUNT";
    }

    while (!fetch_data.eof())
    {
        fetch_data >> name[0] >> name[1] >> name[2] >> name[3] >> name[4] >> account_number >> paiment;
        if (id_number == account_number)
        {
            if (nameOption == "name")
            {
                name[0] = update;
            }
            else if (nameOption == "father_name")
            {
                name[1] = update;
            }
            else if (nameOption == "birth")
            {
                name[2] = update;
            }
            else if (nameOption == "address")
            {
                name[3] = update;
            }
            else if (nameOption == "cnic")
            {
                name[4] = update;
            }
            system("cls");
            allFunctionHading(heding);
            manyTimePrintRecord(name[0], name[1], name[2], name[3], name[4], account_number, paiment);
        }
        put_temp_data << "\n"
                      << name[0] << " " << name[1] << " " << name[2] << " " << name[3];
        put_temp_data << " " << name[4] << " " << account_number << " " << paiment;
    } // while loop

    put_temp_data.close();
    fetch_data.close();

    fetch_temp_data.open("temp.txt", ios::in);
    if (option == '1')
    {
        put_data.open("current.txt", ios::out);
        put_data << "";
        put_data.close();
        put_data.open("current.txt", ios::app);
        heding = "CURRENT ACCOUNT";
    }
    else
    {
        put_data.open("saving.txt", ios::out);
        put_data << "";
        put_data.close();
        put_data.open("saving.txt", ios::app);
        heding = "SAVING ACCOUNT";
    }

    while (!fetch_temp_data.eof())
    {
        fetch_temp_data >> name[0] >> name[1] >> name[2] >> name[3] >> name[4] >> account_number >> paiment;
        put_data << "\n"
                 << name[0] << " " << name[1] << " " << name[2] << " " << name[3];
        put_data << " " << name[4] << " " << account_number << " " << paiment;
    } // while loop

    fetch_temp_data.close();
    put_data.close();
    put_temp_data.open("temp.txt", ios::out);
    put_temp_data << "";
    put_temp_data.close();
}
void deleteAllData(char option)
{
    string name[4], heading;
    long long account_number, paiment, id;
    int check = 0;

    system("cls");
    put_temp_data.open("temp.txt", ios::out);
    if (option == '1')
    {
        heading = "CURRENT ACCOUNT";
        fetch_data.open("current.txt", ios::in);
    }
    else
    {
        heading = "SAVING ACCOUNT";

        fetch_data.open("saving.txt", ios::in);
    }
    allFunctionHading(heading);
    cout << "\n\tENTER ID NUMBER ";
    cin >> id;

    while (!fetch_data.eof())
    {
        fetch_data >> name[0] >> name[1] >> name[2] >> name[3] >> name[4] >> account_number >> paiment;
        if (id == account_number)
        {
            manyTimePrintRecord(name[0], name[1], name[2], name[3], name[4], account_number, paiment);

            check = 4;
        }
        else
        {
            put_temp_data << "\n"
                          << name[0] << " " << name[1] << " " << name[2] << " " << name[3];
            put_temp_data << " " << name[4] << " " << account_number << " " << paiment;
        }
    } // while loop
    fetch_data.close();
    put_temp_data.close();
    if (check == 4)
    {

        if (option == '1')
        {
            put_data.open("current.txt", ios::out);
            put_data << "";
            put_data.close();
            put_data.open("current.txt", ios::app);
        }
        else
        {
            put_data.open("saving.txt", ios::out);
            put_data << "";
            put_data.close();
            put_data.open("saving.txt", ios::app);
        }
        fetch_temp_data.open("temp.txt", ios::app);

        while (!fetch_temp_data.eof())
        {
            fetch_temp_data >> name[0] >> name[1] >> name[2] >> name[3] >> name[4] >> account_number >> paiment;
            if (id == account_number)
            {
            }
            else
            {
                put_data << "\n"
                         << name[0] << " " << name[1] << " " << name[2] << " " << name[3];
                put_data << " " << name[4] << " " << account_number << " " << paiment;
            }
        } // while loop
        cout << "\n\tRECORD DELETE SUCCESSFULLY PRESS ANY KEY";
    }
    else
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\t\tID NUMBER NOT MATCHING PRESS ANY KEY ";
    }
    fetch_temp_data.close();
    put_temp_data.open("temp.txt", ios::out);
    put_temp_data << "";
    put_temp_data.close();
    put_data.close();
}

void currentAndSavingOption(string heading)
{ // this function take heading from main function
createFunction:
    system("cls");
    allFunctionHading(heading);
    cout << "\n\t1 ..>     CURRENT ACCOUNT \n";
    cout << "\n\t2 ..>     SAVING  ACCOUNT \n";
    cout << "\n\t3 ..>     BACK MAIN MENU \n";
    cout << "\n\tSELECT OPTION .. ";
    char option = getch();
    if (option == '1')
    {
        allFunctionCalled(option, heading);
        goto createFunction;
    }
    else if (option == '2')
    {
        allFunctionCalled(option, heading);
        goto createFunction;
    }
    else if (option == '3')
    {
    } //empty because back going from this function
    else
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\t\tYOU ENTER INVALID OPTION PLEASE TRY AGAIN PRESS ANY KEY..";
        getch();
        goto createFunction;
    }
} // this function take heading from main function
void widhdraAndDeposit(char option, long check_account, string check)
{
    string name, fname, birth, cnic, address;
    string fetch_value;
    long account_number;
    long long paiment, newPement;
    if (option == '1')
    {
        fetch_data.open("current.txt", ios::in);
    }
    else
    {
        fetch_data.open("saving.txt", ios::in);
    }
    put_temp_data.open("temp.txt", ios::app);

    while (!fetch_data.eof())
    {
        fetch_data >> name >> fname >> birth >> address >> cnic >> account_number >> paiment;
        if (account_number == check_account)
        {
            if (check == "sub")
            {
            recharge:
                cout << "\n\tENETR AMOUNT TO BE WITHDRAW  OR ( 0 ) FOR BACK ";
                cin >> newPement;
                if (newPement == 0)
                {
                }
                else if (newPement >= 0 && newPement <= paiment)
                {
                    paiment -= newPement;
                    cout << "\n\n\tAMOUNT WITHDRAW SUCCESSFULLY PRESS ANY KEY FOR BACK ";
                    getch();
                }
                else if (newPement < 0)
                {
                    cout << "\n\tENVALID ENTRY TRY AGAIN .. ";
                    goto recharge;
                }
                else
                {
                    cout << "\n\tPLEASE RECHARGE YOUR ACCOUNT ";
                    goto recharge;
                }

            } // withdraw amount
            else
            {
                cout << "\n\tENETR AMOUNT TO BE DEPOSIT  OR ( 0 ) FOR BACK ";
                cin >> newPement;
                paiment += newPement;
                cout << "\n\n\tAMOUNT DEPOSET SUCCESSFULLY PRESS ANY KEY FOR BACK ";
                getch();

            } // deposit amount

        } // if acount equal //

        put_temp_data << "\n"
                      << name << " " << fname << " " << birth << " " << address << " " << cnic << " " << account_number << " " << paiment;
    }
    put_temp_data.close();
    fetch_data.close();

    if (option == '1')
    {
        put_data.open("current.txt", ios::out);
        put_data << "";
        put_data.close();
        put_data.open("current.txt", ios::app);
    }
    else
    {
        put_data.open("saving.txt", ios::out);
        put_data << "";
        put_data.close();
        put_data.open("saving.txt", ios::app);
    }

    fetch_temp_data.open("temp.txt", ios::in);
    while (!fetch_temp_data.eof())
    {
        fetch_temp_data >> name >> fname >> birth >> address >> cnic >> account_number >> paiment;
        put_data << "\n"
                 << name << " " << fname << " " << birth << " " << address << " " << cnic << " " << account_number << " " << paiment;
    }
    fetch_temp_data.close();
    put_temp_data.open("temp.txt", ios::out);
    put_temp_data << "";
    put_temp_data.close();
    put_data.close();

} // deposit and withdra ammount //

void depositAndWithdrawAmount(char option, string check)
{
    long account_number;
topMenu:
    system("cls");
    if (check == "sub")
    {
        string heading = "WITHDRAW AMOUNT";
        allFunctionHading(heading);
    }
    else
    {
        string heading = "DEPOSIT AMOUNT";
        allFunctionHading(heading);
    }
    cout << "\n\tENTER ACCOUNT NUMBER..";
    cin >> account_number;
    if (1 == recordSearch(option, account_number, 1))
    {
        widhdraAndDeposit(option, account_number, check);
    }
    else
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\t\tID NUMBER NOT FOUND PLEASE TRY AGAIN PRESS ANY ";
        getch();
    }
}

void checkRecord(char option)
{ // search data through this function
    long account_number;
topMenu:
    system("cls");
    string heading = "CHECK RECORD";
    allFunctionHading(heading);
    cout << "\n\tENTER ACCOUNT NUMBER..";
    cin >> account_number;
    if (1 == recordSearch(option, account_number, 1))
    {
        cout << "\n\n\tPRESS ANY KEY FOR BACK MENU ";
    }
    else
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\n\n\t\tID NUMBER NOT FOUND PLEASE TRY AGAIN PRESS ANY ";
    }
    getch();
} // search data from this function //

void displayAllData(char option)
{ // all record show through this function
    long account_number;
    short extra;
    long long paiment;
    system("cls");
    allFunctionHading("ALL RECORD");
    string name, fname, birth, cnic, address;
    string fetch_value;
    if (option == '1')
    {
        fetch_data.open("current.txt", ios::in);
        fetch_data >> fetch_value;
        fetch_data.close();
        fetch_data.open("current.txt", ios::in);
    }
    else
    {
        fetch_data.open("saving.txt", ios::in);
        fetch_data >> fetch_value;
        fetch_data.close();
        fetch_data.open("saving.txt", ios::in);
    }
    if (fetch_value != "")
    {
        while (!fetch_data.eof())
        {
            fetch_data >> name >> fname >> birth >> address >> cnic >> account_number >> paiment;
            manyTimePrintRecord(name, fname, birth, address, cnic, account_number, paiment);
        }
        fetch_data.close();
    }
    else
    {
        cout << "\n\t(___RECORD NOT AVAIBLE ___)\n\n";
        fetch_data.close();
    }
} // all record show through this function

void accountCreater(char option)
{ // in this function user enter data mean account creating
    long account_number, check_account;
    string name, fname, birth, cnic, address, name12[0];
    system("cls");

    allFunctionHading("ACCOUNT CREATING");
account:
    srand(time(NULL));
    while (true)
    {
        account_number = rand() % 500;
        account_number += 100000;
        if (account_number >= 100000)
        {
            break;
        }
    } // check acounter number that must be 6 digit

    if (1 == recordSearch(option, account_number, 4))
    {
        goto account;
    }
    else
    {
        if (option == '1')
        {
            put_data.open("current.txt", ios::app);
        }
        else
        {
            put_data.open("saving.txt", ios::app);
        }

        cout << "\n\tENTER CUSTOMER NAME ";
        cin >> name;
        cout << "\n\tENTER CUSTOMER FATHER NAME ";
        cin >> fname;
        cout << "\n\tENTER CUSTOMER BIRTH ";
        cin >> birth;
        cout << "\n\tENTER CUSTOMER ADDRESS ";
        cin >> address;
        cout << "\n\tENTER CUSTOMER CNIC ";
        cin >> cnic;
        put_data << "\n"
                 << name << " " << fname << " " << birth << " " << address << " " << cnic << " " << account_number << " " << 0;
        put_data.close();
        cout << "\n\tACCOUNT NUMBER IS " << account_number;
        cout << "\n\trecord added success full press any key ";
    } // if statment brecket if account number not matching //
} // in this function user enter data into file
void manyTimePrintRecord(string name, string fname, string birth, string address, string cnic, int acc, int pai)
{
    cout << "\n\tNAME IS        " << name;
    cout << "\n\tFATHER NAME    " << fname;
    cout << "\n\tBIRTH IS       " << birth;
    cout << "\n\tACCOUNT NO     " << acc;
    cout << "\n\tCNIC NUMBER    " << cnic;
    cout << "\n\tADDRESS IS     " << address;
    cout << "\n\tBALENCE IS     " << pai << " RS";
    cout << "\n\n\t*********************************\n";
}
void allFunctionHading(string heading)
{ // this function is only for heading this is also used by many function and many time
    printf("\t\t");
    for (int i = 0; heading[i] != '\0'; i++)
    {
        printf("*");
    }
    cout << "\n\t\t" << heading << "\n\t\t";
    for (int i = 0; heading[i] != '\0'; i++)
    {
        printf("*");
    }
    printf("\n\n");
} // this function is only for heading this is also used by many function and many time  (closed function)

int function_checking(string fetch, string orignal)
{ // this function is used to check the id number of all student if match that return 5 and not match that return 2
    int x = 0;
    for (int i = 0; fetch[i] != '\0' || orignal[i] != '\0'; i++)
    {
        if (fetch[i] == orignal[i])
        {
            x = 5;
        }
        else
        {
            x = 2;
        }
    }
    return x;
} // this function is used to check the id number of all student if match that return 5 and not match that return 2  (closed function)
void about()
{
about:
    system("cls");
    allFunctionHading("ABOUT ZATA");

    cout << "\n\n\t1 . BRANCHES ZATA ";
    cout << "\n\n\t2 . CONTACT ZATA ";
    cout << "\n\n\t3 . BACK MAIN MENU ";

    char option;
    option = getch();
    if (option == '1')
    {
        system("cls");
        allFunctionHading("BRANCHES ZATA");
        cout << "\n\n\tKARACHI ZATA BRANCH";
        cout << "\n\n\tISLAMABAD ZATA BRANCH";
        cout << "\n\n\tLAHORE ZATA BRANCH";
        cout << "\n\n\tQUATTA ZATA BRANCH";
        cout << "\n\n\tPESHAWER ZATA BRANCH";
        cout << "\n\n\tPRESS ANY KEY FOR BACK MENU ";
        getch();
        goto about;
    }
    else if (option == '2')
    {
        system("cls");
        allFunctionHading("CONTACT ZATA");
        cout << "\n\n\t03178264008";
        cout << "\n\n\t03555606631";
        cout << "\n\n\tALIZATA23@GMAIL.COM";
        cout <<"\n\n\tAMIRKADOO@GMAIL.COM";
        cout << "\n\n\tPRESS ANY KEY FOR BACK MENU ";
        getch();
        goto about;
    }
    else if (option == '3')
    {
    }
    else
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n\n\t\t INVALID OPTION PLEASE TRY AGAIN PRESS ANY KEY ";
        getch();
        goto about;
    }
}