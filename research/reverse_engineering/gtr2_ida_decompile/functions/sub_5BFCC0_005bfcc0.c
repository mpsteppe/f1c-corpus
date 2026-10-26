int __thiscall sub_5BFCC0(_DWORD *this)
{
  int (__thiscall ***v1)(_DWORD, int); // ecx
  int result; // eax

  v1 = (int (__thiscall ***)(_DWORD, int))this[2];
  if ( v1 )
    return (**v1)(v1, 1);
  return result;
}
