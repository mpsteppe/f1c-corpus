int __thiscall sub_4C2990(_DWORD *this)
{
  _DWORD *v1; // eax
  int v2; // edx

  v1 = (_DWORD *)LinkedListDereference(this);
  if ( v1 )
    return FlagsGetter(v1);
  else
    return v2;
}
