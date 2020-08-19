#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int n;
int ara[1000];

void insert()
{
    int n, i, pos, item;
    printf("Enter the numbers: ");
    scanf("%d",&n);
    printf("Enter the items: ");
    for(i=1; i<=n; i++)
    {
        scanf("%d", &ara[i]);
    }
    printf("Enter the position to insert: ");
    scanf("%d", &pos);
    printf("Enter the number to insert: ");
    scanf("%d", &item);
    i = n;
    while(i >= pos)
    {
        ara[i+1] = ara[i];
        i--;
    }
    ara[pos] = item;
    n++;

    for(i=1; i<=n; i++)
    {
        printf("%d\n", ara[i]);
    }
}

void dlte()
{
    int n, i, pos, item;
    printf("Enter the numbers: ");
    scanf("%d",&n);
    printf("Enter the items: ");
    for(i=1; i<=n; i++)
    {
        scanf("%d", &ara[i]);
    }
    printf("Enter the position to delete: ");
    scanf("%d", &pos);
    item = ara[pos];
    for(i=pos; i <= n; i++)
    {
        ara[i] = ara[i+1];
    }
    n--;
    for(i=1; i<=n; i++)
    {
        printf("%d\n", ara[i]);
    }
}

void search()
{
    int i, n, low_indx, high_indx, mid_indx, search;
   printf("Enter the elements: ");
   scanf("%d",&n);
   printf("Enter the items: ");
   for (i = 0; i < n; i++)
    {
      scanf("%d",&ara[i]);
    }
   printf("Enter value to find: ");
   scanf("%d", &search);
   low_indx = 0;
   high_indx = n - 1;
   mid_indx = (low_indx + high_indx)/2;

   while (low_indx <= high_indx)
    {
      if (ara[mid_indx] < search)
      {
         low_indx = mid_indx + 1;
      }
      else if (ara[mid_indx] == search)
      {
         printf("%d found at location %d\n", search, mid_indx+1);
         break;
      }
      else
         high_indx = mid_indx - 1;
         mid_indx = (low_indx + high_indx)/2;

   }
   if (low_indx > high_indx)
    {
      printf("%d is not found in the array\n", search);
    }
}

int sort()
{
    int i,j,k,n,temp;
    printf("Enter the elements: ");
    while(scanf("%d",&n) != EOF)
    {
        printf("Enter the  numbers for sorting: ");
        for(i=0; i<n; i++)
            scanf("%d", &ara[i]);
        for(i=0; i<n-1; i++)
        {
            for(j=i+1; j<n; j++)
            {
                if(ara[i] > ara[j])
                {
                    temp = ara[i];
                    ara[i] = ara[j];
                    ara[j] = temp;
                }
            }
        }
        for(k=0; k<n; k++)
        {
            printf("%d ",ara[k]);
        }
        printf("\n");
    }
}

void random()
{
   int i, n;
   printf("Enter the number: ");
   scanf("%d", &n);
   for(i = 0; i < n; i++)
   {
       ara[i] = rand()%100;
   }
   display_data();

}
int menu()
{
    int select;
    printf("\n");

    do
    {
        printf("1. rndm value\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Search\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        scanf("%d",&select);
    }
    while(select<1 || select>6);

    return select;

}

void display_data()
{
    int i;
    printf("Data is : ");
    for(i = 0; i < n; i++)
        printf("%d ", ara[i]);
}

int main()
{
    int ch, n;
    do
    {
        /*printf("Enter the choice: ");
        scanf("%d",&ch);*/
        ch=menu();
        switch(ch)
        {
        case 1:
            random();
            break;
        case 2:
            insert();
            break;
        case 3:
            dlte();
            break;
        case 4:
            search();
            break;
        case 5:
            display_data();
            break;
        case 6:
            printf("The project is end!\n");
            break;

    }
    }while(ch!=6);
    //return 0;
}
