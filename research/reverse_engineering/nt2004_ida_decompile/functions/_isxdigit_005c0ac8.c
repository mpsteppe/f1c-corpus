int __cdecl isxdigit(int C)
{
  if ( (int)SrcSizeInBytes <= 1 )
    return *((_BYTE *)off_625680 + 2 * C) & 0x80;
  else
    return _isctype(C, 128);
}
