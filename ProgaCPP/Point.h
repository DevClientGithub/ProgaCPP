#pragma once

#include <vector>
#include <cmath>
#include <string>

struct Point {
    double x;
    double y;
    std::string name;

    Point(double _x, double _y, const std::string& _name = "") : x(_x), y(_y), name(_name) {}

    double distanceTo(const Point& other) const {
        double dx = other.x - x;
        double dy = other.y - y;
        return std::sqrt(dx * dx + dy * dy);
    }

    static Point findPointByName(const std::vector<Point>& points, const std::string& name) {
        for (const Point& p : points) {
            if (p.name == name) {
                return p;
            }
        }
        return Point(0.0, 0.0);
    }

    static Point getPointByIndex(const std::vector<Point>& points, size_t index) {
        if (index < points.size()) {
            return points[index];
        }
        return Point(0.0, 0.0);
    }

    static std::vector<Point> smoothPoints(const std::vector<Point>& points, int smoothingFactor) {
        std::vector<Point> smoothed;
        for (size_t i = 0; i < points.size() - 1; ++i) {
            smoothed.push_back(points[i]);
            for (int j = 1; j <= smoothingFactor; ++j) {
                double ratio = static_cast<double>(j) / (smoothingFactor + 1);
                double smoothX = points[i].x * (1 - ratio) + points[i + 1].x * ratio;
                double smoothY = points[i].y * (1 - ratio) + points[i + 1].y * ratio;
                smoothed.emplace_back(smoothX, smoothY);
            }
        }
        smoothed.push_back(points.back());
        return smoothed;
    }

    static std::vector<Point> connectPoints(const std::vector<Point>& points, int connectionType) {
        std::vector<Point> connected;
        connected.push_back(points[0]);

        for (size_t i = 1; i < points.size(); ++i) {
            connected.push_back(points[i]);

            if (connectionType > 0) {
                int numSegments = connectionType + 1;
                for (int j = 1; j <= numSegments; ++j) {
                    double ratio = static_cast<double>(j) / numSegments;
                    double connX = points[i - 1].x * (1 - ratio) + points[i].x * ratio;
                    double connY = points[i - 1].y * (1 - ratio) + points[i].y * ratio;
                    connected.emplace_back(connX, connY);
                }
            }
        }

        return connected;
    }
};