int __thiscall sub_5AD950(_DWORD *this, int a2)
{
  _DWORD *v2; // ebx
  int v3; // esi
  double **v4; // eax
  double **v5; // eax
  int j; // eax
  double **v7; // eax
  double *v8; // ecx
  double **v9; // eax
  int i; // eax
  double **v11; // eax
  double *v12; // edi
  int v13; // edx
  int v14; // edi
  int v15; // ebp
  bool v16; // cc
  double *v18; // [esp+Ch] [ebp-10h]
  double **v19; // [esp+10h] [ebp-Ch]
  int v21; // [esp+18h] [ebp-4h]

  v2 = this;
  v3 = this[79];
  if ( this[76] )
  {
    if ( v3 )
    {
      for ( i = *(_DWORD *)(v3 + 36); i; i = *(_DWORD *)(i + 36) )
        v3 = i;
      v11 = (double **)operator new(0x28u);
      if ( v11 )
        v5 = sub_5AD4D0(v11, (double *)v2[76]);
      else
        v5 = 0;
      *(_DWORD *)(v3 + 36) = v5;
    }
    else
    {
      v9 = (double **)operator new(0x28u);
      if ( v9 )
      {
        v5 = sub_5AD4D0(v9, (double *)v2[76]);
        v2[79] = v5;
      }
      else
      {
        v5 = 0;
        v2[79] = 0;
      }
    }
    v12 = v5[6];
    v5[5] = (double *)v2[76];
    qmemcpy(v12, (const void *)v2[77], 136 * v2[76]);
    v18 = v5[6];
    v19 = v5;
    v21 = 0;
    if ( (int)v2[76] > 0 )
    {
      do
      {
        v13 = *(_DWORD *)(a2 + 12);
        v14 = *(_DWORD *)(a2 + 16);
        v15 = 0;
        if ( v13 > 0 )
        {
          while ( strcmp((const char *)v18 + 68, (const char *)v14) )
          {
            v14 += 44;
            if ( ++v15 >= v13 )
              goto LABEL_29;
          }
          *(_DWORD *)v18 = *(_DWORD *)(v14 + 32);
LABEL_29:
          v2 = this;
          v5 = v19;
        }
        if ( v15 == *(_DWORD *)(a2 + 12) )
          *(_DWORD *)v18 = -1;
        v16 = v21 + 1 < v2[76];
        v18 += 17;
        ++v21;
      }
      while ( v16 );
    }
  }
  else
  {
    if ( v3 )
    {
      for ( j = *(_DWORD *)(v3 + 36); j; j = *(_DWORD *)(j + 36) )
        v3 = j;
      v7 = (double **)operator new(0x28u);
      if ( v7 )
        v5 = sub_5AD4D0(v7, (double *)1);
      else
        v5 = 0;
      *(_DWORD *)(v3 + 36) = v5;
    }
    else
    {
      v4 = (double **)operator new(0x28u);
      if ( v4 )
      {
        v5 = sub_5AD4D0(v4, (double *)1);
        v2[79] = v5;
      }
      else
      {
        v5 = 0;
        v2[79] = 0;
      }
    }
    v8 = v5[6];
    v5[5] = (double *)1;
    *(_DWORD *)v8 = 0;
  }
  v5[7] = (double *)a2;
  sub_5AD820((_BYTE **)v5);
  return 0;
}
