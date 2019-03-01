// imports area

# include <iostream>
# include <vector>

using namespace std;

// databank area

// main functions ---------------------------------------------------

// a function to read user option and redirect to next step

void get_options()
{
  int option;
  cin >> option;

  //redirect

  if (option == 1)
  {
    make_user();
  }
  else if (option == 2)
  {
    make_friends();
  }
  else if (option == 3)
  {
    show_user_menu();
  }
}

// a function to shoe main show_main_menu

void show_main_menu()
{
    // show main menu
    cout << "1 - Add user" << endl;
    cout << "2 - Make friendship" << endl;
    cout << "3 - Show user" << endl;

    // redirect
    get_options();

}

int main()
{
  show_main_menu();
  return 0;

}
