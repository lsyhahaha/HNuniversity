#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// 结构体表示活动
struct Activity {
    char id;
    int duration;
    vector<char> dependencies; // 依赖的活动
    int es, ls; // 最早开始时间和最晚开始时间

    Activity(char i, int d) : id(i), duration(d), es(0), ls(0) {}
};

class ProjectNetwork {
public:
    // 添加活动
    void addActivity(char id, int duration, const vector<char>& dependencies) {
        activities.push_back(Activity(id, duration));
        activities.back().dependencies = dependencies;
    }

    // 计算最早开始时间
    void calculateES() {
        stack<char> s;
        for (const auto& activity : activities) {
            if (inDegree[activity.id] == 0) {
                s.push(activity.id);
            }
        }

        while (!s.empty()) {
            char current = s.top();
            s.pop();

            for (const auto& dependency : activities[current - 'A'].dependencies) {
                inDegree[dependency]--;
                if (inDegree[dependency] == 0) {
                    s.push(dependency);
                }

                activities[current - 'A'].es = max(activities[current - 'A'].es,
                                                    activities[dependency - 'A'].es +
                                                    activities[dependency - 'A'].duration);
            }
        }
    }

    // 计算最晚开始时间
    void calculateLS() {
        for (const auto& activity : activities) {
            activities.back().ls = activities.back().es;
        }

        for (int i = activities.size() - 2; i >= 0; --i) {
            for (const auto& dependency : activities[i].dependencies) {
                activities[i].ls = min(activities[i].ls,
                                       activities[dependency - 'A'].ls -
                                       activities[i].duration);
            }
        }
    }

    // 计算关键路径
    void calculateCriticalPath() {
        for (const auto& activity : activities) {
            if (activity.es == activity.ls) {
                criticalPath.push_back(activity.id);
            }
        }
    }

    // 输出关键路径
    void printCriticalPath() {
        cout << "Critical Path: ";
        for (const auto& activity : criticalPath) {
            cout << activity << " ";
        }
        cout << endl;
    }

private:
    vector<Activity> activities;
    vector<char> criticalPath;
    vector<int> inDegree = vector<int>(26, 0); // 用于拓扑排序的入度数组
};

int main() {
    ProjectNetwork project;

    // 添加活动，示例中使用的是一个简单的项目网络图
    project.addActivity('A', 3, {});
    project.addActivity('B', 5, {'A'});
    project.addActivity('C', 2, {'A'});
    project.addActivity('D', 4, {'B', 'C'});
    project.addActivity('E', 6, {'D'});

    // 计算最早开始时间
    project.calculateES();

    // 计算最晚开始时间
    project.calculateLS();

    // 计算关键路径
    project.calculateCriticalPath();

    // 输出关键路径
    project.printCriticalPath();

    return 0;
}
