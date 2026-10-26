int __thiscall sub_40F0D0(_DWORD *this)
{
  int result; // eax

  if ( *this == -1 )
  {
    LinkedListNodeInsert_0ad0(this);
    NestedLoopCall(this);
    return sub_4BDE20(this);
  }
  return result;
}

