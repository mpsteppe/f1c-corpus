int __thiscall sub_5F0380(int this, const char *a2, int *a3, _DWORD *a4, int a5)
{
  unsigned __int64 v5; // rax
  double v6; // st7
  double v7; // st6
  unsigned int i; // edi
  unsigned __int8 v10; // al
  char v11; // cl
  int v12; // eax
  int v13; // eax
  int v15; // [esp+8h] [ebp-4h]
  int v16; // [esp+1Ch] [ebp+10h]

  LODWORD(v5) = a5;
  v6 = 1.0;
  v7 = 1.0;
  v15 = a5 & 0x40;
  if ( (a5 & 0x40) == 0 )
  {
    v6 = *(float *)(this + 152);
    v7 = *(float *)(this + 156);
  }
  if ( a4 )
  {
    if ( (a5 & 0x80u) == 0 )
      v5 = (unsigned __int64)((double)(*(_DWORD *)(this + 104) - 2) * v7);
    else
      LODWORD(v5) = *(_DWORD *)(this + 104) - 2;
    *a4 = v5;
  }
  if ( a3 )
  {
    *a3 = 0;
    for ( i = 0; i < strlen(a2); ++i )
    {
      v10 = a2[i];
      if ( v10 >= 0x20u && v10 < *(int *)(this + 124) )
      {
        v11 = *(_BYTE *)(this + 16);
        v12 = this + 24 * v10 - 584;
        if ( v15 )
        {
          if ( (v11 & 2) != 0 )
            v16 = *(char *)(v12 + 7) + *(unsigned __int8 *)(v12 + 4) + 1;
          else
            v16 = *(unsigned __int8 *)(v12 + 4);
          *a3 += (unsigned __int64)((double)v16 * v6 + 0.5);
        }
        else
        {
          if ( (v11 & 2) != 0 )
            v13 = *(char *)(v12 + 7) + *(unsigned __int8 *)(v12 + 4) + 1 + *a3;
          else
            v13 = *(unsigned __int8 *)(v12 + 4) + *a3;
          *a3 = v13;
        }
      }
    }
    v5 = (unsigned __int64)((double)*a3 * v6);
    *a3 = v5;
  }
  return v5;
}
