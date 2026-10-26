char __cdecl sub_5114D5(_DWORD *a1, int a2)
{
  int v3; // edi
  int v5; // [esp+14h] [ebp+4h]

  v3 = a1[94];
  *(_DWORD *)(*a1 + 20) = 117;
  *(_DWORD *)(*a1 + 24) = v3;
  *(_DWORD *)(*a1 + 28) = a2;
  (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, -1);
  while ( 1 )
  {
    if ( v3 < 192 )
    {
LABEL_3:
      v5 = 2;
      goto LABEL_12;
    }
    if ( v3 < 208 || v3 > 215 || v3 == ((a2 + 1) & 7) + 208 || v3 == ((a2 + 2) & 7) + 208 )
    {
      v5 = 3;
    }
    else
    {
      if ( v3 == ((a2 - 1) & 7) + 208 || v3 == ((a2 - 2) & 7) + 208 )
        goto LABEL_3;
      v5 = 1;
    }
LABEL_12:
    *(_DWORD *)(*a1 + 20) = 96;
    *(_DWORD *)(*a1 + 24) = v3;
    *(_DWORD *)(*a1 + 28) = v5;
    (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 4);
    if ( v5 == 1 )
      break;
    if ( v5 != 2 )
      return 1;
    if ( !sub_5110FC(a1) )
      return 0;
    v3 = a1[94];
  }
  a1[94] = 0;
  return 1;
}
