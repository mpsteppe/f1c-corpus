int sub_4DC250()
{
  int v0; // eax

  v0 = SwitchBasedGlobalLookup(0);
  if ( v0 )
  {
    *(_DWORD *)(v0 + 72) = 16776960;
    sub_49F1C0(dword_7CE048, 880, 140, 16776960, v0, dword_8B8DC8);
  }
  return 0;
}

