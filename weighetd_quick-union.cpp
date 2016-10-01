#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /* classic example of weighted quick union-find algorithm. The idea here is to process each
    edge and check if edge attemts to connect already connected nodes. */
    vector<int> uf;
    vector<int> sz;

    bool find(int i, int j) {
        while (uf[i] != i)
            i = uf[i];
        while (uf[j] != j)
            j = uf[j];
        return i == j;
    }

    void Union(int i, int j) {
        int ir = i, jr = j;
        while (uf[ir] != ir)
            ir = uf[ir];
        while (uf[jr] != jr)
            jr = uf[jr];
        if (ir == jr)
            return;

        if (sz[i] > sz[j]) { // merge j tree in i
            uf[jr] = ir; // change root of j tree
            sz[ir] += sz[jr]; // update size of i tree
            sz[jr] = 0; // zero size of j tree (it has moved)
        } else { // merge i tree in j
            uf[ir] = jr;
            sz[jr] += sz[ir];
            sz[ir] = 0;
        }
    }
    bool validTree(int n, vector<pair<int, int> >& edges) {
        for (int i = 0; i < n; i++) {
            uf.push_back(i); // each node is it's own root in begining
            sz.push_back(1); // each is of size 1 in beginning
        }
        for (auto edge : edges) {
            if (find(edge.first, edge.second))
                return false;
            else
                Union(edge.first, edge.second);
        }
        return true;
    }
};


