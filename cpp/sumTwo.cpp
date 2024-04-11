#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> sumTwo(vector<int> &nums, int target) {
  unordered_map<int, int> map;
  for (int i = 0; i < nums.size(); i++) {
    map[nums[i]] = i;
  }
  for (int i = 0; i < nums.size(); i++) {
    int comp = target - nums[i];
    if (map.count(comp) > 0 && map[comp] != i) {
      return { i, map[comp] };
    }
  }
  return {};
}

int main() {
  vector<int> nums = {2, 7, 11, 15};
  vector<int> result = sumTwo(nums, 9);
  cout << result[0] << " " << result[1];
  return 0;
}
