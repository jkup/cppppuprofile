#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

int main() {
    vector<pair<int, string>> id_funcname_pairs = {
        {1, "function1"},
        {2, "function2"},
        {3, "function3"}
    };

    vector<pair<int, double>> id_duration_pairs = {
        {1, 100.0},
        {2, 200.0},
        {3, 300.0}
    };

    json cpuprofile;

    cpuprofile["startTime"] = 0.0;
    cpuprofile["endTime"] = 0.0;

    json nodes = json::array();

    for (const auto& pair : id_funcname_pairs) {
        int id = pair.first;
        string funcname = pair.second;
        double duration = 0.0;

        for (const auto& dur_pair : id_duration_pairs) {
            if (dur_pair.first == id) {
                duration = dur_pair.second;
                break;
            }
        }

        json node;
        node["id"] = id;
        node["callFrame"] = {
            {"functionName", funcname},
            {"scriptId", "0"},
            {"url", ""},
            {"lineNumber", 0},
            {"columnNumber", 0}
        };

        node["hitCount"] = duration;
        nodes.push_back(node);

        // Update the endTime with the maximum duration.
        if (cpuprofile["endTime"] < duration) {
            cpuprofile["endTime"] = duration;
        }
    }

    cpuprofile["nodes"] = nodes;
    cpuprofile["samples"] = json::array();
    cpuprofile["timeDeltas"] = json::array();

    ofstream outfile("profile.cpuprofile");
    if (outfile.is_open()) {
        outfile << cpuprofile.dump(2);
        outfile.close();
    } else {
        cerr << "Unable to open the output file" << endl;
    }

    return 0;
}

