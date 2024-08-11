#include <iostream>
using namespace std;

void login();
void deposit();
void withdrawal();
void showBalance();
void transfer();
void changePin();
void testNewPin();
void menu();
double accountBalance;
string accountName;
int PinNumber;
double amount;

// Log user into their account
void login(){
    while(true){
            // Nromot for account name
            cout << "Account Name: ";
            cin >> accountName;
            // Verify account name
            if (accountName == "VORTEX")
                { // Name matches, continue with pin
                    break;
                }
            else
                { // Invalid name, show error and retry
                    system("cls");
                    cout << "Invalid Account Name. Please try again." << endl;
                    continue;
                }
            }
  // Verify PIN Number
  while (true){
        cout << "Enter your pin number: ";
        cin >> PinNumber;
        if (PinNumber == 1234){
            // PIN matches, login successful
            break;
        }
        else{
           // Invalid PIN, show error and retry
           system("cls");
           cout << "Incorrect pin number.\nPlease enter the correct pin number to proceed."<<endl;
           continue;
       }
  // Login successful
  system("cls");
}
}

// Allow user to deposit funds
void deposit(){
  system("cls");
  while(true){
        cout << "Enter the amount to be deposited: ";
        cin >> amount;
        // Ensure amount entered is valid
        if (amount > 0){
            // Valid amount, proceed with deposit
            accountBalance += amount;
            break;
        }
        else{
            // Invalid amount, show error and retry
            system("cls");
            cout << "That's not a valid amount.\n PLease try again. " << endl;
            continue;
        }
  }
  // Deposit successful
  system("cls");
  cout << "Deposit Successful!" << endl;
  cout << "You Deposited $" << amount << endl;

  // Ask user if user wants to go to menu or exit
  int choice;
  cout << "Press 1 to go back to main menu or 0 to exit: ";
  cin >> choice;

  if (choice == 1) {
    system("cls");
    menu(); // show menu again
  }
  else if(choice == 0) {
    // Exit with custom message
    system("cls");
    cout << "Thanks for visiting!" << endl;
    exit(0);
  }
}

// Allow user to withdraw funds
void withdraw(){
  system("cls");
  while (true){
    cout << "\nWithdrawal Amount: ";
    cin >> amount;
    if ((amount <= accountBalance) && (amount > 0))
    {
      accountBalance -= amount;
      break;
    }
    else if (amount > accountBalance)
    {
      system("cls");
      cout << "Insufficient Fund\n";
      continue;
    }
    else if (amount <= 0)
    {
      system("cls");
      cout << "That's not a valid amount\n Please try again." << endl;
      continue;
    }
  }
  // Withdrawal successful
  system("cls");
  cout << "Amount Withdrawn Successfully!\n Withdrew $"<< amount <<endl;
   // Ask user if user wants to go to menu or exit
  int choice;
  cout << "Press 1 to go back to main menu or 0 to exit: ";
  cin >> choice;

  if (choice == 1) {
    system("cls");
    menu(); // show menu again
  }
  else if(choice == 0) {
    // Exit with custom message
    system("cls");
    cout << "Thanks for visiting!" << endl;
    exit(0);
  }
}

// Display user's current account balance
void showBalance(){
  system ("cls");
  cout << "Name : "<< accountName << endl;
  cout << "Current Balance : $" << accountBalance << endl;
   // Ask user if user wants to go to menu or exit
  int choice;
  cout << "Press 1 to go back to main menu or 0 to exit: ";
  cin >> choice;

  if (choice == 1) {
    system("cls");
    menu(); // show menu again
  }
  else if(choice == 0) {
    // Exit with custom message
    system("cls");
    cout << "Thanks for visiting!" << endl;
    exit(0);
  }
}

// Transfer funds to another account
void transfer(){
  system("cls");
  double transferAmount;
  int recipientAccount;
  // Take recipient account and amount
  cout << "Enter recipient account number: ";
  cin >> recipientAccount;

  while (true)
  {
    int choice;
    // validate amount
    cout << "Enter amount to transfer: ";
    cin >> transferAmount;
    if (transferAmount > 0 && transferAmount <= accountBalance){
      cout << "press 1 to continue to cancel 0: ";
     cin >> choice;
     if (choice == 1) { // update balance
      system("cls");
      accountBalance -= transferAmount;
      cout << "Successfully Transferred $" << transferAmount << " to " << recipientAccount << endl;
      break;// show menu again
     }
      else if(choice == 0) {
    // Exit back to menu
    system("cls");
    menu();
     }
    }
      // Decrease the sender's account by the transfer amount and increase the receiver's by the same amount.

    else if(transferAmount <= 0){
        cout << "Transfer amount must be greater than 0. Please try again." << endl;
      }
    else {
        cout << "Insufficent funds!\n Please try again." << endl;
        }
}
}

// Changing the login PIN number
void changePin() {
  system("cls");
  int currentPin, newPin, ConfirmPin;

  // Take current PIN
  int tries = 0;
  while(tries < 3){

  cout << "Enter your current Pin: ";
  cin >> currentPin;

  // Verify
  if(currentPin == PinNumber){
     // correct, move on
     break;
  }
  else {
        system("cls");
        cout << "Invalid pin, try again" << endl;
        tries++;
  }
}
if(tries >= 3){
        system("cls");
        cout << "Too many attempts";
        exit(0);
}
  // update PIN number
  PinNumber = newPin;
  cout << "Your Pin has been changed successfully!" << endl;
  // Offer to test new PIN
  cout << "Would you like to test your new PIN? (y/n)";
  char choice;
  cin >> choice;
  if(choice == 'y'){
  system("cls");
  testNewPin();
  }
  else{
    system("cls");
    menu();
  }
}

// Test logging in with new PIN
void testNewPin(){
    system("cls");

  int testPin;
  int attempts = 0;

  // Allow 3 login attempts
  while(attempts < 3){
    //Ask for PIN
    cout << "Please enter your new PIN: ";
    cin >> testPin;

    attempts++;
    // Check new PinNumber
    if(testPin == PinNumber){
      cout << "Login successful with new PIN!" << endl;
      return;
    }
    else {
      cout << "Invalid PIN, try again." << endl;
    }
  }

  cout << "Too many failed attempts. Exiting program." << endl;
  exit(1);

}

// Display menu and process user selection
void menu() {
  system("cls");
int choice;
    cout << "WELCOME BACK " << accountName <<endl;
    while (true){
      // Print menu options
        cout << "=============================" << endl;
        cout << "\n\t|MAIN MENU|\n";
        cout << "[1] Deposit\n";
        cout << "[2] Withdraw\n";
        cout << "[3] Show Account Balance\n";
        cout << "[4] Transfer\n";
        cout << "[5] Change PIN\n";
        cout << "[6] EXIT\n";
        cout << "=============================" << endl;
        cout << "Input: ";
        cin >> choice; // Take input
        // Call appropriate function based on choice
        switch (choice){
           case 1 :
               deposit();
               break;
           case 2:
               withdraw();
               break;
            case 3:
                showBalance();
                break;
            case 4:
                transfer();
                break;
            case 5:
                changePin();
                break;
            case 6:
                system("cls");
                cout << "Thanks for visiting!\n";
                return;
            default:
                system("cls");
                cout << "Invalid Input\n";
                continue;
        }
    }
}

int main(){
    login();
    menu();

  return 0;
}

