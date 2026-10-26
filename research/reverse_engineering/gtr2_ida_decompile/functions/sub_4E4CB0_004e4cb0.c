int __thiscall sub_4E4CB0(void *this)
{
  int result; // eax
  double v2; // st7
  float v3; // [esp+0h] [ebp-4h]

  if ( (unsigned __int8)sub_5785A0(dword_91E07C + 16, this) )
    return ((unsigned __int64)(dbl_FB1D18 + dbl_FB1D18) & 1) != 0 ? 0xF : 0;
  if ( *(_DWORD *)(*(&dword_91E088 + dword_91E078) + 22468) == *(_DWORD *)(*(&dword_91E088 + dword_91E080) + 22468)
    && dword_B682E8 )
  {
    switch ( (int)(unsigned __int64)(dbl_FB1D18 * 3.0) % 6 )
    {
      case 0:
        return 1;
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
    v2 = *((float *)dword_91E07C + 4307) / *((float *)dword_91E07C + 4308);
    v3 = v2;
    if ( v2 < 0.89999998 )
    {
      return 0;
    }
    else if ( v3 < 0.93000001 )
    {
      return 1;
    }
    else if ( v3 >= 0.95999998 )
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
  return result;
}
