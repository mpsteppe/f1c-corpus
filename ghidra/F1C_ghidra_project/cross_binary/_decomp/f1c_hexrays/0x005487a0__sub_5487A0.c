// f1c  0x005487a0  size=64
int __thiscall sub_5487A0(_DWORD *this)
{
  int v1; // esi

  v1 = this[9];
  if ( !v1 )
    return 0;
  while ( !sub_546450(v1, -1) )
  {
    InterlockedDecrement(&Addend);
    sub_545F50(0);
    v1 = *(_DWORD *)(v1 + 192);
    if ( !v1 )
      return 0;
  }
  return -1;
}
