int __thiscall sub_40B5A0(_DWORD *this)
{
  int (__thiscall ***v2)(_DWORD, int); // ecx
  int result; // eax

  v2 = (int (__thiscall ***)(_DWORD, int))this[3];
  *this = &off_59E6AC;
  if ( v2 )
    result = (**v2)(v2, 3);
  *this = &off_59E634;
  return result;
}
