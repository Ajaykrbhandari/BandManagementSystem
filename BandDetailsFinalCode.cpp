#include<iostream>
#include <vector>
#include <string>

using namespace std;

class MusicBand {
private:
    string bandName;
    vector<pair<string, string>> bandMembers;         // Pair of member name and instrument
    vector<pair<string, float>> songPerformances;    // Pair of song name and duration
    pair<float, float> timeManagement;              // Pair of rehearsal time and performance time

public:
    // Constructor to take user inputs
    MusicBand() {
        cout << "Enter the band name: ";
        getline(cin, bandName);

        getBandMembers();
        getSongPerformances();
        getTimeManagement();
    }

    // Method to get band members' details
    void getBandMembers() {
        int numMembers;
        cout << "Enter the number of band members: ";
        cin >> numMembers;
        cin.ignore();  // Clear the newline character from the input buffer

        for (int i = 0; i < numMembers; ++i) {
            string memberName, instrument;
            cout << "Enter the name of band member " << i + 1 << ": ";
            getline(cin, memberName);

            cout << "Enter the instrument played by " << memberName << ": ";
            getline(cin, instrument);

            bandMembers.push_back(make_pair(memberName, instrument));
        }
    }

    // Method to get song performances details
    void getSongPerformances() {
        int numSongs;
        cout << "Enter the number of songs performed by the band: ";
        cin >> numSongs;
        cin.ignore();  // Clear the newline character from the input buffer

        for (int i = 0; i < numSongs; ++i) {
            string songName;
            float duration;

            cout << "Enter the name of song " << i + 1 << ": ";
            getline(cin, songName);

            cout << "Enter the duration of " << songName << " performance: ";
            cin >> duration;
            cin.ignore();  // Clear the newline character from the input buffer

            songPerformances.push_back(make_pair(songName, duration));
        }
    }

    // Method to get time management details
    void getTimeManagement() {
        cout << "Enter the total rehearsal time in hours: ";
        cin >> timeManagement.first;

        cout << "Enter the total performance time in hours: ";
        cin >> timeManagement.second;
    }

    // Method to display band information
    void displayBandInfo() {
        cout << "\nBand Information:\n";
        cout << "Band Name: " << bandName << "\n\n";

        cout << "Band Members:\n";
        for (const auto& member : bandMembers) {
            cout << "Name: " << member.first << ", Instrument: " << member.second << "\n";
        }

        cout << "\nSong Performances:\n";
        for (const auto& performance : songPerformances) {
            cout << "Song: " << performance.first << ", Duration: " << performance.second << " mins\n";
        }

        cout << "\nTime Management:\n";
        cout << "Rehearsal Time: " << timeManagement.first << " hours\n";
        cout << "Performance Time: " << timeManagement.second << " hours\n";
    }
};

int main() {
    MusicBand myBand;
    myBand.displayBandInfo();

    return 0;
}

