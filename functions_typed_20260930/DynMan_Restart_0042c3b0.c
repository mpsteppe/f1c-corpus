int sub_42C3B0()
{
  int v0; // esi
  int result; // eax

  if ( (unsigned __int8)StringSplitLoop(2, aDDevF119992002_12, 623) )
    DebugLogWrite(&dword_8AD25C, aEnteredDynmanR);
  v0 = 0;
  dword_7C5694 = 0;
  dword_7C5698 = 0;
  AISettingsFileLoader(&dword_7C73E8);
  if ( dword_5C329C > 0 )
  {
    do
    {
      SceneRenderUpdate(1);
      ++v0;
    }
    while ( v0 < dword_5C329C );
  }
  BatchProcessWithFixedStartOffsets(dword_5EA560);
  dword_7C54DC = dword_7C54E4;
  result = dword_7C54F0[dword_7C54E4];
  dword_7C54E0 = result;
  return result;
}

