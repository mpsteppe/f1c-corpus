int __thiscall ConditionalVirtualCallTriplet(_DWORD *this)
{
  int (__thiscall ***v2)(_DWORD, int); // ecx
  int result; // eax
  int (__thiscall ***v4)(_DWORD, int); // ecx
  int (__thiscall ***v5)(_DWORD, int); // ecx

  v2 = (int (__thiscall ***)(_DWORD, int))this[6];
  if ( v2 )
  {
    result = (**v2)(v2, 1);
    this[6] = 0;
  }
  v4 = (int (__thiscall ***)(_DWORD, int))this[7];
  if ( v4 )
  {
    result = (**v4)(v4, 1);
    this[7] = 0;
  }
  v5 = (int (__thiscall ***)(_DWORD, int))this[8];
  if ( v5 )
  {
    result = (**v5)(v5, 1);
    this[8] = 0;
  }
  return result;
}
