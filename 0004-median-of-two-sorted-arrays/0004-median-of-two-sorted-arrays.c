double findMedianSortedArrays(int* nums1, int nums1Size,
                              int* nums2, int nums2Size) {

    // Binary search hamesha chhote array par karenge
    if(nums1Size > nums2Size)
    {
        return findMedianSortedArrays(
            nums2, nums2Size,
            nums1, nums1Size
        );
    }

    int m = nums1Size;
    int n = nums2Size;

    int left = 0;
    int right = m;

    while(left <= right)
    {
        // nums1 ka partition
        int partition1 = (left + right) / 2;

        // nums2 ka partition
        int partition2 = (m + n + 1) / 2 - partition1;

        int maxLeft1;
        int minRight1;
        int maxLeft2;
        int minRight2;

        if(partition1 == 0)
            maxLeft1 = -2147483648;
        else
            maxLeft1 = nums1[partition1 - 1];

        if(partition1 == m)
            minRight1 = 2147483647;
        else
            minRight1 = nums1[partition1];

        if(partition2 == 0)
            maxLeft2 = -2147483648;
        else
            maxLeft2 = nums2[partition2 - 1];

        if(partition2 == n)
            minRight2 = 2147483647;
        else
            minRight2 = nums2[partition2];

        // Correct partition mil gaya
        if(maxLeft1 <= minRight2 &&
           maxLeft2 <= minRight1)
        {
            // Total elements odd
            if((m + n) % 2 == 1)
            {
                if(maxLeft1 > maxLeft2)
                    return maxLeft1;
                else
                    return maxLeft2;
            }

            // Total elements even
            int leftMax;

            if(maxLeft1 > maxLeft2)
                leftMax = maxLeft1;
            else
                leftMax = maxLeft2;

            int rightMin;

            if(minRight1 < minRight2)
                rightMin = minRight1;
            else
                rightMin = minRight2;

            return (leftMax + rightMin) / 2.0;
        }

        // nums1 ka partition right side move karo
        if(maxLeft1 > minRight2)
        {
            right = partition1 - 1;
        }
        else
        {
            left = partition1 + 1;
        }
    }

    return 0.0;
}