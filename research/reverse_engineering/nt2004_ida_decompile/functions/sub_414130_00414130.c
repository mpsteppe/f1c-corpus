char __userpurge sub_414130@<al>(int a1@<ecx>, char a2@<bl>, _DWORD *ArgList)
{
  char result; // al
  unsigned __int8 i; // bl
  char v6; // al
  unsigned __int8 j; // bl
  char v8; // al
  char v9; // [esp-10h] [ebp-18h]

  result = 0;
  if ( *ArgList )
  {
    sub_57A400((int)ArgList, aS_6, (char)aStats);
    sub_57A400((int)ArgList, asc_5FC484, v9);
    sub_57A400((int)ArgList, aYearD, *(_WORD *)a1);
    sub_57A400((int)ArgList, aNumracesD, *(_BYTE *)(a1 + 2));
    sub_57A400((int)ArgList, aPointsD, *(_DWORD *)(a1 + 12));
    sub_57A400((int)ArgList, aStandingD, *(_BYTE *)(a1 + 16));
    sub_57A400((int)ArgList, aEarningsD, *(_DWORD *)(a1 + 20));
    sub_57A400((int)ArgList, aLapsledD, *(_DWORD *)(a1 + 24));
    if ( *(_DWORD *)(a1 + 4) )
    {
      for ( i = 0; i < *(_BYTE *)(a1 + 2); ++i )
      {
        v6 = *(_BYTE *)(i + *(_DWORD *)(a1 + 4));
        if ( v6 > 0 )
          sub_57A400((int)ArgList, aQualifyingposD, v6);
      }
    }
    if ( *(_DWORD *)(a1 + 8) )
    {
      for ( j = 0; j < *(_BYTE *)(a1 + 2); ++j )
      {
        v8 = *(_BYTE *)(j + *(_DWORD *)(a1 + 8));
        if ( v8 > 0 )
          sub_57A400((int)ArgList, aFinishposD, v8);
      }
    }
    sub_57A400((int)ArgList, asc_5FC2C8, a2);
    return 1;
  }
  return result;
}
