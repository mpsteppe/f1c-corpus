int __thiscall sub_44B780(void *this)
{
  int result; // eax
  LPVOID *v3; // ecx
  LPVOID *v4; // ecx

  result = *((_DWORD *)this + 2);
  *((_DWORD *)this + 1) = 0;
  *(_DWORD *)this = 0;
  if ( result )
  {
    result = sub_5BE8AE((LPVOID)(result - 4));
    *((_DWORD *)this + 2) = 0;
  }
  v3 = (LPVOID *)*((_DWORD *)this + 3);
  if ( v3 )
  {
    sub_44A9B0(v3);
    result = sub_5BE8AE(*((LPVOID *)this + 3));
    *((_DWORD *)this + 3) = 0;
  }
  v4 = (LPVOID *)*((_DWORD *)this + 4);
  if ( v4 )
  {
    sub_44A9B0(v4);
    result = sub_5BE8AE(*((LPVOID *)this + 4));
    *((_DWORD *)this + 4) = 0;
  }
  return result;
}
