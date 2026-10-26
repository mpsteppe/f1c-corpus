unsigned int __thiscall sub_4BF840(_DWORD *this, int a2, char a3, int a4)
{
  unsigned int result; // eax

  result = *(_DWORD *)(a2 + 68);
  if ( result < 0x30 )
  {
    if ( a3 )
      this[result] = a2;
    else
      this[result] = 0;
  }
  return result;
}
