/*#include <bits/stdc++.h>
#define DEBUG
using namespace std;

struct pp {
    int cultura;
    int index;
    vector <pp> seguaci;
};

int T, N, sol;
vector <int> R, C;
queue <pp*> q;

void analizza (pp p) {
    for (size_t i = 0; i < p.seguaci.size(); ++i)
        if (p.seguaci[i].seguaci.size() != 0)
            analizza(p.seguaci[i]);

    int max_ = p.cultura;

    for (size_t i = 0; i < p.seguaci.size(); ++i)
        if (p.seguaci[i].cultura > max_)
            max_ = p.seguaci[i].cultura;

    if (max_ != p.cultura) {
        sol++;
        p.cultura = max_;
        p.seguaci.empty();
        cout << "Replaced: " << p.index << endl;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
#ifndef DEBUG
    freopen("output.txt", "w", stdout);
#endif // DEBUG

    cin >> T;

    for (size_t t = 0; t < T; ++t) {
        cin >> N;
        R.resize(N);
        C.resize(N);
        sol = 0;
        pp core;

        for(size_t i = 0; i < N; ++i) {
            cin >> R[i] >> C[i];
            if (R[i] == -1) {
                core.cultura = C[i];
                core.index = i;
            }
        }

        q.push(&core);

        while (!q.empty())
        {
            pp* tmp = q.front();
            q.pop();
            cout << endl << endl << tmp->index << endl << endl;

            for(size_t i = 0; i < N; ++i) {
                cout << tmp->index << "\t" << R[i] << endl;
                if (R[i] == tmp->index)
                {
                    // Problema:
                    cout << "index " << tmp->index << "\t" << i << endl;
                    cout << "cultura " << tmp->cultura << "\t" << C[i] << endl;
                    pp persona2;
                    persona2.index = i;
                    persona2.cultura = C[i];
                    cout << "index " << tmp->index << "\t" << persona2.index << endl;
                    cout << "cultura " << tmp->cultura << "\t" << persona2.cultura << endl;

                    tmp->seguaci.push_back(persona2);
                    q.push(&persona2);
                }
            }
        }
        cout << core.seguaci[0].index << endl;
        cout << core.seguaci[1].index << endl;

        analizza(core);

        cout << "Case #" << t + 1 << ": " << sol << endl;
    }
}*/

#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("gerarchie_input_1.txt", "r", stdin);
    freopen("gerarchie_output_1.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        vector<int> parents(N), values(N), value_to_node(N);
        for (int i = 0; i < N; ++i) {
            cin >> parents[i] >> values[i];
        }

        for (int i = 0; i < N; ++i)
            value_to_node[values[i]] = i;

        vector<int> values_order(values.begin(), values.end());
        sort(values_order.begin(), values_order.end(), greater<int>());

        int sol = 0;
        for (int v : values_order) {
            int i = value_to_node[v];
            while (parents[i] != -1 && values[parents[i]] < values[i]) {
                int u = parents[i];
                int vu = values[u];
                // scambio u con i
                value_to_node[vu] = i;
                value_to_node[v] = u;
                values[i] = vu;
                values[u] = v;
                i = u;
                sol++;
            }
        }

        cout << "Case #" << t << ": " << sol << endl;
    }
}
