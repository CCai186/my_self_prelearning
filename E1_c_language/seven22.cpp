#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
	a = abs(a);
	b = abs(b);
	while(b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

struct rational {
	int num;
	int den;
};

int get_num(struct rational r) { return r.num; }
int get_den(struct rational r) { return r.den; }

struct rational make_rational(int num, int den) {
	struct rational r;
	int g = gcd(num, den);
	r.num = num / g;
	r.den = den / g;
	if(r.den < 0) {
		r.num = -r.num;
		r.den = -r.den;
	}
	return r;
}

struct rational add_rational(struct rational a, struct rational b) {
	int an = get_num(a), ad = get_den(a);
	int bn = get_num(b), bd = get_den(b);
	int new_num = an * bd + bn * ad;
	int new_den = ad * bd;
	return make_rational(new_num, new_den);
}

struct rational sub_rational(struct rational a, struct rational b) {
	int an = get_num(a), ad = get_den(a);
	int bn = get_num(b), bd = get_den(b);
	int new_num = an * bd - bn * ad;
	int new_den = ad * bd;
	return make_rational(new_num, new_den);
}

struct rational mul_rational(struct rational a, struct rational b) {
	int an = get_num(a), ad = get_den(a);
	int bn = get_num(b), bd = get_den(b);
	int new_num = an * bn;
	int new_den = ad * bd;
	return make_rational(new_num, new_den);
}

struct rational div_rational(struct rational a, struct rational b) {
	int an = get_num(a), ad = get_den(a);
	int bn = get_num(b), bd = get_den(b);
	int new_num = an * bd;
	int new_den = ad * bn;
	return make_rational(new_num, new_den);
}

void print_rational(struct rational r) {
	int num = get_num(r);
	int den = get_den(r);
	if(den == 1) {
		printf("%d\n", num);
		printf("%d/%d\n", num, den);
	}
}

int main(void)
{
	struct rational a = make_rational(1, 8);
	struct rational b = make_rational(-1, 8);
	printf("a+b = "); print_rational(add_rational(a, b));
	printf("a-b = "); print_rational(sub_rational(a, b));
	printf("a*b = "); print_rational(mul_rational(a, b));
	printf("a/b = "); print_rational(div_rational(a, b));
	return 0;
}