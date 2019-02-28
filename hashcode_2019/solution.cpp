#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <utility>
#include <unordered_map>
#include <cmath>
#include <random>

using namespace std;

#define Score first
#define Diff second

using PhotoKey = pair<size_t, size_t>;

struct Photo {
    size_t Id;
    set<string> Tags;

    Photo(size_t id, set<string>&& tags)
        : Id(id)
        , Tags(move(tags))
    {}
};

struct Counter {
    size_t count = 0;
    struct value_type { template<typename T> value_type(const T&) { } };
    void push_back(const value_type&) {
        ++count;
    }
};

PhotoKey comparePhotos(const Photo& lhs, const Photo& rhs) {
    Counter c;
    std::set_intersection(
        lhs.Tags.begin(), lhs.Tags.end(),
        rhs.Tags.begin(), rhs.Tags.end(),
        std::back_inserter(c)
    );
    int score = min({lhs.Tags.size() - c.count, c.count, rhs.Tags.size() - c.count});
    int diff = abs((int)lhs.Tags.size() - (int)rhs.Tags.size());

    return {score, diff};
}

int main() {
    int n, tagsCount, iidx;
    char type;
    string tag;
    cin >> n;

    vector<Photo> photos;
    vector<set<pair<PhotoKey, size_t>>> photoToPhotos(n);
    map<size_t, string> idxToIdx;
    string indices;
    set<string> tags;

    for (size_t i = 0; i < n; ++i) {
        cin >> type >> iidx >> tagsCount;

        for (size_t i = 0; i < tagsCount; ++i) {
            cin >> tag;
            tags.insert(tag);
        }

        photos.emplace_back(i, move(tags));
        tags.clear();
    }

    for (size_t i = 0; i < n; ++i) {
        cin >> iidx;
        cin.ignore();
        getline(cin, indices);
        idxToIdx[i] = indices;
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i; j < n; ++j) {
            auto key = comparePhotos(photos[i], photos[j]);
            if (key.Score > 0) {
                photoToPhotos[i].emplace(key, j);
            }
        }
        cerr << i << '/' << n << endl;
    }

    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1e6);

    int finalResult = 0;
    vector<size_t> finalOrder;

    for (size_t i = 0; i < 1; ++i) {
        set<size_t> unvisited;

        for (size_t i = 0; i < n; ++i) {
            unvisited.insert(i);
        }

        auto v = unvisited.begin();
        vector<size_t> order;
        bool success;

        while (!unvisited.empty()) {
            success = false;
            order.push_back(*v);
            unvisited.erase(v);

            for (const auto& [key, idx]: photoToPhotos[*v]) {
                auto nv = unvisited.find(idx);
                if (nv != unvisited.end()) {
                    success = true;
                    v = nv;
                    break;
                }
            }

            if (!success) {
                v = unvisited.begin();
//                auto adv = dist(rng);
//
//                if (adv > 0 && unvisited.size() > 0) {
//                    advance(v, adv % unvisited.size());
//                }
            }
        }

        int result = 0;

        for (size_t i = 0; i < order.size(); ++i) {
            if (i < order.size() - 1) {
                result += comparePhotos(photos[order[i]], photos[order[i + 1]]).Score;
            }
        }

        if (result > finalResult) {
            finalResult = result;
            finalOrder = order;
        }
    }

    cout << finalOrder.size() << endl;
    for (size_t i = 0; i < finalOrder.size(); ++i) {
        cout << idxToIdx[finalOrder[i]] << endl;
    }

    cout << endl << finalResult << endl;
//
//    for (size_t i = 0; i < n; ++i) {
//        if (photoToPhotos[i].size() > 0) {
//            cout << i << ' ';
//            for (const auto& [key, idx]: photoToPhotos[i]) {
//                cout << '('<< key.Score << ',' << idx << ')' << endl;
//            }
//        }
//    }

    return 0;
}
