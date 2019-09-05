#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

#define pr(s) {cout << #s << " = " << (s) << endl;}

struct Row {
    Row(double debt, double q, double m):
        debt(debt),
        percent(q * debt),
        x(m - percent) {}
    double debt;
    double percent;
    double x;
    auto m() const {
        return x + percent;
    }
    auto newDebt() const {
        const auto result = debt - x;
        if (std::abs(result) < 1e-6) {
            return 0.0;
        }
        return result;
    }
};

using Plan = vector<Row>;

double getQ(double p) {
    return p / 1200;
}

double getZ(double q, int n) {
    return std::pow(1 + q, n);
}

double getM(double s, double p, int n) {
    const auto q = getQ(p);
    const auto z = getZ(q, n);
    return s * z * q / (z - 1);
}

Plan getPlan(double s, double p, int n) {
    const auto m = getM(s, p, n);
    const auto q = getQ(p);
    Plan result;
    result.emplace_back(s, q, m);
    for (int i = 1; i < n; ++i) {
        result.emplace_back(result[i - 1].newDebt(), q, m);
    }
    return result;
}

double getAllPercent(const Plan& plan) {
    double result = 0.0;
    for (const auto& pay : plan) {
        result += pay.percent;
    }
    return result;
}

double getAllX(const Plan& plan) {
    double result = 0.0;
    for (const auto& pay : plan) {
        result += pay.x;
    }
    return result;
}

void printPlan(const Plan& plan) {
    {int i = 1; for (const auto& pay : plan) {
        cout <<
            setw(3) << i <<
            setw(10) << pay.debt <<
            setw(10) << pay.percent <<
            setw(10) << pay.x <<
            setw(10) << pay.m() <<
            setw(10) << pay.newDebt() <<
            endl;
            ;
        ++i;
    }}
    const auto fillChar = cout.fill();
    cout << setfill('-') << setw(53) << "" << endl << setfill(fillChar);
    cout <<
        setw(3) << "all" <<
        setw(10) << "" <<
        setw(10) << getAllPercent(plan) <<
        setw(10) << getAllX(plan) <<
        setw(10) << "" <<
        setw(10) << "" <<
        endl;
}

int main() {
    while (1) {
        double s;
        double p;
        cin >> s >> p;

        const auto q = getQ(p);

        pr(s);
        pr(p);
        pr(s * q);

        int n1, n2, step;
        cin >> n1 >> n2 >> step;
        for (int i = n1; i <= n2; i += step) {
            const auto mi = getM(s, p, i);
            cout << setw(4) << i <<
                setw(10) << mi <<
                setw(10) << mi * i <<
                setw(10) << mi * i - s <<
                setw(10) << s / mi << endl;
        }

        int n;
        cin >> n;
        printPlan(getPlan(s, p, n));
    }
}
