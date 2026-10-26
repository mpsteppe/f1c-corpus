double __stdcall sub_530F70(char *String2)
{
  double result; // st7
  _DWORD *v2; // eax
  char *v3; // eax
  _DWORD *v4; // eax
  char *v5; // eax
  double v6; // st7
  float v7; // [esp+0h] [ebp-4h]

  result = 1.0;
  if ( String2 && strlen(String2) )
  {
    if ( sub_616840(String2) && (v2 = (_DWORD *)sub_616630(off_9034F4)) != 0 )
    {
      v3 = sub_48D380(v2);
      v7 = atof(v3);
      v4 = (_DWORD *)sub_616840("FieldSelection");
      if ( v4 && (v5 = sub_48D380(v4), !_stricmp(v5, "FASTEST")) )
      {
        return v7 + 0.0;
      }
      else
      {
        v6 = flt_BE08A4[(unsigned __int8)dword_BE08A0++] * 0.40000001;
        return v6 - 0.2 + v7;
      }
    }
    else
    {
      return (float)1.0;
    }
  }
  return result;
}
