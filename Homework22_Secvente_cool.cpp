#include <iostream>
#include <vector>
#include <optional>

//Face chemarea functiei is_coolSequence() si daca avem std::nullopt, returnam numarul de elemente 
size_t coolSequence(const std::vector<size_t>& vector, const size_t& K);


int main()
{
	size_t size_v; //nr de elemente din sir
	size_t size_c; //nr de elemente dintr-o secventa cool

	std::cout << "Introduce-ti doar numere pozitive!" << std::endl;
	std::cout << "Introdu numarul de elemente care vor fi stocate in sir: "; 
	std::cin >> size_v; 

	std::cout << "Introdu numarul de elemente ce trebuie sa contina o secventa cool: "; 
	std::cin >> size_c; 

	std::vector<size_t> vector(size_v); 

	std::cout << "Introdu elementele din sir: " << std::endl;
	for (size_t i{}; i < size_v; ++i)
	{
		std::cout << "vector.at(" << i << ") = "; 
		std::cin >> vector.at(i); 
	}

	std::cout << std::endl;
	std::cout << coolSequence(vector, size_c);
}
