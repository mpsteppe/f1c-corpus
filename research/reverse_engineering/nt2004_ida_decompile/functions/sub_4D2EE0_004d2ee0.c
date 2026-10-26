char __thiscall sub_4D2EE0(char *this, int a2, float a3)
{
  float ***v3; // edx
  float **v4; // eax
  bool v5; // zf
  float *v6; // ecx
  float *v7; // esi
  float **v8; // eax
  float **v9; // eax
  char result; // al

  v3 = (float ***)&this[16 * a2 + 2304];
  v4 = *v3;
  v5 = *v3 == 0;
  v3[2] = *v3;
  if ( v5 )
    v6 = 0;
  else
    v6 = *v4;
  v7 = 0;
  if ( !v6 )
    return 0;
  while ( *v6 <= (double)a3 )
  {
    v8 = v3[2];
    v7 = v6;
    if ( v8 )
      v3[2] = (float **)v8[1];
    v9 = v3[2];
    if ( !v9 )
      return 0;
    v6 = *v9;
    if ( !*v9 )
      return 0;
  }
  if ( !v7 )
    return 0;
  result = 1;
  if ( !*((_BYTE *)v7 + 4) )
    return 0;
  return result;
}
