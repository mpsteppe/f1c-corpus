int __sse2_available_init()
{
  unsigned int v0; // kr00_4
  unsigned int v2; // kr04_4
  char v13; // [esp+Fh] [ebp-19h]
  int v14; // [esp+10h] [ebp-18h]
  char Str2[4]; // [esp+14h] [ebp-14h] BYREF
  int v16; // [esp+18h] [ebp-10h]
  int v17; // [esp+1Ch] [ebp-Ch]
  int v18; // [esp+24h] [ebp-4h]

  v18 = dword_912B08;
  v13 = 0;
  v14 = 0;
  Str2[0] = 0;
  v0 = __readeflags();
  _ECX = v0;
  __writeeflags(v0 ^ 0x200000);
  v2 = __readeflags();
  _EDX = v2 - v0;
  if ( v2 != v0 )
  {
    __writeeflags(v0);
    _EAX = 0;
    __asm { cpuid }
    *(_DWORD *)Str2 = _EBX;
    v16 = _EDX;
    v17 = _ECX;
    _EAX = 1;
    __asm { cpuid }
    v13 = HIBYTE(_EDX);
    v14 = _EAX;
  }
  dword_FBB5E4 = 0;
  dword_FBB5E0 = 0;
  if ( (v13 & 4) != 0 )
  {
    if ( has_osfxsr_set(_ECX, _EDX) )
    {
      dword_FBB5E4 = 1;
      if ( strncmp("AuthenticAMD", Str2, 0xCu) || ((v14 >> 8) & 0xF) + (((v14 >> 8) & 0xF) == 15 ? v14 >> 20 : 0) != 15 )
        dword_FBB5E0 = 1;
    }
  }
  return 0;
}
