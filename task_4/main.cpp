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

// Function to display the tree structure (In-order Traversal for simplicity)
void displayTree(TreeNode* root) {
    if (!root) return;
    displayTree(root->left);
    cout << root->data << " ";
    displayTree(root->right);
}

// Main function
int main() {
    // Given data
    vector<int> data = {55, 78, 87, 25, 28, 56, 2, 99, 41, 13, 9, 1, 70, 16, 79};
    TreeNode* bst = populateTree(data);
    vector<int> postOrderResult, preOrderResult;
    MinHeap minHeapInsert, minHeapBuild;

    // Display initial BST
    cout << "======================= Initial Binary Search Tree ======================\n";
    cout << "   Tree (In-order Traversal): ";
    displayTree(bst);
    cout << "\n=========================================================================\n";

    int choice;

    do {
        cout << "\n================================== Menu ==================================\n";
        cout << "|                      1. Post-order Traversal of BST                    |\n";
        cout << "|                      2. Build Min-Heap (Insert Method)                 |\n";
        cout << "|                      3. Pre-order Traversal of BST                     |\n";
        cout << "|                      4. Build Min-Heap (BuildHeap Method)              |\n";
        cout << "|                      5. Display Tree (In-order Traversal)              |\n";
        cout << "|                                 6. Exit                                |\n";
        cout << "==========================================================================\n";
        cout << "                            Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            postOrderResult.clear();
            postOrder(bst, postOrderResult);
            cout << "Post-order Traversal: ";
            for (int val : postOrderResult)
                cout << val << " ";
            cout << endl;
            break;

        case 2:
            if (postOrderResult.empty()) {
                cout << "Perform Post-order Traversal first (Option 1).\n";
                break;
            }
            for (int val : postOrderResult)
                minHeapInsert.insert(val);
            cout << "Min-Heap (Insert Method): ";
            minHeapInsert.display();
            break;

        case 3:
            preOrderResult.clear();
            preOrder(bst, preOrderResult);
            cout << "Pre-order Traversal: ";
            for (int val : preOrderResult)
                cout << val << " ";
            cout << endl;
            break;

        case 4:
            if (preOrderResult.empty()) {
                cout << "Perform Pre-order Traversal first (Option 3).\n";
                break;
            }
            minHeapBuild.buildHeap(preOrderResult);
            cout << "Min-Heap (BuildHeap Method): ";
            minHeapBuild.display();
            break;

        case 5:
            cout << "Tree (In-order Traversal): ";
            displayTree(bst);
            cout << endl;
            break;

        case 6:
            cout << "Exiting program. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
