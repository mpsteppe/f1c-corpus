int __cdecl wctomb(char *MbCh, wchar_t WCh)
{
  UINT *v2; // eax

  v2 = (UINT *)_getptd()[25];
  if ( v2 != off_91290C )
    v2 = (UINT *)__updatetlocinfo();
  return __wctomb_mt(v2, MbCh, WCh);
}
