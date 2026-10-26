int __cdecl isalnum(int C)
{
  if ( (int)SrcSizeInBytes <= 1 )
    return *((_WORD *)off_625680 + C) & 0x107;
  else
    return _isctype(C, 263);
}
