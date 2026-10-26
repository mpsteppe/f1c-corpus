LPCVOID __onexitinit()
{
  _DWORD *v0; // eax
  LPCVOID result; // eax

  v0 = malloc(0x80u);
  dword_801514 = v0;
  if ( !v0 )
    _amsg_exit(0x18u);
  *v0 = 0;
  result = dword_801514;
  dword_801510 = (int)dword_801514;
  return result;
}
