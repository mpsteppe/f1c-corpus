int sub_4FAD00()
{
  int result; // eax

  if ( StringSplitLoop(dword_8AD25C, 2, (int)aDDevF119992002_26, 1457) )
    DebugLogWrite((int)dword_8AD25C, (int)aEnteredVidmanE_0);
  CollisionSystemShutdownCleanup();
  GlobalDispatch(dword_8AFE64);
  sub_4A1830();
  sub_4A14E0();
  sub_4A1830();
  result = dword_8AFE64;
  if ( dword_8AFE64 )
  {
    result = TestAndFreeWrapper(&dword_8AFE64);
    dword_8AFE64 = 0;
  }
  return result;
}

