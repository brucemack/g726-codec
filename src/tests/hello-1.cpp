#include <iostream>
#include <fstream>
#include <string>

extern "C" {
#include "g72x.h"
}

using namespace std;

int main(int, const char**) {

    g726_state state_ptr_encode;
    g726_init_state(&state_ptr_encode);
    g726_state state_ptr_decode;
    g726_init_state(&state_ptr_decode);

    ifstream in("../test-vectors/NRM.M");
    if (!in.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    uint8_t ulaw[160];
    unsigned ulawLen = 0;

    string line;
    while (std::getline(in, line) && ulawLen < 160) {
        if (line.length() == 65) {
            line = line.substr(0, 64);
            // Convert each from hex
            for (size_t i = 0; i < line.length(); i += 2) {
                // Extract a substring of length 2
                string hexToken = line.substr(i, 2);
                ulaw[ulawLen++] = std::stoi(hexToken, nullptr, 16); 
                if (ulawLen == 160)
                    break;
            }

        } else {
            cout << "Ignoring line: " << line << endl;
        }
    }

    // Convert first frame
    for (unsigned i = 0; i < 160; i++) {
        // This is a 4-bit code word
        int c = g726_32_encoder(ulaw[i], AUDIO_ENCODING_ULAW, &state_ptr_encode);
        //cout <<  std::hex << c << endl;
        
        // Re-encode to ulaw
        int d = g726_32_decoder(c, AUDIO_ENCODING_ULAW, &state_ptr_decode);
        cout <<  std::hex << d << endl;
    }
}
