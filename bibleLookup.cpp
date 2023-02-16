// Natalie Mayfield
// 11 - 1 - 22
// Bible lookup

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdbool.h>


using namespace std;


int main() {

        ifstream Bible;                                                 //create an input stream that will read data from Bible.txt with the variable name "Bible"
        Bible.open("Bible.txt");
        string book;                                                    //create a string for the book, chapter, and verse
        string chapter;
        string verse;

        bool bookFound = false;                                         //create booleans for if the book, chapter, and verse are found and initialize to false
        bool chapterFound = false;
        bool verseFound = false;

        cout << "Please enter the book you would like to retrieve" << endl;             // get the book, chapter, and verse from user
        getline(cin,book);
        cout << "Please enter the chapter you would like to retrieve" << endl;
        cin >> chapter;
        cout << "Please enter the verse you would like to retrieve" << endl;
        cin >> verse;

        transform(book.begin(), book.end(), book.begin(), ::toupper);                   //turn book into all caps
        string line;                                                            //create line that will be compared to the book, chapter, and verse

        if(book == "PSALMS"){
                chapter = "PSALM " + chapter;
        }
        else{                                                           //put "CHAPTER " in front of the all the books that have chapters and psalms in front of the ps>
                chapter = "CHAPTER " + chapter;
        }

        switch (book[0]) {                                              //convert numbered books into words
                case '1':
                        book = "FIRST " + book.substr(2, book.size() - 1);
                        break;
                case '2':
                        book = "SECOND " + book.substr(2, book.size() - 1);
                        break;
                case '3':
                        book = "THIRD " + book.substr(2, book.size() - 1);
                        break;
        }





        book = "THE BOOK OF " + book;

        while(!Bible.eof()){                                    //while the program hasn't reached the end of the Bible.txt file...


                getline(Bible, line);                           //continuously look at each individual line of the txt file

                if (line == book){                              //if the current line is identical to the book string, set bookFound equal to true
                        bookFound = true;
                        getline(Bible,line);                    //need this for the following statement
                }
                if (bookFound && line.substr(0,11) == "THE BOOK OF"){                   //if the code reaches another book, break out of the code because chapter doesn>
                        break;
                }

                if (bookFound && line == chapter){              //if the book has been found and the current line is identical to the chapter string, set chapterFound >
                        chapterFound = true;
                }

                if (line.substr(0, verse.length()) == verse && chapterFound){           //if the verse number is equal to the line's verse number and the chapter has b>
                        verseFound = true;
                        cout << line << endl;
                        break;
                }


                }


        ofstream outputFile;                            //create and open an output stream that will write the outputted verse to the text file
        outputFile.open("bibleVerse.txt");
        outputFile << line;
        outputFile.close();                             //close the file


        book.erase(0,12);                               //delete "THE BOOK OF "
        transform(book.begin(), book.end(), book.begin(), ::tolower);           //turn the book's name to lowercase
        book[0] = toupper(book[0]);                     //capitalize the first letter of the book


        transform(chapter.begin(),chapter.end(), chapter.begin(), ::tolower);           //turn the chapter's name to lowercase


                if(!bookFound) {                                                                        //if the book, chapter, or verse isn't found, print out why
                        cout << "The Bible does not contain the book " << book << "." << endl;
                }

                else if(!chapterFound) {
                        cout << "The book " << book << " does not have " << chapter << endl;
                }
                else if(!verseFound) {
                        cout << "Chapter " << chapter << " of book " << book << " does not have verse " << verse << endl;
                }


        Bible.close();                                  //close the Bible.txt file
        return 0;

}

