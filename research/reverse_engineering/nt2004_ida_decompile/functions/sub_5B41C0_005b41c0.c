_DWORD *__stdcall sub_5B41C0(int a1, _DWORD *a2, _DWORD *a3)
{
  _DWORD *result; // eax

  if ( a1 <= 827611204 )
  {
    if ( a1 == 827611204 )
    {
      if ( a2 )
        *a2 = 1;
      result = a3;
      if ( a3 )
        *a3 = 9;
    }
    else
    {
      switch ( a1 )
      {
        case 20:
          if ( a2 )
            *a2 = 24;
          goto LABEL_12;
        case 21:
          if ( a2 )
            *a2 = 32;
          result = a3;
          if ( a3 )
            *a3 = 8;
          return result;
        case 22:
          if ( a2 )
            *a2 = 32;
LABEL_12:
          result = a3;
          if ( a3 )
            *a3 = 7;
          break;
        case 23:
          if ( a2 )
            *a2 = 16;
          result = a3;
          if ( a3 )
            *a3 = 6;
          break;
        case 24:
        case 25:
          if ( a2 )
            *a2 = 16;
          result = a3;
          if ( a3 )
            *a3 = 5;
          break;
        case 26:
          if ( a2 )
            *a2 = 16;
          result = a3;
          if ( a3 )
            *a3 = 3;
          break;
        case 40:
        case 41:
          if ( a2 )
            *a2 = 8;
          result = a3;
          if ( a3 )
            *a3 = 4;
          break;
        default:
          goto LABEL_51;
      }
    }
    return result;
  }
  if ( a1 > 877942852 )
  {
    if ( a1 != 894720068 )
      goto LABEL_51;
    if ( a2 )
      *a2 = 1;
    result = a3;
    if ( a3 )
      *a3 = 13;
  }
  else
  {
    switch ( a1 )
    {
      case 877942852:
        if ( a2 )
          *a2 = 1;
        result = a3;
        if ( a3 )
          *a3 = 12;
        break;
      case 844388420:
        if ( a2 )
          *a2 = 1;
        result = a3;
        if ( a3 )
          *a3 = 10;
        break;
      case 861165636:
        if ( a2 )
          *a2 = 1;
        result = a3;
        if ( a3 )
          *a3 = 11;
        return result;
      default:
LABEL_51:
        if ( a2 )
          *a2 = 0;
        result = a3;
        if ( a3 )
          *a3 = 0;
        return result;
    }
  }
  return result;
}
