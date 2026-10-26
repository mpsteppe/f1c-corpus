int __cdecl sub_55875C(int *a1)
{
  int v2; // eax
  int v3; // ebx
  char v4; // dl
  bool v5; // zf
  int v6; // ecx
  int v7; // eax
  int v8; // eax
  int *v9; // ebx
  int i; // edi
  int v11; // ecx
  int v12; // eax
  unsigned int v13; // edi
  unsigned int v14; // edi
  _DWORD *v15; // eax
  int result; // eax
  int v17; // [esp+10h] [ebp-10h]
  _DWORD *v18; // [esp+10h] [ebp-10h]
  _DWORD *v19; // [esp+14h] [ebp-Ch]
  int *v20; // [esp+14h] [ebp-Ch]
  int v21; // [esp+18h] [ebp-8h]
  int v22; // [esp+1Ch] [ebp-4h]
  int v23; // [esp+1Ch] [ebp-4h]
  bool v24; // [esp+2Bh] [ebp+Bh]

  v2 = a1[90];
  v3 = a1[101];
  v24 = v2 == 0;
  v4 = 0;
  v21 = v3;
  if ( v2 )
  {
    v6 = a1[91];
    if ( v2 > v6 || v6 >= 64 )
      v4 = 1;
    v5 = a1[72] == 1;
  }
  else
  {
    v5 = a1[91] == 0;
  }
  if ( !v5 )
    v4 = 1;
  v7 = a1[92];
  if ( v7 && a1[93] != v7 - 1 )
    v4 = 1;
  if ( a1[93] > 13 )
    v4 = 1;
  if ( v4 )
  {
    *(_DWORD *)(*a1 + 20) = 14;
    *(_DWORD *)(*a1 + 24) = a1[90];
    *(_DWORD *)(*a1 + 28) = a1[91];
    *(_DWORD *)(*a1 + 32) = a1[92];
    *(_DWORD *)(*a1 + 36) = a1[93];
    (*(void (__cdecl **)(int *))*a1)(a1);
  }
  v22 = 0;
  if ( a1[72] > 0 )
  {
    v19 = a1 + 73;
    do
    {
      v8 = *(_DWORD *)(*v19 + 4);
      v9 = (int *)(a1[35] + (v8 << 8));
      v17 = v8;
      if ( !v24 && *v9 < 0 )
      {
        *(_DWORD *)(*a1 + 20) = 111;
        *(_DWORD *)(*a1 + 24) = v8;
        *(_DWORD *)(*a1 + 28) = 0;
        (*(void (__cdecl **)(int *, int))(*a1 + 4))(a1, -1);
        v8 = v17;
      }
      for ( i = a1[90]; i <= a1[91]; ++i )
      {
        v11 = v9[i];
        if ( v11 < 0 )
          v11 = 0;
        if ( a1[92] != v11 )
        {
          *(_DWORD *)(*a1 + 20) = 111;
          *(_DWORD *)(*a1 + 24) = v8;
          *(_DWORD *)(*a1 + 28) = i;
          (*(void (__cdecl **)(int *, int))(*a1 + 4))(a1, -1);
          v8 = v17;
        }
        v9[i] = a1[93];
      }
      ++v22;
      ++v19;
    }
    while ( v22 < a1[72] );
    v3 = v21;
  }
  if ( a1[92] )
  {
    if ( v24 )
      *(_DWORD *)(v3 + 4) = sub_55830C;
    else
      *(_DWORD *)(v3 + 4) = sub_5583EE;
  }
  else if ( v24 )
  {
    *(_DWORD *)(v3 + 4) = sub_557EE6;
  }
  else
  {
    *(_DWORD *)(v3 + 4) = sub_5580E3;
  }
  v23 = 0;
  if ( a1[72] > 0 )
  {
    v18 = (_DWORD *)(v3 + 36);
    v20 = a1 + 73;
    while ( 1 )
    {
      v12 = *v20;
      if ( !v24 )
        break;
      if ( !a1[92] )
      {
        v13 = *(_DWORD *)(v12 + 20);
        if ( v13 >= 4 || !a1[v13 + 40] )
        {
          *(_DWORD *)(*a1 + 20) = 49;
          *(_DWORD *)(*a1 + 24) = v13;
          (*(void (__cdecl **)(int *))*a1)(a1);
        }
        sub_557579((int)a1, a1[v13 + 40], v21 + 4 * v13 + 56);
LABEL_49:
        v3 = v21;
      }
      v15 = v18;
      ++v23;
      ++v20;
      ++v18;
      *v15 = 0;
      if ( v23 >= a1[72] )
        goto LABEL_51;
    }
    v14 = *(_DWORD *)(v12 + 24);
    if ( v14 >= 4 || !a1[v14 + 44] )
    {
      *(_DWORD *)(*a1 + 20) = 49;
      *(_DWORD *)(*a1 + 24) = v14;
      (*(void (__cdecl **)(int *))*a1)(a1);
    }
    sub_557579((int)a1, a1[v14 + 44], v21 + 4 * v14 + 56);
    *(_DWORD *)(v21 + 72) = *(_DWORD *)(v21 + 4 * v14 + 56);
    goto LABEL_49;
  }
LABEL_51:
  *(_BYTE *)(v3 + 24) = 0;
  *(_DWORD *)(v3 + 20) = 0;
  *(_DWORD *)(v3 + 16) = 0;
  *(_DWORD *)(v3 + 32) = 0;
  result = a1[63];
  *(_DWORD *)(v3 + 52) = result;
  return result;
}
