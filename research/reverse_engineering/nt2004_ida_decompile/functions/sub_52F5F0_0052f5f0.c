char sub_52F5F0()
{
  _EAX = 1;
  __asm { cpuid }
  if ( ((unsigned int)&unk_800000 & _EDX) == 0 )
    return 0;
  _m_empty();
  return 1;
}
