int __thiscall sub_60AC50(_DWORD *this, int a2)
{
  int result; // eax
  bool v3; // zf

  result = 0;
  if ( a2 > 4096 )
  {
    if ( a2 > 0x8000 )
    {
      if ( a2 == 0x10000 )
        return this[8];
      v3 = a2 == 0x20000;
    }
    else
    {
      if ( a2 == 0x8000 || a2 == 0x2000 )
        return this[8];
      v3 = a2 == 0x4000;
    }
    if ( !v3 )
      return result;
    return this[8];
  }
  if ( a2 == 4096 )
    return this[8];
  switch ( a2 )
  {
    case 0:
      result = 0;
      break;
    case 1:
      result = this[9];
      break;
    case 2:
      result = this[10];
      break;
    case 4:
      result = this[11];
      break;
    case 16:
      result = this[12];
      break;
    case 32:
      result = this[13];
      break;
    default:
      return result;
  }
  return result;
}
