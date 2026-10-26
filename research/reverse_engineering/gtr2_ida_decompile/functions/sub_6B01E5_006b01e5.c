int __thiscall sub_6B01E5(_DWORD *this)
{
  int result; // eax
  unsigned int v3; // ebx
  int v4; // edi
  int v5; // eax

  result = sub_6C6CB5((int)this);
  if ( result >= 0 )
  {
    sub_6BC1A9(this);
    v3 = this[3];
    v4 = 0;
    if ( v3 )
    {
      while ( 1 )
      {
        v5 = *(_DWORD *)(this[6] + 4 * v4);
        this[64] = v5;
        this[63] = v4;
        if ( (*(_WORD *)(v5 + 2) & 0xFFF0) != 0 )
        {
          result = sub_6AF40D((int)this, (int)this);
          if ( result < 0 )
            break;
        }
        if ( ++v4 >= v3 )
          goto LABEL_6;
      }
    }
    else
    {
LABEL_6:
      result = sub_6875A0(this);
      if ( result >= 0 )
      {
        result = sub_688BDF(this);
        if ( result >= 0 )
        {
          result = sub_6825A9(this);
          if ( result >= 0 )
          {
            sub_6BC1A9(this);
            return 0;
          }
        }
      }
    }
  }
  return result;
}
