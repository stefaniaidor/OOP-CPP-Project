#include<iostream>
#include<string>

using namespace std;

class NaughtyCheck{
private:
    string name;
    string status;
public:
    NaughtyCheck(string firstName, string kidStatus){
       name=firstName;
       status=kidStatus;
    };

    const string &getName() const {
        return name;
    }

    const string &getStatus() const {
        return status;
    }

};