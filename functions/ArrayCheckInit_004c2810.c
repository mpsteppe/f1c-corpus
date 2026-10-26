char __thiscall sub_4C2810(void *this)
{
  _DWORD *v1; // eax

  v1 = (_DWORD *)LinkedListDereference(this);
  if ( !v1 )
    return 0;
  sub_4C1050(v1);
  return 1;
}
