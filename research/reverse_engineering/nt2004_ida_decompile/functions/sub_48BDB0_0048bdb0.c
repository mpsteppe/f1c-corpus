_DWORD *__thiscall sub_48BDB0(_DWORD *this)
{
  const char *v2; // eax

  v2 = (const char *)this[88];
  if ( !v2 )
    v2 = &byte_629120;
  if ( strlen(v2) && this[85] )
    return this + 78;
  else
    return 0;
}
