int __thiscall sub_680E9C(_DWORD *this)
{
  unsigned int v1; // eax

  v1 = *this & 0xFFF00000;
  if ( v1 > 0x74200000 )
  {
    if ( v1 == 1949302784
      || v1 == 1950351360
      || v1 == 1951399936
      || v1 == 1952448512
      || v1 == 1953497088
      || v1 == 1956642816 )
    {
      return 1;
    }
    return v1 == 1957691392;
  }
  else
  {
    if ( v1 == 1948254208 )
      return 1;
    if ( v1 > 0x11500000 )
    {
      if ( v1 == 545259520 || v1 == 546308096 )
        return 1;
      return v1 == 1947205632;
    }
    else
    {
      if ( v1 == 290455552 || v1 == 286261248 || v1 == 287309824 || v1 == 288358400 )
        return 1;
      return v1 == 289406976;
    }
  }
}
