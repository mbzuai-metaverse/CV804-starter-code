/* Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above notice and this permission notice shall be included in all copies
 * or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
/* File for "Putting It All Together" lesson of the OpenGL tutorial on
 * www.videotutorialsrock.com
 */



#include <math.h>
#include "vec3d.h"

using namespace std;

Vec3d::Vec3d() {}

Vec3d::Vec3d(double x, double y, double z) {
	v[0] = x;
	v[1] = y;
	v[2] = z;
}

double &Vec3d::operator[](int index) {
	return v[index];
}

double Vec3d::operator[](int index) const {
	return v[index];
}

Vec3d Vec3d::operator*(double scale) const {
	return Vec3d(v[0] * scale, v[1] * scale, v[2] * scale);
}

Vec3d Vec3d::operator/(double scale) const {
	return Vec3d(v[0] / scale, v[1] / scale, v[2] / scale);
}

Vec3d Vec3d::operator+(const Vec3d &other) const {
	return Vec3d(v[0] + other.v[0], v[1] + other.v[1], v[2] + other.v[2]);
}

Vec3d Vec3d::operator-(const Vec3d &other) const {
	return Vec3d(v[0] - other.v[0], v[1] - other.v[1], v[2] - other.v[2]);
}

Vec3d Vec3d::operator-() const {
	return Vec3d(-v[0], -v[1], -v[2]);
}

const Vec3d &Vec3d::operator*=(double scale) {
	v[0] *= scale;
	v[1] *= scale;
	v[2] *= scale;
	return *this;
}

const Vec3d &Vec3d::operator/=(double scale) {
	v[0] /= scale;
	v[1] /= scale;
	v[2] /= scale;
	return *this;
}

const Vec3d &Vec3d::operator+=(const Vec3d &other) {
	v[0] += other.v[0];
	v[1] += other.v[1];
	v[2] += other.v[2];
	return *this;
}

const Vec3d &Vec3d::operator-=(const Vec3d &other) {
	v[0] -= other.v[0];
	v[1] -= other.v[1];
	v[2] -= other.v[2];
	return *this;
}

double Vec3d::magnitude() const {
	return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

double Vec3d::magnitudeSquared() const {
	return v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
}

Vec3d Vec3d::normalize() const {
	double m = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	return Vec3d(v[0] / m, v[1] / m, v[2] / m);
}

double Vec3d::dot(const Vec3d &other) const {
	return v[0] * other.v[0] + v[1] * other.v[1] + v[2] * other.v[2];
}

Vec3d Vec3d::cross(const Vec3d &other) const {
	return Vec3d(v[1] * other.v[2] - v[2] * other.v[1],
				 v[2] * other.v[0] - v[0] * other.v[2],
				 v[0] * other.v[1] - v[1] * other.v[0]);
}

Vec3d operator*(double scale, const Vec3d &v) {
	return v * scale;
}


Vec3d Vec3d::operator*(const Vec3d &other) const {
	return Vec3d(v[0] * other.v[0], v[1] * other.v[1], v[2] * other.v[2]);
}

ostream &operator<<(ostream &output, const Vec3d &v) {
	cout << '(' << v[0] << ", " << v[1] << ", " << v[2] << ')';
	return output;
}
