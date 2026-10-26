int __thiscall sub_5B5A90(_DWORD *this, int a2, int a3)
{
  int result; // eax

  switch ( a2 )
  {
    case 1:
      this[5] = a3;
      break;
    case 2:
      this[9] = a3;
      break;
    case 3:
      this[13] = a3;
      break;
  }
  result = dword_7E8E5C;
  *(_DWORD *)(dword_7E8E5C + 240) |= 0x800u;
  return result;
}
