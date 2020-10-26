/*
 *
 改进的二分法查找一个数组/向量里面的数e，如果找到了就返回它的秩，如果没有找到就返回不大于e的数的秩
 *
 */
int binSearch(int* A, const int& e, int lo, int hi)
{
	while(lo < hi)
	{
		int mi = (lo + hi) >> 1;
		(e < A[mi])? hi = mi : lo = mi + 1;
	}
	return --lo;
}
