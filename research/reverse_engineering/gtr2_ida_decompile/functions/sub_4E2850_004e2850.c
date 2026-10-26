int __thiscall sub_4E2850(_DWORD *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx
  int result; // eax

  v2 = (void (__thiscall ***)(_DWORD, int))this[20];
  if ( v2 )
    (**v2)(v2, 1);
  result = 0;
  memset(this, 0, 0x50u);
  return result;
}
