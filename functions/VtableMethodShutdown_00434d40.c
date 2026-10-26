int __thiscall sub_434D40(_DWORD *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx

  v2 = (void (__thiscall ***)(_DWORD, int))this[3];
  if ( v2 )
  {
    (**v2)(v2, 1);
    this[3] = 0;
  }
  return 0;
}
