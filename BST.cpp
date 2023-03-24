int maxDifference(Node *root, int target){
    int  maxDiffValue = INT_MIN;
     if (root == NULL) {
        return 0;
    }
    if (root->data == target) {
        int leftSum = maxDiff(root->left, target, maxDiffValue);
        int rightSum = maxDiff(root->right, target, maxDiffValue);
        if (leftSum == -1 || rightSum == -1) {
            return -1;
        }
        maxDiffValue = max(maxDiffValue, leftSum + rightSum);
        return 0;
    }
    int leftSum = maxDiff(root->left, target, maxDiffValue);
    int rightSum = maxDiff(root->right, target, maxDiffValue);
    if (leftSum == -1 && rightSum == -1) {
        return -1;
    }
    if (leftSum == -1) {
        return rightSum + root->data;
    }
    if (rightSum == -1) {
        return leftSum + root->data;
    }
    int sum = leftSum + rightSum + root->data;
    maxDiffValue = max(maxDiffValue, sum - leftSum - rightSum);
    return sum;
}