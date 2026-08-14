class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {

    int n = s.size();

    struct Node {
        int pref;
        int suff;
        int best;
        int len;
        char left;
        char right;
    };

    vector<Node> tree(4 * n);

    auto merge = [](Node a, Node b) {

        Node res;

        res.len = a.len + b.len;
        res.left = a.left;
        res.right = b.right;

        // Prefix
        res.pref = a.pref;

        if (a.pref == a.len && a.right == b.left) {
            res.pref = a.len + b.pref;
        }

        // Suffix
        res.suff = b.suff;

        if (b.suff == b.len && a.right == b.left) {
            res.suff = b.len + a.suff;
        }

        // Best
        res.best = max(a.best, b.best);

        // A repeating sequence crossing the middle
        if (a.right == b.left) {
            res.best = max(res.best, a.suff + b.pref);
        }

        return res;
    };

    function<void(int, int, int)> build =
        [&](int node, int l, int r) {

        if (l == r) {
            tree[node] = {1, 1, 1, 1, s[l], s[l]};
            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    };

    function<void(int, int, int, int, char)> update =
        [&](int node, int l, int r, int pos, char ch) {

        if (l == r) {
            tree[node] = {1, 1, 1, 1, ch, ch};
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid) {
            update(2 * node, l, mid, pos, ch);
        }
        else {
            update(2 * node + 1, mid + 1, r, pos, ch);
        }

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    };

    build(1, 0, n - 1);

    vector<int> ans;

    for (int i = 0; i < queryIndices.size(); i++) {

        int index = queryIndices[i];
        char ch = queryCharacters[i];

        s[index] = ch;

        update(1, 0, n - 1, index, ch);

        ans.push_back(tree[1].best);
    }

    return ans;
}
};