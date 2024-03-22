#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool compare(pair<string, int>& a, pair<string, int>& b) {
  if (a.second == b.second) {
    if (a.first.size() == b.first.size()) return a.first < b.first;
    return a.first.size() > b.first.size();
  }
  return a.second > b.second;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  map<string, int> wordCount;
  for (int i = 0; i < N; i++) {
    string word;
    cin >> word;
    if (word.size() >= M) {
      wordCount[word]++;
    }
  }

  vector<pair<string, int>> words(wordCount.begin(), wordCount.end());
  sort(words.begin(), words.end(), compare);

  for (auto& word : words) cout << word.first << '\n';

  return 0;
}