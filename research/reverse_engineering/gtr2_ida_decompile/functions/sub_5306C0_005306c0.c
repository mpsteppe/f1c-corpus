double __stdcall sub_5306C0(const char *a1, int a2, int a3)
{
  double result; // st7
  _DWORD *v4; // eax
  char *v5; // eax
  char Buffer[64]; // [esp+8h] [ebp-40h] BYREF

  if ( a2 < 0 )
    return 0.0;
  sprintf(Buffer, "%s_%s", a1, "SeasonScoringInfo");
  if ( sub_616840(Buffer) && (v4 = (_DWORD *)sub_616610(a2 - 1)) != 0 )
  {
    v5 = sub_48D380(v4);
    result = atof(v5);
  }
  else
  {
    result = 0.0;
  }
  if ( a3 > 0 )
  {
    if ( a3 <= 2 )
    {
      return result * 0.5;
    }
    else if ( a3 == 3 )
    {
      return 0.0;
    }
  }
  return result;
}
