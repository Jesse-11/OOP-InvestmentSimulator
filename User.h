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
        : username(username), password(password) {}

        bool Authenticate(const string& enteredPassword) const 
        { return password == enteredPassword; }


        // getters
        const vector<Investment>& GetInvestments() const 
        { return investments; }

        const string& GetUsername() const 
        { return username; }
            
    private:
        string username;
        string password;
        vector<Investment> investments;

};