char *__stdcall sub_451960(int a1)
{
  if ( a1 <= 128 )
  {
    if ( (unsigned int)a1 < 0x5A )
      return &aPause_0[16 * a1];
    else
      return &byte_629120;
  }
  else if ( (unsigned int)(a1 - 128) < 0x58 )
  {
    return &aNA[16 * a1 - 2048];
  }
  else
  {
    return &byte_629120;
  }
}
