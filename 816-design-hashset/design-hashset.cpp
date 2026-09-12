class MyHashSet {
public:
    vector<bool> present;
    MyHashSet() {
        present.resize(1000001, false);
    }
    void add(int key) {
        present[key] = true;
    }
    void remove(int key) {
        present[key] = false;
    }
    bool contains(int key) {
        return present[key];
    }
};