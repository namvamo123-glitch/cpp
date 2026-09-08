#include <bits/stdc++.h>
using namespace std;

int main() {
    const int width = 80;
    const int height = 25;
    const int max_iter = 1000;

    // Area of the complex plane to render
    const double x_min = -2.5;
    const double x_max = 1.0;
    const double y_min = -1.0;
    const double y_max = 1.0;

    // Characters from "dense" to "sparse" (you can tweak)
    const string gradient = "@%#*+=-:. ";
    const int gsize = (int)gradient.size();

    ios::sync_with_stdio(false);

    for (int row = 0; row < height; ++row) {
        double y = y_max - (double)row * (y_max - y_min) / (height - 1);
        for (int col = 0; col < width; ++col) {
            double x = x_min + (double)col * (x_max - x_min) / (width - 1);
            complex<double> c(x, y);
            complex<double> z(0.0, 0.0);
            int iter = 0;
            while (abs(z) <= 2.0 && iter < max_iter) {
                z = z * z + c;
                ++iter;
            }

            char out;
            if (iter >= max_iter) {
                out = ' ';
            } else {
                int idx = (int)((double)iter / (double)max_iter * (gsize - 1));
                // clamp
                if (idx < 0) idx = 0;
                if (idx >= gsize) idx = gsize - 1;
                out = gradient[idx];
            }
            cout << out;
        }
        cout << '\n';
    }

    return 0;
}
