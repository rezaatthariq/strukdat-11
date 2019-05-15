/*
Author 		: M Reza Atthariq Kori 
NPM 		: 140810180060
Kelas		: B
Tanggal		: 15 Mei 2019
Deskripsi	: Program Menu Fungsi Binary Tree
*/

#include<iostream>
using namespace std;

struct Simpul{
    int info;
    Simpul* left;
    Simpul* right;
};

typedef Simpul* pointer;
typedef pointer Tree;

void createSimpul(pointer& pBaru)
{
    pBaru=new Simpul;
    cout<<"Masukkan angka : ";
    cin>>pBaru->info;
    pBaru->left=NULL;
    pBaru->right=NULL;
}

void insertBST (Tree& Root, pointer pBaru)
{
    if(Root==NULL)
	{
        Root=pBaru;
    }
    else if (pBaru->info < Root->info)
	{
        insertBST(Root->left,pBaru);
    }
    else if (pBaru->info >= Root->info)
	{
        insertBST(Root->right,pBaru);
    }
}

void preOrder (Tree Root) {
    if (Root != NULL)
	{
        cout<< Root->info <<endl;
        preOrder(Root->left);
        preOrder(Root->right);
    }
}

void inOrder (Tree Root) 
{
    if (Root != NULL)
	{
        inOrder(Root->left);
        cout<< Root->info <<endl;
        inOrder(Root->right);
    }
}

void postOrder (Tree Root) 
{
    if (Root != NULL)
	{
        postOrder(Root->left);
        postOrder(Root->right);
        cout<< Root->info <<endl;
    }
}

int height(Tree Root)
{
	if (Root==NULL)	return 0;
	else
	{
		int lHeight=height(Root->left);
		int rHeight=height(Root->right);
		
		if (lHeight>rHeight) return (lHeight+1);
		else return (rHeight+1);
	}
}

void givenLevel(Tree Root, int level)
{
	if (Root==NULL) return;
	if (level==1) cout << Root->info <<" ";
	else if (level>1)
	{
		givenLevel(Root->left,level-1);
		givenLevel(Root->right,level-1);
	}
}

void levelOrder(Tree Root)
{
	int h=height(Root);
	for (int i=0; i<=h; i++)
	{
		givenLevel(Root,i);
		cout<<endl;
		cout<<"Tingkat ke-"<<i+1<<" : ";
		
	}
}

void depthOrder (Tree Root)
{
	int h=height(Root);
	for (int i=1; i<=h; i++)
	{
		cout <<"Kedalaman ke-"<< i-1 << " : ";
		givenLevel(Root,i);
		cout << endl;
	} 
}

void printChildren(Tree Root, pointer pBaru)
{
    pBaru=Root;
    if(pBaru!=NULL)
	{
        cout << "Parent Node : " << pBaru->info <<endl;

        if(pBaru->left==NULL)
            cout << "Left Child: NULL" << endl;
        else
            cout << "Left Child: " << pBaru->left->info << endl;
                     
        if(pBaru->right==NULL)
            cout << "Right Child: NULL" << endl;
        else
            cout << "Right Child: " << pBaru->right->info << endl;
		cout<<endl;
		
		printChildren(Root->left, pBaru);
        printChildren(Root->right, pBaru);
    }
}

int main()
{
    Tree Root;
    pointer p;
    int pil, n;
    char jawab;

    Root=NULL;
    
    do
	{
    	system("cls");
    	cout<<"Pilihan Menu : "<<endl;
    	cout<<"1. Insert BST"<<endl;
    	cout<<"2. Tampilan Pre Order"<<endl;
    	cout<<"3. Tampilan In Order"<<endl;
    	cout<<"4. Tampilan Post Order"<<endl;
    	cout<<"5. Tampilan Kedalaman"<<endl;
    	cout<<"6. Tampilan Level/Tingkat"<<endl;
    	cout<<"7. Tampilan Ayah dan Anak"<<endl;
    	cout<<"8. Exit"<<endl;
    	cout<<"Pilih Menu : ";cin>>pil;
    	cout<<"\n";

    	switch(pil){
    		case 1:
    			cout<<"Masukkan banyak data : "; cin>>n;
    			for (int i=0;i<n;i++)
				{
        			createSimpul(p);
        			insertBST(Root,p);
    			}
    			break;
    			
        	case 2:
        		cout<<"Tampilan secara Pre Order"<<endl;
        		preOrder(Root);
        		break;
        
        	case 3:
        		cout<<"Tampilan secara In Order"<<endl;
        		inOrder(Root);
        		break;
        
        	case 4:
        		cout<<"Tampilan secara Post Order"<<endl;
        		postOrder(Root);
        		break;
			
			case 5:
				cout<<"Tampilan Kedalaman"<<endl;
				depthOrder(Root);
				break;
			
			case 6:
				cout<<"Tampilan Level/Tingkat"<<endl;
				levelOrder(Root);
				break;
			
			case 7:
				cout<<"Tampilan Ayah dan Anak"<<endl;
				printChildren(Root,p);
				break;
			
			case 8:
				return 0;
				break;

        	default:
        		cout<<"Pilihan tidak tersedia!"<<endl;
        		break;
    	}
    	cout<<"\nKembali ke menu?(Y/N)"; cin>>jawab;
	}
	while(jawab=='y'|| jawab=='Y');
}
