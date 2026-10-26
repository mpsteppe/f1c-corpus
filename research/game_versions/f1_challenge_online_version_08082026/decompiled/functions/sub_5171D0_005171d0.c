int sub_5171D0()
{
  char v26[16]; // [esp+Ch] [ebp-28h] BYREF
  _DWORD v27[5]; // [esp+1Ch] [ebp-18h] BYREF
  int v28; // [esp+30h] [ebp-4h]

  strcpy((char *)v27, "UnknownVendr");
  strcpy(v26, "AuthenticAMD");
  _EAX = 0;
  __asm { cpuid }
  v28 = 1;
  _EAX = 0;
  __asm { cpuid }
  v27[0] = _EBX;
  v27[1] = _EDX;
  v27[2] = _ECX;
  if ( _EAX )
  {
    _EAX = 1;
    __asm { cpuid }
    v27[4] = _EAX;
    v28 |= ((_EDX & (unsigned int)&unk_800000) != 0 ? 0x20 : 0) | 2;
    _EAX = 0x80000000;
    __asm { cpuid }
    if ( _EAX > 0x80000000 )
    {
      v28 |= 4u;
      _EAX = -2147483647;
      __asm { cpuid }
      v28 |= _EDX < 0 ? 0x80 : 0;
      if ( !memcmp(v26, v27, 0xCu) )
      {
        v28 |= (_EDX & 0x40000000) != 0 ? 0x100 : 0;
        return ((_EDX & 0x400000) != 0 ? 0x200 : 0) | v28;
      }
    }
  }
  return v28;
}
