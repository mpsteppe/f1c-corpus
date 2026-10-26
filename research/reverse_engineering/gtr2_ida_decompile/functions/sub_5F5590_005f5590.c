int __stdcall sub_5F5590(_DWORD *a1, _DWORD *a2, int a3, _DWORD *a4)
{
  unsigned int v4; // kr00_4
  unsigned int v5; // kr04_4
  unsigned __int64 v11; // rax
  int result; // eax

  v4 = __readeflags();
  __writeeflags(v4 ^ 0x200000);
  v5 = __readeflags();
  if ( v5 != v4 )
  {
    _EAX = 1;
    __asm { cpuid }
    if ( (_EDX & 0x10) != 0 )
    {
      v11 = __rdtsc() - __PAIR64__(*a1, *a2);
      *a1 = HIDWORD(v11);
      *a2 = v11;
    }
    if ( a3 )
    {
      _EAX = 0;
      __asm { cpuid }
      *(_DWORD *)a3 = _EBX;
      *(_DWORD *)(a3 + 4) = _EDX;
      *(_DWORD *)(a3 + 8) = _ECX;
      *(_BYTE *)(a3 + 12) = 0;
    }
    _EAX = 1;
    __asm { cpuid }
  }
  _EAX = 0x80000000;
  __asm { cpuid }
  if ( _EAX >= 0x80000004 && a4 )
  {
    _EAX = -2147483646;
    __asm { cpuid }
    *a4 = _EAX;
    a4[1] = _EBX;
    a4[2] = _ECX;
    a4[3] = _EDX;
    _EAX = -2147483645;
    __asm { cpuid }
    a4[4] = _EAX;
    a4[5] = _EBX;
    a4[6] = _ECX;
    a4[7] = _EDX;
    _EAX = -2147483644;
    __asm { cpuid }
    a4[8] = _EAX;
    a4[9] = _EBX;
    a4[10] = _ECX;
    a4[11] = _EDX;
  }
  _EAX = 1;
  __asm { cpuid }
  return result;
}
