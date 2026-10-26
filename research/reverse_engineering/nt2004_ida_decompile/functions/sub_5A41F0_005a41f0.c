int __thiscall sub_5A41F0(int this, const char *a2, int *a3, _DWORD *a4, int a5)
{
  __int64 v5; // rax
  double v6; // st7
  double v7; // st6
  const char *v9; // edx
  int v10; // ebp
  unsigned __int8 v11; // al
  int v12; // ecx
  int v13; // eax
  __int64 v14; // rax
  int v16; // [esp+14h] [ebp+Ch]

  LODWORD(v5) = a5;
  v6 = 1.0;
  v7 = 1.0;
  if ( a5 == 1 )
  {
    v6 = *(float *)(this + 172);
    v7 = *(float *)(this + 176);
  }
  if ( a4 )
  {
    if ( (a5 & 0x4000) != 0 )
      LODWORD(v5) = *(_DWORD *)(this + 120) - 2;
    else
      v5 = (__int64)((double)(*(_DWORD *)(this + 120) - 2) * v7);
    *a4 = v5;
  }
  if ( a3 )
  {
    v9 = a2;
    v10 = 0;
    *a3 = 0;
    if ( strlen(a2) )
    {
      while ( 1 )
      {
        v11 = v9[v10];
        if ( v11 < 0x20u || v11 >= *(int *)(this + 140) )
          goto LABEL_21;
        v12 = *(_DWORD *)(this + 100);
        v13 = 16 * v11 + this - 328;
        if ( (a5 & 0x2000) != 0 )
          break;
        if ( (v12 & 0x100000) == 0 )
        {
          LODWORD(v14) = *(unsigned __int8 *)(v13 + 4) + *a3;
LABEL_20:
          *a3 = v14;
          goto LABEL_21;
        }
        *a3 += *(char *)(v13 + 7) + *(unsigned __int8 *)(v13 + 4) + 1;
LABEL_21:
        v9 = a2;
        if ( ++v10 >= strlen(a2) )
          goto LABEL_22;
      }
      if ( (v12 & 0x100000) != 0 )
        v16 = *(char *)(v13 + 7) + *(unsigned __int8 *)(v13 + 4) + 1;
      else
        v16 = *(unsigned __int8 *)(v13 + 4);
      v14 = (__int64)((double)v16 * *(float *)(this + 172) + 0.5 + (double)*a3);
      goto LABEL_20;
    }
LABEL_22:
    v5 = (__int64)((double)*a3 * v6);
    *a3 = v5;
  }
  return v5;
}
