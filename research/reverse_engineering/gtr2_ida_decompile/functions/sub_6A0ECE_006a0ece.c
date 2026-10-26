int __thiscall sub_6A0ECE(_DWORD *this, _DWORD *a2, int a3)
{
  unsigned int v3; // edx
  bool v5; // zf

  v3 = *a2 & 0xFFF00000;
  if ( *(_DWORD *)(*(_DWORD *)(this[5] + 4 * *(_DWORD *)(a2[2] + 4 * a3 * (*a2 & 0xFFFFF))) + 108) == 17 )
  {
    if ( v3 == 805306368 )
    {
      if ( !a3 )
        return 1;
    }
    else
    {
      if ( v3 > 0x73800000 )
      {
        if ( v3 == 1950351360 || v3 == 1951399936 || v3 == 1952448512 )
          return 1;
        v5 = v3 == 1953497088;
      }
      else
      {
        if ( v3 == 1937768448 || v3 == 284164096 || v3 == 1934622720 || v3 == 1935671296 )
          return 1;
        v5 = v3 == 1936719872;
      }
      if ( v5 )
        return 1;
    }
  }
  return 0;
}
