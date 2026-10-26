int __stdcall sub_5F1830(_DWORD *a1, int a2, int a3)
{
  int result; // eax

  if ( a1 )
  {
    result = a2;
    switch ( a3 )
    {
      case 0:
        if ( a2 == 8 )
        {
LABEL_4:
          *a1 = 21;
          return result;
        }
        if ( a2 != 14 )
        {
          if ( a2 != 7 )
          {
            switch ( a2 )
            {
              case 6:
LABEL_8:
                *a1 = 23;
                return result;
              case 5:
                goto LABEL_10;
              case 3:
                *a1 = 26;
                return result;
            }
LABEL_26:
            if ( a2 == 4 )
            {
              *a1 = 41;
              return result;
            }
            break;
          }
LABEL_19:
          *a1 = 20;
          return result;
        }
LABEL_16:
        *a1 = 22;
        return result;
      case 32:
        if ( a2 == 8 )
          goto LABEL_4;
        if ( a2 == 14 )
          goto LABEL_16;
        break;
      case 24:
        if ( a2 == 7 )
          goto LABEL_19;
        break;
      case 16:
        switch ( a2 )
        {
          case 6:
            goto LABEL_8;
          case 5:
LABEL_10:
            *a1 = 25;
            return result;
          case 3:
            *a1 = 26;
            return result;
        }
        break;
      case 8:
        goto LABEL_26;
    }
    switch ( a2 )
    {
      case 9:
        *a1 = 827611204;
        break;
      case 10:
        *a1 = 844388420;
        break;
      case 11:
        *a1 = 861165636;
        break;
      case 12:
        *a1 = 877942852;
        break;
      case 13:
        *a1 = 894720068;
        break;
    }
  }
  return result;
}
