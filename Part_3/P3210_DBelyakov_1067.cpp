#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

struct Dir {
    map<string, Dir*> sub_dirs;
};

Dir dirs[100001];
int dirs_number = 0;
int n;

Dir* cd_dir(Dir* parent, string child_name)
{
    auto& d = parent->sub_dirs[child_name];
    if (!d) d = &dirs[++dirs_number];
    return d;
}

void print(Dir* roots, string s)
{
    for (auto root_dir : roots->sub_dirs)
    {
        cout << tabs << root_dir.first << endl;
        print(root_dir.second, s + " ");
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str, dir;
        cin >> str;
        stringstream ss(str);
        Dir* parent_dir = &dirs[0];

        while (getline(ss, dir, '\\'))
            parent_dir = cd_dir(parent_dir, dir);
    }

    print(&dirs[0], "");
}