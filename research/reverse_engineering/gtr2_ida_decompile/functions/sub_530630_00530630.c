double __stdcall sub_530630(int a1, int a2)
{
  double result; // st7
  _DWORD *v3; // eax
  char *v4; // eax

  if ( a1 < 0 )
    return 0.0;
  if ( sub_616840("SeasonScoringInfo") && (v3 = (_DWORD *)sub_616610(a1 - 1)) != 0 )
  {
    v4 = sub_48D380(v3);
    result = atof(v4);
  }
  else
  {
    result = 0.0;
  }
  switch ( a2 )
  {
    case 1:
    case 2:
      result = result * 0.5;
      break;
    case 3:
      result = 0.0;
      break;
    default:
      return result;
  }
  return result;
}
