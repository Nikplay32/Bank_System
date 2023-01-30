#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <iomanip>
using namespace std;


class Bank
{
private:
    string name,last,word;
    int acno, age, account_number, number, deposit_amount, safety_number, safe, account, value_amount, withdraw_amount, limit, value2, value, value3;
    ofstream myfile;

public:
    void newAccount();
    void closeAccount();
    void show();
    void withdraw();
    void deposit();
    void getbalance();
    void limit_change();
    void requestDelete();
    void quit();
};

void Bank::newAccount(){

  safe = 9991;
  srand(time(0));
  for(int i = 0 ; i < 10000 ; i++ ){ 
      account_number = rand() % 10000;
  }
  
  cout << "Enter your Age: ";
  cin >> age;
  if (age >= 18){
    cout << "Enter your Name: ";
    cin >> name;
    cout << "Enter your Last Name: ";
    cin >> last;
    cout << "Account Opened Successfully!" << endl;
    cout << "Your account number is: " << account_number << endl;
    cout << "Your safe code is: " << safe << "." << endl;
    myfile.open ("data.txt");
    myfile << "Person Age: " << age << endl << "Person Name: " << name << endl << "Person Last Name: " << last << endl;
    myfile << "Account number: " << account_number << endl << "Safety PIN: " << safe << endl;
    }else{
      cout << "You cant open account, you need to be at least 18 years old" << endl;
    }
}

void Bank::closeAccount(){
   safe = 9991;
   cout << "Enter Account Number(You can check it in the file): ";
   cin >> account_number;
   cout << "Enter Your Safety Number: ";
   cin >> safety_number;
   if (safety_number == safe){
      cout << "Account Closed Successfully!" << endl;
      remove("data.txt");
      remove("balance.txt"); 
   }else{
    cout << "You entered incorrect safety PIN!" << endl;
  }
}

void Bank::show(){   
  cout << "Enter Account Number(You can check it in the file): "; 
  cin >> number;
  ifstream MyFile("data.txt");
  while (getline (MyFile, name)){
        cout << name << endl;
  }
 
}

void Bank::deposit(){
  ofstream myfile;
  safe = 9991;
  safety_number = safe; 
  cout << "Enter Account Number(You can check it in the file): "; 
  cin >> account_number;
  cout << "Enter Safety PIN: " ;
  cin >> safe;
  if (safety_number == safe){
    cout << "Enter Deposit Amount: "; 
    cin >> deposit_amount;
    value = value + deposit_amount;
    value2 = value;
    myfile.open ("balance.txt");
    myfile << value << endl;
    cout << "Your balance has been sucessfully updated!" << endl;
  }else{
      cout << "You entered incorrect safety PIN. Try Again!" << endl;
  } 
  
}

void Bank::withdraw(){
   ofstream myfile;
   safe = 9991;
   safety_number = safe;
   cout << "Enter Account Number(You can check it in the file): "; 
   cin >> account_number;
   cout << "Enter Withdraw Amount: "; 
   cin >> withdraw_amount;
   value3 = value2 - withdraw_amount;
   myfile.open ("balance.txt");
   myfile << "Account balance: " << value3 << endl;
   cout << "Operation has been finished" << endl;
}


void Bank::getbalance(){
  cout << "Enter Account Number: "; 
  cin >> number;
  ifstream MyFile("balance.txt");
  cout << "Your balance is: " << endl; 
  while (getline (MyFile, last)){
    cout << last << endl;
  }
}

void Bank::limit_change(){
  ofstream myfile;
  cout << "You want to change limits?" << endl;
  cout << "Please give us your limit value" << endl;
  cin >> limit;
  myfile.open("limit.txt");
  cout << "Thank you for your request, you will receive answer soon, within 24 hours" << endl;
  myfile << "Client Request for money limits: " << limit << endl;
  
}

void Bank::requestDelete(){
  ofstream myfile;
  cout << "You want to delete your request?" << endl;
  cout << "Please write YES if you really want to do it" << endl;
  cin >> word;
  if (word == "YES" || word == "Yes" || word == "yes"){
  remove("limit.txt");
  cout << "Your request to our client office has been deleted!" << endl;
  }else{
    cout << "Okay, you rejected delete function. Have a good day!" << endl;
  }
}

void Bank::quit(){
  cout << "Good Bye! Have a nice day!" << endl;
}


int main(void){
Bank obj;
  int option;
  string answer;
      cout << "|=============================|" << endl;
      cout << "|          WELCOME TO         |" << endl;
      cout << "|           THE BANK!         |" << endl;
      cout << "|=============================|" << endl;
      cout << "|=============================|" << endl;
      cout << "|          PIKC RVT           |" << endl;
      cout << "|       VALSTS Tehnikums      |" << endl;
      cout << "|=============================|" << endl;

      cout << endl;

      cout << "What Would You Like To Do?:" << endl;
      cout << "   1. Open Account" << endl;
      cout << "   2. Close Account" << endl;
      cout << "   3. Show Account Data" << endl;
      cout << "   4. Deposit in Account" << endl;
      cout << "   5. Withdraw in Account" << endl;
      cout << "   6. Show Balance" << endl;
      cout << "   7. Provide limit request" << endl;
      cout << "   8. Delete request" << endl;
      cout << "   9. Quit" << endl;
      cout << endl;
      cout << "Please Enter Your Option: ";

while(option != 9){
cin>>option;
  switch(option){
      case 1 :obj.newAccount();
          cout << "Anything else?" << endl;
          cout << "Please Enter Your Option: " << endl;
          cin >> option;
          if(option == 1){
            obj.closeAccount();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          if(option == 2){
            obj.closeAccount();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 3){
            obj.show();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 4){
            obj.deposit();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 5){
            obj.withdraw();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 6){
            obj.getbalance();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 7){
            obj.limit_change();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 8){
            obj.requestDelete();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 9){
            obj.quit();
          }
          break;
      case 2 :obj.closeAccount();
          cout << "Anything else?" << endl;
          cout << "Please Enter Your Option: " << endl;
          cin >> option;
          if (option == 3){
            obj.show();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 4){
            obj.deposit();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 5){
            obj.withdraw();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 6){
            obj.getbalance();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 7){
            obj.limit_change();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 8){
            obj.requestDelete();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 9){
            obj.quit();
          }
          break;
      case 3 :obj.show();
          cout << "Anything else?" << endl;
          cout << "Please Enter Your Option: " << endl;
          cin >> option;
          if(option == 2){
            obj.closeAccount();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 3){
            obj.show();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 4){
            obj.deposit();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 5){
            obj.withdraw();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 6){
            obj.getbalance();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 7){
            obj.limit_change();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 8){
            obj.requestDelete();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 9){
            obj.quit();
          }
          break;
      case 4 :obj.deposit();
          cout << "Anything else?" << endl;
          cout << "Please Enter Your Option: " << endl;
          cin >> option;
          if(option == 2){
            obj.closeAccount();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 3){
            obj.show();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }

          else if (option == 5){
            obj.withdraw();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 6){
            obj.getbalance();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 7){
            obj.limit_change();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 8){
            obj.requestDelete();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 9){
            obj.quit();
          }
          break;
      case 5: obj.withdraw();
          cout << "Anything else?" << endl;
          cout << "Please Enter Your Option: " << endl;
          cin >> option;
          if(option == 2){
            obj.closeAccount();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 3){
            obj.show();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 4){
            obj.deposit();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 6){
            obj.getbalance();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 7){
            obj.limit_change();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 8){
            obj.requestDelete();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 9){
            obj.quit();
          }
          break;
      case 6: obj.getbalance();
          cout << "Anything else?" << endl;
          cout << "Please Enter Your Option: " << endl;
          cin >> option;
          if(option == 2){
            obj.closeAccount();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 3){
            obj.show();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 4){
            obj.deposit();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 5){
            obj.withdraw();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 7){
            obj.limit_change();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 8){
            obj.requestDelete();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 9){
            obj.quit();
          }
          break;
      case 7: obj.limit_change();
          cout << "Anything else?" << endl;
          cout << "Please Enter Your Option: " << endl;
          cin >> option;
          if(option == 2){
            obj.closeAccount();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 3){
            obj.show();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 4){
            obj.deposit();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 5){
            obj.withdraw();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 6){
            obj.getbalance();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 8){
            obj.requestDelete();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 9){
            obj.quit();
          }
          break;
      case 8: obj.requestDelete();
          cout << "Anything else?" << endl;
          cout << "Please Enter Your Option: " << endl;
          cin >> option;
          if(option == 2){
            obj.closeAccount();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 3){
            obj.show();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 4){
            obj.deposit();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 5){
            obj.withdraw();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 6){
            obj.getbalance();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 7){
            obj.limit_change();
            cout << "Anything else?" << endl;
            cout << "Please Enter Your Option: " << endl;
          }
          else if (option == 9){
            obj.quit();
          }
          break;   
      case 9: obj.quit();
          break;
      default: cout<<"Illegal Option"<<endl;
  }
}
}
