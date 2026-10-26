char __thiscall sub_52EFF0(_DWORD *this)
{
  void (__thiscall ***v2)(_DWORD, int); // ecx

  v2 = (void (__thiscall ***)(_DWORD, int))*this;
  if ( !v2 )
    return 0;
  (**v2)(v2, 1);
  *this = 0;
  return 1;
}
