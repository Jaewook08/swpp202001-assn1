#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argv, char **argc) {
  vector<pair<string, int>> words;
  ifstream fin(argc[1]);
  string nextword;

  while (fin >> nextword) {
    bool found = false;
    for (auto &[word, occurrence] : words) {
      if (word == nextword) {
        ++occurrence;
        found = true;
        break;
      }
    }
    if (!found)
      words.emplace_back(nextword, 1);
  }

  if (words.empty()) {
    cout << "Input is empty" << endl;
    return 0;
  }

  string word_with_max_occur = words[0].first;
  int max_occur = words[0].second;
  for (auto &[word, occur] : words)
    if (occur > max_occur) {
      word_with_max_occur = word;
      max_occur = occur;
    }

  cout << "Word '" << word_with_max_occur << "' appeared " << max_occur
       << " times." << endl;
  return 0;
}
