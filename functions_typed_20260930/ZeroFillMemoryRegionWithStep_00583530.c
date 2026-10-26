char __thiscall sub_583530(_DWORD *this, _DWORD *a2, int a3)
{
  _DWORD *v4; // ebx
  int i; // esi
  char result; // al

  LinkedListNodeAppend_6000(a2, 1);
  v4 = this + 4;
  for ( i = 0; i < 8312; i += 4156 )
    result = LinkedListNodeAllocPrepend(v4, i + *a2, 0);
  return result;
}

