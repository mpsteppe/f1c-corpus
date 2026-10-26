int __thiscall sub_435E40(int this)
{
  int result; // eax
  void *v3; // esi

  sub_435A40((_DWORD *)this);
  if ( *(_DWORD *)(this + 20) )
    sub_5BE8AE(*(LPVOID *)(this + 20));
  result = *(_DWORD *)(this + 8);
  if ( result )
    result = sub_5BE8AE(*(LPVOID *)(this + 8));
  v3 = *(void **)this;
  if ( v3 )
    return sub_5BE8AE(v3);
  return result;
}
