void __thiscall sub_5ADB80(_DWORD *this, const char *a2)
{
  _DWORD *i; // edi

  for ( i = (_DWORD *)this[79]; i; i = (_DWORD *)i[9] )
  {
    if ( !strcmp(a2, (const char *)(i[7] + 28)) )
    {
      i[1] &= ~0x20000u;
      sub_5AD860((int)i);
    }
  }
}
