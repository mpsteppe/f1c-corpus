int __thiscall sub_55BFF0(_DWORD *this, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int *v8; // ecx
  int result; // eax

  v8 = (int *)this[a2 + 2];
  if ( !v8 )
    return -1;
  result = sub_55BD20(v8, a3, a4, a5, a6, a7);
  if ( result )
    return -1;
  *this = a2;
  return result;
}
