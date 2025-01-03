#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {

        bitset<51> visited;
        for (int num : nums){
            visited[num] = 1;
        }
        int sum = nums[0]; // initialize the sum with first integer of array

        if (nums.size() == 1){
            if (nums[0] != 0){
                return nums[0] +1;
            }
            else {
                return 1;
            }

        }


        for (int i = 1; i < nums.size() && nums[i] == nums[i - 1] + 1; ++i){
                if (nums[i] != nums[i - 1] + 1) {
                // non-sequential number found
                return nums[0] + 1;  // return num + 1
            }
            sum += nums[i];
        }

        for (int x = sum; x <= 51; ++x){ 
            if (!visited[x]){           
                return x;
            }
        }


        return sum;
    }
};