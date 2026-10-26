int sub_45BE80()
{
  int result; // eax

  AVIStreamCleanup((int)&dword_7CD208);
  result = dword_7CD208;
  if ( dword_7CD208 )
    return FreeWrapper_7bcf((LPVOID)dword_7CD208);
  return result;
}

