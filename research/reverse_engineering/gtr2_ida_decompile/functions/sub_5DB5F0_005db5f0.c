int __stdcall sub_5DB5F0(_DWORD *a1)
{
  int result; // eax

  if ( a1 )
  {
    if ( (*(_BYTE *)a1 & 0x10) != 0 )
    {
      result = sub_5FDFB0(a1, 1);
      *a1 |= 0x100000u;
    }
    else
    {
      result = sub_5FDFB0(a1, 1);
      *a1 |= 0x200000u;
    }
  }
  return result;
}
