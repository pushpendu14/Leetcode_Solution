/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start
class LFUCache {
public:
    class Node{
        public:
        int key,value;
        Node* next;
        Node* prev;
        Node(int k, int v){
            key=k;
            value=v;
            next=nullptr;
            prev=nullptr;
        }
    };
    unordered_map<int, Node*> map;
    unordered_map<int, int> count;

    int limit;
    Node* head,*tail;
    LFUCache(int capacity) {
        limit=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    void insertNode(Node *newNode){
        Node *nextNode=head->next;
        head->next=newNode;
        nextNode->prev=newNode;
        newNode->next=nextNode;
        newNode->prev=head;

    }

    void deleteNode(Node *newNode){
        Node *prevNode=newNode->prev;
        Node *nextNode=newNode->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    
    int get(int key) {
        if(map.find(key) != map.end()){
            Node *tbd=map[key];
            deleteNode(tbd);
            insertNode(tbd);
            count[key]++;
            return tbd->value;
        }
        return -1;
    }
    
    void put(int key, int value) {

        if(map.find(key) != map.end()){
            Node *tbd=map[key];
            deleteNode(tbd);
            Node *newNode=new Node(key,value);
            map[key]=newNode;
            count[key]++;
            insertNode(newNode);
        }else{

            if(map.size()==limit){
                int minfreq=INT_MAX;
                for(auto x :  count){
                    if(x.second <minfreq){
                        minfreq=x.second;
                    }
                }
                Node* curr = tail->prev;
                while(curr != head){
                    if(count[curr->key] == minfreq)
                        break;
                    curr = curr->prev;
                }
                map.erase(curr->key);
                count.erase(curr->key);
                deleteNode(curr);
                delete curr;
            }
            Node *newNode=new Node(key,value);
            count[key]=1;
            map[key]=newNode;
            insertNode(newNode);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

