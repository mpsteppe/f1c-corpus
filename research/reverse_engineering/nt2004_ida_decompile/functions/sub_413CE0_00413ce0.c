char __userpurge sub_413CE0@<al>(int a1@<ecx>, char a2@<bpl>, _DWORD *ArgList)
{
  CHAR *v4; // eax
  char v5; // bl
  _BYTE *v6; // edi
  int v7; // ebp
  char v9; // [esp-Ch] [ebp-14h]

  if ( !*ArgList )
    return 0;
  sub_57A400((int)ArgList, aS_7, (char)aSponsor_0);
  sub_57A400((int)ArgList, asc_5FC404, v9);
  v4 = *(CHAR **)a1;
  if ( !*(_DWORD *)a1 )
    v4 = &byte_629120;
  sub_57A400((int)ArgList, aNameS_1, (char)v4);
  sub_57A400((int)ArgList, aIncomeD, *(_DWORD *)(a1 + 8));
  sub_57A400((int)ArgList, aReputationD_0, *(_BYTE *)(a1 + 12));
  sub_57A400((int)ArgList, aContractlength_0, *(_BYTE *)(a1 + 13));
  sub_57A400((int)ArgList, aTimeleftincont_0, *(_BYTE *)(a1 + 14));
  v5 = 0;
  v6 = (_BYTE *)(a1 + 15);
  v7 = 6;
  do
  {
    if ( *v6 )
      sub_57A400((int)ArgList, aLevelD1, v5);
    ++v5;
    ++v6;
    --v7;
  }
  while ( v7 );
  sub_57A400((int)ArgList, asc_5FC34C, a2);
  return 1;
}
