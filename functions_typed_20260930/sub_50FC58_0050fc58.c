BOOL sub_50FC58()
{
  _EAX = 1;
  __asm { cpuid }
  return ((unsigned int)&unk_800000 & _EDX) != 0;
}

