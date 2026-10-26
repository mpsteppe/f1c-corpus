DNameNode *__thiscall DNameNode::DNameNode(DNameNode *this)
{
  DNameNode *result; // eax

  result = this;
  *(_DWORD *)this = &off_726A24;
  *((_DWORD *)this + 1) = 0;
  return result;
}
