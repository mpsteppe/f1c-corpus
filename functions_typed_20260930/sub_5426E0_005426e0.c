int __thiscall sub_5426E0(_DWORD *this, int a2, __int16 a3)
{
  int v3; // eax
  int result; // eax

  v3 = a2;
  if ( a3 < 0 || a2 || (v3 = dword_8B8DE4, dword_8B8DE4 != 255) )
  {
    switch ( v3 )
    {
      case 1:
      case 9:
      case 10:
      case 11:
      case 12:
      case 13:
        this[12] = v3;
        this[9] = 1;
        result = 0;
        break;
      case 2:
        this[12] = v3;
        this[9] = 2;
        result = 0;
        break;
      case 3:
        this[12] = v3;
        this[9] = 4;
        result = 0;
        break;
      case 4:
        this[12] = v3;
        this[9] = 8;
        result = 0;
        break;
      case 5:
      case 6:
        this[12] = v3;
        this[9] = 16;
        result = 0;
        break;
      case 7:
        this[12] = v3;
        this[9] = 24;
        result = 0;
        break;
      case 8:
        this[12] = v3;
        this[9] = 32;
        result = 0;
        break;
      default:
        this[12] = 255;
        this[9] = 0;
        result = 0;
        break;
    }
  }
  else
  {
    sub_53C590(-1, aUndefinedVideo);
    return -1;
  }
  return result;
}

