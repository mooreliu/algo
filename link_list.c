#include "link_list.h"

// typedef stuct LinkList  LinkList;
SingleLinkList* linkList = NULL;


BOOL init() {
    printf(" ==== LinkList init ==== \n");

    linkList = (SingleLinkList*)malloc(sizeof(SingleLinkList));
    if(linkList == NULL) {
        return FALSE;
    }

    SingleLinkListNode* head = (SingleLinkListNode*)malloc(sizeof(SingleLinkListNode));
    head->data = NULL;
    head->next = NULL;
    linkList->head = head;
    linkList->tail = head;
    linkList->size = 0;

    return TRUE; 
}

BOOL add(void* data) {
    printf(" ===== LinkList add ==== \n");
    SingleLinkListNode* newNode = (SingleLinkListNode*)malloc(sizeof(SingleLinkListNode));
    if(newNode == NULL) {
        return FALSE;
    }

    newNode->data = data;
    newNode->next = NULL;
    linkList->tail->next = newNode;
    linkList->tail = newNode;
    linkList->size++;

    return TRUE;
}

BOOL del(int pos) {
    printf(" ==== LinkList delele ==== \n");
    if(pos < 1) {
        return FALSE;//pos=0 代表头，头的next节点的pos=1
    }

    SingleLinkListNode* pre = linkList->head;
    if(pre == NULL) {
        return FALSE;//without head
    }
    SingleLinkListNode* cur = pre->next;//pos=1
    if(cur == NULL) {
        return FALSE;//empty link list
    }
    SingleLinkListNode* next = cur->next;
    
    while(--pos > 0) {
        if(next == NULL && pos !=0 ) {
            return FALSE;
        }
        pre = pre->next;
        cur = cur->next;
        next = next->next;
    }

    pre->next = next;
    free(cur);

    return TRUE;
}

int main(int argc, char const *argv[])
{
    init();
    add("he");
    add("llo");
    add("wor");
    add("ld");
    del(1);
    printf("link list size = %zu \n", linkList->size);

    SingleLinkListNode *p= linkList->head->next;
    while(p != NULL) {
        printf(" %s \n", p->data);
        p = p->next;
    }
    /* code */
    return EXIT_SUCCESS;
}
