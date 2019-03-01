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
vector <user> users_storage;
int last_user = 0;


// user functions ------------------------------------------------------------

// generete a new user
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

      users_storage.push_back(user());
      users_storage[last_user+1].name = name;
      users_storage[last_user+1].random_thing = random;
      last_user++;

    }
    else{
      cout << "user-storage-error-overflow";
    }
}

// delete user
void delete_user()
{
    cout << endl;

    int id;
    cout << "write id to delete user" << endl;
    cin >> id;

    if (id > last_user)
    {
      cout << "user not found" << endl;
    }
    else
    {
      users_storage.erase(users_storage.begin()+id);
      last_user--;
    }
}


// make a friendship
void make_friends()
{
  cout << endl;

  if (last_user < 1){
      cout << "missing users";
  }
  else
  {
      cout << "write user 1 id" << endl;
      int x;
      cin >> x;
      cout << "write user 2 id" << endl;
      int y;
      cin >> y;

      if (x > last_user or y > last_user)
      {
        cout << "user not found" << endl;
      }
      else
      {
        users_storage[x].friendsId.push_back(y);
        users_storage[y].friendsId.push_back(x);
        cout << "friendship made" << endl;
      }
  }
}

// shoe menu for users manippulation
void show_user_menu()
{
    // show user menu
    cout << endl;
    cout << "1 - edit user data" << endl;
    cout << "2 - delete user" << endl;
    cout << "3 - show information" << endl;
    cout << "4 - show user spider web" << endl;
    cout << "5 - list users" << endl;
    cout << "6 - back" << endl;

    // redirect
    int option;
    cin >> option;

    // redirect to next step
    if (option == 1)
    {
      edit_user_information();
    }
    else if (option == 2)
    {
      delete_user();
    }
    else if (option == 3)
    {
      show_user();
    }
    else if (option == 4)
    {
      show_spider_web();
    }
    else if (option == 5)
    {
      users_list();
    }
    else if (option == 6)
    {
      goback = false;
    }

    if (goback){
      show_user_menu();
    }

    goback = true;
}

// main functions ------------------------------------------------------------


// a function to show main menu
void show_main_menu()
{
    // show main menu
    cout << endl;
    cout << "1 - Add user" << endl;
    cout << "2 - Make friendship" << endl;
    cout << "3 - Show user" << endl;

    // redirect
    int option;
    cin >> option;

    //redirect to next step
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

    if (goback){
      show_main_menu();
    }

}

int main()
{
  show_main_menu();
  return 0;

}
