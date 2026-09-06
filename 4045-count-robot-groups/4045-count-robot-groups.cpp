class Solution {
public:
    struct Event {
        long long num, den; 
        int l, r;
    };

    struct Compare {
        bool operator()(const Event& a, const Event& b) const {
            __int128 left = (__int128)a.num * b.den;
            __int128 right = (__int128)b.num * a.den;

            if (left != right)
                return left > right;

            return a.l > b.l;
        }
    };

    int countGroups(vector<int>& position,
                    vector<int>& speed,
                    int distance) {

        int n = position.size();

        vector<int> prv(n), nxt(n);
        vector<bool> alive(n, true);

        for (int i = 0; i < n; i++) {
            prv[i] = i - 1;
            nxt[i] = (i + 1 < n ? i + 1 : -1);
        }

        priority_queue<Event, vector<Event>, Compare> pq;


        auto addEvent = [&](int l, int r) {
            if (l == -1 || r == -1)
                return;

            long long gap = (long long)position[r] - position[l];

    
            if (gap <= distance) {
                pq.push({0, 1, l, r});
                return;
            }

            long long dv = (long long)speed[l] - speed[r];

            if (dv > 0) {
                long long dt = gap - distance;
                pq.push({dt, dv, l, r});
            }
        };

 
        for (int i = 0; i + 1 < n; i++) {
            addEvent(i, i + 1);
        }

        int groups = n;

        while (!pq.empty()) {
            Event e = pq.top();
            pq.pop();

            int l = e.l;
            int r = e.r;


            if (!alive[l] || !alive[r])
                continue;

            if (nxt[l] != r || prv[r] != l)
                continue;

            alive[l] = false;
            groups--;

            int p = prv[l];

            if (p != -1) {
                nxt[p] = r;
            }

            prv[r] = p;

            if (p != -1) {
                addEvent(p, r);
            }
        }

        return groups;
    }
};