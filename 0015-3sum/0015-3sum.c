int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    *returnSize = 0;

    int capacity = 1000;

    int** result = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));

    // Sort the array
    for(int i = 0; i < numsSize - 1; i++)
    {
        for(int j = i + 1; j < numsSize; j++)
        {
            if(nums[i] > nums[j])
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }

    for(int i = 0; i < numsSize - 2; i++)
    {
        // Skip duplicate first values
        if(i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = numsSize - 1;

        while(left < right)
        {
            long sum = (long)nums[i] + nums[left] + nums[right];

            if(sum == 0)
            {
                if(*returnSize >= capacity)
                {
                    capacity *= 2;
                    result = realloc(result, capacity * sizeof(int*));
                    *returnColumnSizes =
                        realloc(*returnColumnSizes, capacity * sizeof(int));
                }

                result[*returnSize] = malloc(3 * sizeof(int));

                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];

                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                // Skip duplicate left values
                while(left < right && nums[left] == nums[left + 1])
                    left++;

                // Skip duplicate right values
                while(left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }
            else if(sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return result;
}