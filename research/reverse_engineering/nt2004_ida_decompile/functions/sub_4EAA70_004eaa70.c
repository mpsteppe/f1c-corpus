int __thiscall sub_4EAA70(void *this)
{
  int v2; // eax
  int result; // eax
  void *v4; // esi

  v2 = *((_DWORD *)this + 6);
  if ( v2 )
    sub_592C40(v2);
  if ( *((_DWORD *)this + 4) )
    sub_5BE8AE(*((LPVOID *)this + 4));
  result = *((_DWORD *)this + 2);
  if ( result )
    result = sub_5BE8AE(*((LPVOID *)this + 2));
  v4 = *(void **)this;
  if ( v4 )
    return sub_5BE8AE(v4);
  return result;
}
