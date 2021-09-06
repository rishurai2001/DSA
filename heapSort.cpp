//heap sort for increassing order

void heapSort(int arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);  //heapify is percolate down;
		printArray(arr,n);
	// One by one extract an element from heap
	for (int i = n - 1; i > 0; i--) {
		// Move current root to end,because its maximum
		swap(arr[0], arr[i]);
		printArray(arr,n);
		// call max heapify on the reduced heap
       //node >=i is excluded while heapifying;
		heapify(arr, i, 0);
	}
struct BSTNode {
        bool isBST;
        int mn;
        int mx;
        int sum;
    };
    BSTNode findMaxBST(TreeNode* node, int& res) {
        if (node != nullptr) {
            BSTNode left = findMaxBST(node -> left, res);
            BSTNode right = findMaxBST(node -> right, res);
            bool isBST = (left.isBST and right.isBST and left.mx < node -> val and node -> val < right.mn);
            int sum = node -> val + left.sum + right.sum;
            if (isBST) res = max(res, sum);
            return { isBST, min(node -> val, left.mn), max(node -> val, right.mx) , sum};
        } else {
            return { true, INT_MAX, INT_MIN, 0};
        }
    }
    int maxSumBST(TreeNode* root) {
        int res = 0;
        findMaxBST(root, res);
        return res;
    }
