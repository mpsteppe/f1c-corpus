// f1c  0x0042c440  size=497
char sub_42C440()
{
  char result; // al
  int v1; // edi
  __int16 *v2; // esi
  int *v3; // edx
  int v4; // ecx
  const char *v5; // [esp-Ch] [ebp-Ch]

  result = dword_7C54E8;
  if ( !*(_DWORD *)(dword_7C54E8 + 13000) )
  {
    result = byte_7CE254;
    if ( !byte_7CE254 )
    {
      v1 = 0;
      if ( dword_7CB218 > 0 )
      {
        v2 = &word_7CB21C;
        do
        {
          switch ( *v2 )
          {
            case ';':
              sub_42B8D0(7, &dword_7CE6AC, 2, aSteeringAssist);
              break;
            case '<':
              v5 = aOppositeLockAs;
              v3 = &dword_7CE7CC;
              v4 = 6;
              goto LABEL_17;
            case '=':
              sub_42B8D0(8, &dword_7CE718, 2, aBrakingPointAs);
              break;
            case '>':
              sub_42B8D0(2, &dword_7CE7F0, 2, aStabilityAssis);
              break;
            case '?':
              sub_42B8D0(9, &dword_7CE760, 2, aSpinRecovery);
              break;
            case '@':
              v5 = aInvulnerabilit;
              v3 = &dword_7CE784;
              v4 = 5;
              goto LABEL_17;
            case 'A':
              sub_42B8D0(3, &dword_7CE8A4, 3, aAutoShifting);
              break;
            case 'B':
              sub_42B8D0(0, &dword_7CE6F4, 2, aTractionContro);
              break;
            case 'C':
              sub_42B8D0(1, &dword_7CE73C, 2, aAntiLockBrakes);
              break;
            case 'D':
              v5 = aPitLaneAssista;
              v3 = &dword_7CE7A8;
              v4 = 10;
              goto LABEL_17;
            case 'W':
              v5 = aClutchAssistan;
              v3 = &dword_7CE850;
              v4 = 4;
LABEL_17:
              sub_42B8D0(v4, v3, 1, v5);
              break;
            default:
              break;
          }
          ++v1;
          ++v2;
        }
        while ( v1 < dword_7CB218 );
      }
      if ( dword_7CC260 )
        sub_4A5E10(dword_7C54E8 + 13004);
      if ( dword_7CC394 && byte_7C9081 && !byte_7C74A4 )
        sub_447C70(byte_7C9080 == 0, 0);
      if ( dword_7CC3C0 )
        sub_447D00(-1);
      if ( dword_7CC3EC )
        sub_447D00(1);
      if ( dword_7CC6D8 )
        byte_7C9081 = byte_7C9081 == 0;
      result = dword_7CC704;
      if ( dword_7CC704 )
      {
        result = sub_447160(&dbl_7C7428);
        if ( result )
          return sub_4471F0(0);
      }
    }
  }
  return result;
}
