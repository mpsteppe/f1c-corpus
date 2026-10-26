// f1c  0x004dd400  size=78
float *__thiscall sub_4DD400(_DWORD *this, int a2, float a3, int a4, float *a5, float *a6, char *a7)
{
  float *result; // eax

  sub_4DD3A0(this, a2, a3, *(float *)&a4, &a7, (float *)&a4, a7);
  if ( a5 )
    *a5 = (double)(int)a7 / (double)dword_5D6D60;
  result = a6;
  if ( a6 )
    *a6 = (double)a4 / (double)dword_5D6D64;
  return result;
}
