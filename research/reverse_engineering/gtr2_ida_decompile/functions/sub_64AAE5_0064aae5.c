int __thiscall sub_64AAE5(_DWORD *this)
{
  int (__thiscall ***v2)(_DWORD, int); // ecx
  int result; // eax

  v2 = (int (__thiscall ***)(_DWORD, int))this[1];
  if ( v2 )
    result = (**v2)(v2, 1);
  if ( *this )
    return (**(int (__thiscall ***)(_DWORD, int))*this)(*this, 1);
  return result;
}
