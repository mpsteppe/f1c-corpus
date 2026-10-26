int __thiscall sub_6ABF83(_DWORD *this)
{
  int v2; // edi
  int v3; // eax
  _DWORD *v4; // eax
  int result; // eax
  int v6; // edi
  int v7; // eax
  _DWORD *v8; // eax

  v2 = 0;
  if ( this[3] )
  {
    while ( 1 )
    {
      v3 = this[6];
      this[63] = v2;
      v4 = *(_DWORD **)(v3 + 4 * v2);
      this[64] = v4;
      if ( (*v4 & 0xFFF00000) == 0x11000000 )
      {
        result = sub_6A267E(this);
        if ( result < 0 )
          break;
      }
      if ( (unsigned int)++v2 >= this[3] )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    sub_6BC1A9(this);
    v6 = 0;
    if ( this[3] )
    {
      while ( 1 )
      {
        v7 = this[6];
        this[63] = v6;
        v8 = *(_DWORD **)(v7 + 4 * v6);
        this[64] = v8;
        if ( (*v8 & 0xFFF00000) == 0x11000000 )
        {
          result = sub_6A2906(this);
          if ( result < 0 )
            break;
        }
        if ( (unsigned int)++v6 >= this[3] )
          goto LABEL_9;
      }
    }
    else
    {
LABEL_9:
      sub_6BC1A9(this);
      result = sub_6875A0(this);
      if ( result >= 0 )
      {
        result = sub_68FECA(this);
        if ( result >= 0 )
        {
          result = sub_6825A9(this);
          if ( result >= 0 )
          {
            result = sub_688BDF(this);
            if ( result >= 0 )
            {
              sub_6BC1A9(this);
              return 0;
            }
          }
        }
      }
    }
  }
  return result;
}
