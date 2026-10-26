int __thiscall sub_4ECA40(void *this)
{
  int v2; // eax
  int result; // eax
  void *v4; // esi

  v2 = *((_DWORD *)this + 10);
  if ( v2 )
  {
    sub_592310(v2);
    *((_DWORD *)this + 10) = 0;
  }
  if ( *((_DWORD *)this + 7) )
    sub_5BE8AE(*((LPVOID *)this + 7));
  result = *((_DWORD *)this + 3);
  if ( result )
    result = sub_5BE8AE(*((LPVOID *)this + 3));
  v4 = *(void **)this;
  if ( v4 )
    return sub_5BE8AE(v4);
  return result;
}
