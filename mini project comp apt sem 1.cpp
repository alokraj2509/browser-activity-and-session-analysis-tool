#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

/* =====================================================
   STRUCTURE
   ===================================================== */

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

/* =====================================================
   GLOBAL VARIABLES
   ===================================================== */

struct BrowserActivity history[MAX];
int count = 0;

/* =====================================================
   FUNCTION PROTOTYPES
   ===================================================== */

void addActivity();
void displayActivities();
void searchActivity();
void deleteActivity();
void totalTime();
void averageTime();
void mostVisited();
void longestSession();
void activityAnalysis();
void saveData();
void loadData();
void generateReport();

/* =====================================================
   ADD ACTIVITY
   ===================================================== */

void addActivity()
{
    if (count >= MAX)
    {
        printf("\nStorage is full!\n");
        return;
    }

    history[count].id = count + 1;

    printf("\nEnter website name: ");
    scanf(" %[^\n]", history[count].website);

    printf("Enter URL: ");
    scanf(" %[^\n]", history[count].url);

    printf("Enter activity type: ");
    scanf(" %[^\n]", history[count].activityType);

    printf("Enter duration in minutes: ");
    scanf("%d", &history[count].duration);

    printf("Enter date (DD-MM-YYYY): ");
    scanf(" %[^\n]", history[count].date);

    printf("Enter time: ");
    scanf(" %[^\n]", history[count].time);

    count++;

    printf("\nActivity added successfully!\n");
}

/* =====================================================
   DISPLAY ACTIVITIES
   ===================================================== */

void displayActivities()
{
    int i;

    if (count == 0)
    {
        printf("\nNo browser activity available.\n");
        return;
    }

    printf("\n================ BROWSER HISTORY ================\n");

    for (i = 0; i < count; i++)
    {
        printf("\nID       : %d", history[i].id);
        printf("\nWebsite  : %s", history[i].website);
        printf("\nURL      : %s", history[i].url);
        printf("\nActivity : %s", history[i].activityType);
        printf("\nDuration : %d minutes", history[i].duration);
        printf("\nDate     : %s", history[i].date);
        printf("\nTime     : %s", history[i].time);

        printf("\n-----------------------------------------------");
    }
}

/* =====================================================
   SEARCH ACTIVITY
   ===================================================== */

void searchActivity()
{
    char search[100];
    int i, found = 0;

    printf("\nEnter website to search: ");
    scanf(" %[^\n]", search);

    for (i = 0; i < count; i++)
    {
        if (strstr(history[i].website, search) != NULL)
        {
            printf("\nID       : %d", history[i].id);
            printf("\nWebsite  : %s", history[i].website);
            printf("\nURL      : %s", history[i].url);
            printf("\nActivity : %s", history[i].activityType);
            printf("\nDuration : %d minutes", history[i].duration);
            printf("\nDate     : %s", history[i].date);
            printf("\nTime     : %s\n", history[i].time);

            found = 1;
        }
    }

    if (!found)
    {
        printf("\nWebsite not found.\n");
    }
}

/* =====================================================
   DELETE ACTIVITY
   ===================================================== */

void deleteActivity()
{
    int id;
    int i, j;
    int found = 0;

    printf("\nEnter activity ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (history[i].id == id)
        {
            for (j = i; j < count - 1; j++)
            {
                history[j] = history[j + 1];
                history[j].id = j + 1;
            }

            count--;
            found = 1;

            printf("\nActivity deleted successfully!\n");
            break;
        }
    }

    if (!found)
    {
        printf("\nActivity ID not found.\n");
    }
}

/* =====================================================
   TOTAL TIME
   ===================================================== */

void totalTime()
{
    int total = 0;
    int i;

    for (i = 0; i < count; i++)
    {
        total += history[i].duration;
    }

    printf("\nTotal browsing time = %d minutes\n", total);
}

/* =====================================================
   AVERAGE TIME
   ===================================================== */

void averageTime()
{
    int total = 0;
    int i;
    float average;

    if (count == 0)
    {
        printf("\nNo data available.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        total += history[i].duration;
    }

    average = (float)total / count;

    printf("\nAverage session time = %.2f minutes\n", average);
}

/* =====================================================
   MOST VISITED WEBSITE
   ===================================================== */

void mostVisited()
{
    int i, j;
    int maxVisits = 0;
    int currentVisits;
    char mostVisitedWebsite[100] = "";

    for (i = 0; i < count; i++)
    {
        currentVisits = 0;

        for (j = 0; j < count; j++)
        {
            if (strcmp(history[i].website,
                       history[j].website) == 0)
            {
                currentVisits++;
            }
        }

        if (currentVisits > maxVisits)
        {
            maxVisits = currentVisits;

            strcpy(mostVisitedWebsite,
                   history[i].website);
        }
    }

    if (count == 0)
    {
        printf("\nNo browsing data available.\n");
    }
    else
    {
        printf("\nMost visited website: %s",
               mostVisitedWebsite);

        printf("\nNumber of visits: %d\n",
               maxVisits);
    }
}

/* =====================================================
   LONGEST SESSION
   ===================================================== */

void longestSession()
{
    int i;
    int longestIndex = 0;

    if (count == 0)
    {
        printf("\nNo data available.\n");
        return;
    }

    for (i = 1; i < count; i++)
    {
        if (history[i].duration >
            history[longestIndex].duration)
        {
            longestIndex = i;
        }
    }

    printf("\n========== LONGEST SESSION ==========\n");

    printf("Website  : %s\n",
           history[longestIndex].website);

    printf("Duration : %d minutes\n",
           history[longestIndex].duration);

    printf("Activity : %s\n",
           history[longestIndex].activityType);
}

/* =====================================================
   ACTIVITY ANALYSIS
   ===================================================== */

void activityAnalysis()
{
    int browsing = 0;
    int video = 0;
    int social = 0;
    int study = 0;
    int shopping = 0;
    int other = 0;

    int i;

    for (i = 0; i < count; i++)
    {
        if (strcmp(history[i].activityType,
                   "Browsing") == 0)
        {
            browsing++;
        }
        else if (strcmp(history[i].activityType,
                         "Video") == 0)
        {
            video++;
        }
        else if (strcmp(history[i].activityType,
                         "Social") == 0)
        {
            social++;
        }
        else if (strcmp(history[i].activityType,
                         "Study") == 0)
        {
            study++;
        }
        else if (strcmp(history[i].activityType,
                         "Shopping") == 0)
        {
            shopping++;
        }
        else
        {
            other++;
        }
    }

    printf("\n========== ACTIVITY ANALYSIS ==========\n");

    printf("Browsing : %d\n", browsing);
    printf("Video    : %d\n", video);
    printf("Social   : %d\n", social);
    printf("Study    : %d\n", study);
    printf("Shopping : %d\n", shopping);
    printf("Other    : %d\n", other);
}

/* =====================================================
   SAVE DATA
   ===================================================== */

void saveData()
{
    FILE *file;
    int i;

    file = fopen("browser_data.txt", "w");

    if (file == NULL)
    {
        printf("\nUnable to save data.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        fprintf(file,
                "%d|%s|%s|%s|%d|%s|%s\n",
                history[i].id,
                history[i].website,
                history[i].url,
                history[i].activityType,
                history[i].duration,
                history[i].date,
                history[i].time);
    }

    fclose(file);

    printf("\nData saved successfully!\n");
}

/* =====================================================
   LOAD DATA
   ===================================================== */

void loadData()
{
    FILE *file;

    file = fopen("browser_data.txt", "r");

    if (file == NULL)
    {
        return;
    }

    count = 0;

    while (count < MAX &&
           fscanf(file,
                  "%d|%99[^|]|%199[^|]|%29[^|]|%d|%19[^|]|%19[^\n]\n",
                  &history[count].id,
                  history[count].website,
                  history[count].url,
                  history[count].activityType,
                  &history[count].duration,
                  history[count].date,
                  history[count].time) == 7)
    {
        count++;
    }

    fclose(file);
}

/* =====================================================
   GENERATE REPORT
   ===================================================== */

void generateReport()
{
    printf("\n");
    printf("============================================\n");
    printf("       BROWSER ACTIVITY REPORT\n");
    printf("============================================\n");

    printf("\nTotal Activities : %d\n", count);

    totalTime();
    averageTime();
    mostVisited();
    longestSession();
    activityAnalysis();

    printf("\n============================================\n");
}

/* =====================================================
   MAIN FUNCTION
   ===================================================== */

int main()
{
    int choice;

    loadData();

    do
    {
        printf("\n\n");
        printf("============================================\n");
        printf("     BROWSER ACTIVITY & ANALYSIS TOOL\n");
        printf("============================================\n");

        printf("\n1. Add Browser Activity");
        printf("\n2. Display Browser History");
        printf("\n3. Search Activity");
        printf("\n4. Delete Activity");
        printf("\n5. Total Browsing Time");
        printf("\n6. Average Browsing Time");
        printf("\n7. Most Visited Website");
        printf("\n8. Longest Session");
        printf("\n9. Activity Analysis");
        printf("\n10. Generate Report");
        printf("\n11. Save Data");
        printf("\n0. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addActivity();
            break;

        case 2:
            displayActivities();
            break;

        case 3:
            searchActivity();
            break;

        case 4:
            deleteActivity();
            break;

        case 5:
            totalTime();
            break;

        case 6:
            averageTime();
            break;

        case 7:
            mostVisited();
            break;

        case 8:
            longestSession();
            break;

        case 9:
            activityAnalysis();
            break;

        case 10:
            generateReport();
            break;

        case 11:
            saveData();
            break;

        case 0:
            saveData();
            printf("\nThank you for using the tool!\n");
            break;

        default:
            printf("\nInvalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}