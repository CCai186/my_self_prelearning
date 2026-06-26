#include <stdio.h>
#include <math.h>

enum coordinate_type { RECTANGULAR, POLAR };
struct complex_struct {
	enum coordinate_type t;
	double a, b;
};

struct complex_struct make_from_real_img(double x, double y) {
	struct complex_struct z;
	z.t = RECTANGULAR;
	z.a = x;
	z.b = y;
	return z;
}
struct complex_struct make_from_mag_ang(double r, double A) {
	struct complex_struct z;
	z.t = POLAR;
	z.a = r;
	z.b = A;
	return z;
}

double real_part(struct complex_struct z) {
	if(z.t == RECTANGULAR) {
		return z.a;
	} else {
		return z.a * cos(z.b);
	}
}

double img_part(struct complex_struct z) {
	if(z.t == RECTANGULAR) {
		return z.b;
	} else {
		return z.a * sin(z.b);
	}
}

double magnitude(struct complex_struct z) {
	if(z.t == RECTANGULAR) {
		return sqrt(z.a*z.a + z.b*z.b);
	} else {
		return z.a;
	}
}

double angle(struct complex_struct z) {
	if(z.t == RECTANGULAR) {
		return atan2(z.b, z.a);
	} else {
		return z.b;
	}
}

void print_complex(struct complex_struct z) {
	double real = real_part(z);
	double img = img_part(z);
	if(img == 0) {
		printf("%g\n", real);
	} else if(real == 0) {
		printf("%gi\n", img);
	} else {
		if(img > 0) {
			printf("%g+%gi\n", real, img);
		} else {
			printf("%g-%gi\n", real, -img);
		}
	}
}

struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2) {
	return make_from_real_img(real_part(z1)+real_part(z2), img_part(z1)+img_part(z2));
}

int main(void) {
	struct complex_struct z1 = make_from_real_img(3, 4);
	printf("直角存储的z1：\n");
	printf("实部=%g, 虚部=%g, 模=%g, 角度=%g\n", 
		real_part(z1), img_part(z1), magnitude(z1), angle(z1));

	struct complex_struct z2 = make_from_mag_ang(5, atan2(4, 3));
	printf("\n极坐标存储的z2：\n");
	printf("实部=%g, 虚部=%g, 模=%g, 角度=%g\n", 
		real_part(z2), img_part(z2), magnitude(z2), angle(z2));

	printf("\nz1+z2 = "); 
	print_complex(add_complex(z1, z2));
	return 0;
}