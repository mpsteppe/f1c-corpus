int *__thiscall sub_507140(_DWORD *this, int a2, int a3, int a4, CHAR **a5, int *a6, CHAR *a7)
{
  CHAR *v7; // eax
  int *result; // eax

  v7 = a7;
  if ( !a7 )
  {
    v7 = (CHAR *)this[10];
    if ( !v7 )
      v7 = &byte_629120;
  }
  sub_505C10((int)v7, a2, &a7, &a4, a3, a4);
  if ( a5 )
    *a5 = a7;
  result = a6;
  if ( a6 )
    *a6 = a4;
  return result;
}
