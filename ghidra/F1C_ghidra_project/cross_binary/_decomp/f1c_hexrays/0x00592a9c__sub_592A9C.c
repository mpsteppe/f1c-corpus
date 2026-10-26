// f1c  0x00592a9c  size=88
_BYTE *sub_592A9C()
{
  _BYTE *v0; // esi
  unsigned __int8 v1; // al

  if ( !dword_8D5A4C )
    sub_597218();
  v0 = (_BYTE *)dword_8D5A44;
  if ( *(_BYTE *)dword_8D5A44 != 34 )
  {
    if ( *(_BYTE *)dword_8D5A44 > 0x20u )
    {
      do
        ++v0;
      while ( *v0 > 0x20u );
    }
    goto LABEL_12;
  }
  while ( 1 )
  {
    v1 = *++v0;
    if ( v1 == 34 || !v1 )
      break;
    if ( sub_596DFE(v1) )
      ++v0;
  }
  if ( *v0 != 34 )
    goto LABEL_12;
  do
  {
    ++v0;
LABEL_12:
    ;
  }
  while ( *v0 && *v0 <= 0x20u );
  return v0;
}
