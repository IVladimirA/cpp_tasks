#include <array>
#include <ctime>
#include <iostream>
#include <vector>

struct Point {
    double x;
    double y;

    Point() {}
    Point(double nx, double ny) : x(nx), y(ny) {}
};

struct Circle {
    double radius;
    Point center;
    Circle() {}

    Circle(double rad) : radius(rad), center(0, 0) {}

    bool covers(const Point& p) {
        return (p.x - center.x) * (p.x - center.x) + (p.y - center.y) * (p.y - center.y) < radius * radius;
    }
};

struct Target {
    std::vector<Circle> circles;
    std::vector<uint64_t> scores;
    Circle block;

    void setCenters(const Point& p) {
        for (Circle& circle: circles) {
            circle.center = p;
        }
    }

    uint64_t getScore(const Point& p) {
        if (block.covers(p)) {
            return 0;
        }
        for (size_t i = 0; i < circles.size(); ++i) {
            if (circles[i].covers(p)) {
                return scores[i];
            }
        }
        return 0;
    }
};

int main()
{
    using namespace std;

    srand(time(NULL));

    uint64_t score = 0;
    std::array<Target, 2> targets;
    targets[0].circles = {{1}, {2}};
    targets[0].scores = {10, 5};
    targets[1].circles = {{1}, {2}, {3}};
    targets[1].scores = {10, 5, 1};
    cout << "Choose target (1 or 2): ";
    size_t targetType;
    cin >> targetType;
    --targetType;
    Circle block{3};
    block.center = {3.0 + rand() % 5, 3.0 + rand() % 5};
    Point targetCenter{3.0 + rand() % 5, 3.0 + rand() % 5};
    targets[targetType].setCenters(targetCenter);
    cout << "Enter required score: ";
    uint64_t requiredScore;
    cin >> requiredScore;
    cout << "Enter max shot count: ";
    uint64_t shots;
    cin >> shots;
    uint64_t shotCount = 0;
    for (uint64_t i = 0; i < shots; ++i) {
        cout << "Enter coordinates of shot \"x y\": ";
        Point shot;
        cin >> shot.x >> shot.y;
        score += targets[targetType].getScore(shot);
        cout << "Current score: " << score << '\n';
        if (score >= requiredScore) {
            shotCount = i + 1;
            break;
        }
    }   
    cout << "Shot count: " << shotCount << "\nRank: ";
    if (shotCount < 5) {
        cout << "Legend\n";
    } else if (shotCount < 10) {
        cout << "Veteran\n";
    } else if (shotCount < 15) {
        cout << "Mulitary\n";
    } else {
        cout << "Newbie\n";
    }

    return 0;
}