double __stdcall sub_4C02D0(int a1)
{
  int v1; // edi
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  char *v4; // eax
  double result; // st7
  int v6; // eax

  if ( !a1 || !sub_4C5840(0) || !sub_5679C0(aQualifying) )
    return -1.0;
  v1 = 0;
  while ( 1 )
  {
    v2 = (_DWORD *)sub_5679A0(v1);
    v3 = v2;
    if ( v2 )
    {
      v4 = sub_499E20(v2);
      if ( !sub_588410(a1, v4) )
        break;
    }
    if ( ++v1 >= 104 )
      return -1.0;
  }
  v6 = sub_567970(v3);
  result = sub_58850F(v6);
  if ( result < 10.0 )
    return -1.0;
  return result;
}
