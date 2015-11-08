#include<cstdio>
#include<algorithm>

struct avlNode {
  avlNode *parent, *lchild, *rchild;
  int val;
  int freq;
  int height;
};

int getHeight(avlNode* node) {
  if(node==NULL)
    return 0;
  return node->height;
}

avlNode* leftRotate(avlNode* root, avlNode* z) {
  avlNode *zc=z->rchild;
  z->rchild=zc->lchild;
  if(zc->lchild!=NULL)
    zc->lchild->parent=z;
  zc->lchild=z;
  zc->parent=z->parent;
  if(z==root)
    root=zc;
  else if (z==z->parent->lchild)
    z->parent->lchild=zc;
  else
    z->parent->rchild=zc;
  z->parent=zc;
  z->height=std::max(getHeight(z->lchild), getHeight(z->rchild))+1;
  zc->height=std::max(getHeight(zc->lchild),getHeight(zc->rchild))+1;
  return root;
}

avlNode* rightRotate(avlNode* root, avlNode* z) {
  avlNode* zc=z->lchild;
  z->lchild=zc->rchild;
  if(zc->rchild!=NULL)
    zc->rchild->parent=z;
  zc->rchild=z;
  zc->parent=z->parent;
  if(z==root)
    root=zc;
  else if (z==z->parent->lchild)
    z->parent->lchild=zc;
  else
    z->parent->rchild=zc;
  z->parent=zc;
  z->height=std::max(getHeight(z->lchild), getHeight(z->rchild))+1;
  zc->height=std::max(getHeight(zc->lchild),getHeight(zc->rchild))+1;
  return root;
}

int getBalance(avlNode* n) {
  if(n==NULL)
    return 0;
  return getHeight(n->lchild)-getHeight(n->rchild);
}

avlNode* insert(avlNode* root, int value) {
  avlNode* item=new avlNode;
  item->val=value;
  item->freq=1;
  item->height=1;
  item->lchild=NULL;
  item->rchild=NULL;

  avlNode* z=root, *zp=NULL;
  while(z!=NULL) {
    zp=z;
    if(item->val<z->val)
      z=z->lchild;
    else
      z=z->rchild;
  }
  item->parent=zp;
  if(zp==NULL)
    root=item;
  else {
    if(item->val<zp->val)
      zp->lchild=item;
    else
      zp->rchild=item;	
  }
  int balance;
  while(zp!=NULL) {
    zp->height=std::max(getHeight(zp->lchild),getHeight(zp->rchild))+1;

    balance=getBalance(zp);

    if((balance>1)&&(item->val>=zp->lchild->val)) {
      root=leftRotate(root,zp->lchild);
      root=rightRotate(root,zp);
    }
    else if ((balance>1)&&(item->val<zp->lchild->val)) {
      root=rightRotate(root,zp);
    }
    else if((balance<-1)&&(item->val>=zp->rchild->val)) {
      root=leftRotate(root,zp);
    }
    else if((balance<-1)&&(item->val<zp->rchild->val)) {
      root=rightRotate(root,zp->rchild);
      root=leftRotate(root,zp);
    }
    zp=zp->parent;
  }
  return root;
}

avlNode* search(avlNode* root, int key) {
  avlNode* z=root;
  while((z!=NULL)&&(z->val!=key)) {
    if(key<z->val)
      z=z->lchild;
    else
      z=z->rchild;
  }
  return z;
}

avlNode* insIncrement(avlNode* root, int key) {
  avlNode* z;
  z=search(root,key);
  if(z!=NULL)
    z->freq=z->freq+1;
  else
    root=insert(root,key);
  return root;
}

void dispInOrder(avlNode *z) {
  if(z!=NULL) {
    dispInOrder(z->lchild);
    printf("%d -> %d \n",z->val,z->freq);
    dispInOrder(z->rchild);
  }
}

avlNode* compVal(avlNode* z1, avlNode* z2) {
  if((z1==NULL)&&(z2==NULL))
    return NULL;
  else if(z1==NULL)
    return z2;
  else if (z2==NULL)
    return z1;
  else {
    if(z1->freq>z2->freq)
      return z1;
    else
      return z2;
  }
}

avlNode* findMaxVal(avlNode* z) {
  avlNode *zl,*zr,*z1,*z2;
  if(z!=NULL) {
    zl=findMaxVal(z->lchild);
    zr=findMaxVal(z->rchild);
    z1=compVal(zl,zr);
    return compVal(z1,z);
  }
  else
    return NULL;
}

void clear(avlNode* root) {
  if(root==NULL)
    return;
  if (root->lchild!=NULL) {
    clear(root->lchild);
  }
  if(root->rchild!=NULL)
    clear(root->rchild);
  delete root;
}


int main() {
  int nTest,n,temp;
  bool flag;
  avlNode* root,*z;
  scanf("%d",&nTest);
  for(int t=1;t<=nTest;t++) {
    root=NULL;
    flag=false;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
      scanf("%d",&temp);
      root=insIncrement(root,temp);
    }
    z=findMaxVal(root);
    if(z!=NULL) {
      if(z->freq>n/2)
	printf("YES %d\n",z->val);
      else
	printf("NO\n");
    }
    clear(root);
  }
  return 0;
}
