#include "test.h"

using namespace std;

void Test::testBoardIsAttacked()
{
    Move m;
    Board board;
    board.init();


    cout << board.isAttacked(20, white) << endl;
    cout << board.isAttacked(21, white) << endl;
    m.x = parseMove("e2e4");
    board.makeMove(m);

    cout << board.isAttacked(35, white) << endl;
    cout << board.isAttacked(39, white) << endl;
    cout << board.isAttacked(40, white) << endl;
    m.x = parseMove("b8c6");
    board.makeMove(m);

    cout << board.isAttacked(27, black) << endl;
    cout << board.isAttacked(28, black) << endl;

}

int Test::mainTest()
{  

    string s, tok, description;
    ifstream fin;
    fin.open("tests.txt");

    int testCounter = 0;

    Move move;
	Board board;
    bool pass;
	
if (fin.is_open())
  {
    while (getline(fin, s))
    {
        pass = true;
        board.init();
        ++testCounter;
        istringstream iss(s);
        
        iss >> description;
        while (iss >> tok)
        {
            move = board.getMove(parseMove(tok));
            if (!board.makeMove(move))
			{
				pass = false;
				break;
			}
        }

        if (pass)
            cout << "Test " << testCounter << " passed (" << description << ")\n";
        else
            cout << "Test " << testCounter << " failed (" << description << ")\n";
    }
    fin.close();
  } 
  else {
      cout << "FAIL" << endl;
  }

    return 0;
}