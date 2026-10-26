// f1c  0x004117b0  size=130
int __stdcall sub_4117B0(unsigned int a1, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  int result; // eax

  result = 1;
  if ( a1 <= 1 )
  {
    result = 0;
    if ( a1 )
    {
      *a2 = dword_5BF8D0;
      *a3 = dword_5BF8D4;
      *a4 = off_5BF8E8;
      *a5 = off_5BF8F0;
    }
    else
    {
      *a2 = dword_5BF8C8;
      *a3 = dword_5BF8CC;
      *a4 = off_5BF8D8;
      *a5 = off_5BF8E0;
    }
  }
  return result;
}
