__int16 __fastcall sub_5D7710(int a1, int a2, int a3, int a4)
{
  __int16 v4; // ax

  if ( a3 == 1 )
  {
    v4 = *(_WORD *)(a1 + 68);
  }
  else
  {
    v4 = 512;
    if ( a3 != 2 )
      v4 = a3;
  }
  return v4 | a1 & 0xFCFF;
}
