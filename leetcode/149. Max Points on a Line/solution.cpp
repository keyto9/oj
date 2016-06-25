/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 
 bool collinear(Point a, Point b, Point c) {
    return (a.x - c.x) * (b.y - c.y) == (b.x - c.x) * (a.y - c.y);
 }
 
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int n = points.size();
        if (n <= 2) return n;
        bool flag = false;
        for (int i = 1; i < n; i++) {
            if (points[i-1].x != points[i].x || points[i-1].y != points[i].y)
                flag = true;
        }
        if (!flag) return n;
        int ret = 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || points[i].x == points[j].x && points[i].y == points[j].y) continue;
                int sum = 2;
                for (int k = 0; k < n; k++) {
                    if (i == k || j == k) continue;
                    if (collinear(points[i], points[j], points[k]))
                        sum++;
                }
                ret = max(ret, sum);
            }
        }
        return ret;
    }
};