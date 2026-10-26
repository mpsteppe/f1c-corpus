float *__thiscall sub_4DD3A0(_DWORD *this, int a2, float a3, float a4, char **a5, float *a6, char *a7)
{
  char *v7; // eax
  float *result; // eax

  v7 = a7;
  if ( !a7 )
  {
    v7 = (char *)this[10];
    if ( !v7 )
      v7 = byte_5EA438;
  }
  sub_4DC600((int)v7, a2, (int *)&a7, (int *)&a4, a3, a4);
  if ( a5 )
    *a5 = a7;
  result = a6;
  if ( a6 )
    *a6 = a4;
  return result;
}
