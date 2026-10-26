int sub_42DC00()
{
  int result; // eax

  ScoreSlotDeallocator(dword_7C7030);
  result = dword_7C5728;
  if ( dword_7C5728 )
    return FreeWrapper_7bcf((LPVOID)dword_7C5728);
  return result;
}
