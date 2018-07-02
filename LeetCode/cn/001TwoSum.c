/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i, min = nums[0];
    int* indices = malloc(2*sizeof(int));
    /* find the min of nums[numsSize] */
    for (i = 1; i < numsSize; i++)
        if (min > nums[i])
            min = nums[i];
    
    int hashSize = target - min - min + 1;
    int hash[hashSize];
    /* initialization of hash */
    for (i = 0; i < hashSize; i++)
        hash[i] = INT_MIN;
    /* loop of nums
       1 skip the elements larger than target-min
       2 tag the corresponding element
       3 when find the tag, return the two indices
    */
    for (i = 0; i < numsSize; i++){
        if (nums[i] > target-min)
            continue;
        else if (hash[nums[i]-min] == INT_MIN)
            hash[target-nums[i]-min] = i;
        else{
            indices[0] = hash[nums[i] - min];
            indices[1] = i;
            return indices;
        }
    }
    return NULL;
}
