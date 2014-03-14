#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Simplify Path
// Given an absolute path for a file (Unix-style), simplify it.

// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"
// click to show corner cases.

// Corner Cases:
// Did you consider the case where path = "/../"?
// In this case, you should return "/".
// Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
// In this case, you should ignore redundant slashes and return "/home/foo”.

string simplifyPath(string path)
{
    if (path.size() == 0) return path;
    
    stack<string> S; // use stack to record the real path between every two slashes
    for (int i = 0; i < path.size(); )
    {
        if (path[i] == '/')  // meet slash，nothing to do
        {
            ++i;
            continue;
        }
        else if (path[i] == '.')
        {
            int ii = i;
            while (ii < path.size())
            {
                if (path[ii] != '.')
                    break;
                ++ii;
            }
            
            if (ii == path.size())
            {
                if (ii-i == 1)  // case of /. return /
                {
                    i = ii;
                }
                else if (ii-i == 2)  // case of /.. return /
                {
                    if (!S.empty()) S.pop();
                    i = ii;
                }
                else  // case of /... return /...
                {
                    S.push(string(path, i, ii-i));
                    i = ii;
                }
            }
            else
            {
                if (ii-i == 1 && path[ii] == '/')  // case of /./, nothing to do
                {
                    i = ii;
                }
                else if (ii-i == 2 && path[ii] == '/')  // case of /../, return to the previous directory
                {
                    if (!S.empty()) S.pop();
                    i = ii;
                }
                else  // case of /.history or /..history, just return /.history or /..history
                {
                    while (ii < path.size())
                    {
                        if (path[ii] == '/')
                            break;
                        ++ii;
                    }
                    
                    S.push(string(path, i, ii-i));
                    i = ii;
                }
            }
        }
        else // record the real path between two slashes
        {
            int ii = i;
            while (ii < path.size())
            {
                if (path[ii] == '/')
                    break;
                ++ii;
            }
            S.push(string(path, i, ii-i));
            
            i = ii;
        }
    }
    
    string str;
    if (S.empty()) str = "/";

    while (!S.empty())
    {
        str = "/" + S.top() + str;
        S.pop();
    }
    
    return str;
}

int main(int argc, const char * argv[])
{
    std::cout << simplifyPath("/.") << std::endl;             //  /
    std::cout << simplifyPath("/./") << std::endl;            //  /
    std::cout << simplifyPath("/..") << std::endl;            //  /
    std::cout << simplifyPath("/../") << std::endl;           //  /
    std::cout << simplifyPath("/...") << std::endl;           //  /...
    std::cout << simplifyPath("/.../") << std::endl;          //  /...
    std::cout << simplifyPath("/.history") << std::endl;      // /.history
    std::cout << simplifyPath("/..history") << std::endl;     // /..history
    std::cout << simplifyPath("/...history") << std::endl;    // /...history
    std::cout << simplifyPath("///") << std::endl;            // /
    std::cout << simplifyPath("//ab/..///c/a") << std::endl;  // /c/a
    std::cout << simplifyPath("/history") << std::endl;       // history
    std::cout << simplifyPath("//a/..") << std::endl;         // /

    return 0;
}
