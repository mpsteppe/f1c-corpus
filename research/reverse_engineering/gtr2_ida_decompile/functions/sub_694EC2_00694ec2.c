int __stdcall sub_694EC2(int a1, int a2)
{
  bool v2; // cc
  int result; // eax
  bool v4; // zf
  int v5; // eax
  bool v6; // zf

  if ( a1 == a2 )
    return 0;
  switch ( a1 )
  {
    case 1:
    case 5:
      if ( a2 <= 0 )
        goto LABEL_6;
      v2 = a2 <= 8;
      goto LABEL_5;
    case 2:
    case 6:
      if ( a2 <= 0 )
        goto LABEL_6;
      if ( a2 <= 2 )
        return 0;
      if ( a2 <= 4 )
        goto LABEL_6;
      v2 = a2 <= 6;
LABEL_5:
      if ( !v2 )
        goto LABEL_6;
      return 0;
    case 3:
    case 7:
      if ( a2 == 1 || a2 == 3 )
        return 0;
      v5 = a2 - 5;
      v4 = a2 == 5;
      goto LABEL_14;
    case 4:
    case 8:
      if ( a2 == 1 )
        return 0;
      if ( a2 <= 3 )
        goto LABEL_6;
      if ( a2 <= 5 )
        return 0;
      v6 = a2 == 8;
      goto LABEL_27;
    case 9:
      if ( a2 < 9 )
        goto LABEL_6;
      v2 = a2 <= 12;
      goto LABEL_5;
    case 10:
      if ( a2 < 9 )
        goto LABEL_6;
      v2 = a2 <= 10;
      goto LABEL_5;
    case 11:
      v5 = a2 - 9;
      v4 = a2 == 9;
LABEL_14:
      if ( v4 )
        return 0;
      v6 = v5 == 2;
LABEL_27:
      if ( v6 )
        return 0;
LABEL_6:
      result = 1;
      break;
    case 12:
      if ( a2 == 9 )
        return 0;
      v6 = a2 == 12;
      goto LABEL_27;
    default:
      goto LABEL_6;
  }
  return result;
}
