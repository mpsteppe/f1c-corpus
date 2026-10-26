BOOL sub_5AE762()
{
  _EAX = 1;
  __asm { cpuid }
  return ((unsigned int)&byte_800000 & _EDX) != 0;
}
