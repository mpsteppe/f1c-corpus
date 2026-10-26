int __thiscall sub_4FA640(void *this)
{
  if ( StringSplitLoop(dword_8AD25C, 2, (int)aDDevF119992002_26, 1136) )
    DebugLogWrite((int)dword_8AD25C, (int)aEnteredVidmanR);
  sub_42D210(&dword_7C569C, 0);
  switch ( dword_7C56A4 )
  {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      GlobalFlagSetClear(64, 0);
      GlobalFlagSetClear(128, 1);
      goto LABEL_6;
    case 5:
      GlobalFlagSetClear(64, 1);
      GlobalFlagSetClear(128, 0);
LABEL_6:
      GlobalFlagSetClear(256, 1);
      break;
    case 6:
    case 7:
      GlobalFlagSetClear(64, 1);
      GlobalFlagSetClear(128, 1);
      GlobalFlagSetClear(256, 0);
      if ( dword_7C56A4 == 7
        && dword_8AB6E4 != 2
        && !ConditionalFlagReturn(&dword_5EA43C)
        && byte_7CE254
        && !SessionStateCheckWrapper(dword_7CD25C) )
      {
        sub_42D210(&dword_7C569C, 1);
      }
      break;
    default:
      GlobalFlagSetClear(64, 0);
      GlobalFlagSetClear(128, 0);
      GlobalFlagSetClear(256, 0);
      break;
  }
  sub_4F9FC0(this, 0.0);
  dbl_8AFEA8 = 0.0;
  dword_8AFE84 = 0;
  ConditionalInitBranch(&dword_8AFCA8, dword_8AFCAC);
  return GlobalFloatSetter(0);
}
