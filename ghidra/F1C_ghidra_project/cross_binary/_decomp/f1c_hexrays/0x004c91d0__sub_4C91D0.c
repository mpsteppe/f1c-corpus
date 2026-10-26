// f1c  0x004c91d0  size=65
int __thiscall sub_4C91D0(_DWORD *this)
{
  int (__thiscall ***v2)(_DWORD, int); // ecx
  int result; // eax
  int (__thiscall ***v4)(_DWORD, int); // ecx
  int (__thiscall ***v5)(_DWORD, int); // ecx

  v2 = (int (__thiscall ***)(_DWORD, int))this[8];
  if ( v2 )
  {
    result = (**v2)(v2, 1);
    this[8] = 0;
  }
  v4 = (int (__thiscall ***)(_DWORD, int))this[9];
  if ( v4 )
  {
    result = (**v4)(v4, 1);
    this[9] = 0;
  }
  v5 = (int (__thiscall ***)(_DWORD, int))this[10];
  if ( v5 )
  {
    result = (**v5)(v5, 1);
    this[10] = 0;
  }
  return result;
}
