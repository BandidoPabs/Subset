#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;
ofstream newfile("output_SalinasPablo.dat"); // creating a new file to store the results into

class Operation {
private:
	string set1, set2;
public:
	void setstrings(string a, string b) {
		set1 = a;
		set2 = b;
	}
	bool Subset(string a, int c, string b, int d) {
		bool status = true;
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < c; j++) {
				if (b[i] == a[j]) {
					break;
				}
				else
					status = false;
			}
		}
		return status;
	}
	void Union(string a, int c, string b, int d) {
		int han = 0;
		string texans;
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < d; j++) {
				if (a[i] == b[j]) {
					han = 1;
					break;
				}
				else if (a[i] != b[j]) {
					han = 0;
				}
			}
			if (han == 1) {
				texans += a[i];
			}
			else if (han == 0) {
				texans += a[i];
				texans += b[i];
			}
		}
		sort(texans.begin(), texans.end());
		for (int i = 0; i <= texans.length(); i++) {
			if (i == 0) {
				newfile << "{";
				cout << "{";
			}
			if (i == texans.length()) {
				cout << texans[texans.length()-1] << "}";
				newfile << texans[texans.length() - 1] << "}";
			}
			if (i < texans.length()-1) {
				cout << texans[i] << ", ";
				newfile << texans[i] << ", ";
			}
		}
	}
	void Intersection(string a, int c, string b, int d) {
		int value = 0;
		string sat;
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < d; j++) {
				if (a[i] == b[j]) {
					value = 1;
					break;
				}
				else if (a[i] != b[j]) {
					value = 0;
				}

			}
			if (value == 1) {
				sat += a[i];
			}
		}
		for (int i = 0; i <= sat.length(); i++) {
			if (i == 0) {
				cout << "{";
				newfile << "{";
			}
			if (i == sat.length()) {
				cout << sat[sat.length() - 1] << "}";
				newfile << sat[sat.length() - 1] << "}";
			}
			if (i < sat.length() - 1) {
				cout << sat[i] << ", ";
				newfile << sat[i] << ", ";
			}
		}


	}
	void Complement(string a, int c, string b, int d) {
		int value = 0;
		string wat;
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < d; j++) {
				if (a[i] != b[j]) {
					value = 1;


				}
				else if (a[i] == b[j]) {
					value = 0;
					break;
				}

			}
			if (value == 1) {
				wat += a[i];
			}
		}
		for (int i = 0; i <= wat.length(); i++) {
			if (i == 0) {
				cout << "{";
				newfile << "{";
			}
			if (i == wat.length()) {
				cout << wat[wat.length() - 1] << "}";
				newfile << wat[wat.length() - 1] << "}";
			}
			if (i < wat.length() - 1) {
				cout << wat[i] << ", ";
				newfile << wat[i] << ", ";
			}
		}
	}

};


int main() {
	Operation pro; //declaring an object in order to use the function in the class
	string line, line2, line3, line4; // String to store the information that is read into the file
	int length1, length2; 
	
	ifstream myfile("input.dat"); // opening the file
	if (myfile.is_open()) {

		getline(myfile, line);	// storing the information from the file into the strings
		getline(myfile, line2);
		myfile.close();
	}
	// Removing the commas and adding into a new string
	for (int i = 0; i < line2.length(); i++) {
		if (line[i] != ',') {
			line4 += line2[i];
		}
	} 

	// Removing the commas and adding into a new string
	for (int i = 0; i < line.length(); i++) {
		if (line[i] != ',') {
			line3 += line[i];
		}
	}

	// setting my string lengths
	length1 = line3.length();
	length2 = line4.length();

	//setting the strings into the class

	pro.setstrings(line3, line4);


	// printing out the contents and using the class functions to complement, intersect, union, and subset
	//storing to a new file as well
	
		newfile << "Given these sets: A = ";
		cout << "Given these sets: A = ";
		for (int i = 0; i <= line3.length(); i++) {
			if (i == 0) {
				cout << "{";
				newfile << "{";
			}
			if (i == line3.length()) {
				cout << line3[line3.length() - 1] << "}";
				newfile << line3[line3.length() - 1] << "}";
			}
			if (i < line3.length() - 1) {
				cout << line3[i] << ", ";
				newfile << line3[i] << ", ";
			}
		}
		newfile << " and B = ";
		cout << " and B = ";
		for (int i = 0; i <= line4.length(); i++) {
			if (i == 0) {
				cout << "{";
				newfile << "{";
			}
			if (i == line4.length()) {
				cout << line4[line4.length() - 1] << "}";
				newfile << line4[line4.length() - 1] << "}";
			}
			if (i < line4.length() - 1) {
				cout << line4[i] << ", ";
				newfile << line4[i] << ", ";
			}
		}
		cout << endl << endl;
		newfile << endl << endl;
		newfile << "A is-a-subset-of B ==> ";
		cout << "A is-a-subset-of B ==> ";
		if (pro.Subset(line3, length1, line4, length2) == 1) {
			cout << "True";
			newfile << "True";
		}
		else {
			cout << "False";
			newfile << "False";
		}
		newfile << endl;
		cout << endl;
		newfile << "B is-a-subset-of A ==> ";
		cout << "B is-a-subset-of A ==> ";
		if (pro.Subset(line4, length2, line3, length1) == 1) {
			cout << "True";
			newfile << "True";
		}
		else {
			cout << "False";
			newfile << "False";
		}
		cout << endl;
		newfile << endl;
		newfile << "A + B = ";
		cout << "A + B = ";
		pro.Union(line3, length1, line4, length2);
		newfile << endl;
		cout << endl;
		newfile << "A ^ B = ";
		cout << "A ^ B = ";
		pro.Intersection(line3, length1, line4, length2);
		cout << endl;
		newfile << endl;
		newfile << "A - B = ";
		cout << "A - B = ";
		pro.Complement(line3, length1, line4, length2);
		cout << endl;
		newfile << endl;
		newfile << "B - A = ";
		cout << "B - A = ";
		pro.Complement(line4, length2, line3, length1);
		cout << endl;
		newfile << endl;
		newfile.close();
	
	cout << endl;
	system("pause");
	return 0;
}

