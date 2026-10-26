int __cdecl isdigit(int C)
{
  if ( (int)SrcSizeInBytes <= 1 )
    return *((_BYTE *)off_625680 + 2 * C) & 4;
  else
    return _isctype(C, 4);
}
