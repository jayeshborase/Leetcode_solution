/*
#   Using Hare and tortoise method.
#   Here we’ll be using 2 pointers fast and slow. Initially slow will initialize with the first element and fast       will initialize with the element present in nums[0] index.
#   In the first loop, we’ll move both pointers with 1 index & break after slow=fast.
#   Then we’ll make fast 0 & in the next loop we’ll move the slow pointer with 1 position and fast with 2               positions.
#   One point the both will equal and return fast/slow.
      Time complexity: O(n).*/
// TC = O(n) , SC = (1);
class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {    
        if (nums.size() > 1)
        {
            int slow = nums[0];
            int fast = nums[nums[0]];
            while (slow != fast)
            {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }

            fast = 0;
            while (fast != slow)
            {
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
        return -1;
    }
};