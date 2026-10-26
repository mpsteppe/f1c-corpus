int sub_42C9F0()
{
  int i; // esi

  if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_12, 933) )
    DebugLogWrite(&dword_8AD25C, aEnteredDynmanP);
  for ( i = 0; i < dword_5C329C; ++i )
    sub_4C6E80(dword_7C54F0[i]);
  WheelDynamicsInit(&dbl_7C7428);
  SeasonScoringReset();
  return GraphicsResourceDestructor(dword_5EA560);
}

