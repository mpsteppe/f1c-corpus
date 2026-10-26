int __thiscall sub_45D260(_DWORD *this)
{
  int i; // eax
  int result; // eax

  this[1] = (unsigned __int16)word_7D0FE8;
  this[2] = (unsigned __int16)word_7D0FE8;
  *(_BYTE *)this = 0;
  dword_8D4680 = 0;
  dword_8D4684 = 0;
  dword_8D4688 = 0;
  dword_8D468C = 0;
  for ( i = 0; i < 6; ++i )
    *((_BYTE *)&dword_8D4680 + i) = byte_59F0C4[i] ^ 0x3E;
  result = MemoryObjectAllocator(&dword_8D4680, 8, sub_45D2D0, 1, 0);
  this[3] = result;
  return result;
}

