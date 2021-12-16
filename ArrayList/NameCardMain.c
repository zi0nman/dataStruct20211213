#include <stdio.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void){
	List list;
	NameCard comNameCard;
	NameCard* nameCard;
	ListInit(&list);
	int cmdFlag = 0;
	char name[10];
	char phone[10];
	while(1){
		cmdFlag = 0;
		
		printf("***** MENU *****\n");
		printf("1. Insert		: �����͸� �߰�\n");
		printf("2. Search		: �����͸� �˻�, �̸��� �������� �˻�\n");
		printf("3. Modify		: �����͸� ����, �̸��� �������� ����\n");
		printf("4. Delete		: �����͸� ����, �̸��� �������� ����\n");
		printf("5. Print All		: ��� �����͸� ���\n");
		printf("6. Count		: ���� �������� ���� ��ȯ\n");
		printf("7. Exit			: �ܼ� ���α׷��� ����\n");
		printf("* Choose the item : ");
		scanf("%d",&cmdFlag); 
		
		if(cmdFlag == 7){
			printf("[ EXIT ]\n");
			break;
		} else if (cmdFlag == 1){
			printf("[ Insert ]\n");
			printf("* �̸� : ");
			scanf("%s", name);
			printf("* ����ó : ");
			scanf("%s", phone);
			
			nameCard = MakeNameCard(name, phone);
			LInsert(&list, nameCard);
			
		} else if (cmdFlag == 2){
			printf("[ Search ]\n");
			printf("* �̸� : ");
			scanf("%s", name);
			if(LFirst(&list,&nameCard)) {
				if(NameCompare(nameCard, name) == 0) {
					ShowNameCardInfo(nameCard);		
				}
				while(LNext(&list, &nameCard)) {
					if(NameCompare(nameCard, name) == 0) {
						ShowNameCardInfo(nameCard);		
					}
				} 
			} 
			
		} else if (cmdFlag == 3){
			printf("[ Modify ]\n");
			printf("* �̸� : ");
			scanf("%s", name);
			printf("* ������ ����ó : ");
			scanf("%s", phone);
			if(LFirst(&list,&nameCard)) {
				if(NameCompare(nameCard, name) == 0) {
					ChangePhoneNumber(nameCard, phone);		
				}
				while(LNext(&list, &nameCard)) {
					if(NameCompare(nameCard,name) == 0) {
						ChangePhoneNumber(nameCard, phone);		
					}
				} 
			} 
			
		} else if (cmdFlag == 4){
			printf("[ Delete ]\n");
			printf("* �̸� : ");
			scanf("%s", name);
			
			if(LFirst(&list,&nameCard)) {
				if(NameCompare(nameCard, name) == 0) {
					LRemove(&list);
					free(nameCard);		
				}
				while(LNext(&list, &nameCard)) {
					if(NameCompare(nameCard, name) == 0) {
						LRemove(&list);		
						free(nameCard);	
					}
				} 
			} 
			
		} else if (cmdFlag == 5){
			printf("[ Print All ]\n");
			
			if(LFirst(&list,&nameCard)) {
				ShowNameCardInfo(nameCard);		
				while(LNext(&list, &nameCard)) {
					ShowNameCardInfo(nameCard);
				} 
			} 
			
		} else if (cmdFlag == 6){
			printf("[ Count ]\n");
			
			printf("���� �������� �� : %d\n", LCount(&list));
			
		} else {
			printf("**** �߸� �Է��Ͽ����ϴ�.****\n");
		}
		while (getchar() != '\n'); 
		//int�� ������ �޾ƾ� �Ҷ�, ���� �� �ٸ� ������ ������ �Ǹ�, ���� ���⿡ �����Ͽ� �������� �Էµ� \n�� �ݺ��ǰ� �ȴ�. 
	}
	
	return 0;
}
/*
int main(void){
	List list;
	NameCard comNameCard;
	NameCard* nameCard;
	ListInit(&list);
	
	nameCard = MakeNameCard("�ֻ���", "010-1111-1111");
	LInsert(&list, nameCard);
	
	nameCard = MakeNameCard("�����", "010-2222-2222");
	LInsert(&list, nameCard);
	
	nameCard = MakeNameCard("�ڻ���", "010-3333-3333");
	LInsert(&list, nameCard);
	
	// ��� ���� ���
	printf("== ��� ����� ���� ��� ==\n"); 
	if(LFirst(&list,&nameCard)) {
		ShowNameCardInfo(nameCard);		
		while(LNext(&list, &nameCard)) {
			ShowNameCardInfo(nameCard);
		} 
	} 
	
	// �ڻ����� ������ ���
	printf("== �ڻ����� ������ ��� ==\n"); 
	if(LFirst(&list,&nameCard)) {
		if(NameCompare(nameCard,"�ڻ���") == 0) {
			ShowNameCardInfo(nameCard);		
		}
		while(LNext(&list, &nameCard)) {
			if(NameCompare(nameCard,"�ڻ���") == 0) {
				ShowNameCardInfo(nameCard);		
			}
		} 
	} 
	
	// �ڻ����� ���� ���� 
	printf("== �ڻ����� ������ ���� ==\n"); 
	if(LFirst(&list,&nameCard)) {
		if(NameCompare(nameCard,"�ڻ���") == 0) {
			ChangePhoneNumber(nameCard, "010-9999-9999");		
		}
		while(LNext(&list, &nameCard)) {
			if(NameCompare(nameCard,"�ڻ���") == 0) {
				ChangePhoneNumber(nameCard, "010-9999-9999");		
			}
		} 
	} 
	
	// ��� ���� ���
	printf("== ��� ����� ���� ��� ==\n"); 
	if(LFirst(&list,&nameCard)) {
		ShowNameCardInfo(nameCard);		
		while(LNext(&list, &nameCard)) {
			ShowNameCardInfo(nameCard);
		} 
	} 
	
	// �ڻ����� ���� ���� 
	if(LFirst(&list,&nameCard)) {
		if(NameCompare(nameCard,"�ڻ���") == 0) {
			LRemove(&list);
			free(nameCard);		
		}
		while(LNext(&list, &nameCard)) {
			if(NameCompare(nameCard,"�ڻ���") == 0) {
				LRemove(&list);		
				free(nameCard);	
			}
		} 
	} 
	
	// ��� ���� ���
	printf("== ��� ����� ���� ��� ==\n"); 
	if(LFirst(&list,&nameCard)) {
		ShowNameCardInfo(nameCard);		
		while(LNext(&list, &nameCard)) {
			ShowNameCardInfo(nameCard);
		} 
	} 
	printf("���� �������� �� : %d\n",LCount(&list));
	
	return 0;
}
*/