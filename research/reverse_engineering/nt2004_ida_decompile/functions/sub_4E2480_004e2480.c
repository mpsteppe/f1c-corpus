double __stdcall sub_4E2480(char *String2)
{
  double result; // st7
  int v2; // eax
  const char *v3; // eax
  double v4; // st7
  double v5; // st6

  result = 1.0;
  if ( String2 && strlen(String2) )
  {
    if ( sub_57AE50(String2) && (v2 = sub_57A720(off_6105F4)) != 0 )
    {
      v3 = (const char *)sub_57A6D0(v2);
      v4 = atof(v3);
      v5 = flt_7D3C54[(unsigned __int8)dword_7D3C50++];
      return v4 / 1.0 + v5 * 0.40000001 - 0.2;
    }
    else
    {
      return (float)1.0;
    }
  }
  return result;
}
