int __cdecl sub_58F1D0(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // edi
  int v6; // esi
  int v7; // ebx
  int v9; // [esp+20h] [ebp+10h]

  if ( a4 == 1 || *(_BYTE *)(a3 + 5) )
  {
    sub_58F270(a3, a2);
    v9 = sub_58F2E0(a3, a2, a5);
    goto LABEL_11;
  }
  v9 = 1;
  v5 = 0;
  v6 = *(unsigned __int8 *)(a3 + 4) >> 2;
  if ( !v6 )
  {
LABEL_11:
    sub_58F5F0(a1, a2, a3);
    return v9;
  }
  v7 = a2;
  while ( *(_BYTE *)(v7 + 5) && sub_58F5C0(v7) )
  {
    ++v5;
    v7 += 8;
    if ( v5 >= v6 )
      goto LABEL_11;
  }
  return 0;
}
