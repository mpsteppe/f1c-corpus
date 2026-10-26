int __stdcall sub_556700(int a1)
{
  int result; // eax

  result = dword_8B8E48 + 32;
  if ( a1 + 32 < dword_8B8E48 + 32 )
    return HighResolutionTimerReset(&dword_8B6C28[19 * a1 + 608]);
  return result;
}

