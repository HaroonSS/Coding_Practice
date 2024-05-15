void put(int key_, int value) {
if (m.find(key_) != m.end()) {
node * existingnode = m[key_];
m.erase(key_);
deletenode(existingnode);
}
if (m.size() == cap) {
m.erase(tail -> prev -> key);
deletenode(tail -> prev);
}
​
addnode(new node(key_, value));
m[key_] = head -> next;
}
};
​
/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache* obj = new LRUCache(capacity);
* int param_1 = obj->get(key);
* obj->put(key,value);
*/**