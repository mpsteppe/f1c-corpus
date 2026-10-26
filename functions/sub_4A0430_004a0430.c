int sub_4A0430()
{
  if ( dword_7D0410 <= 0 )
    return 0;
  if ( dword_7D0410 <= 4 )
  {
    LookupDispatch((_DWORD *)dword_7CD8C0, (int)aMonitorpage, -1);
    return 0;
  }
  if ( dword_7D0410 != 5 )
    return 0;
  if ( StateCheckWrapper(dword_7CD25C) )
    LookupDispatch((_DWORD *)dword_7CD8C0, (int)aMphostgrid, -1);
  else
    LookupDispatch((_DWORD *)dword_7CD8C0, (int)aMpclientgrid, -1);
  return 0;
}
