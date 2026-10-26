int __thiscall sub_6A6DC1(_DWORD *this, int a2, _DWORD *a3, int a4, unsigned int a5, int a6)
{
  _DWORD *v6; // esi
  int v7; // eax
  _DWORD *v9; // edi
  _DWORD *v10; // edx
  unsigned int v11; // eax
  int v12; // ecx
  int v13; // eax
  unsigned int v14; // eax
  int v15; // eax
  _DWORD *v16; // esi
  _DWORD *v17; // eax
  int v18; // eax
  _DWORD *v19; // esi
  int *v20; // edx
  int v21; // eax
  unsigned int v22; // ecx
  unsigned int v23; // ecx
  int v24; // edi
  int v25; // ecx
  int v26; // eax
  int *v27; // edx
  int v28; // ecx
  unsigned int v29; // eax
  unsigned int j; // eax
  int v31; // eax
  int i; // [esp+Ch] [ebp-4h]
  unsigned int v34; // [esp+28h] [ebp+18h]
  unsigned int v35; // [esp+28h] [ebp+18h]
  unsigned int v36; // [esp+28h] [ebp+18h]

  v6 = this;
  if ( !a6 )
  {
    v7 = 0;
    v34 = 0;
    if ( a5 )
    {
      while ( 1 )
      {
        v9 = (_DWORD *)(a4 + 4 * v7);
        v10 = (_DWORD *)*v9;
        v11 = *(_DWORD *)*v9 & 0xFFF00000;
        if ( v11 != 285212672 && v11 != 1913651200 )
        {
          v12 = *(_DWORD *)v10[2];
          v13 = *(_DWORD *)(v6[5] + 4 * v12);
          if ( (*(_WORD *)(*(_DWORD *)(v6[4] + 4 * *(_DWORD *)(v13 + 4)) + 4) & 0x840) != 0 )
          {
            v14 = *(_DWORD *)(v13 + 12);
            if ( v14 >= 6 )
              return 0;
            v15 = 4 * v14;
            v16 = (_DWORD *)(v15 + a2);
            if ( *(_DWORD *)(v15 + a2) )
              return 0;
            v17 = &a3[v15 / 4u];
            if ( *v17 == -1 )
            {
              *v17 = v12;
            }
            else if ( *v17 != v12 )
            {
              return 0;
            }
            *v16 = v10;
            *v9 = 0;
            *v17 = *(_DWORD *)v10[2];
          }
        }
        v7 = ++v34;
        if ( v34 >= a5 )
          return 1;
        v6 = this;
      }
    }
    return 1;
  }
  if ( a6 == 1 )
  {
    v18 = 0;
    v35 = 0;
    if ( a5 )
    {
      v19 = a3;
      while ( 1 )
      {
        v20 = (int *)(a4 + 4 * v18);
        v21 = *v20;
        if ( *v20 )
        {
          v22 = *(_DWORD *)v21 & 0xFFF00000;
          if ( v22 != 285212672 && v22 != 1913651200 )
          {
            v23 = 0;
            v24 = a2 - (_DWORD)v19;
            for ( i = a2 - (_DWORD)v19;
                  *(_DWORD *)((char *)v19 + v24) || *v19 != **(_DWORD **)(v21 + 8) && *v19 != -1;
                  v24 = i )
            {
              ++v23;
              ++v19;
              if ( v23 >= 6 )
                break;
            }
            if ( v23 == 6 )
              return 0;
            v19 = a3;
            v25 = v23;
            a3[v25] = **(_DWORD **)(v21 + 8);
            *(_DWORD *)(v25 * 4 + a2) = v21;
            *v20 = 0;
          }
        }
        v18 = ++v35;
        if ( v35 >= a5 )
          return 1;
      }
    }
    return 1;
  }
  if ( a6 != 2 )
    return 1;
  v26 = 0;
  v36 = 0;
  if ( !a5 )
    return 1;
  while ( 1 )
  {
    v27 = (int *)(a4 + 4 * v26);
    v28 = *v27;
    if ( !*v27 )
      goto LABEL_42;
    v29 = *(_DWORD *)v28 & 0xFFF00000;
    if ( v29 != 285212672 && v29 != 1913651200 )
      goto LABEL_42;
    for ( j = 0; j < 6; ++j )
    {
      if ( !*(_DWORD *)(a2 + 4 * j) )
        break;
    }
    if ( j == 6 )
      return 0;
    v31 = j;
    a3[v31] = **(_DWORD **)(v28 + 8);
    *(_DWORD *)(v31 * 4 + a2) = v28;
    *v27 = 0;
LABEL_42:
    v26 = ++v36;
    if ( v36 >= a5 )
      return 1;
  }
}
