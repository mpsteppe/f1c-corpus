int __thiscall sub_4C2760(void *this)
{
  int v1; // eax

  v1 = LinkedListDereference(this);
  if ( v1 )
    return *(_DWORD *)(v1 + 45380);
  else
    return 0;
}
