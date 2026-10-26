int __thiscall sub_45E900(_BYTE *this)
{
  void *v1; // esi
  int result; // eax

  if ( *this )
  {
    v1 = off_624A10;
    if ( *((_DWORD *)off_624A10 + 45) )
      sub_5BA9E0(off_624A10);
    return sub_5BA970(v1);
  }
  return result;
}
