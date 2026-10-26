int __stdcall sub_6D5260(int *a1)
{
  int v2; // eax
  int result; // eax
  int v4; // edi
  int v5; // ebx
  int v6; // ecx
  bool v7; // cc
  _DWORD v8[4]; // [esp+4h] [ebp-2Ch] BYREF
  _DWORD v9[4]; // [esp+14h] [ebp-1Ch] BYREF
  _DWORD *v10; // [esp+24h] [ebp-Ch]
  int v11; // [esp+28h] [ebp-8h]
  int v12; // [esp+2Ch] [ebp-4h]
  int *v13; // [esp+38h] [ebp+8h]

  v2 = a1[93];
  memset(v9, 0, sizeof(v9));
  memset(v8, 0, sizeof(v8));
  v12 = v2;
  result = a1[63];
  v11 = 0;
  if ( result > 0 )
  {
    v13 = a1 + 64;
    do
    {
      v4 = *(_DWORD *)(*v13 + 20);
      v5 = *(_DWORD *)(*v13 + 24);
      v6 = v9[v4];
      v10 = &v9[v4];
      if ( !v6 )
      {
        if ( !a1[v4 + 22] )
          a1[v4 + 22] = sub_6B5F80((int)a1);
        sub_6D4FF0(a1, a1[v4 + 22], *(_DWORD *)(v12 + 4 * v4 + 76));
        *v10 = 1;
      }
      if ( !v8[v5] )
      {
        if ( !a1[v5 + 26] )
          a1[v5 + 26] = sub_6B5F80((int)a1);
        sub_6D4FF0(a1, a1[v5 + 26], *(_DWORD *)(v12 + 4 * v5 + 92));
        v8[v5] = 1;
      }
      result = v11 + 1;
      v7 = ++v11 < a1[63];
      ++v13;
    }
    while ( v7 );
  }
  return result;
}
