// f1c  0x00598c70  size=24
void __thiscall sub_598C70(_DWORD *this)
{
  void (__thiscall ***v1)(_DWORD, int); // eax

  if ( *this )
  {
    v1 = (void (__thiscall ***)(_DWORD, int))sub_598C88();
    if ( v1 )
      (**v1)(v1, 1);
  }
}
