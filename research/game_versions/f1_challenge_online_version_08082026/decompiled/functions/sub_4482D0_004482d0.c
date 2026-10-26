int __thiscall sub_4482D0(_DWORD *this)
{
  int (__thiscall ***v2)(_DWORD, int); // ecx
  int result; // eax

  v2 = (int (__thiscall ***)(_DWORD, int))this[1];
  *this = 0;
  if ( v2 )
  {
    result = (**v2)(v2, 1);
    this[1] = 0;
  }
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[6] = -8388609;
  return result;
}
