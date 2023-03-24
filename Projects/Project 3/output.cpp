//
// Created by bob on 11/23/18.
//

#include <fstream>
#include <iostream>
#include "pathfinder.h"

using namespace std;

void drawLine(ofstream &outFile,uint32_t r1,uint32_t c1,uint32_t r2,uint32_t c2,uint32_t off1,uint32_t off2) {

    outFile << "newpath\n"
            << c1 * off1 + 54 + off2 << ' ' << 762 - (r1 * off1 + 54 + off2) << " moveto\n"
            << c2 * off1 + 54 + off2 << ' ' << 762 - (r2 * off1 + 54 + off2) << " lineto\n"
            << "stroke\n";
}
/*
void drawLine2(ofstream outFile,int r1,int c1,int r2,int c2) {

    outFile << "newpath\n"
            << c1 * 5 + 54 + 5 << ' ' << 762 - (r1 * 5 + 54 + 5) << " moveto\n"
            << c2 * 5 + 54 + 5 << ' ' << 762 - (r2 * 5 + 54 + 5) << " lineto\n"
            << "stroke\n";
}
*/

void drawMaze(ofstream &outFile,uint8_t maze[][MAX_COLS],int nR,int nC,
              bool drawSolution,bool drawDeadEnds) {
    uint32_t i,j;

    outFile << "newpath\n"
            << "54 " << 762 - (nR * 10 + 54) << " moveto\n"
            << "54 708 lineto\n"
            << nC * 10 + 54 << " 708 lineto\nstroke\n";

    for (i=0;i<nR;i++)
        for (j=0;j<nC;j++) {
            if (maze[i][j] & WALL_RIGHT)
                drawLine(outFile,i,j+1,i+1,j+1,10,0);
            if (maze[i][j] & WALL_DOWN)
                drawLine(outFile,i+1,j,i+1,j+1,10,0);
        }

    if (drawDeadEnds) {
        outFile << "1 0 0 setrgbcolor\n";
        for (i=0;i<nR;i++)
            for (j=0;j<nC;j++)
                if ((maze[i][j] & DEAD_END) != 0) {
                    if ((maze[i][j] & WALL_UP) == 0)
                        drawLine(outFile,2*i,2*j,2*(i-1),2*j,5,5);
                    if ((maze[i][j] & WALL_RIGHT) == 0)
                        drawLine(outFile,2*i,2*j,2*i,2*(j+1),5,5);
                    if ((maze[i][j] & WALL_DOWN) == 0)
                        drawLine(outFile,2*i,2*j,2*(i+1),2*j,5,5);
                    if ((maze[i][j] & WALL_LEFT) == 0)
                        drawLine(outFile,2*i,2*j,2*i,2*(j-1),5,5);
                }
    }

    if (drawSolution) {
        outFile << "0 0 1 setrgbcolor gsave currentlinewidth 3 mul setlinewidth "
                   " 1 setlinecap\n";
        for (i=0;i<nR;i++)
            for (j=0;j<nC;j++)
                if ((maze[i][j] & (VISITED | DEAD_END)) == VISITED) {
                    if ((maze[i][j] & WALL_UP) == 0 &&
                        (maze[i-1][j] & (VISITED | DEAD_END)) == VISITED)
                        drawLine(outFile,2*i,2*j,2*(i-1),2*j,5,5);
                    if ((maze[i][j] & WALL_RIGHT) == 0 &&
                        (maze[i][j+1] & (VISITED | DEAD_END)) == VISITED)
                        drawLine(outFile,2*i,2*j,2*i,2*(j+1),5,5);
                    if ((maze[i][j] & WALL_DOWN) == 0 &&
                        (maze[i+1][j] & (VISITED | DEAD_END)) == VISITED)
                        drawLine(outFile,2*i,2*j,2*(i+1),2*j,5,5);
                    if ((maze[i][j] & WALL_LEFT) == 0 &&
                        (maze[i][j-1] & (VISITED | DEAD_END)) == VISITED)
                        drawLine(outFile,2*i,2*j,2*i,2*(j-1),5,5);
                }
        outFile << "grestore\n";
    }
}

void printMaze(uint8_t maze[][MAX_COLS],int nR,int nC) {
    ofstream
        outFile;

    outFile.open("maze.ps");
    if (!outFile) {
        cout << "Error: cannot open maze.ps" << endl;
        return;
    }

    outFile << "%!PS-Adobe-2.0\n\n%%Pages: 3\n%%Page: 1 1\n";

    outFile << "/Arial findfont 20 scalefont setfont\n"
               "54 730 moveto (Random Maze) show\n";

    drawMaze(outFile,maze,nR,nC,false,false);

    outFile << "showpage\n";
    outFile << "%%Page: 2 2\n";

    outFile << "/Arial findfont 20 scalefont setfont\n"
               "54 730 moveto (Random Maze With Solution) show\n";

    drawMaze(outFile,maze,nR,nC,true,false);

    outFile << "showpage\n";
//    outFile << "%%Page: 3 3\n";
//
//    outFile << "/Arial findfont 20 scalefont setfont\n"
//               "54 730 moveto (Random Maze With Solution "
//               "and Dead Ends) show\n";
//
//    drawMaze(outFile,maze,nR,nC,true,true);
//
//    outFile << "showpage\n";
}
