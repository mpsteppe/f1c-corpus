DNameNode *__thiscall DNameNode::DNameNode(DNameNode *this)
{
  DNameNode *result; // eax

  result = this;
  *(_DWORD *)this = &off_72B3C0;
  *((_DWORD *)this + 1) = 0;
  return result;
}
