// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// No more permutations can be generated 
#define END -1 

// Permutation is valid 
#define VALID 1 

// Utility function to print the 
// generated permutation 
void printString(vector<int>& word, 
				vector<pair<char, int> >& ref) 
{ 

	for (int i = 0; i < word.size(); i++) { 
		cout << ref[word[i]].first; 
	} 
	cout << "\n"; 
} 

// Function that checks for any conflict present 
// in the word/string for the index 
bool hasConflict(vector<int>& word, 
				vector<pair<char, int> >& ref, int index) 
{ 

	// Check number of instances where value of 
	// the character is equal to the 
	// value at checking index 
	int conflictCount = 0; 
	for (int i = 0; i < index; i++) { 
		if (word[i] == word[index]) 
			conflictCount++; 
	} 

	// If the number of instances are greater 
	// than the number of occurrences of the 
	// character then conflict is present 
	if (conflictCount < ref[word[index]].second) { 
		return false; 
	} 

	return true; 
} 

// Function that returns the validity of the 
// next permutation generated and makes 
// changes to the word array 
int getNext(vector<int>& word, 
			vector<pair<char, int> >& ref, int mod) 
{ 

	int left, right, carry; 

	right = word.size() - 1; 

	carry = 1; 

	// Simply add 1 to the array word following 
	// the number system with base mod 
	// generates a new permutation 
	for (left = right; left >= 0; left--) { 
		if (left == 0 && word[left] + carry >= mod) { 
			return END; // overflown 
		} 

		if (word[left] + carry >= mod) { 
			word[left] = (word[left] + carry) % mod; 
		} 
		else { 
			word[left] = word[left] + carry; 
			break; 
		} 
	} 

	// All the values between left and right (inclusive) 
	// were changed and therefore need to be 
	// adjusted to get a valid permutation 
	while (left <= right) { 
		while (hasConflict(word, ref, left) && word[left] < mod) { 

			// Increment till conflict between substring [0, i) 
			// is resolved or word[left] goes above mod 
			word[left]++; 
		} 
		if (word[left] >= mod) { 

			// The value for left has crossed mod therefore 
			// all the values for word with [0, left) 
			// constant have been convered therefore add 1 
			// to the substring [0, left) to get a new value 
			// of left which represents all affected parts. 
			// Repeat the process of conflict resolvation 
			// and validity checking from this new left 
			word[left] %= mod; 
			int carry = 1; 
			left--; 
			while (left >= 0) { 
				if (left == 0 && word[left] + carry >= mod) { 

					// Overflow 
					return END; 
				} 

				if (word[left] + carry >= mod) { 
					word[left] = (word[left] + carry) % mod; 
					left--; 
				} 
				else { 
					word[left] = (word[left] + carry); 
					break; 
				} 
			} 
		} 
		else { 

			// Increment left if conflict is resolved 
			// for current index and do conflict 
			// resolution for the next index 
			left++; 
		} 
	} 

	return VALID; 
} 

// Iterative function to generate all the 
// distinct permutations of str 
void generatePermutations(string str) 
{ 
	if (str.size() == 0) 
		return; 

	// First sort the string to assign mapped values 
	// and occurrences to each letter 
	// Sorting needs to handle letters 
	// with multiple occurrences 
	sort(str.begin(), str.end()); 

	// Reference vector to store the mapping of 
	// its index to its corresponding char 
	// and the number of occurrences of the character 
	// as the second element of the pair 
	vector<pair<char, int> > ref(str.size()); 

	// Assign each character its index and the 
	// number of occurrences 
	int count = 0; 
	ref[count] = make_pair(str[0], 1); 

	for (int i = 1; i < str.size(); i++) { 

		// Increment occurrences if character is repeated 
		// Else create new mapping for the next character 
		if (str[i] == str[i - 1]) { 
			ref[count].second++; 
		} 
		else { 
			count++; 
			ref[count] = make_pair(str[i], 1); 
		} 
	} 

	// Size may differ in case of multiple 
	// occurrences of characters 
	ref.resize(count + 1); 

	// Construct the word 
	// Word stores the mapped values for every letter 
	// in a permuted sequence i.e. say for "abc" 
	// word would be initially [0, 1, 2] or "aba", [0, 1, 0] 
	vector<int> word; 
	for (int i = 0; i < ref.size(); i++) { 
		for (int j = 0; j < ref[i].second; j++) 
			word.push_back(i); 
	} 

	// mod is the number of distinct letters in string 
	int mod = ref.size(); 
	int flag = VALID; 

	while (flag != END) { 

		// If the permutation sent by getNext 
		// is valid then print it 
		printString(word, ref); 

		// Get the next permutation, validity 
		// stored in flag 
		flag = getNext(word, ref, mod); 
	} 
} 

// Driver code 
int main() 
{ 
	string str; 
    cin>>str;
	generatePermutations(str); 

	return 0; 
} 
