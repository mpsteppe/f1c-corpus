int __fastcall sub_5BBB80(int a1, int a2, int a3, int a4)
{
  char v4; // al
  char v5; // al
  int v7; // ecx

  v4 = *(_BYTE *)(a2 + 20) & 0xE3;
  *(_BYTE *)(a2 + 20) = v4;
  if ( a4 )
  {
    if ( a4 != 1 )
      goto LABEL_6;
    v5 = v4 | 8;
  }
  else
  {
    v5 = v4 | 4;
  }
  *(_BYTE *)(a2 + 20) = v5;
LABEL_6:
  if ( *(_DWORD *)(a1 + 16) < *(_DWORD *)(a1 + 4) )
    return sub_5BBC20();
  v7 = a1 + 20;
  if ( a3 )
    return sub_5BBC00(v7);
  else
    return sub_5BBBD0(v7);
}
