class NodeT
{
  public:
    NodeT(int data);

    int getData();
    NodeT *getLeft();
    NodeT *getRight();

    NodeT(int data, NodeT *left, NodeT *right);
    void setData(int data);
    void setLeft(NodeT *left);
    void setRight(NodeT *right);

  private:
    int data;
    NodeT *left, *right;
};

NodeT::NodeT(int data)
{
    this->data = data;
}

NodeT::NodeT(int data, NodeT *left, NodeT *right)
{
    this->data = data;
    this->left = left;
    this->right = right;
}

int NodeT::getData()
{
    return data;
}

NodeT *NodeT::getLeft()
{
    return left;
}

NodeT *NodeT::getRight()
{
    return right;
}

void NodeT::setData(int data)
{
    this->data = data;
}

void NodeT::setLeft(NodeT *left)
{
    this->left = left;
}
void NodeT::setRight(NodeT *right)
{
    this->right = right;
}
