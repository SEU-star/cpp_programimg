class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> mergeNum(n1+n2);

        //先判断其中一个为0的情况
        if(0 == n1)
        {
            if(0 == (n2%2))
                return (nums2[n2/2 -1] + nums2[n2/2])/2.0;
            else
                return nums2[n2/2];
        }
        if(0 == n2)
        {
            if(0 == (n1%2))
                return (nums1[n1/2 -1] + nums1[n1/2])/2.0;
            else
                return nums1[n1/2];
        }
        //合并向量
        int count = 0;//新向量的个数
        int i, j = 0;//老向量的索引
        while(count != (n1+n2))
        {
            if(i == n1)
            {
                while(j != n2)
                    mergeNum[count++] = nums2[j++];
                break;
            }
            
            if(j == n2)
            {
                while(i != n1)
                    mergeNum[count++] = nums1[i++];
                break;
            }
            
            if(nums1[i] <= nums2[j])
                mergeNum[count++] = nums1[i++];
            else
                mergeNum[count++] = nums2[j++];
        }

        if(0 == count%2)
            return (mergeNum[count/2 -1] + mergeNum[count/2])/2.0;
        else
            return mergeNum[count/2];
    }
};