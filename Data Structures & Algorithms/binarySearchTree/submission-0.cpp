class TreeNode {
public:
    int key;
    int value;
    TreeNode* left;
    TreeNode* right;


    TreeNode (int key, int value) {
        this->key = key;
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class TreeMap {

public:
    TreeNode* root;
    TreeMap() {
        root = nullptr;
    }

    void insert(int key, int val) {
        TreeNode* temp = new TreeNode(key, val);

        if (!root) {
            root = temp;
            return;
        }
        TreeNode* prev;
        TreeNode* curr = root;
        bool left;

        while (curr) {
            if (key < curr->key) {
                prev = curr;
                curr = curr->left;
                left = true;
            }
            else if (key > curr->key) {
                prev = curr;
                curr = curr->right;
                left = false;
            }
            else {
                curr->value = val;
                return;
            }
        }
        if (left) {
            prev->left = temp;
        }
        else {
            prev->right = temp;
        }
    }

    int get(int key) {
        if (!root) {
            return -1;
        }

        TreeNode* curr = root;
        while(curr) {
            if (key > curr->key) {
                curr = curr->right;
            }
            else if (key < curr->key) {
                curr = curr->left;
            }
            else {
                return curr->value;
            }
        }
        return -1;
    }

    int getMin() {
        if (!root) {
            return -1;
        }

        TreeNode* curr = root;
        while(curr && curr->left) {
            curr = curr->left;
        }
        return curr->value;
    }

    int getMax() {
        if (!root) {
            return -1;
        }

        TreeNode* curr = root;
        while(curr && curr->right) {
            curr = curr->right;
        }
        return curr->value;
    }

    void remove(int key) {
        root = removeRecursive(root, key);
    }

    std::vector<int> getInorderKeys() {
        vector<int> result;
        return getInorderKeysRecursive(root, result);
    }

private:
    TreeNode* getMinKeyNode(TreeNode* root1) {
        if (!root1) {
            return nullptr;
        }

        TreeNode* curr = root1;
        while(curr && curr->left) {
            curr = curr->left;
        }
        return curr;
    }

    TreeNode* removeRecursive(TreeNode* root1, int key) {
        if (!root1) {
            return nullptr;
        }

        
        if (key > root1->key) {
            root1->right= removeRecursive(root1->right, key);
        }
        else if (key < root1->key) {
            root1->left= removeRecursive(root1->left, key);
        }
        else {
            if (!root1->left) {
                return root1->right;
            }
            else if (!root1->right) {
                return root1->left;
            }
            else {
                TreeNode* mintemp = getMinKeyNode(root1->right);
                root1->key = mintemp->key;
                root1->value = mintemp->value;
                root1->right = removeRecursive(root1->right, mintemp->key);
            }
        }
        return root1;
    }

    vector<int> getInorderKeysRecursive(TreeNode* root1, vector<int>& result) {
        if (!root1) {
            return result;
        }
        getInorderKeysRecursive(root1->left, result);
        result.push_back(root1->key);
        getInorderKeysRecursive(root1->right, result);
        return result;
    }
};
