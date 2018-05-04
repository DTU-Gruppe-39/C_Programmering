

#include<stdio.h>
#include<stdlib.h>

struct linked_list{
    char number;
    struct linked_list *next;
    struct linked_list *previous;
};

typedef struct linked_list node;
node *head = NULL, *tail = NULL;

void insert_at_tail(char number);
void print_forward_order();
void print_list();
int getListLength();

int main()
{
FILE *infile, *outfile;
char c;


  infile = fopen("NECKLACE.DAT", "r");

      if (infile == NULL) {
          printf("Couldn't open .DAT file\n");
          exit(0);
      }

  outfile = fopen("NECKLACE.SOL", "w");

      if(outfile == NULL) {
          printf("Couldn't find .SOL file \n" );
          exit(0);
      }
while (c != EOF) {
for(int i = 0; i < 100; i++){
    c = getc(infile);
    putc(c, outfile);
    insert_at_tail(c);

    if(c == '\n'){
      printf("%d\n", i);
      print_list();
//      free(newNode);

}

}

    return 0;
}
}
// Insert a node at tail of a circular doubly linked list
void insert_at_tail(char number)
{
    node *newNode = (node *) malloc(sizeof(node));

    newNode->number = number;
    newNode->next = newNode;
    newNode->previous = newNode;

    if(head==NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->next = head;
        newNode->previous = tail;
        tail = newNode;
        head->previous = tail;
    }
}


// Print the list in FORWARD order and REVERSE order
void print_list()
{
    printf("FORWARD order print:\n");
    print_forward_order();

}

// Print FORWARD ORDER all node's data of a circular doubly linked list
void print_forward_order()
{
    if(head==NULL)  return;

    node *current = head;

    do
    {
        printf("%c ", current->number);
        current = current->next;
    }   while(current != head);

    printf("\nList Length: %d\n", getListLength());
}



int getListLength()
{
    if(head==NULL) return 0;

    int count = 0;
    node *current = head;

    do
    {
        count++;
        current = current->next;
    }   while(current != head);

    return count;
}
