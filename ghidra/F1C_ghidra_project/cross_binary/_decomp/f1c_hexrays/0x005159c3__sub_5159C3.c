// f1c  0x005159c3  size=50
unsigned int sub_5159C3()
{
  unsigned int v0; // kr00_4
  unsigned int v1; // kr04_4
  int v2; // edx

  v0 = __readeflags();
  __writeeflags(v0 ^ 0x200000);
  v1 = __readeflags();
  v2 = v0 ^ v1;
  if ( v0 != v1 )
  {
    _EAX = 1;
    __asm { cpuid }
    return ((unsigned int)&unk_800000 & _EDX) >> 23;
  }
  return v2;
}
