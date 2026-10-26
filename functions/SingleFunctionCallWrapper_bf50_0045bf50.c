_DWORD *sub_45BF50()
{
  if ( OperatorNewNhMallocWrapper(118368) )
    dword_7CD25C[0] = AudioChannelInit(dword_7CD25C);
  else
    dword_7CD25C[0] = 0;
  return dword_7CD25C;
}
