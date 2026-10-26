int __thiscall sub_5DA590(_DWORD *this, int a2)
{
  switch ( a2 )
  {
    case 0x1000:
      return this[14];
    case 0x8000:
      return this[15];
    case 0x10000:
      return this[16];
  }
  return 0;
}
