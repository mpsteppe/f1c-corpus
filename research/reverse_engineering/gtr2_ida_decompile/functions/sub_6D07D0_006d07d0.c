int __stdcall sub_6D07D0(int *a1)
{
  int v2; // ecx
  int v3; // ebx
  _DWORD *v4; // edi
  bool v5; // zf
  int v6; // edx
  int v7; // eax
  int v8; // ecx
  int v9; // ecx
  int *v10; // ebx
  int v11; // eax
  int i; // edi
  int v13; // eax
  bool v14; // cc
  int v15; // eax
  unsigned int v16; // eax
  _DWORD *v17; // ebx
  int result; // eax
  _DWORD *v19; // [esp+Ch] [ebp-10h]
  int v20; // [esp+10h] [ebp-Ch]
  _DWORD *v21; // [esp+10h] [ebp-Ch]
  int *v22; // [esp+14h] [ebp-8h]
  int *v23; // [esp+14h] [ebp-8h]
  BOOL v24; // [esp+18h] [ebp-4h]
  int v25; // [esp+24h] [ebp+8h]
  int v26; // [esp+24h] [ebp+8h]
  int v27; // [esp+24h] [ebp+8h]

  v2 = a1[101];
  v3 = a1[102];
  v4 = (_DWORD *)a1[112];
  v19 = v4;
  v25 = 0;
  v24 = v2 == 0;
  if ( v2 )
  {
    if ( v2 > v3 || v3 >= 64 )
      v25 = 1;
    v5 = a1[83] == 1;
  }
  else
  {
    v5 = v3 == 0;
  }
  if ( !v5 )
    v25 = 1;
  v6 = a1[103];
  if ( v6 && a1[104] != v6 - 1 )
    v25 = 1;
  if ( a1[104] > 13 || v25 )
  {
    v7 = *a1;
    *(_DWORD *)(v7 + 20) = 16;
    *(_DWORD *)(v7 + 24) = v2;
    v8 = a1[104];
    *(_DWORD *)(v7 + 28) = v3;
    *(_DWORD *)(v7 + 32) = v6;
    *(_DWORD *)(v7 + 36) = v8;
    (*(void (__stdcall **)(int *))v7)(a1);
  }
  v26 = 0;
  if ( a1[83] > 0 )
  {
    v22 = a1 + 84;
    do
    {
      v9 = *(_DWORD *)(*v22 + 4);
      v10 = (int *)(a1[41] + (v9 << 8));
      v20 = v9;
      if ( !v24 && *v10 < 0 )
      {
        v11 = *a1;
        *(_DWORD *)(v11 + 20) = 115;
        *(_DWORD *)(v11 + 24) = v9;
        *(_DWORD *)(v11 + 28) = 0;
        (*(void (__stdcall **)(int *, int))(v11 + 4))(a1, -1);
        v9 = v20;
      }
      for ( i = a1[101]; i <= a1[102]; ++i )
      {
        if ( a1[103] != (v10[i] < 0 ? 0 : v10[i]) )
        {
          v13 = *a1;
          *(_DWORD *)(v13 + 20) = 115;
          *(_DWORD *)(v13 + 24) = v9;
          *(_DWORD *)(v13 + 28) = i;
          (*(void (__stdcall **)(int *, int))(v13 + 4))(a1, -1);
          v9 = v20;
        }
        v10[i] = a1[104];
      }
      v14 = ++v26 < a1[83];
      ++v22;
    }
    while ( v14 );
    v4 = v19;
  }
  if ( a1[103] )
  {
    if ( v24 )
      v4[1] = sub_6D0340;
    else
      v4[1] = sub_6D0430;
  }
  else if ( v24 )
  {
    v4[1] = sub_6CFEE0;
  }
  else
  {
    v4[1] = sub_6D0110;
  }
  v27 = 0;
  if ( a1[83] > 0 )
  {
    v21 = v4 + 6;
    v23 = a1 + 84;
    do
    {
      v15 = *v23;
      if ( v24 )
      {
        if ( !a1[103] )
          sub_6CF3E0(a1, 1u, *(_DWORD *)(v15 + 20), &v4[*(_DWORD *)(v15 + 20) + 11]);
      }
      else
      {
        v16 = *(_DWORD *)(v15 + 24);
        v17 = &v4[v16 + 11];
        sub_6CF3E0(a1, 0, v16, v17);
        v4[15] = *v17;
      }
      *v21++ = 0;
      ++v27;
      ++v23;
    }
    while ( v27 < a1[83] );
  }
  result = a1[70];
  v4[4] = 0;
  v4[3] = 0;
  v4[2] = 0;
  v4[5] = 0;
  v4[10] = result;
  return result;
}
