#include <Investment.h>
#include <InvestmentMarket.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class User 
{

    public:

        User(const string& username, const string& password)
        : username(username), password(password) {} // constructor for username and password

        bool Authenticate(const string& enteredPassword) const 
        { return password == enteredPassword; } // used to check and store the entered password


        // getters
        const vector<Investment>& GetInvestments() const 
        { return investments; }

        const string& GetUsername() const 
        { return username; }
        
        // setters
        void SetUsername(const string& username) 
        { this->username = username; }

        void SetPassword(const string& password) 
        { this->password = password; }


    private:

        string username;
        string password;
        vector<Investment> investments;

};