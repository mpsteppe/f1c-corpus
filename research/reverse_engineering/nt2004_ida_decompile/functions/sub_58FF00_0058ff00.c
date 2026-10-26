int __cdecl sub_58FF00(int a1, int a2, _DWORD *a3)
{
  int v3; // esi
  int v4; // ebp
  unsigned int v5; // ecx
  unsigned int v6; // edx
  char *v7; // eax
  int v8; // esi
  int v9; // ecx
  char *v10; // edi
  int i; // ebp
  int v13; // [esp+10h] [ebp-4h]

  sub_58FED0((int)a3);
  v3 = a1;
  v4 = a2;
  v13 = *(unsigned __int8 *)(a1 + 5);
  if ( a2 >= v13 )
    return 0;
  v5 = *(_BYTE *)(a1 + 4) & 0xF;
  a3[2] = v5;
  v6 = v5 + 2;
  v7 = (char *)(a2 * (v5 + 2) + a1 + 12);
  if ( v5 )
  {
    qmemcpy(a3 + 3, (const void *)(a2 * (v5 + 2) + a1 + 14), v5);
    v3 = a1;
  }
  if ( *v7 < 0 )
  {
    v4 = *(unsigned __int8 *)(a2 * (v5 + 2) + a1 + 13);
    v7 = (char *)(v4 * v6 + v3 + 12);
  }
  v8 = (*(unsigned __int8 *)(v3 + 7) + 1) << 8;
  v9 = v8 * ((unsigned __int8)v7[1] + ((unsigned __int8)*v7 << 8));
  v10 = &v7[v6];
  a3[1] = v9;
  for ( i = v4 + 1; ; ++i )
  {
    if ( i >= v13 )
    {
      *a3 = v8 * *(unsigned __int16 *)(a1 + 8) - v9;
      return 1;
    }
    if ( *v10 >= 0 )
      break;
    v10 += v6;
  }
  *a3 = v8 * ((unsigned __int8)v10[1] + ((unsigned __int8)*v10 << 8)) - v9;
  return 1;
}
