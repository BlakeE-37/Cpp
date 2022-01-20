#include <iostream>
#include <fstream>
using namespace std;

void check_user(){

} 

void add_user(string user, string pass){

//uses fstream- calls the built in classes 'open' (available for writing) and 'close'
//writes the username to the text file
    fstream user_txt;
    user_txt.open("username.txt", fstream::out | fstream::app);

    user_txt << user << "\n";

    user_txt.close();
    cout << "Your account has been created";
}

void has_account(){
    string user;
    string pass;
    cout << "EXISTING USER\n";
    cout << "Username: \n";
    cin >> user;
    cout << "Password: \n";
    cin >> pass;
}

void make_account(){
    string user;
    string pass;
    string confirm_pass;
//Username
    cout << "NEW USER\n";
    cout << "Username: ";
    cin >> user;

//Password
    cout << "Password: ";
    cin >> pass;
    cout << "Confirm Passweord: ";
    cin >> confirm_pass;

//Check if passwords match
    if (pass == confirm_pass){

    } else if (pass != confirm_pass){
        cout << "Passwords do not match";
        make_account();
    }

//Add user to the user file
    add_user(user, pass);
}

int main(){

// Check if they have an existing username and password
    char account_yn;
    cout << "Do you have an account yet? [y/n]: ";
    cin >> account_yn;

//if they have a username and password send them to type it
//if they do not have a username and password send them to add it
    if (account_yn == 'y') {
        has_account();
    } else if (account_yn == 'n'){
        make_account();
    } else {
        cout << "Please enter \"y\" or \"n\" only";
        main();
    } 

return 0;
}