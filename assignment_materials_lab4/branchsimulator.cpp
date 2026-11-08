#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <bitset>

using namespace std;

unsigned bht(unsigned pc, int h) {
	return (pc >> 2) % (1u << h);
}

unsigned pht(unsigned pc, unsigned w_history, int m, int w) {
    unsigned bits = (pc >> 2) % (1u << (m - w));
    return (bits << w) + w_history;
}

int predict(int entry) {
    if (entry >= 2) {
		return 1;
	}
    return 0;    
}

int update_entry(int entry, int taken) {
    if (taken == 1) {
        if (entry < 3) {
            return entry + 1;
        } else {
            return 3;
        }
    } else {
        if (entry > 0) {
            return entry - 1;
        } else {
            return 0;
        }
    }
}


int main (int argc, char** argv) {
	ifstream config;
	config.open(argv[1]);

	int m, w, h;
	config >> m;
	config >> h;
	config >> w;
 
	config.close();

	ofstream out;
	string out_file_name = string(argv[2]) + ".out";
	out.open(out_file_name.c_str());
	
	ifstream trace;
	trace.open(argv[2]);

	// TODO: Implement a two-level branch predictor 
	while (!trace.eof()) {
		out << 0 << endl; // predict not taken
	}
	 
	trace.close();	
	out.close();
}

// Path: branchsimulator_skeleton_23.cpp