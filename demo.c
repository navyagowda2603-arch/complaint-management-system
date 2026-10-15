#include <stdio.h>
#include <string.h>

struct Complaint
{
    int id;
    char name[50];
    char complaint[100];
    char status[20];
};

struct Complaint c[50];
int count = 0;

void addComplaint()
{
    if (count >= 50)
    {
        printf("\nComplaint limit reached!\n");
        return;
    }

    c[count].id = count + 1;

    printf("\nEnter your name: ");
    scanf(" %[^\n]", c[count].name);

    printf("Enter your complaint: ");
    scanf(" %[^\n]", c[count].complaint);

    strcpy(c[count].status, "Pending");

    printf("\nComplaint added successfully!");
    printf("\nComplaint ID: %d\n", c[count].id);

    count++;
}

void viewComplaints()
{
    int i;

    if (count == 0)
    {
        printf("\nNo complaints available.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        printf("\nComplaint ID: %d", c[i].id);
        printf("\nName: %s", c[i].name);
        printf("\nComplaint: %s", c[i].complaint);
        printf("\nStatus: %s\n", c[i].status);
    }
}

void searchComplaint()
{
    int id, i, found = 0;

    printf("\nEnter Complaint ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (c[i].id == id)
        {
            printf("\nName: %s", c[i].name);
            printf("\nComplaint: %s", c[i].complaint);
            printf("\nStatus: %s\n", c[i].status);
            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("\nComplaint not found.\n");
}

void resolveComplaint()
{
    int id, i, found = 0;

    printf("\nEnter Complaint ID to resolve: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (c[i].id == id)
        {
            strcpy(c[i].status, "Resolved");
            printf("\nComplaint resolved successfully!\n");
            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("\nComplaint not found.\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n\n--- COMPLAINT MANAGEMENT SYSTEM ---");
        printf("\n1. Add Complaint");
        printf("\n2. View Complaints");
        printf("\n3. Search Complaint");
        printf("\n4. Resolve Complaint");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addComplaint();
                break;

            case 2:
                viewComplaints();
                break;

            case 3:
                searchComplaint();
                break;

            case 4:
                resolveComplaint();
                break;

            case 5:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}