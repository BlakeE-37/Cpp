#include <iostream>
#include <fstream>
using namespace std;
void has_account();
void make_account();

//once they type the username and password, run through the username file 
//to find the matching credentials
//if no credentials match then have them retype there username and password
void check_user(string user, string pass){
    fstream user_txt;
    user_txt.open("username.txt", fstream::in);

//compares username and password to file
    string line, concat;
    string insertion(1, ':');
    concat = user + insertion + pass;
    while(getline(user_txt, line)) {
        if (line == concat){
            cout << "\nYou are logged in.\n\n";
            user_txt.close();
            terminate();
        }
    }
//If none of the lines in the file match rerun the file
    char confirm;
    cout << "\nUsername or Password is incorrect\n\n";
    cout << "Are you sure you have an account? [y/n]: ";
    cin >> confirm;
    user_txt.close();

    if (confirm == 'y'){
        has_account();
    } else if (confirm == 'n'){
        char create;
        cout << "Would you like to create an account? [y/n]: ";
        cin >> create;

        if (create == 'y'){
            make_account();
        } else {
            terminate();        }
    }
        
        
}

void add_user(string user, string pass){

//uses fstream- calls the built in classes 'open' (available for writing) and 'close'
//writes the username to the text file
    fstream user_txt;
    user_txt.open("username.txt", fstream::out | fstream::app);

//adds the useranme and password to the username file
    string user_pass;
    user_pass = user + ':' + pass;
    user_txt << user_pass << "\n";

    user_txt.close();
    cout << "Your account has been created";
}
//if the user says they have an account, have them type it 
//and send the username and password to the check function
void has_account(){
    string user;
    string pass;
    cout << "EXISTING USER\n";
    cout << "Username: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;

    check_user(user, pass);
}
//if the user does not have an account, have them create one 
//by typing a username and password and sending it to the add user function
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
    cout << "Confirm Password: ";
    cin >> confirm_pass;

//Check if passwords match
    if (pass == confirm_pass){

    } else if (pass != confirm_pass){
        cout << "Passwords do not match";
        make_account();
    }

//Add user to the username file
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