unsigned int __cdecl _hextodec(int C)
{
  int v1; // esi
  int v2; // eax

  v1 = C;
  if ( (int)SrcSizeInBytes <= 1 )
    v2 = *((_BYTE *)off_625680 + 2 * C) & 4;
  else
    v2 = _isctype(C, 4);
  if ( !v2 )
    return (C & 0xFFFFFFDF) - 7;
  return v1;
}
