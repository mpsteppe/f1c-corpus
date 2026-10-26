BOOL sub_50FD16()
{
  int v11; // [esp+Ch] [ebp-4h]

  v11 = 0;
  _EAX = 0x80000000;
  __asm { cpuid }
  if ( _EAX >= 0x80000001 )
  {
    _EAX = -2147483647;
    __asm { cpuid }
    return _EDX < 0;
  }
  return v11;
}

