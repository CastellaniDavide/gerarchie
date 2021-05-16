#include <bits/stdc++.h>
#define DEBUG
using namespace std;

struct pp {
    int cultura;
    int index;
    vector <pp> seguaci;
};

int T, N;
vector <int> R, C;
queue <pp*> q;

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
                    cout << "index " << tmp->index << "\t" << i << endl;
                    cout << "cultura " << tmp->cultura << "\t" << C[i] << endl;
                    pp persona2;
                    persona2.cultura = C[i];
                    persona2.index = i;
                    cout << "index " << tmp->index << "\t" << persona2.index << endl;
                    cout << "cultura " << tmp->cultura << "\t" << persona2.cultura << endl;

                    tmp->seguaci.push_back(persona2);
                    q.push(&persona2);
                }
            }
        }
        cout << core.seguaci[0].index;
        cout << core.seguaci[1].index;

        //cout << "Case #" << t + 1 << ": " << sol << endl;
    }
}
