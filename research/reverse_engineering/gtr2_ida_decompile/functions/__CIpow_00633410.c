double __usercall _CIpow@<st0>(double x@<st0>, double y@<st1>)
{
  int v2; // eax
  bool v3; // zf
  unsigned __int64 v5; // st6
  char v6; // [esp+Ch] [ebp-8h]

  if ( !dword_FBB5E0 )
    goto __CIpow_default;
  v2 = _mm_getcsr() & 0x1F80;
  v3 = v2 == 8064;
  if ( v2 == 8064 )
    v3 = (v6 & 0x7F) == 127;
  if ( v3 )
  {
    _CIpow_pentium4();
  }
  else
  {
__CIpow_default:
    *(double *)&v5 = x;
    x = y;
    start_2(v5, HIDWORD(v5), LODWORD(y), HIDWORD(y));
  }
  return x;
}
