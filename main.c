#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <time.h>

int main()
{
    char r;
    char BookCategory[50];
    int BookID;
    char BookName[50];
    char BookAuthor[50];
    int NumberOfBookPages;
    float BookPrice;
    int NumberOfBooksInTheLibrary;
    char TheNameOfTheBookToBeDeleted[50];
    char TheNameOfTheBookToSeeTheInformation[50];
    char InformationFile[100];

    FILE *books;
    char FileName[100];


    printf("Library \n\n");

    printf("1.Add a book\n");
    printf("2.Delete the book\n");
    printf("3.Show list of books\n");
    printf("4.Exit\n");
    puts("");

    printf("Enter number\n");
    scanf("%c",&r);

    switch(r)
    {
        case'1':


        printf("Enter a file name. Add '.txt' to the end of the file:\n");
        printf("If you give, for example, the author of a book, give it with '-' Adam-Mickiewicz. Same with other two or more words \n");
        scanf("%s",&FileName);


        books = fopen(FileName,"w");


        printf("Enter book categories: \n");
        scanf("%s",&BookCategory);
        fprintf(books,"Book category: %s \n",BookCategory);

        printf("Enter the ID of the book: \n");
        scanf("%d",&BookID);
        fprintf(books,"Book ID: %d \n",BookID);

        printf("Enter the name of the book: \n");
        scanf("%s",&BookName);
        fprintf(books,"Book name: %s \n",BookName);

        printf("Name the author of the book: \n");
        scanf("%s",&BookAuthor);
        fprintf(books,"Book author: %s \n",BookAuthor);

        printf("Enter how many pages the book has: \n");
        scanf("%d",&NumberOfBookPages);
        fprintf(books,"The number of pages of the book: %d \n",NumberOfBookPages);

        printf("Enter the price of the book: \n");
        scanf("%f",&BookPrice);
        fprintf(books,"Book price: %f \n",BookPrice);

        printf("Enter the current number of books in the library: \n");
        scanf("%d",&NumberOfBooksInTheLibrary);
        fprintf(books,"The current number of books in the library: %d \n",NumberOfBooksInTheLibrary);


        fclose(books);

        break;

        case'2':

        printf("List of all books: \n\n");

        struct _finddata_t txt_file;
        intptr_t eFile;

        if( (eFile = _findfirst( "*.txt", &txt_file )) == -1L )
        printf( "No book files\n" );
        else


        do {
        char buffer[30];

        ctime_s( buffer, _countof(buffer), &txt_file.time_write );
        printf( "%s, ",txt_file.name );

        } while( _findnext( eFile, &txt_file ) == 0 );
        _findclose( eFile );

        puts("");
        printf("Enter the file name of the book you want to delete:\n");
        scanf("%s",&TheNameOfTheBookToBeDeleted);

        remove(TheNameOfTheBookToBeDeleted);

        break;

        case'3':

        printf("List of all books: \n\n");

        struct _finddata_t c_file;
        intptr_t hFile;

        if( (hFile = _findfirst( "*.txt", &c_file )) == -1L )
        printf( "No book files\n" );
        else


        do {
        char buffer[30];

        ctime_s( buffer, _countof(buffer), &c_file.time_write );
        printf( "%s, ",c_file.name );

        } while( _findnext( hFile, &c_file ) == 0 );
        _findclose( hFile );

        puts("");
        printf("Enter the name of the file: \n");
        scanf("%s",&TheNameOfTheBookToSeeTheInformation);

        books = fopen(TheNameOfTheBookToSeeTheInformation,"r");

        puts("");
        while(fgets(InformationFile,100,books))
        {
        printf("%s",InformationFile);
        }


        fclose(books);

        break;

        case'4':

        return;

        break;
    }




    return 0;
}
