#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct SinhVien
	{
		int MaSV;
		float DTB[10];
		char TenSV[100], DiaChi[100];
		struct SinhVien *next;
		struct SinhVien *back;	
	};
typedef struct SinhVien *pointer;
pointer firstSV;

void NhapFile(FILE *f)
{
	float TempFloat;
	int i;
	pointer p1, p2;
	
	firstSV = (pointer)malloc(sizeof(struct SinhVien));
	fscanf(f,"%d",&firstSV->MaSV);
	fgetc(f);//xuong hang
 	fgets(firstSV->TenSV,100,f);
	fgets(firstSV->DiaChi,100,f);
	
	for (i = 0; i < 10; i++)
	{
		fscanf(f,"%f", &TempFloat);
		firstSV->DTB[i] = TempFloat;
	}
	
	p1 = (pointer)malloc(sizeof(struct SinhVien));
	firstSV->next = p1;
	firstSV->back = NULL;
	while (fgetc(f) != EOF)
	{
		fscanf(f,"%d",&p1->MaSV);
		fgetc(f);//xuong hang
		fgets(p1->TenSV,100,f);
		fgets(p1->DiaChi,100,f);
	
		for (i = 0; i < 10; i++)
		{
			fscanf(f,"%f", &TempFloat);
			p1->DTB[i] = TempFloat;
		}
		p2 = p1;
		p1 = (pointer)malloc(sizeof(struct SinhVien));
		p1->back = p2;
		p2->next = p1;		
	}
	p2->next = NULL;
	free(p1);
	fclose(f);
}

void XuatFile(FILE *f)
{
	pointer p;
	int i;
	
	p = firstSV;
	while (p != NULL)
	{
		fprintf(f,"\n");
		fprintf(f,"\n");
		fprintf(f,"%d\n",p->MaSV);
		fprintf(f,"%s",p->TenSV);
		fprintf(f,"%s",p->DiaChi);
		for (i = 0; i < 9; i++)
		{
			fprintf(f,"%.2f ",p->DTB[i]);
		}
		fprintf(f,"%.2f",p->DTB[9]);
		p = p->next;
	}
	fclose(f);
}

void GiaoDien()
{
	int choice;
	system("cls");
	printf("1>File\n");
	printf("2>Edit\n");
	printf("3>Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	char dir[100] = "";
	switch (choice)
	{
		case 1:
			system("cls");
			printf("#>File\n");
			printf("	1>Save\n");
			printf("	2>Load\n");
			printf("	3>Cancel\n");
			printf("#>Edit\n");
			printf("#>Exit\n");
			printf("Enter your choice: ");
			scanf("%d", &choice);
			switch (choice)
			{
				case 1:
					system("cls");
					printf("Save ...\n");
					printf("Where?\n");
					printf("Your anwser: ");
					scanf("%s", &dir);
					XuatFile(fopen(dir,"w"));
				break;
				case 2:
					system("cls");
					printf("Load ...\n");
					printf("Where?\n");
					printf("Your anwser: ");
					scanf("%s", &dir);
					NhapFile(fopen(dir,"r"));
				break;
				case 3:
				break;
			}
		break;
		case 3:
			exit(0);
		break;
	}
	
}

int main()
{
	while (1 < 2)
	{
		GiaoDien();
	}
}
