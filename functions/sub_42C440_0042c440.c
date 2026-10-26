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
              AIShiftPattern(7, &dword_7CE6AC, 2, aSteeringAssist);
              break;
            case '<':
              v5 = aOppositeLockAs;
              v3 = &dword_7CE7CC;
              v4 = 6;
              goto LABEL_17;
            case '=':
              AIShiftPattern(8, &dword_7CE718, 2, aBrakingPointAs);
              break;
            case '>':
              AIShiftPattern(2, &dword_7CE7F0, 2, aStabilityAssis);
              break;
            case '?':
              AIShiftPattern(9, &dword_7CE760, 2, aSpinRecovery);
              break;
            case '@':
              v5 = aInvulnerabilit;
              v3 = &dword_7CE784;
              v4 = 5;
              goto LABEL_17;
            case 'A':
              AIShiftPattern(3, &dword_7CE8A4, 3, aAutoShifting);
              break;
            case 'B':
              AIShiftPattern(0, &dword_7CE6F4, 2, aTractionContro);
              break;
            case 'C':
              AIShiftPattern(1, &dword_7CE73C, 2, aAntiLockBrakes);
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
              AIShiftPattern(v4, v3, 1, v5);
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
        SessionTransitionDispatch(dword_7C54E8 + 13004);
      if ( dword_7CC394 && byte_7C9081 && !byte_7C74A4 )
        VisualStateChange(byte_7C9080 == 0, 0);
      if ( dword_7CC3C0 )
        BrakeBiasAdjustmentControl(-1);
      if ( dword_7CC3EC )
        BrakeBiasAdjustmentControl(1);
      if ( dword_7CC6D8 )
        byte_7C9081 = byte_7C9081 == 0;
      result = dword_7CC704;
      if ( dword_7CC704 )
      {
        result = VehicleActive(&dbl_7C7428);
        if ( result )
          return SuspensionVibration(0);
      }
    }
  }
  return result;
}
