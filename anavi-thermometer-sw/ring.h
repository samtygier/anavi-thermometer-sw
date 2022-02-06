#include <cstddef>
#include <array>
#include <cassert>

template<class T, std::size_t N>
class ringbuffer
{
	private:
		std::array<T, N> store;
		std::size_t next = 0;
		std::size_t size = 0;
	public:
		ringbuffer(){
			store.fill(0);
			};
		std::size_t len() const {return size;};
		void put(T x);
		T get(size_t x) const;
};

template<class T, std::size_t N>
void ringbuffer<T, N>::put(T x)
{
	assert(next < N);
	store[next] = x;
	next = (next + 1) % N;
	if (size < N) size++;
}

template<class T, std::size_t N>
T ringbuffer<T, N>::get(std::size_t n) const
{
	assert(n < N);
	return store[(next + n) % N];
}
