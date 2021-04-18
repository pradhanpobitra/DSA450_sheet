#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

void dfs(int i,bool vis[],vector<int> edges[],int &composize) {
    vis[i] = true;
    composize++;
    for(int x : edges[i]) {
        if(!vis[x]) dfs(x,vis,edges,composize);
    }
}

// Complete the journeyToMoon function below.
long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    bool vis[n] = {false};
    int i;
    vector<int> componentSizes;
    vector<int> edges[n];
    for(vector<int> x : astronaut) {
        edges[x[0]].push_back(x[1]);
        edges[x[1]].push_back(x[0]);
    }
    for(i=0;i<n;i++) {
        if(!vis[i]) {
            int composize = 0;
            dfs(i,vis,edges,composize);
            componentSizes.push_back(composize);
        }
    }
    long long sum = 0;
    for(int x : componentSizes) {
        sum += (long long) x * (n-x);
    }
    sum /= 2;
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long long result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
