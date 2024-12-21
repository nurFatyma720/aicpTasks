#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// TreeNode class for BST
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Heap class for Min-Heap
class MinHeap {
private:
    vector<int> heap;

    void heapifyDown(int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        if (index > 0 && heap[index] < heap[parent]) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void buildHeap(const vector<int>& data) {
        heap = data;
        for (int i = heap.size() / 2 - 1; i >= 0; --i)
            heapifyDown(i);
    }

    void display() {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

// Function to insert a node into the BST
TreeNode* add(TreeNode* root, int value) {
    if (!root) return new TreeNode(value);
    if (value < root->data)
        root->left = add(root->left, value);
    else
        root->right = add(root->right, value);
    return root;
}

// Function to populate the BST
TreeNode* populateTree(const vector<int>& data) {
    TreeNode* root = nullptr;
    for (int value : data)
        root = add(root, value);
    return root;
}

// Function for post-order traversal
void postOrder(TreeNode* root, vector<int>& result) {
    if (!root) return;
    postOrder(root->left, result);
    postOrder(root->right, result);
    result.push_back(root->data);
}

// Function for pre-order traversal
void preOrder(TreeNode* root, vector<int>& result) {
    if (!root) return;
    result.push_back(root->data);
    preOrder(root->left, result);
    preOrder(root->right, result);
}

// Main function
int main() {
    // Given data
    vector<int> data = {55, 78, 87, 25, 28, 56, 2, 99, 41, 13, 9, 1, 70, 16, 79};

    // Step 1: Build BST
    TreeNode* bst = populateTree(data);
    cout << "Binary Search Tree built successfully.\n";

    // Step 2: Post-order traversal
    vector<int> postOrderResult;
    postOrder(bst, postOrderResult);
    cout << "Post-order Traversal: ";
    for (int val : postOrderResult)
        cout << val << " ";
    cout << endl;

    // Step 3: Min-Heap using "Insert" method
    MinHeap minHeapInsert;
    for (int val : postOrderResult)
        minHeapInsert.insert(val);
    cout << "Min-Heap (Insert method): ";
    minHeapInsert.display();

    // Step 4: Pre-order traversal
    vector<int> preOrderResult;
    preOrder(bst, preOrderResult);
    cout << "Pre-order Traversal: ";
    for (int val : preOrderResult)
        cout << val << " ";
    cout << endl;

    // Step 5: Min-Heap using "BuildHeap" method
    MinHeap minHeapBuild;
    minHeapBuild.buildHeap(preOrderResult);
    cout << "Min-Heap (BuildHeap method): ";
    minHeapBuild.display();

    return 0;
}
