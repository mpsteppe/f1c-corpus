int __thiscall sub_496F66(void *this)
{
  unsigned int v1; // kr00_4
  int result; // eax

  v1 = __getcallerseflags();
  result = *(_DWORD *)__ROL4__(dword_16C6E00, dword_16D6C25);
  __writeeflags(v1);
  if ( result )
  {
    if ( *(_BYTE *)(result + 16) )
      return sub_5FDFB0(this, 0);
  }
  return result;
}
