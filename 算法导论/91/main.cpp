#include "head.h"
#include "node.h"
#include "queue.h"
#include "makeadj.h"
#include "handle.h"

using namespace std;

int main(int argc, char *argv[])
{
   handle_bfs("e:\\in3.txt",0);          //∫¨≤‚ ‘ ˝æ› 
   handle_dfs("e:\\in3.txt");
    system("PAUSE");
    return EXIT_SUCCESS;
}
