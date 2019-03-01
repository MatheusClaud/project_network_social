// imports area

# include <iostream>
# include <vector>

using namespace std;

// databank area

// user model
struct user{
  vector <int> friendsId;
  char name;
  char random_thing;
};

// processament area
bool goback = true;

// users storage / capacity: 50 users
user users_storage[49];
int last_user = -1; // last user space used / -1: empty

// user functions ------------------------------------------------------------

void make_user()
{
    cout << endl;

    if (last_user < 50){
      char name;
      char random;

      cout << "please write a name" << endl;
      cin >> name;

      cout << "tell some letter" << endl;
      cin >> random;

      users_storage[last_user+1].name = name;
      users_storage[last_user+1].random_thing = random;

    }
    else{
      cout << "user-storage-error-overflow";
    }
}

// main functions ------------------------------------------------------------

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

// a function to show main menu
void show_main_menu()
{
    // show main menu
    cout << endl;
    cout << "1 - Add user" << endl;
    cout << "2 - Make friendship" << endl;
    cout << "3 - Show user" << endl;

    // redirect
    get_options();

    if (goback){
      show_main_menu();
    }

}

int main()
{
  show_main_menu();
  return 0;

}
