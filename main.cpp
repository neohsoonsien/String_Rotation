# include <fstream>
# include <string>
using namespace std;


string string_rotation(string & s, const int & leftshift, const int & rightshift)
{
    int net_shift;          // declare a variable, so that to know the net rotation is to the right or to the left
    int length = s.size();  // find the length of the string

    if (leftshift > rightshift)             // then we do only leftshift
    {
        net_shift = leftshift - rightshift;
        for (int i = 0; i < net_shift; i++)
        {
            char first = s.at(0);            // get the first element
            s.erase(0, 1);                  // remove the first character
            s = s + first;                   // append the removed first character to the last
        }
    }
    else if (leftshift < rightshift)        // then we do only rightshift
    {
        net_shift = rightshift - leftshift;
        for (int i = 0; i < net_shift; i++)
        {
            char last = s.at(length - 1);   // get the last element
            s.erase(length - 1, 1);         // remove the last character
            s = last + s;                   // then prepend the removed last character to the front
        };

    }
    else if (leftshift == rightshift)       // if left-rotation == right-rotation, no rotation is needed
    {
        s = s;
    };

    return s;
}

int main()
{
    ifstream input;
    input.open("Input.txt"); // to provide input

    ofstream output;
    output.open("Output.txt"); // to give the output

    int test_case_number;
    string s;
    int leftshift, rightshift;


    input >> test_case_number; // the first line in "Input.txt" will tell the number of test cases
    for (int example = 0; example < test_case_number; example++)
    {
        // to input the s, number of leftshift and number of rightshift
        input >> s >> leftshift >> rightshift;

        // print the output, and also to return the string after rotation
        output << "Test case number " << example + 1 << ", and the string is ";
        output << string_rotation(s, leftshift, rightshift) << endl;
    };

    // close the files
    input.close();
    output.close();

    return 0;
}
