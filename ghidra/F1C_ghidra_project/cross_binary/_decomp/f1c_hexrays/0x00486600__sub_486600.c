// f1c  0x00486600  size=36
int __thiscall sub_486600(_DWORD *this)
{
  int i; // esi

  for ( i = this[51]; i; i = *(_DWORD *)(i + 24) )
    sub_49A5D0(this);
  return 0;
}
