#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Helper function to parse dotted-decimal IP address (optionally with /CIDR)
bool parseIP(const string &str, int &o1, int &o2, int &o3, int &o4, int &cidr) {
    string ipPart = str;
    size_t slashPos = str.find('/');
    if (slashPos != string::npos) {
        string cidrPart = str.substr(slashPos + 1);
        ipPart = str.substr(0, slashPos);
        try {
            size_t idx;
            cidr = stoi(cidrPart, &idx);
            if (idx != cidrPart.length()) {
                return false;
            }
        } catch (...) {
            return false;
        }
    }

    char d1, d2, d3;
    stringstream ss(ipPart);
    if ((ss >> o1 >> d1 >> o2 >> d2 >> o3 >> d3 >> o4) && d1 == '.' && d2 == '.' && d3 == '.') {
        string rem;
        if (ss >> rem) {
            return false;
        }
        return (o1 >= 0 && o1 <= 255 && o2 >= 0 && o2 <= 255 && o3 >= 0 && o3 <= 255 && o4 >= 0 && o4 <= 255);
    }
    return false;
}

void solve() {
    int o1 = -1, o2 = -1, o3 = -1, o4 = -1;
    int cidr = -1;
    string token;

    // 1. Get user input for Base IP and CIDR prefix
    cout << "Enter base IP address (e.g., 192.168.10.0): ";
    if (!(cin >> token)) {
        cout << "Error: Invalid input." << endl;
        return;
    }

    if (token.find('.') != string::npos) {
        if (!parseIP(token, o1, o2, o3, o4, cidr)) {
            cout << "Error: Invalid IP address format or octets out of bounds (0-255)." << endl;
            return;
        }
    } else {
        // Handle space-separated input
        try {
            size_t idx;
            o1 = stoi(token, &idx);
            if (idx != token.length()) {
                throw 1;
            }
        } catch (...) {
            cout << "Error: Invalid IP address format or octets out of bounds (0-255)." << endl;
            return;
        }

        if (!(cin >> o2 >> o3 >> o4)) {
            cout << "Error: Invalid IP address format or octets out of bounds (0-255)." << endl;
            return;
        }

        if (o1 < 0 || o1 > 255 || o2 < 0 || o2 > 255 || o3 < 0 || o3 > 255 || o4 < 0 || o4 > 255) {
            cout << "Error: Invalid IP address format or octets out of bounds (0-255)." << endl;
            return;
        }
    }

    // Prompt for CIDR prefix if not provided in the IP string
    if (cidr == -1) {
        cout << "Enter CIDR prefix (e.g., 26 for /26): ";
        string cidrStr;
        if (!(cin >> cidrStr)) {
            cout << "Error: Invalid input." << endl;
            return;
        }
        if (!cidrStr.empty() && cidrStr[0] == '/') {
            cidrStr = cidrStr.substr(1);
        }
        try {
            size_t idx;
            cidr = stoi(cidrStr, &idx);
            if (idx != cidrStr.length()) {
                cout << "Error: Invalid CIDR prefix." << endl;
                return;
            }
        } catch (...) {
            cout << "Error: Invalid CIDR prefix." << endl;
            return;
        }
    }

    // Validate for Class C subnetting range
    if (cidr < 24 || cidr > 30) {
        cout << "Error: This program currently supports Class C subnetting (CIDR 24 to 30)." << endl;
        return;
    }

    // 2. Calculate the core subnetting details
    int hostBits = 32 - cidr;
    int blockSize = 1 << hostBits;
    int numSubnets = 256 / blockSize;
    int usableHosts = blockSize - 2;
    int lastOctetMask = 256 - blockSize;

    cout << "\n--- General Subnet Information ---" << endl;
    cout << "Calculated Subnet Mask : 255.255.255." << lastOctetMask << endl;
    cout << "Total Usable Hosts     : " << usableHosts << " per subnet" << endl;
    cout << "Total Subnets Created  : " << numSubnets << "\n" << endl;

    for (int i = 0; i < numSubnets; ++i) {
        int network = i * blockSize;
        int firstHost = network + 1;
        int lastHost = network + usableHosts;
        int broadcast = network + blockSize - 1;

        cout << "=========================================" << endl;
        cout << "Subnet " << (i + 1) << endl;
        cout << "=========================================" << endl;
        cout << "Network Address   : " << o1 << "." << o2 << "." << o3 << "." << network << endl;
        cout << "First Host        : " << o1 << "." << o2 << "." << o3 << "." << firstHost << endl;
        cout << "Last Host         : " << o1 << "." << o2 << "." << o3 << "." << lastHost << endl;
        cout << "Broadcast Address : " << o1 << "." << o2 << "." << o3 << "." << broadcast << endl;
        cout << "\nUsable IP Addresses:" << endl;
        for (int j = firstHost; j <= lastHost; ++j) {
            cout << "  " << o1 << "." << o2 << "." << o3 << "." << j << endl;
        }
        cout << endl;
    }
}

int main() {
    solve();
    return 0;
}
