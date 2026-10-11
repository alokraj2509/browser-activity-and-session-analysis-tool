#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

/* =========================================================
   STRUCTURE
   ========================================================= */

struct BrowserActivity
{
    int id;
    char website[100];
    char url[200];
    char activityType[30];
    int duration;
    char date[20];
    char time[20];
};


/* =========================================================
   GLOBAL VARIABLES
   ========================================================= */

struct BrowserActivity history[MAX];

int count = 0;


/* =========================================================
   FUNCTION DECLARATIONS
   ========================================================= */

void addActivity();
void displayHistory();
void searchWebsite();
void deleteActivity();

void totalBrowsingTime();
void averageSession();
void mostVisitedWebsite();
void longestSession();

void activityTypeAnalysis();
void analysisReport();

void saveData();
void loadData();

void header();
void pauseScreen();


/* =========================================================
   HEADER FUNCTION
   ========================================================= */

void header()
{
    printf("\n");
    printf("============================================================\n");
    printf("        BROWSER ACTIVITY & SESSION ANALYSIS TOOL\n");
    printf("============================================================\n");
}


/* =========================================================
   PAUSE FUNCTION
   ========================================================= */

void pauseScreen()
{
    printf("\nPress Enter to continue...");

    getchar();
    getchar();
}


/* =========================================================
   ADD BROWSER ACTIVITY
   ========================================================= */

void addActivity()
{
    if (count >= MAX)
    {
        printf("\nHistory is full!\n");
        return;
    }


    history[count].id = count + 1;


    printf("\n--------------- ADD BROWSER ACTIVITY ---------------\n");


    printf("Enter Website Name: ");
    scanf(" %[^\n]", history[count].website);


    printf("Enter URL: ");
    scanf(" %[^\n]", history[count].url);


    printf("Enter Activity Type\n");
    printf("1. Search\n");
    printf("2. Video\n");
    printf("3. Visit\n");
    printf("4. Download\n");
    printf("5. Social Media\n");

    int typeChoice;

    printf("Enter choice: ");
    scanf("%d", &typeChoice);


    switch (typeChoice)
    {
        case 1:
            strcpy(history[count].activityType, "Search");
            break;

        case 2:
            strcpy(history[count].activityType, "Video");
            break;

        case 3:
            strcpy(history[count].activityType, "Visit");
            break;

        case 4:
            strcpy(history[count].activityType, "Download");
            break;

        case 5:
            strcpy(history[count].activityType, "Social Media");
            break;

        default:
            strcpy(history[count].activityType, "Other");
    }


    printf("Enter Session Duration in minutes: ");
    scanf("%d", &history[count].duration);


    printf("Enter Date (DD-MM-YYYY): ");
    scanf(" %[^\n]", history[count].date);


    printf("Enter Time (HH:MM): ");
    scanf(" %[^\n]", history[count].time);


    count++;


    printf("\nActivity added successfully!\n");
}


/* =========================================================
   DISPLAY BROWSER HISTORY
   ========================================================= */

void displayHistory()
{
    int i;


    if (count == 0)
    {
        printf("\nNo browser activity available.\n");
        return;
    }


    printf("\n================ BROWSER HISTORY ================\n");


    printf("\n%-5s %-18s %-25s %-15s %-10s %-12s %-8s\n",
           "ID",
           "Website",
           "URL",
           "Activity",
           "Duration",
           "Date",
           "Time");


    printf("------------------------------------------------------------------------------------------\n");


    for (i = 0; i < count; i++)
    {
        printf("%-5d %-18s %-25s %-15s %-10d %-12s %-8s\n",
               history[i].id,
               history[i].website,
               history[i].url,
               history[i].activityType,
               history[i].duration,
               history[i].date,
               history[i].time);
    }
}


/* =========================================================
   SEARCH WEBSITE
   ========================================================= */

void searchWebsite()
{
    char search[100];

    int i;

    int found = 0;


    printf("\nEnter website name to search: ");

    scanf(" %[^\n]", search);


    printf("\n--------------- SEARCH RESULT ---------------\n");


    for (i = 0; i < count; i++)
    {
        if (
            strstr(
                history[i].website,
                search
            ) != NULL
        )
        {
            printf("\nActivity ID : %d",
                   history[i].id);

            printf("\nWebsite     : %s",
                   history[i].website);

            printf("\nURL         : %s",
                   history[i].url);

            printf("\nActivity    : %s",
                   history[i].activityType);

            printf("\nDuration    : %d minutes",
                   history[i].duration);

            printf("\nDate        : %s",
                   history[i].date);

            printf("\nTime        : %s\n",
                   history[i].time);

            printf("--------------------------------------------\n");


            found = 1;
        }
    }


    if (!found)
    {
        printf("\nWebsite not found in browser history.\n");
    }
}


/* =========================================================
   DELETE ACTIVITY
   ========================================================= */

void deleteActivity()
{
    int id;

    int i;

    int position = -1;


    if (count == 0)
    {
        printf("\nNo activity available.\n");
        return;
    }


    printf("\nEnter Activity ID to delete: ");

    scanf("%d", &id);


    for (i = 0; i < count; i++)
    {
        if (history[i].id == id)
        {
            position = i;
            break;
        }
    }


    if (position == -1)
    {
        printf("\nActivity ID not found.\n");
        return;
    }


    for (i = position; i < count - 1; i++)
    {
        history[i] = history[i + 1];

        history[i].id = i + 1;
    }


    count--;


    printf("\nActivity deleted successfully!\n");
}


/* =========================================================
   TOTAL BROWSING TIME
   ========================================================= */

void totalBrowsingTime()
{
    int i;

    int total = 0;


    for (i = 0; i < count; i++)
    {
        total += history[i].duration;
    }


    printf("\n--------------- TOTAL BROWSING TIME ---------------\n");


    printf("Total Minutes : %d minutes\n", total);


    printf("Total Hours   : %.2f hours\n",
           total / 60.0);
}


/* =========================================================
   AVERAGE SESSION
   ========================================================= */

void averageSession()
{
    int i;

    int total = 0;


    if (count == 0)
    {
        printf("\nNo session data available.\n");
        return;
    }


    for (i = 0; i < count; i++)
    {
        total += history[i].duration;
    }


    printf("\n--------------- AVERAGE SESSION ---------------\n");


    printf(
        "Average Session Duration : %.2f minutes\n",
        (float)total / count
    );
}


/* =========================================================
   MOST VISITED WEBSITE
   ========================================================= */

void mostVisitedWebsite()
{
    int i, j;

    int maxVisits = 0;

    int currentVisits;


    if (count == 0)
    {
        printf("\nNo browser activity available.\n");
        return;
    }


    for (i = 0; i < count; i++)
    {
        currentVisits = 0;


        for (j = 0; j < count; j++)
        {
            if (
                strcmp(
                    history[i].website,
                    history[j].website
                ) == 0
            )
            {
                currentVisits++;
            }
        }


        if (currentVisits > maxVisits)
        {
            maxVisits = currentVisits;
        }
    }


    printf("\n--------------- MOST VISITED WEBSITE ---------------\n");


    for (i = 0; i < count; i++)
    {
        currentVisits = 0;


        for (j = 0; j < count; j++)
        {
            if (
                strcmp(
                    history[i].website,
                    history[j].website
                ) == 0
            )
            {
                currentVisits++;
            }
        }


        if (currentVisits == maxVisits)
        {
            printf("Website : %s\n",
                   history[i].website);

            printf("Visits  : %d\n",
                   currentVisits);

            break;
        }
    }
}


/* =========================================================
   LONGEST SESSION
   ========================================================= */

void longestSession()
{
    int i;

    int maxIndex = 0;


    if (count == 0)
    {
        printf("\nNo browser activity available.\n");
        return;
    }


    for (i = 1; i < count; i++)
    {
        if (
            history[i].duration >
            history[maxIndex].duration
        )
        {
            maxIndex = i;
        }
    }


    printf("\n--------------- LONGEST SESSION ---------------\n");


    printf("Website  : %s\n",
           history[maxIndex].website);


    printf("Duration : %d minutes\n",
           history[maxIndex].duration);


    printf("Activity : %s\n",
           history[maxIndex].activityType);


    printf("Date     : %s\n",
           history[maxIndex].date);
}


/* =========================================================
   ACTIVITY TYPE ANALYSIS
   ========================================================= */

void activityTypeAnalysis()
{
    int search = 0;
    int video = 0;
    int visit = 0;
    int download = 0;
    int social = 0;
    int other = 0;


    int i;


    for (i = 0; i < count; i++)
    {
        if (
            strcmp(
                history[i].activityType,
                "Search"
            ) == 0
        )
        {
            search++;
        }

        else if (
            strcmp(
                history[i].activityType,
                "Video"
            ) == 0
        )
        {
            video++;
        }

        else if (
            strcmp(
                history[i].activityType,
                "Visit"
            ) == 0
        )
        {
            visit++;
        }

        else if (
            strcmp(
                history[i].activityType,
                "Download"
            ) == 0
        )
        {
            download++;
        }

        else if (
            strcmp(
                history[i].activityType,
                "Social Media"
            ) == 0
        )
        {
            social++;
        }

        else
        {
            other++;
        }
    }


    printf("\n--------------- ACTIVITY TYPE ANALYSIS ---------------\n");


    printf("Search       : %d\n", search);

    printf("Video        : %d\n", video);

    printf("Visit        : %d\n", visit);

    printf("Download     : %d\n", download);

    printf("Social Media : %d\n", social);

    printf("Other        : %d\n", other);
}


/* =========================================================
   COMPLETE ANALYSIS REPORT
   ========================================================= */

void analysisReport()
{
    printf("\n");
    printf("============================================================\n");
    printf("              BROWSER ANALYSIS REPORT\n");
    printf("============================================================\n");


    printf("\nTotal Activities : %d\n", count);


    totalBrowsingTime();


    averageSession();


    mostVisitedWebsite();


    longestSession();


    activityTypeAnalysis();


    printf("\n============================================================\n");
}


/* =========================================================
   SAVE DATA TO FILE
   ========================================================= */

void saveData()
{
    FILE *file;

    int i;


    file = fopen(
        "browser_history.txt",
        "w"
    );


    if (file == NULL)
    {
        printf("\nUnable to open file.\n");
        return;
    }


    for (i = 0; i < count; i++)
    {
        fprintf(
            file,
            "%d|%s|%s|%s|%d|%s|%s\n",

            history[i].id,

            history[i].website,

            history[i].url,

            history[i].activityType,

            history[i].duration,

            history[i].date,

            history[i].time
        );
    }


    fclose(file);


    printf(
        "\nBrowser data saved successfully!\n"
    );
}


/* =========================================================
   LOAD DATA FROM FILE
   ========================================================= */

void loadData()
{
    FILE *file;


    file = fopen(
        "browser_history.txt",
        "r"
    );


    if (file == NULL)
    {
        printf(
            "\nNo previous browser data found.\n"
        );

        return;
    }


    count = 0;


    while (
        fscanf(
            file,
            "%d|%99[^|]|%199[^|]|%29[^|]|%d|%19[^|]|%19[^\n]\n",

            &history[count].id,

            history[count].website,

            history[count].url,

            history[count].activityType,

            &history[count].duration,

            history[count].date,

            history[count].time
        ) == 7
    )
    {
        count++;


        if (count >= MAX)
        {
            break;
        }
    }


    fclose(file);


    printf(
        "\nPrevious browser data loaded successfully!\n"
    );
}


/* =========================================================
   MAIN FUNCTION
   ========================================================= */

int main()
{
    int choice;


    loadData();


    do
    {
        header();


        printf("\n");
        printf("1.  Add Browser Activity\n");
        printf("2.  Display Browser History\n");
        printf("3.  Search Website\n");
        printf("4.  Delete Activity\n");
        printf("5.  Total Browsing Time\n");
        printf("6.  Average Session Duration\n");
        printf("7.  Most Visited Website\n");
        printf("8.  Longest Session\n");
        printf("9.  Activity Type Analysis\n");
        printf("10. Complete Analysis Report\n");
        printf("11. Save Data\n");
        printf("12. Exit\n");


        printf("\n------------------------------------------------------------\n");


        printf("Enter your choice: ");

        scanf("%d", &choice);


        switch (choice)
        {
            case 1:

                addActivity();

                break;


            case 2:

                displayHistory();

                break;


            case 3:

                searchWebsite();

                break;


            case 4:

                deleteActivity();

                break;


            case 5:

                totalBrowsingTime();

                break;


            case 6:

                averageSession();

                break;


            case 7:

                mostVisitedWebsite();

                break;


            case 8:

                longestSession();

                break;


            case 9:

                activityTypeAnalysis();

                break;


            case 10:

                analysisReport();

                break;


            case 11:

                saveData();

                break;


            case 12:

                saveData();

                printf(
                    "\n============================================================\n"
                );

                printf(
                    " Thank you for using Browser Activity Analyzer!\n"
                );

                printf(
                    "============================================================\n"
                );

                break;


            default:

                printf(
                    "\nInvalid choice! Please try again.\n"
                );
        }


        if (choice != 12)
        {
            pauseScreen();
        }


    }
    while (choice != 12);


    return 0;
}