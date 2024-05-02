#include <vector>
#include <optional>
#include <iostream>


//Metoda Insertion Sort 
//Aranjarea elementelor in ordinea crescatoare
static void rearrangement(std::vector<size_t>& vector)
{
    const size_t vectorSize = vector.size(); //Pentru optimizare

    for (int i = 1; i < vectorSize; ++i) {
        size_t key = vector[i];
        int j = i - 1;

        // Elementele mai mari decat key sunt mutate cu o pozitie la dreapta
        while (j >= 0 && vector[j] > key) {
            vector[j + 1] = vector[j];
            j = j - 1;
        }

        // Insereaza key in pozitia corecta
        vector[j + 1] = key;
    }
}



//Daca nu exista subsecventa de lungimea necesar, este returnat std::nullopt
static std::optional<size_t> is_coolSequence(const std::vector<size_t>& input, const size_t K)
{
    const size_t inputSize = input.size(); //Pentru optimizare
    bool flag = false;

    //Valoarea ce va fi returnata
    std::optional<size_t> max = std::nullopt; //Sirul nu poate contine valori nule
    //Daca nu sa gasit nici un subsir cool - returnam std::nullopt

    std::vector<size_t> seq;

    for (size_t i{}; i < inputSize; i++)
    {
        //Secventa nu poate sa inceapa de la indice mai mare decat 'inputSize - K'
        if (inputSize - i >= K)
        {
            std::cout << "secventa noua" << std::endl;
            //Incepand de la indexul i, stocam in 'seq' K elemente ce urmeaza in vectorul 'input'
            for (size_t k{ i }; k < i + K; k++)
            {
                seq.push_back(input.at(k));
            }

            //Aranjam secventa 'seq' in ordinea crescatoare
            rearrangement(seq);

            size_t seqSize = seq.size(); //Size-ul este salvat intr-o variabila pentru a nu consuma resurse suplimentare
                                         //la fiecare chemare a metodei 'size()'


            for (size_t k{ 1 }; k < seqSize; k++)
            {
                //Daca se gaseste o pereche de elemente care nu sunt consecutive
                if (seq.at(k) != (seq.at(k - 1) + 1))
                {
                    //Resetarea vectorului
                    seq = std::vector<size_t>(0);
                    break; 
                }
            }

            //Daca vectorul contine elemente si valoare maxima din el este mai mare decat cea curenta din 'max'
            //atunci o rescriem in variabila 'max'
            if (seq.size() != 0)
                if (seq.at(seq.size() - 1) > max)
                    max = seq.at(seq.size() - 1);
        }
    }
    return max;
}



//Face chemarea functiei is_coolSequence() si daca avem std::nullopt, returnam numarul de elemente 
size_t coolSequence(const std::vector<size_t>& vector, const size_t& K)
{
    //Chemarea functiei pentru a verifica daca exista secvente perfecte
    std::optional<size_t> temp = is_coolSequence(vector, K); 

    //Daca 'temp' contine o valoare diferita de 'std::nullopt', o returnam
    if (temp.has_value())
    {
        std::cout << "In sir exista cel putin o secventa cool." << std::endl;
        return temp.value();
    }


    size_t vectorSize = vector.size();
    size_t result = 0; 
    bool flag = false;


    //Numaram cate valori unice se contin in vectorul introdus de la tastatura
    for (size_t i{}; i < vectorSize; i++)
    {
        for (size_t j{}; j < vectorSize; j++)
        {
            if (vector.at(i) == vector.at(j))
            {
                if (!(i == j))
                {
                    flag = true;
                    break;
                }
            }
        }
        
        if (flag)
        {
            flag = false; 
        } 
        else
        {
            ++result;
        }
    }

    std::cout << "In sir nu au fost gasite secvente cool." << std::endl;
    return result;
}