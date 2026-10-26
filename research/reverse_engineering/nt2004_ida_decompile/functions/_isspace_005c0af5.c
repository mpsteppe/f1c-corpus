int __cdecl isspace(int C)
{
  if ( (int)SrcSizeInBytes <= 1 )
    return *((_BYTE *)off_625680 + 2 * C) & 8;
  else
    return _isctype(C, 8);
}
