#include<stdio.h>
#include<stdlib.h>

struct node{
    int coff;
    int exp;
    struct node*next;
};
struct node*insert(struct node*head,int co,int ex){
    struct node*temp;
    struct node*newn=malloc(sizeof(struct node));
    newn->coff=co;
    newn->exp=ex;
    newn->next=NULL;

    if(head==NULL || ex>head->exp){
        newn->next=head;
        head=newn;
    }
    else{
        temp=head;
        while(temp->next!=NULL &&temp->next->exp>ex){temp=temp->next;}
            newn->next=temp->next;
            temp->next=newn;
        
        
    }
    return head;
 }
 struct node*creat(struct node*head)
 {
    int n;
    printf("enter the no of terms");
    scanf("%d",&n);
    int coff;
    int exp;
    for(int i=0;i<n;i++){
    printf("enetr the coff of term: %d",i+1);
    scanf("%d",&coff);
      printf("enetr the exp of term: %d",i+1);
    scanf("%d",&exp);

    head=insert(head,coff,exp);
 }
 return head;
 }

 
  void print(struct node* head) {
    if (head == NULL) {
        printf("No polynomial\n");
        return;
    }
    struct node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coff, temp->exp);
        temp = temp->next;
        if (temp != NULL) printf(" + ");
    }
    printf("\n");

   
}




 void addpoly(struct node*head1,struct node*head2){
        struct node*ptr1=head1;
        struct node*ptr2=head2;
        struct node*head3=NULL;

        while(ptr1!=NULL && ptr2!=NULL)
        {
            if(ptr1->exp==ptr2->exp){
                head3=insert(head3,ptr1->coff+ptr2->coff,ptr1->exp);
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }

            else if(ptr1->exp>ptr2->exp)
            {
                head3=insert(head3,ptr1->coff,ptr1->exp);
                ptr1=ptr1->next;
            }

              else if(ptr1->exp<ptr2->exp)
            {
                head3=insert(head3,ptr2->coff,ptr2->exp);
                ptr2=ptr2->next;
            }

        }

        while(ptr1!=NULL){
            head3=insert(head3,ptr1->coff,ptr1->exp);
            ptr1=ptr1->next;
        }

                while(ptr2!=NULL){
            head3=insert(head3,ptr2->coff,ptr2->exp);
            ptr2=ptr2->next;
        }

        printf("added poly is");
        print(head3);


    }


  int main(){
    struct node*head1=NULL;
    struct node*head2=NULL;
    printf("enter 1st poly\n");
    head1=creat(head1);
     printf("enter 2nd poly\n");
    head2=creat(head2);

    addpoly(head1,head2);
    return 0;

  }