#include <bits/stdc++.h>
using namespace std;


int main(){

    map<string, string> tickets;

    tickets["Chennai"] = "Bangalore";
    tickets["Bombay"] = "Delhi";
    tickets["Goa"] = "Channai";
    tickets["Delhi"] = "Goa";

    map<string, bool> destinationCities;

    for(auto ticket : tickets){

        destinationCities[ticket.second] = true;
    }

    string startCity = "";

    //find the start cities
    for(auto ticket : tickets){

        if(destinationCities.find(ticket.first) == destinationCities.end()){

            startCity = ticket.first;
            break;
        }
    }

    //if not found starting city
    if(startCity == ""){

        cout << "Invalid Input" << endl;

        return 0;
    }

    //print complete itinerary

    cout << "Complete Itinerary: " << endl;

    while(tickets.find(startCity) != tickets.end()){

        string nextCity = tickets[startCity];

        cout << startCity << " ->" << nextCity << endl;

        startCity = nextCity;
    }

    return 0;

}