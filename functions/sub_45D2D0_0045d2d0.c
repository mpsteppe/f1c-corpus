char __cdecl sub_45D2D0(void *a1, int a2)
{
  char result; // al
  const char *v3; // esi
  int v4; // eax
  char v5; // cl

  result = a2;
  if ( a2 != 2 )
  {
    if ( a2 == 1 )
    {
      byte_7CD2A0 = 1;
      switch ( sub_563E70(a1) )
      {
        case 0:
          v3 = byte_5EA438;
          if ( dword_7C569C != 5 && StringSplitLoop(dword_8AD25C, 2, (int)aDDevF119992002_1, 239) )
            DebugLogWrite((int)dword_8AD25C, (int)aDoneUpdatingGa);
          goto LABEL_16;
        case 1:
          v3 = aGettingGameLis;
          if ( dword_7C569C != 5 && StringSplitLoop(dword_8AD25C, 2, (int)aDDevF119992002_1, 244) )
            DebugLogWrite((int)dword_8AD25C, (int)aGettingGameLis);
          goto LABEL_16;
        case 2:
          v3 = aSearchingLan;
          if ( dword_7C569C != 5 && StringSplitLoop(dword_8AD25C, 2, (int)aDDevF119992002_1, 249) )
            DebugLogWrite((int)dword_8AD25C, (int)aSearchingLan);
          goto LABEL_16;
        case 3:
          v3 = aQueryingGames;
          if ( dword_7C569C != 5 && StringSplitLoop(dword_8AD25C, 2, (int)aDDevF119992002_1, 254) )
            DebugLogWrite((int)dword_8AD25C, (int)aQueryingGames);
LABEL_16:
          if ( BinarySearchInStringTable(byte_5EC4C0, v3, byte_5EC4CC) )
            strcpy(byte_5EC4CC, v3);
          break;
        default:
          if ( BinarySearchInStringTable(byte_5EC4C0, asc_5C5C8C, byte_5EC4CC) )
          {
            v4 = 0;
            do
            {
              v5 = asc_5C5C8C[v4];
              byte_5EC4CC[v4++] = v5;
            }
            while ( v5 );
          }
          break;
      }
      return PathRegistryCallWrapper((int)byte_5EC4CC);
    }
    else if ( dword_7C569C != 5 )
    {
      result = StringSplitLoop(dword_8AD25C, 2, (int)aDDevF119992002_1, 266);
      if ( result )
        return DebugLogWrite((int)dword_8AD25C, (int)aUnknownGamelis);
    }
  }
  return result;
}
