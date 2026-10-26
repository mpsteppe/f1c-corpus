// f1c  0x00545a10  size=38
int __thiscall sub_545A10(_DWORD *this)
{
  int i; // esi

  for ( i = this[87]; i; i = *(_DWORD *)(i + 52) )
    sub_560C10(this, 0);
  return 0;
}
