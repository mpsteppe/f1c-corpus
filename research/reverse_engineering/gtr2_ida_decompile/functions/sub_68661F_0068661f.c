int __thiscall sub_68661F(_DWORD *this)
{
  unsigned int i; // edi
  int v2; // edx
  _DWORD *v3; // eax
  int v4; // esi
  int v5; // edx
  int v6; // edx
  int v7; // edx
  int v8; // edx
  int v9; // edx
  _DWORD *v10; // eax
  unsigned int v11; // esi
  int *v12; // edx
  int v13; // edi
  unsigned int k; // esi
  int *v15; // edx
  int v16; // edi
  unsigned int j; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < this[2]; v3[14] = v9 )
  {
    v2 = this[5];
    v3 = *(_DWORD **)(v2 + 4 * i);
    v4 = v3[2];
    if ( v4 == -1 )
      v5 = -1;
    else
      v5 = *(_DWORD *)(*(_DWORD *)(v2 + 4 * v4) + 48);
    v3[2] = v5;
    v6 = v3[5];
    if ( v6 == -1 )
      v7 = -1;
    else
      v7 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v6) + 48);
    v3[5] = v7;
    v8 = v3[14];
    if ( v8 == -1 )
      v9 = -1;
    else
      v9 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * v8) + 48);
    ++i;
  }
  for ( j = 0; j < this[3]; ++j )
  {
    v10 = *(_DWORD **)(this[6] + 4 * j);
    v11 = 0;
    if ( *v10 )
    {
      if ( v10[1] )
      {
        do
        {
          v12 = (int *)(v10[2] + 4 * v11);
          if ( *v12 == -1 )
            v13 = -1;
          else
            v13 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v12) + 48);
          ++v11;
          *v12 = v13;
        }
        while ( v11 < v10[1] );
      }
      for ( k = 0; k < v10[3]; *v15 = v16 )
      {
        v15 = (int *)(v10[4] + 4 * k);
        if ( *v15 == -1 )
          v16 = -1;
        else
          v16 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v15) + 48);
        ++k;
      }
    }
  }
  return 0;
}
