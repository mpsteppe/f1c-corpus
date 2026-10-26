// f1c  0x005567f5  size=101
int __cdecl sub_5567F5(_DWORD *a1, _DWORD *a2, int a3)
{
  unsigned int v3; // kr00_4
  unsigned int v4; // kr04_4
  int result; // eax
  unsigned __int64 v11; // rax

  v3 = __readeflags();
  __writeeflags(v3 ^ 0x200000);
  v4 = __readeflags();
  result = 0;
  if ( v4 != v3 )
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
  return result;
}
