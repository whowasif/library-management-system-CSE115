#include<stdio.h>
#include<string.h>

struct shop
{
    int id;
    char bname[100];
    char aname[100];
    char type[100];
    int year;
    float price;
};

struct preorder
{
    int id;
    char pbname[100];
    char paname[100];
    char buyername[100];
    char phnnum[100];
    float price;
    int quantity;
    char ps[100];
};

struct bill
{
    int billno;
    char bname[100];
    char buyername[100];
    char phnnum[100];
    int quantity;
    float price;
    char date[100];
};

int main()
{
    int choose, i, n, j, k, m, nb, np, nbi, index, srchid, flag=0;
    char srchname[100];
    struct shop b[1000];
    struct preorder p[1000];
    struct bill bi[1000];
    char srchtype[100];
    FILE *fp1;
    fp1= fopen("trial project.txt","r");

    fscanf(fp1,"%d",&nb);

     for(i=0; i<nb; i++)
        {
            fscanf(fp1,"%d", &b[i].id);
            fscanf(fp1,"%s", b[i].bname);
            fscanf(fp1,"%s", b[i].aname);
            fscanf(fp1,"%s", b[i].type);
            fscanf(fp1,"%d", &b[i].year);
            fscanf(fp1,"%f", &b[i].price);
        }
    fclose(fp1);
    FILE *fpp;
    fpp = fopen("pre order.txt","r");
    fscanf(fpp,"%d",&np);

    for(i=0; i<np; i++)
    {
        fscanf(fpp,"%d", &p[i].id);
        fscanf(fpp,"%s", p[i].pbname);
        fscanf(fpp,"%s", p[i].paname);
        fscanf(fpp,"%s", p[i].buyername);
        fscanf(fpp," %s", p[i].phnnum);
        fscanf(fpp," %f", &p[i].price);
        fscanf(fpp,"%d", &p[i].quantity);
        fscanf(fpp,"%s", p[i].ps);
    }
    fclose(fpp);

        FILE *fpb;
        fpb=fopen("bill.txt", "r");
        fscanf(fpb,"%d",&nbi);

        for(i=0; i<nbi; i++)
        {
            fscanf(fpb,"%d",&bi[i].billno);
            fscanf(fpb,"%s",bi[i].bname);
            fscanf(fpb,"%s",bi[i].buyername);
            fscanf(fpb,"%s",bi[i].phnnum);
            fscanf(fpb,"%d",&bi[i].quantity);
            fscanf(fpb,"%f",&bi[i].price);
            fscanf(fpb,"%s",bi[i].date);
        }
        fclose(fpb);

    while(1)
    {
        printf("*** Welcome to Monster Book Shop ***\n");
        printf("------------------------------------      \n");
        printf("1. Show all the books ID & Name.\n");
        printf("2. Search for a book.\n");
        printf("3. Add a new book to your stock.\n");
        printf("4. Edit a book’s information.\n");
        printf("5. Remove a book from your stock.\n");
        printf("6. Add book in Pre-Order list.\n");
        printf("7. Show the Pre-Order list.\n");
        printf("8. Make Bill.\n");
        printf("9. Show previous bills.\n");
        printf("10. Exit.\n\n");
        printf("Enter the option you want to choose:");
        scanf("%d",&choose);
        printf("\n");
        switch(choose)
        {
        case 1:
            printf("Here is our book list:-\n");

            for(i=0; i<nb; i++)
                {
                    printf("Book ID: %d \n", b[i].id);
                    printf("Book Name: %s \n", b[i].bname);
                    printf("Author Name: %s \n", b[i].aname);
                    printf("Books Type: %s \n", b[i].type);
                    printf("Publishing: %d \n", b[i].year);
                    printf("Price: %.2f TK\n", b[i].price);
                    printf("\n");
                }
        break;

        case 2:
            printf("1. Search through name.\n");
            printf("2. Search through ID.\n");
            printf("3. Search through Type.\n");
            printf("Choose:");
            scanf("%d",&choose);
            switch(choose)
            {
            case 1:
                printf("Enter the book name you want to see: ");
                scanf("%s", srchname);
                printf("*Here is your book's information: \n");
                flag=0;
                for(i=0; i<nb; i++)
                    {
                        if(strcmp(srchname,b[i].bname)==0)
                            {
                                flag=1;
                                printf("\n");
                                printf("Book ID: %d \n", b[i].id);
                                printf("Book Name: %s \n", b[i].bname);
                                printf("Author Name: %s \n", b[i].aname);
                                printf("Books Type: %s \n", b[i].type);
                                printf("Publishing: %d \n", b[i].year);
                                printf("Price: %.2f TK\n", b[i].price);
                                printf("\n");
                            }
                    }
                    if(flag==0)
                    {
                        printf("NO BOOK FOUND!!\n\n");
                    }
            break;

            case 2:
                printf("Search for a book by ID: ");
                scanf("%d",&srchid);
                printf("*Here is your book's information: \n");

                for(i=0; i<nb; i++)
                    {
                        if(srchid==b[i].id)
                            {
                                index=i;
                            }
                    }
                flag=0;
                for(i=0; i<nb; i++)
                    {
                        if(index==i)
                            {
                                flag=1;
                                printf("\n");
                                printf("Book ID: %d \n", b[i].id);
                                printf("Book Name: %s \n", b[i].bname);
                                printf("Author Name: %s \n", b[i].aname);
                                printf("Books Type: %s \n", b[i].type);
                                printf("Publishing: %d \n", b[i].year);
                                printf("Price: %.2f TK\n", b[i].price);
                                printf("\n");
                            }
                    }
                    if(flag==0)
                    {
                        printf("NO BOOK FOUND!!\n\n");
                    }
            break;

            case 3:
                printf("Enter the book type you want to see: ");
                scanf("%s", srchtype);
                printf("*Here is your book's information: \n");
                flag=0;

                for(i=0; i<nb; i++)
                    {
                        if(strcmp(srchtype,b[i].type)==0)
                            {
                                flag =1;
                                printf("\n");
                                printf("Book ID: %d \n", b[i].id);
                                printf("Book Name: %s \n", b[i].bname);
                                printf("Author Name: %s \n", b[i].aname);
                                printf("Books Type: %s \n", b[i].type);
                                printf("Publishing: %d \n", b[i].year);
                                printf("Price: %.2f TK\n", b[i].price);
                                printf("\n");
                            }
                    }
                    if(flag==0)
                    {
                        printf("NO BOOK FOUND!!\n\n");
                    }

            break;
            }
        break;

        case 3:
            printf("Give new informations:-");

            FILE *fp3;
            fp3= fopen("trial project.txt","w");

            printf("\nEnter ID: ");
            scanf("%d", &b[nb].id);
            printf("\nEnter Name: ");
            scanf("%s", b[nb].bname);
            printf("\nEnter Author Name: ");
            scanf("%s", b[nb].aname);
            printf("\nEnter Type: ");
            scanf("%s", b[nb].type);
            printf("\nEnter Year: ");
            scanf("%d", &b[nb].year);
            printf("\nEnter Price: ");
            scanf("%f", &b[nb].price);

            flag=0;

            nb++;
            fprintf(fp3,"%d\n",nb);

            for(i=0;i<nb; i++)
            {
                flag=1;
                fprintf(fp3,"%d ",b[i].id);
                fprintf(fp3,"%s ",b[i].bname);
                fprintf(fp3,"%s ",b[i].aname);
                fprintf(fp3,"%s ",b[i].type);
                fprintf(fp3,"%d ",b[i].year);
                fprintf(fp3,"%.2f\n",b[i].price);
                //printf("\n");
            }
            fclose(fp3);
            if(flag==1)
            {
                printf("New book added!!\n\n");
            }
        break;

        case 4:
            printf("Enter the book name you want to edit: ");
            scanf("%s",srchname);
            for(i=0; i<nb; i++)
                {  //printf("%s",srchname);
                    if(strcmp(b[i].bname,srchname)==0)
                        {
                            printf("Book Founded!!\n");
                            printf("ID: %d \n",b[i].id);
                            printf("Name: %s \n",b[i].bname);
                            printf("Author: %s \n",b[i].aname);
                            printf("Type: %s\n",b[i].type);
                            printf("Year: %d \n",b[i].year);
                            printf("Price: %.2f\n\n",b[i].price);
                            printf("Choose which field you want to edit:\n ");
                            printf("1. Book's ID. \n");
                            printf("2. Book's Name. \n");
                            printf("3. Author's Name. \n");
                            printf("4. Book's Type.  \n");
                            printf("5. Publishing Year. \n");
                            printf("6. Book's Price. \n");
                            printf("7. Whole Information. \n");
                            printf("Choose:");
                            scanf("%d",&choose);

                            switch(choose)
                            {
                                case 1:
                                     printf("Enter the new ID: ");
                                     scanf("%d", &b[i].id);
                                     printf("New info added!!\n\n");
                                break;

                                case 2:
                                    printf("Enter the new Book's Name: ");
                                    scanf("%s", b[i].bname);
                                    printf("New info added!!\n\n");
                                break;

                                case 3:
                                    printf("Enter the new Author's Name: ");
                                    scanf("%s", b[i].aname);
                                    printf("New info added!!\n\n");
                                break;

                                case 4:
                                    printf("Enter the new Type: ");
                                    scanf("%s", b[i].type);
                                    printf("New info added!!\n\n");
                                break;

                                case 5:
                                    printf("Enter the new Year: ");
                                    scanf("%d", &b[i].year);
                                    printf("New info added!!\n\n");
                                break;

                                case 6:
                                    printf("Enter the new Price: ");
                                    scanf("%f", &b[i].price);
                                    printf("New info added!!\n\n");
                                break;

                                case 7:
                                    printf("Enter the new ID: ");
                                    scanf("%d", &b[i].id);
                                    printf("Enter the new book name: ");
                                    scanf("%s", b[i].bname);
                                    printf("Ented the new author name: ");
                                    scanf("%s", b[i].aname);
                                    printf("Enter the new type: ");
                                    scanf("%s", b[i].type);
                                    printf("Enter the new year: ");
                                    scanf("%d", &b[i].year);
                                    printf("Enter the new price: ");
                                    scanf("%f", &b[i].price);
                                    printf("New info added!!\n\n");
                                break;
                            }
                        }
                }
                        FILE *fp4;
                        fp4=fopen("trial project.txt","w");

                        fprintf(fp4,"%d\n",nb);

                        for(i=0; i<nb; i++)
                            {
                                fprintf(fp4,"%d ",b[i].id);
                                fprintf(fp4,"%s ",b[i].bname);
                                fprintf(fp4,"%s ",b[i].aname);
                                fprintf(fp4,"%s ",b[i].type);
                                fprintf(fp4,"%d ",b[i].year);
                                fprintf(fp4,"%.2f \n",b[i].price);
                            }
                        fclose(fp4);
        break;

        case 5:
            printf("enter the name you want to delete: ");
            scanf("%s",srchname);

            for(i=0; i<nb; i++)
                {
                    if(strcmp(srchname,b[i].bname)==0)
                        {
                            index=i;
                            flag=1;
                        }
                }
            if(flag==1)
            {
            nb--;
            FILE *fp5;
            fp5=fopen("trial project.txt","w");


            fprintf(fp5,"%d\n",nb);

            for(i=0; i<=nb; i++)
            {
                if(i!=index)
                    {
                        fprintf(fp5,"%d ",b[i].id);
                        fprintf(fp5,"%s ",b[i].bname);
                        fprintf(fp5,"%s ",b[i].aname);
                        fprintf(fp5,"%s ",b[i].type);
                        fprintf(fp5,"%d ",b[i].year);
                        fprintf(fp5,"%.2f \n",b[i].price);
                    }

            }
            fclose(fp5);
            printf("Book removed!!\n\n");
            }
                else
                    {
                        printf("No id found");
                    }
            break;
        case 6:
             printf("Give necessary info.-\n");
    FILE *fp1;
    fp1 = fopen("pre order.txt","w");
        printf("\nOrder no.: ");
        scanf("%d", &p[np].id);
        printf("\nBook's Name: ");
        scanf("%s", p[np].pbname);
        printf("\nAuthor Name: ");
        scanf("%s", p[np].paname);
        printf("\nBuyer's name: ");
        scanf("%s", p[np].buyername);
        printf("\nBuyer's phone number: ");
        scanf("%s", p[np].phnnum);
        printf("\nPrice: ");
        scanf(" %f", &p[np].price);
        printf("\nQuantity: ");
        scanf("%d", &p[np].quantity);
        printf("\nPayment status: ");
        scanf("%s", p[np].ps);

         np++;
         fprintf(fp1,"%d\n",np);
    for(i=0;i<np; i++)
    {
         fprintf(fp1,"%d ",p[i].id);
        fprintf(fp1,"%s ", p[i].pbname);
        fprintf(fp1,"%s ",p[i].paname);
        fprintf(fp1,"%s ",p[i].buyername);
        fprintf(fp1,"%s ",p[i].phnnum);
        fprintf(fp1,"%.2f ",p[i].price);
        fprintf(fp1,"%d ",p[i].quantity);
        fprintf(fp1,"%s \n", p[i].ps);
      //  printf("\n");
    }
    fclose(fp1);
    printf("\n");
        break;
        case 7:
            printf("Here is your pre-order list: \n\n");
            for(i=0; i<np; i++)
                {
                    printf("Order No.: %d \n", p[i].id);
                    printf("Book Name: %s \n", p[i].pbname);
                    printf("Author Name: %s \n", p[i].paname);
                    printf("Buyer's name: %s \n", p[i].buyername);
                    printf("Buyer's phone number: %s \n", p[i].phnnum);
                    printf("Price: %.2f TK\n", p[i].price);
                    printf("Quantity: %d \n", p[i].quantity);
                    printf("Payment Status: %s \n", p[i].ps);
                    printf("\n");
                }
                break;
        case 8:

           printf("Search for the book by the name you want to buy: ");
            scanf("%s",srchname);
          //  printf("%d ",n);
           /* FILE *fp80;
                fp80=fopen("trial project.txt","r");
                fscanf(fp80,"%d",&nb);
                fclose(fp80);*/
               // printf("%d",nb);
                for(i=0;i<nb;i++)
                {
                    if(strcmp(srchname,b[i].bname)==0)
                    {
                        index=i;
                    }
                }
                //printf("%d",index);
                FILE *fp8;
                fp8=fopen("bill.txt","r");
                fscanf(fp8,"%d",&nbi);
                //printf("%d",j);
                fclose(fp8);


                 strcpy(bi[nbi].bname,b[index].bname);
                 k=b[index].price;
                 bi[nbi].price = k;
                 //printf("%s",b[index].bname);

                bi[nbi].billno= nbi+1;
                printf("Enter Buyer's Name: ");
                scanf("%s",bi[nbi].buyername);
                printf("Buyer's Phone Number: ");
                scanf("%s",bi[nbi].phnnum);
                printf("Quantity: ");
                scanf("%d",&bi[nbi].quantity);
                printf("date: ");
                scanf("%s",bi[nbi].date);

                float totalamount;
                totalamount= ((bi[nbi].price)*(bi[nbi].quantity));

                printf("\n\n");
                printf("1. Confirm bill.\n");
                printf("2. Go Back.\n");
                printf("Choose:");
                scanf("%d",&choose);
                printf("\n\n");
                switch(choose)
                {
                case 1:

                   printf("____________________________________________________________________\n");
                    printf("|                      **MONSTER BOOK SHOP**                       |\n");
                    printf("|                                                                  |\n");
                    printf("|                             B B                                  |\n");
                    printf("|                           B O O K                                |\n");
                    printf("|                           B O O K                                |\n");
                    printf("|                             K K                                  |\n");
                    printf("|                                                                  |\n");
                    printf("|                         ===Receipt===                            |\n");
                    printf("--------------------------------------------------------------------\n");
                    printf(" Date             |%s      \n",bi[nbi].date);
                    printf("--------------------------------------------------------------------\n");
                    printf(" Buyer's Name     |%s        \n",bi[nbi].buyername);
                    printf("--------------------------------------------------------------------\n");
                    printf(" Phone Number     |%s   \n",bi[nbi].phnnum);
                    printf("--------------------------------------------------------------------\n");
                    printf(" Book's Name      |%s             \n",bi[nbi].bname);
                    printf("--------------------------------------------------------------------\n");
                    printf(" Quantity         |%d Pieces            \n",bi[nbi].quantity);
                    printf("--------------------------------------------------------------------\n");
                    printf(" Total            |%.2fTK             \n",totalamount);
                    printf("--------------------------------------------------------------------\n");
                    printf("|                ***Thank you for buying from us.***               |\n");
                    printf("|                        ***Come Again***                          |\n");
                    printf("____________________________________________________________________\n");

                    nbi++;
                    FILE *fp81;
                    fp81=fopen("bill.txt","w");
                    fprintf(fp81,"%d\n",nbi);

                    for(i=0; i<nbi; i++)
                    {
                        fprintf(fp81,"%d ",bi[i].billno);
                        fprintf(fp81,"%s ",bi[i].bname);
                        fprintf(fp81,"%s ",bi[i].buyername);
                        fprintf(fp81,"%s ",bi[i].phnnum);
                        fprintf(fp81,"%d ",bi[i].quantity);
                        fprintf(fp81,"%.2f ",bi[i].price);
                        fprintf(fp81,"%s\n",bi[i].date);
                    }
                    fclose(fp81);
                    break;


               case 2:
                    break;
        }
        break;

        case 9:
            printf("Here is your previous bills:-\n");

            for(i=0; i<nbi; i++)
                {
                    printf("Bill No.: %d \n",bi[i].billno);
                    printf("Book Name: %s \n", bi[i].bname);
                    printf("Buyer's Name: %s \n",bi[i].buyername);
                    printf("Buyer's Phone Number: %s \n",bi[i].phnnum);
                    printf("Quantity: %d \n",bi[i].quantity);
                    printf("Price: %.2f TK\n",bi[i].price);
                    printf(" Date: %s\n",bi[i].date);
                    printf("\n");
                }
                break;

        case 10:
            printf("Thank you!!");
            return;
            break;
        }
    }
}


