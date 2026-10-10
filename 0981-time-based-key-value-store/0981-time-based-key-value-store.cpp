class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> store;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto it = store.find(key);

        if (it == store.end()) {
            return "";
        }
        const auto& entries = it->second;
        int left = 0;
        int right = entries.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (entries[mid].first <= timestamp) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (left == 0) {
            return "";
        }
        return entries[left - 1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */