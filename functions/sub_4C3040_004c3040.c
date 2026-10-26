int sub_4C3040()
{
  int result; // eax

  result = dword_8AC490;
  if ( dword_8AC490 )
  {
    result = FreeWrapper_7bcf((LPVOID)dword_8AC490);
    dword_8AC490 = 0;
  }
  return result;
}
