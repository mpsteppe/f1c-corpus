int __thiscall sub_5531F0(int this, const char *a2, int *a3, int *a4, int a5)
{
  int result; // eax
  double v6; // st7
  unsigned int v8; // edx
  unsigned __int8 v9; // al

  result = a5;
  v6 = 1.0;
  if ( a5 )
    v6 = *(float *)(this + 92);
  if ( a4 )
  {
    result = CRTFtol(v6);
    *a4 = result;
  }
  if ( a3 )
  {
    v8 = 0;
    for ( *a3 = 0; v8 < strlen(a2); ++v8 )
    {
      v9 = a2[v8];
      if ( v9 >= 0x20u && v9 < *(int *)(this + 68) )
        *a3 += *(unsigned __int8 *)(this + 8 * v9 - 148);
    }
    result = CRTFtol(v6);
    *a3 = result;
  }
  return result;
}
