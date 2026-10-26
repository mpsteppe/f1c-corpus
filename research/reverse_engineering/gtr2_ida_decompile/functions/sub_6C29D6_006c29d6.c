int __thiscall sub_6C29D6(_DWORD *this, _DWORD *a2, int a3, unsigned int a4)
{
  int v6; // eax
  _DWORD *v7; // ecx
  int v8; // eax
  unsigned int v9; // eax
  _DWORD *v10; // eax
  int v11; // ecx
  unsigned int v12; // ecx
  unsigned int v13; // edx
  int v14; // ecx
  int v15; // ecx
  unsigned int v16; // ecx
  unsigned int v17; // eax
  unsigned int v18; // edi
  unsigned int i; // eax
  void *v21; // ecx
  unsigned int j; // eax
  int v23; // ecx
  int v24; // [esp+Ch] [ebp-14h]
  int v25; // [esp+10h] [ebp-10h]
  _DWORD *v26; // [esp+10h] [ebp-10h]
  _DWORD *v27; // [esp+14h] [ebp-Ch]
  unsigned int v28; // [esp+18h] [ebp-8h]
  unsigned int v29; // [esp+1Ch] [ebp-4h]
  unsigned int v30; // [esp+28h] [ebp+8h]

  if ( (*(int (__thiscall **)(_DWORD *, _DWORD *, _DWORD))(*this + 32))(this, a2, 0) )
    goto LABEL_39;
  v29 = 0;
  v6 = a2[3];
  v30 = -1;
  if ( v6 )
  {
    v7 = (_DWORD *)a2[4];
    v25 = v6;
    do
    {
      v8 = *(_DWORD *)(this[5] + 4 * *v7);
      if ( v29 < *(_DWORD *)(v8 + 76) )
        v29 = *(_DWORD *)(v8 + 76);
      v9 = *(_DWORD *)(v8 + 72);
      if ( v30 > v9 )
        v30 = v9;
      ++v7;
      --v25;
    }
    while ( v25 );
  }
  if ( a2[1] )
  {
    v26 = (_DWORD *)a2[2];
    v24 = a2[1];
    do
    {
      v10 = *(_DWORD **)(this[5] + 4 * *v26);
      if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * v10[1]) + 4) & 2) != 0 )
      {
        v11 = v10[18];
        if ( v11 != -1 )
        {
          v12 = v11 + 1;
          if ( v29 < v12 )
            v29 = v12;
          while ( 1 )
          {
            v16 = v10[20];
            if ( v30 < v16 )
              break;
            if ( v16 == -1 )
              goto LABEL_29;
            v13 = 0;
            if ( !a4 )
              goto LABEL_29;
            v14 = *(_DWORD *)(this[6] + 4 * v16);
            do
            {
              if ( *(_DWORD *)(a3 + 4 * v13) == v14 )
                break;
              ++v13;
            }
            while ( v13 < a4 );
            if ( v13 >= a4 )
              goto LABEL_29;
            v15 = *(_DWORD *)(a3 + 4 * v13);
            v28 = 0;
            if ( *(_DWORD *)(v15 + 12) )
            {
              v27 = *(_DWORD **)(v15 + 16);
              do
              {
                if ( v10[4] == *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *v27) + 16) )
                  break;
                ++v28;
                ++v27;
              }
              while ( v28 < *(_DWORD *)(v15 + 12) );
            }
            if ( v28 >= *(_DWORD *)(v15 + 12) )
            {
LABEL_29:
              v30 = v10[20] - 1;
              break;
            }
            v10 = *(_DWORD **)(this[5] + 4 * *(_DWORD *)(*(_DWORD *)(v15 + 16) + 4 * v28));
          }
        }
      }
      ++v26;
      --v24;
    }
    while ( v24 );
  }
  v17 = 0;
  if ( a4 )
  {
    do
    {
      v18 = *(_DWORD *)(*(_DWORD *)(this[5] + 4 * **(_DWORD **)(*(_DWORD *)(a3 + 4 * v17) + 16)) + 72);
      if ( v18 >= v29 && v18 <= v30 )
        break;
      ++v17;
    }
    while ( v17 < a4 );
  }
  else
  {
    v18 = 0;
  }
  if ( v17 == a4 || (*(int (__thiscall **)(_DWORD *, _DWORD *, unsigned int))(*this + 52))(this, a2, v18) )
  {
LABEL_39:
    if ( a2 )
      sub_66238F(a2, 1);
    return 1;
  }
  else
  {
    for ( i = 0; i < a4; ++i )
      **(_DWORD **)(a3 + 4 * i) = 0;
    v21 = *(void **)(this[6] + 4 * v18);
    if ( v21 )
      sub_66238F(v21, 1);
    *(_DWORD *)(this[6] + 4 * v18) = a2;
    for ( j = 0; j < a2[3]; *(_DWORD *)(v23 + 72) = v18 )
      v23 = *(_DWORD *)(this[5] + 4 * *(_DWORD *)(a2[4] + 4 * j++));
    return 0;
  }
}
