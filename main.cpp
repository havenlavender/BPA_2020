#include <iostream>
#include <string>
#include <vector>

using namespace std;

// prompts user to input a int value
int getInput(string prompt = "");

// prompts user for a y/n input
bool promptBool(string prompt = "");

// checks if a given number is prime
bool isPrime(int n);

// checks if a given number is perfect
bool isPerfect(int n);


// prompts user for a number an prints all prime and perfect numbers from 0 to the provided number
int main()
{
    bool cont = true;
    int value = 0;

    do
    {
        vector<int> primeValues{};
        vector<int> perfectValues{};

        value = getInput("enter a number greater than 0 : ");

        // print this out because large numbers can take awhile to calculate all the possibilities
        system("cls");
        cout << "computing ..." << endl;

        // loop through ( 0 -> input )
        // if 'i' is prime or perfect it is added to the corresponding vector
        for (int i = 0; i < value; i++)
        {
            if (isPrime(i)) primeValues.push_back(i);
            if (isPerfect(i)) perfectValues.push_back(i);
        }

        system("cls");

        // display all prime values
        cout << "Prime Values (0 - " << value << "):" << endl;
        for (int i = 0; i < primeValues.size(); i++)
        {
            if (i > 0) cout << ", ";
            cout << primeValues[i];
        }


        // clear console
        cout << '\n' << endl;
        system("pause");
        system("cls");

        // display all perfect values
        cout << "Perfect Values (0 - " << value << "):" << endl;
        for (int i = 0; i < perfectValues.size(); i++)
        {
            if (i > 0) cout << ", ";
            cout << perfectValues[i];
        }

        // clear console
        cout << '\n' << endl;
        system("pause");
        system("cls");

        // prompt user if they want to run the program again
        cin.ignore();
        cont = promptBool("run again? (y/n)\n > ");
        system("cls");

    } while (cont);

    return 0;
}

int getInput(string prompt)
{
    string input{};
    int output{};

    cout << prompt;
    cin >> input;

    // attempts to convert the string to an int
    // if it fails or the number isnt more than 0 it calls the function again
    try { output = stoi(input); }
    catch (exception e) { output = getInput(prompt); }
    if (output <= 0) output = getInput(prompt);

    return output;
}

bool promptBool(string prompt)
{
    string input{};
    cout << prompt;
    cin >> input;

    // checks whether input is y or n, if not it calls the function again
    if (input == "n")
    {
        return false;
    }
    else if (input == "y")
    {
        return true;
    }
    else
    {
        // clear the console and reprompts
        system("cls");
        cout << "invalid input" << endl;
        return promptBool(prompt);
    }
}

bool isPrime(int n)
{
    // 0 and 1 are not prime so we return false
    if (n == 0 || n == 1) return false;

    // loops through (2 -> n / 2) checking if n is divisible by i
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    // if it wasn't divisible by anything then it is prime
    return true;
}

bool isPerfect(int n)
{
    // perfect numbers cannot be less than 1
    if (n < 1) return false;

    // loop through (1 -> n) checking if n is divisible by i
    // if so then add i to the sum
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }

    // if the sum of all values divisible by 'i' is equal to 'n' then return true
    return sum == n;
}
