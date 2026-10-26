float *__thiscall sub_5071A0(_DWORD *this, int a2, int a3, int a4, float *a5, float *a6, CHAR *a7)
{
  float *result; // eax

  sub_507140(this, a2, a3, a4, &a7, &a4, a7);
  if ( a5 )
    *a5 = (double)(int)a7 / (double)dword_6152E8;
  result = a6;
  if ( a6 )
    *a6 = (double)a4 / (double)dword_6152EC;
  return result;
}
