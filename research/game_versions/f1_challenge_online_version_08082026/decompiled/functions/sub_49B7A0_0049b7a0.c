int __thiscall sub_49B7A0(void *this)
{
  int result; // eax
  double v2; // st7
  float v3; // [esp+0h] [ebp-4h]

  if ( (unsigned __int8)sub_4F1AA0(dword_7C54E0 + 12, this) )
    return (sub_587BDC(dbl_8AFEA0 + dbl_8AFEA0) & 1) != 0 ? 0xF : 0;
  if ( *(_DWORD *)(dword_7C54F0[dword_7C54DC] + 18580) == *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580)
    && dword_7C9158 )
  {
    switch ( sub_587BDC(dbl_8AFEA0 * 3.0) % 6 )
    {
      case 0:
        result = 1;
        break;
      case 1:
      case 5:
        result = 2;
        break;
      case 2:
      case 4:
        result = 4;
        break;
      case 3:
        result = 8;
        break;
      default:
        return 0;
    }
  }
  else
  {
    v2 = *(float *)(dword_7C54E0 + 14752) / *(float *)(dword_7C54E0 + 14756);
    v3 = v2;
    if ( v2 >= 0.89999998 )
    {
      if ( v3 >= 0.93000001 )
      {
        if ( v3 >= 0.95999998 )
        {
          result = 7;
          if ( v3 >= 0.977 )
            return 15;
        }
        else
        {
          return 3;
        }
      }
      else
      {
        return 1;
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}
