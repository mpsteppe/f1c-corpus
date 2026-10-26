// f1c  0x004b72a0  size=81
float *__thiscall sub_4B72A0(char *this, int a2, float a3)
{
  char *v3; // edx
  float **v4; // eax
  bool v5; // zf
  float *v6; // ecx
  int v7; // edx
  int v8; // eax
  float **v9; // eax

  v3 = &this[16 * a2 + 64];
  v4 = *(float ***)v3;
  v5 = *(_DWORD *)v3 == 0;
  *((_DWORD *)v3 + 2) = *(_DWORD *)v3;
  if ( v5 )
    return 0;
  v6 = *v4;
  if ( *v4 )
  {
    while ( !sub_4B50C0(v6, a3) )
    {
      v8 = *(_DWORD *)(v7 + 8);
      if ( v8 )
        *(_DWORD *)(v7 + 8) = *(_DWORD *)(v8 + 4);
      v9 = *(float ***)(v7 + 8);
      if ( !v9 )
        return 0;
      v6 = *v9;
      if ( !*v9 )
        return v6;
    }
  }
  return v6;
}
