#include <bits/stdc++.h>
using namespace std;

struct Circle {
    int x, y, r;
};

double circleDistance(const Circle &a, const Circle &b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void solveCircleProblem() {
    cout << "=== BAI 1: DUONG DI GIUA CAC HINH TRON ===\n";
    int n;
    cin >> n;
    vector<Circle> circles(n);
    for (int i = 0; i < n; ++i)
        cin >> circles[i].x >> circles[i].y >> circles[i].r;

    vector<vector<pair<int, double>>> graph(n);
    
    // Tạo đồ thị
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            double d = circleDistance(circles[i], circles[j]);
            if (d <= circles[i].r + circles[j].r) {
                graph[i].push_back({j, d});
                graph[j].push_back({i, d});
            }
        }
    }

    // Dijkstra
    vector<double> dist(n, 1e9);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, w] : graph[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[n-1] == 1e9)
        cout << "Khong co duong di.\n";
    else
        cout << "Khoang cach ngan nhat: " << fixed << setprecision(2) << dist[n-1] << "\n";
}


const int INF = 1e9;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solveMintableProblem() {
    cout << "\n=== BAI 2: DUONG DI TRONG BANG ===\n";
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (auto &row : grid)
        for (auto &cell : row)
            cin >> cell;

    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;

    vector<vector<int>> dist(n, vector<int>(m, INF));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    dist[sx][sy] = grid[sx][sy];
    pq.push({dist[sx][sy], sx, sy});

    while (!pq.empty()) {
        auto [cost, x, y] = pq.top(); pq.pop();
        if (x == ex && y == ey) break;

        if (cost > dist[x][y]) continue;

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                int newCost = cost + grid[nx][ny];
                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({newCost, nx, ny});
                }
            }
        }
    }

    if (dist[ex][ey] == INF)
        cout << "Khong co duong di.\n";
    else
        cout << "Chi phi nho nhat: " << dist[ex][ey] << "\n";
}


int main() {
    int choice;
    cout << "Chon bai muon chay:\n";
    cout << "1. Bai 1 - CIRCLE\n";
    cout << "2. Bai 2 - MINTABLE\n";
    cout << "Lua chon cua ban: ";
    cin >> choice;

    if (choice == 1)
        solveCircleProblem();
    else if (choice == 2)
        solveMintableProblem();
    else
        cout << "Lua chon khong hop le!\n";

    return 0;
}
