
template <typename T1, typename T2>
class Pair {
private:
	T1 data1;
	T2 data2;
public:
	Pair(T1 data1, T2 data2) : data1(data1), data2(data2) {};

	T1 get_data1() {
		return data1;
	}
	T2 get_data2() {
		return data2;
	}
	void set_data1(T1 data1) {
		this->data1 = data1;
	}
	void set_data2(T2 data2) {
		this->data2 = data2;
	}
};