/*
很简单的LRU，但是自己面试的时候写的是另一个算法，腾讯面试官并不认账
*/

class LRUCache {
public:
    class Node{
    public:
        Node* left;
        Node* right;
        int v;
        int k;
    };

    Node* begin = nullptr;
    Node* end = nullptr;
    int size = 0;
    int capacity = 0;

    unordered_map<int, Node*> ketToNode = unordered_map<int ,Node*>();
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = ketToNode.find(key);
        Node* node = it != ketToNode.end() ? it->second : nullptr;
        if (node != nullptr) {
            remove(node);

            back(node);
            return node->v;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = ketToNode.find(key);
        Node* node = it != ketToNode.end() ? it->second : nullptr;
        if (node != nullptr) {
            // find
            node ->v = value;

            remove(node);

            back(node);
        }
        else {
            //not find

            if (size >= capacity) {
                Node* needRemove = begin;

                if (needRemove != nullptr) {
                    -- size;
                    ketToNode.erase(needRemove->k);
                    remove(needRemove);
                    delete needRemove;
                }
            }
            
            Node* node = new Node();
            node->v = value;
            node->k = key;

            back(node);
            ++size;

            ketToNode[key] = node;
        }
    }

    void remove(Node* node) {
        Node* l = node->left;
        Node* r = node->right;

        if (l != nullptr && r!=nullptr) {
            l->right = r;
            r->left = l;
        } else if(l != nullptr) {
            l->right = r;
        } else if(r != nullptr) {
            r->left = l;
        }

        if (node->right == nullptr) {
            end = node->left;
        }
        if (node->left == nullptr) {
            begin = node->right;
        }
    }

    void back(Node* node) {
        Node* oldEnd = this->end;

        if (oldEnd !=nullptr) {
            oldEnd->right = node;
            node->left = oldEnd;
            node->right = nullptr;
            
            this->end = node;
        } else {
            this->begin = this->end = node;
            node->left = node->right = nullptr;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */