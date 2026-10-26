// f1c  0x004c9790  size=25
int __thiscall sub_4C9790(_DWORD *this)
{
  int (__thiscall ***v2)(_DWORD, int); // ecx
  int result; // eax

  v2 = (int (__thiscall ***)(_DWORD, int))this[8];
  if ( v2 )
  {
    result = (**v2)(v2, 1);
    this[8] = 0;
  }
  return result;
}
