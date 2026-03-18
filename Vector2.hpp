#include <concepts>
#include <cmath>

namespace mjs {

	struct angle_init_tag {};

	template <typename T>
	requires std::is_floating_point<T>::value
	class vector2 {
	public:
		T x;
		T y;

		vector2() : x(0), y(0) {}

		vector2(T x, T y) : x(x), y(y) {}

		vector2(auto arg, auto mag, angle_init_tag) {

			x = mag * std::cos(arg);
			y = mag * std::sin(arg);
		}

		vector2 operator+ (const vector2& _right) {

			return vector2(x + _right.x, y + _right.y);
		}

		template <typename Tr>
		requires std::is_floating_point<Tr>::value || std::is_integral<Tr>::value
		vector2 operator* (Tr _right) {

			return vector2(x * _right, y * _right);
		}

		vector2 invert() const {

			return vector2(x * -1.f, y * -1.f);
		}

		auto magnitude() const {

			return std::sqrt(x * x + y * y);
		}
	};

	using vector2f = vector2<float>;
	using vector2d = vector2<double>;

}