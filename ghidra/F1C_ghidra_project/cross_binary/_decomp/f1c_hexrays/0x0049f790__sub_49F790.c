// f1c  0x0049f790  size=213
char __thiscall sub_49F790(int *this)
{
  char result; // al
  int v2; // eax

  result = dword_7CC234;
  if ( dword_7CC234 )
  {
    if ( dword_5EA518 == dword_5EA528
      && (*(_DWORD *)(dword_5EA528 + 52) == 1 || dword_5EA518 == dword_5EA528 && *(_DWORD *)(dword_5EA528 + 52) == 2) )
    {
      v2 = *this;
      while ( ++v2 < 5 )
      {
        if ( v2 == 2 )
        {
          if ( (byte_7CF7AC & 1) != 0 )
            goto LABEL_19;
        }
        else if ( v2 == 3 )
        {
          if ( (byte_7CF7AC & 2) != 0 )
            goto LABEL_19;
        }
        else if ( v2 != 4 || (byte_7CF7AC & 4) != 0 )
        {
          goto LABEL_19;
        }
      }
      v2 = 0;
LABEL_19:
      result = sub_49F150(this, v2);
    }
    else
    {
      result = sub_49F150(this, *this != 1);
    }
  }
  if ( *this == 1 )
  {
    if ( dword_7CC28C )
    {
      return sub_49F170(this, 1);
    }
    else if ( dword_7CC2B8 )
    {
      return sub_49F170(this, 0);
    }
    else if ( dword_7CC2E4 )
    {
      return sub_4A5750(this[1]);
    }
    else
    {
      result = dword_7CC310;
      if ( dword_7CC310 )
        return sub_4A57A0(this[1]);
    }
  }
  return result;
}
