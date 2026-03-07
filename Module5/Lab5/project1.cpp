/* project1.cpp -  Gym Membership
    Name: Liam Walker
    Module: 5
    Project: 1
    Problem Statement: Create a structure which tracks information for new members in a gym

    Algorithm / Plan:
    1. Follow lab instructions to learn more about classes

*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
using namespace std;

// Constants
const double kBasicRate = 42.75,   
             kPremiumRate = 60.00;

// Member structure
struct Member {
    static int total_visits, active_members, last_id;
    
    int id;
    string name;
    char type;
    int visits;

    // Constructor
    Member(string name, char type) {  
        this->name = name;
        this->type = type;
        visits = 0; 
        active_members++; 
        id = last_id++; 
    }

    // Destructor
    ~Member() {
        active_members--;
    }
};

void visit(Member* member_ptr);

// Statics
int Member::total_visits = 0; 
int Member::active_members = 0;  
int Member::last_id = 100000; 

int main() {

    // Random number generator
    random_device seed;
    default_random_engine gen(seed());
    uniform_int_distribution<int> slot(5, 20);  
    
    vector<Member*> members;
    
   // Add members
    members.push_back(new Member("Oprah Winfrey", 'P'));

    members.push_back(new Member("Fluffy", 'P'));

    members.push_back(new Member("Charlie Sheen", 'B'));

    members.push_back(new Member("Leona Helmsley", 'B'));


    // Remove Charlie Sheen
    for (auto it = members.begin(); it != members.end(); ) {
        if ((*it)->name == "Charlie Sheen") {

            delete *it;
            it = members.erase(it); 
            
        } else {
            ++it;
        }
    }


    // Add visits
    for (auto member : members) {
        for (int i = 0; i < slot(gen); i++) {
            visit(member);
        }
    }

    cout << left << setw(10) << "ID" << "  " 
         << setw(20) << "Name" << "  " 
         << setw(6) << "Visits" << "  " 
         << setw(15) << "Membership" << "  " 
         << setw(10) << "Monthly Rate" << "  " 
         << endl;

    //Columnar report
    for (auto member : members) {
        string membership = "";
        double rate = 0;

        if(member->type == 'B') {
            membership = "Basic";
            rate = kBasicRate;
        } else {
            membership = "Premium";
            rate = kPremiumRate;
        }
        cout << setprecision(2) << fixed << left << setw(10) << member->id << "  " 
         << setw(20) << member->name << "  " 
         << right << setw(6) << member->visits << "  " 
         << left << setw(15) << membership << "  " 
         << right << setw(7) << "$" << rate << "  " 
         << endl;
    }
    cout << endl;

    cout << "Total Visits: " << Member::total_visits << endl;
    cout << "Total Members: " << Member::active_members << endl;



    // Clear
    for (auto memeber : members) {
        delete memeber;
    }
    members.clear();


    return 0;
}

void visit(Member* member_ptr) {
    member_ptr->visits++;
    Member::total_visits++;
}