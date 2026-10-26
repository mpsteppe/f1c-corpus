char sub_42E4B0()
{
  char result; // al
  int v1; // esi
  __int16 *v2; // edi

  result = sub_42DBA0();
  if ( result )
  {
    result = byte_76617C;
    if ( !byte_76617C )
    {
      if ( (dword_761FF8 & 1) != 0 && (byte_762119 & 2) != 0 || (dword_761FF8 & 1) != 0 && (byte_762199 & 2) != 0 )
      {
        v1 = 0;
        v2 = &word_762A08;
        while ( v1 < ((dword_761FF8 & 1) != 0 ? dword_762A04 : 0) )
        {
          switch ( *v2 & 0xEFFF )
          {
            case ';':
              sub_42D810(7, (int *)dword_7667B0, 2, aSteeringHelp);
              ++v1;
              ++v2;
              break;
            case '<':
              sub_42D810(8, (int *)dword_76681C, 2, aBrakingHelp);
              ++v1;
              ++v2;
              break;
            case '=':
              sub_42D810(2, (int *)dword_766918, 2, aStabilityContr);
              ++v1;
              ++v2;
              break;
            case '>':
              sub_42D810(9, (int *)dword_766864, 1, aSpinRecovery);
              ++v1;
              ++v2;
              break;
            case '?':
              sub_42D810(5, (int *)dword_766888, 1, aInvulnerabilit);
              ++v1;
              ++v2;
              break;
            case '@':
              sub_42D810(4, (int *)dword_766978, 1, aAutoClutch);
              ++v1;
              ++v2;
              break;
            case 'A':
              sub_42D810(3, (int *)dword_7669CC, 3, aAutoShifting);
              ++v1;
              ++v2;
              break;
            case 'B':
              sub_42D810(0, (int *)dword_7667F8, 2, aTractionContro);
              ++v1;
              ++v2;
              break;
            case 'C':
              sub_42D810(1, (int *)dword_766840, 2, aAntiLockBrakes);
              goto LABEL_19;
            default:
LABEL_19:
              ++v1;
              ++v2;
              break;
          }
        }
      }
      if ( dword_7640D8 && byte_76082E && !byte_75E9CC && byte_76082C )
        sub_44A390(byte_76082D == 0, 0);
      if ( dword_764080 )
        sub_44A420(-1);
      if ( dword_7640AC )
        sub_44A420(1);
      if ( dword_764028 )
        byte_76082E = byte_76082E == 0;
      result = dword_764054;
      if ( dword_764054 )
      {
        result = sub_4497B0(&dbl_75E930);
        if ( result )
          return sub_449840(0);
      }
    }
  }
  return result;
}
