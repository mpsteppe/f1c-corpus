// f1c  0x004bf6a0  size=144
double __stdcall sub_4BF6A0(const char *a1)
{
  double result; // st7
  int v2; // eax
  int v3; // eax
  double v4; // st7
  double v5; // st6

  result = 1.0;
  if ( a1 && strlen(a1) )
  {
    if ( sub_568210(a1) && (v2 = sub_5679C0(off_5D263C)) != 0 )
    {
      v3 = sub_567970(v2);
      v4 = sub_58850F(v3);
      v5 = flt_8AAE74[(unsigned __int8)dword_8AAE70++];
      return v4 / 1.0 + v5 * 0.40000001 - 0.2;
    }
    else
    {
      return (float)1.0;
    }
  }
  return result;
}
