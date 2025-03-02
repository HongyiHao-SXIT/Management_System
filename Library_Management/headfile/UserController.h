int menu();
void loadUsersFromFile(vector<User>& users);
void saveUsersToFile(const vector<User>& users);
bool login(vector<User>& users, string& input_username);
bool registerUser(vector<User>& users);