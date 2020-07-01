#include <iostream>
#include <array>

int main()
{
	constexpr unsigned size = 1000000;
	std::array<bool, size> is_prime;
	is_prime.fill(true);

	for (int i = 2; i < sqrt(size); ++i)
	{
		if (is_prime[i])
			for (int j = i * i; j < size; j += i)
			{
				if (is_prime[j])
					is_prime[j] = false;
			}
	}

	unsigned number;
	while (true)
	{
		std::cout << "input number: ";
		std::cin >> number;
		if (number <= 0 || number >= size) {
			break;
		}
		if (number == 1)
			std::cout << number << " is a universal number" << "\n";
		else if (is_prime[number])
			std::cout << number << " is a prime" << "\n";
		else
			std::cout << number << " is not a prime" << "\n";
	}
}