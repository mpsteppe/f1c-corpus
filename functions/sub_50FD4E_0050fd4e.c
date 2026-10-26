int __usercall sub_50FD4E@<eax>(int a1@<ebp>)
{
  int v1; // ecx
  _DWORD v13[15]; // [esp-3Ch] [ebp-3Ch] BYREF

  SEHHandlerInit();
  v13[14] = v1;
  *(_DWORD *)(a1 - 16) = v13;
  *(_DWORD *)(a1 - 20) = 0;
  strcpy((char *)(a1 - 36), "GenuineIntel");
  *(_DWORD *)(a1 - 4) = 0;
  _EAX = 0;
  __asm { cpuid }
  *(_DWORD *)(a1 - 44) = _EAX;
  *(_DWORD *)(a1 - 56) = _EBX;
  *(_DWORD *)(a1 - 52) = _EDX;
  *(_DWORD *)(a1 - 48) = _ECX;
  *(_DWORD *)(a1 - 4) = -1;
  if ( !*(_DWORD *)(a1 - 44) )
    return *(_DWORD *)(a1 - 20);
  _EAX = 1;
  __asm { cpuid }
  *(_DWORD *)(a1 - 44) = _EAX;
  *(_DWORD *)(a1 - 40) = _EDX;
  if ( (*(_DWORD *)(a1 - 40) & 0x2000000) != 0 )
    *(_DWORD *)(a1 - 20) |= 4u;
  if ( (*(_DWORD *)(a1 - 40) & 0x4000000) != 0 )
    *(_DWORD *)(a1 - 20) |= 8u;
  return *(_DWORD *)(a1 - 20);
}
