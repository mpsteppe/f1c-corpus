int __cdecl isalpha(int C)
{
  if ( (int)SrcSizeInBytes <= 1 )
    return *((_WORD *)off_625680 + C) & 0x103;
  else
    return _isctype(C, 259);
}
