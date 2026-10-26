// f1c  0x00486630  size=36
int __thiscall sub_486630(_DWORD *this)
{
  int i; // esi

  for ( i = this[52]; i; i = *(_DWORD *)(i + 24) )
    sub_49A5D0(this);
  return 0;
}
