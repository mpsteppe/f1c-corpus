unsigned __int16 __thiscall sub_411A50(unsigned __int16 *this, int a2)
{
  unsigned __int16 result; // ax
  bool v3; // zf

  result = 0;
  if ( (unsigned int)a2 <= 0x218 )
  {
    if ( a2 > 397 )
    {
      if ( a2 != 426 )
      {
        v3 = a2 == 536;
LABEL_12:
        if ( !v3 )
          return CircularBufferIndexIncrement(&this[2 * a2]);
        return -1;
      }
    }
    else if ( a2 != 397 )
    {
      if ( a2 > 2 )
      {
        if ( a2 < 291 || a2 > 292 )
          return CircularBufferIndexIncrement(&this[2 * a2]);
        return -1;
      }
      if ( a2 < 1 )
      {
        v3 = a2 == 0;
        goto LABEL_12;
      }
    }
    return 0;
  }
  return result;
}
