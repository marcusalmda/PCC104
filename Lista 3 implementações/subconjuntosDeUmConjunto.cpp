#include <iostream>
#include <vector>
#include <algorithm>


void print_subsets(const std::vector<std::vector<int>>& power_set) {
	for (size_t i = 0; i < power_set.size(); i++)
	{
		for (size_t j = 0; j < power_set[0].size(); j++)
		{
			if (power_set[i][j] == 1) {
				std::cout << "e" << power_set[0].size()-j << ", ";
			}
		}
		std::cout << std::endl;
	}
	
}

void print_bit_strings(std::vector<std::vector<int>>& power_set) {
	for (size_t i = 0; i < power_set.size(); i++)
	{
		for (size_t j = 0; j < power_set[0].size(); j++)
		{
			std::cout << power_set[i][j] << ", ";
		}
		std::cout << std::endl;
	}

}

std::vector<std::vector<int>> generate_power_set(int n) {
	std::vector<std::vector<int>> power_set;

	if (n == 1) {
		power_set.push_back({ 0 });
		power_set.push_back({ 1 });
	}
	else {
		std::vector<std::vector<int>> L1 = generate_power_set(n - 1);
		std::vector<std::vector<int>> L2 = L1;
		std::reverse(L2.begin(), L2.end());

		for (std::vector<int>& str : L1) {
			str.emplace(str.begin(), 0);
		}

		for (std::vector<int>& str : L2) {
			str.emplace(str.begin(), 1);
		}

		L2.insert(L2.begin(), L1.begin(), L1.end());
		power_set = L2;
	}

	return power_set;

}
int main(){
    std::vector<std::vector<int>> power_set = generate_power_set(3);

	print_bit_strings(power_set);

	print_subsets(power_set);


    return 0;
}