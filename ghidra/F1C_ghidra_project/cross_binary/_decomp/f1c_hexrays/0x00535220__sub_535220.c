// f1c  0x00535220  size=142
int __fastcall sub_535220(int a1, int a2, int a3)
{
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  int v8; // [esp-14h] [ebp-1Ch]
  int v9; // [esp-8h] [ebp-10h]

  if ( !a1 || *(_BYTE *)(a1 + 92) != 119 )
    return -2;
  *(_DWORD *)a1 = a2;
  *(_DWORD *)(a1 + 4) = a3;
  if ( !a3 )
    goto LABEL_11;
  while ( 1 )
  {
    if ( *(_DWORD *)(a1 + 16) )
      goto LABEL_7;
    v9 = *(_DWORD *)(a1 + 64);
    v8 = *(_DWORD *)(a1 + 72);
    *(_DWORD *)(a1 + 12) = v8;
    if ( sub_588678(v8, 1, 0x4000, v9) != 0x4000 )
      break;
    *(_DWORD *)(a1 + 16) = 0x4000;
LABEL_7:
    v4 = sub_535E80(a1, 0);
    *(_DWORD *)(a1 + 56) = v4;
    if ( v4 || !*(_DWORD *)(a1 + 4) )
      goto LABEL_11;
  }
  *(_DWORD *)(a1 + 56) = -1;
LABEL_11:
  v5 = sub_536E90(a3);
  v6 = *(_DWORD *)(a1 + 4);
  *(_DWORD *)(a1 + 76) = v5;
  return a3 - v6;
}
