#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<vector<int>> anagrams(const vector<string> &A) {
  vector<vector<int>> ans;
  unordered_map<string, vector<int>> us;
  for (int i = 0; i < A.size(); i++) {
    string key = A[i];
    sort(begin(key), end(key));
    us[key].push_back(i + 1);
    // if (us.find(key) != us.end()) {
    //   us[key].push_back(i + 1);
    // } else {
    //   us[key] = {i + 1};
    // }
  }
  for (auto it = us.begin(); it != us.end(); ++it) {
    ans.push_back(it->second);
  }
  return ans;
}
