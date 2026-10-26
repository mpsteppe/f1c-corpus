_DWORD *sub_464930()
{
  int v0; // eax

  v0 = OperatorNewNhMallocWrapper(58832);
  if ( v0 )
    dword_7CD2A8 = LargeStructInitialization(v0);
  else
    dword_7CD2A8 = 0;
  return &dword_7CD2A8;
}

