int __thiscall sub_4C9960(_DWORD *this)
{
  int (__thiscall ***v2)(_DWORD, int); // ecx
  int result; // eax

  v2 = (int (__thiscall ***)(_DWORD, int))this[7];
  if ( v2 )
  {
    result = (**v2)(v2, 1);
    this[7] = 0;
  }
  return result;
}
