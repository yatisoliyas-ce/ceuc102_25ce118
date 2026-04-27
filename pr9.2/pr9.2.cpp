#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;

int main() {
    map<string, int> wordCount;
    string sentence, word;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    // Convert to lowercase
    for (int i = 0; i < sentence.length(); i++)
        sentence[i] = tolower(sentence[i]);

    // Remove punctuation
    string cleaned = "";
    for (int i = 0; i < sentence.length(); i++)
        if (isalpha(sentence[i]) || sentence[i] == ' ')
            cleaned += sentence[i];

    // Parse words and count
    istringstream ss(cleaned);
    while (ss >> word)
        wordCount[word]++;

    // Display all words and frequencies
    cout << "\n--- Word Frequency ---" << endl;
    for (auto it = wordCount.begin(); it != wordCount.end(); it++)
        cout << it->first << " : " << it->second << endl;

    // Find most and least frequent
    string mostWord = "", leastWord = "";
    int maxFreq = 0, minFreq = INT_MAX;

    for (auto it = wordCount.begin(); it != wordCount.end(); it++) {
        if (it->second > maxFreq)  { maxFreq = it->second;  mostWord  = it->first; }
        if (it->second < minFreq)  { minFreq = it->second;  leastWord = it->first; }
    }

    cout << "\nMost frequent  : \"" << mostWord  << "\" (" << maxFreq << " times)" << endl;
    cout << "Least frequent : \"" << leastWord << "\" (" << minFreq << " times)" << endl;
    cout << "Total unique words: " << wordCount.size() << endl;

    return 0;
}
