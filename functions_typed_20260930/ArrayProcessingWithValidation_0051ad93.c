int __cdecl sub_51AD93(_DWORD *a1)
{
  int v2; // edi
  unsigned int v3; // ebx
  unsigned int v4; // eax
  int result; // eax
  unsigned int v6; // [esp+Ch] [ebp-Ch]
  int v7; // [esp+10h] [ebp-8h]
  _DWORD *v8; // [esp+14h] [ebp-4h]
  _DWORD *v9; // [esp+20h] [ebp+8h]

  v2 = a1[101];
  if ( a1[90] || a1[91] != 63 || a1[92] || a1[93] )
  {
    *(_DWORD *)(*a1 + 20) = 118;
    (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, -1);
  }
  v7 = 0;
  if ( (int)a1[72] > 0 )
  {
    v8 = (_DWORD *)(v2 + 32);
    v9 = a1 + 73;
    do
    {
      v3 = *(_DWORD *)(*v9 + 20);
      v4 = *(_DWORD *)(*v9 + 24);
      v6 = v4;
      if ( v3 >= 4 || !a1[v3 + 40] )
      {
        *(_DWORD *)(*a1 + 20) = 49;
        *(_DWORD *)(*a1 + 24) = v3;
        (*(void (__cdecl **)(_DWORD *))*a1)(a1);
        v4 = v6;
      }
      if ( v4 >= 4 || !a1[v4 + 44] )
      {
        *(_DWORD *)(*a1 + 20) = 49;
        *(_DWORD *)(*a1 + 24) = v4;
        (*(void (__cdecl **)(_DWORD *))*a1)(a1);
      }
      sub_51A5EA((int)a1, a1[v3 + 40], v2 + 4 * v3 + 52);
      sub_51A5EA((int)a1, a1[v6 + 44], v2 + 4 * v6 + 68);
      *v8 = 0;
      ++v9;
      ++v8;
      ++v7;
    }
    while ( v7 < a1[72] );
  }
  *(_BYTE *)(v2 + 24) = 0;
  *(_DWORD *)(v2 + 20) = 0;
  *(_DWORD *)(v2 + 8) = 0;
  *(_DWORD *)(v2 + 12) = 0;
  *(_DWORD *)(v2 + 16) = 0;
  result = a1[63];
  *(_DWORD *)(v2 + 48) = result;
  return result;
}

