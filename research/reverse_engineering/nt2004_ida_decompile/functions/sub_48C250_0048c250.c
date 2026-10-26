_DWORD *__thiscall sub_48C250(_DWORD *this)
{
  char *v2; // eax
  int v3; // eax

  v2 = (char *)this[88];
  if ( !v2 )
    v2 = &byte_629120;
  v3 = sub_4AD970(v2, 0, 0, 1);
  if ( !v3 )
    v3 = sub_4AD970(aProfileiconDft, 0, 0, 1);
  sub_4B0AC0(v3);
  return this + 78;
}
