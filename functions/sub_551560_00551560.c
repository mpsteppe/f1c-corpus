int __thiscall sub_551560(_DWORD *this, int a2)
{
  _DWORD *v2; // ebx
  int v3; // esi
  int *v4; // eax
  int *v5; // eax
  int j; // eax
  int *v7; // eax
  _DWORD *v8; // ecx
  int *v9; // eax
  int i; // eax
  int *v11; // eax
  void *v12; // edi
  int v13; // edx
  int v14; // edi
  int v15; // ebp
  bool v16; // cc
  int v18; // [esp+Ch] [ebp-10h]
  int *v19; // [esp+10h] [ebp-Ch]
  int v21; // [esp+18h] [ebp-4h]

  v2 = this;
  v3 = this[79];
  if ( this[76] )
  {
    if ( v3 )
    {
      for ( i = *(_DWORD *)(v3 + 36); i; i = *(_DWORD *)(i + 36) )
        v3 = i;
      v11 = (int *)OperatorNewNhMallocWrapper(40);
      if ( v11 )
        v5 = sub_5510F0(v11, v2[76]);
      else
        v5 = 0;
      *(_DWORD *)(v3 + 36) = v5;
    }
    else
    {
      v9 = (int *)OperatorNewNhMallocWrapper(40);
      if ( v9 )
      {
        v5 = sub_5510F0(v9, v2[76]);
        v2[79] = v5;
      }
      else
      {
        v5 = 0;
        v2[79] = 0;
      }
    }
    v12 = (void *)v5[6];
    v5[5] = v2[76];
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
          while ( strcmp((const char *)(v18 + 68), (const char *)v14) )
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
        v18 += 136;
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
      v7 = (int *)OperatorNewNhMallocWrapper(40);
      if ( v7 )
        v5 = sub_5510F0(v7, 1);
      else
        v5 = 0;
      *(_DWORD *)(v3 + 36) = v5;
    }
    else
    {
      v4 = (int *)OperatorNewNhMallocWrapper(40);
      if ( v4 )
      {
        v5 = sub_5510F0(v4, 1);
        v2[79] = v5;
      }
      else
      {
        v5 = 0;
        v2[79] = 0;
      }
    }
    v8 = (_DWORD *)v5[6];
    v5[5] = 1;
    *v8 = 0;
  }
  v5[7] = a2;
  EntityFlagSetSubInitChain(v5);
  return 0;
}
