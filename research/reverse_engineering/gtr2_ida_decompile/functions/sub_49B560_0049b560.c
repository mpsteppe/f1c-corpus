char __thiscall sub_49B560(_DWORD *this, int a2, int a3, int a4)
{
  _BYTE v6[4]; // [esp+4h] [ebp-4h] BYREF

  if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, int))(*this + 108))(this, a2) )
  {
    sub_4DE540(v6, &a2);
    sub_4D0D20(a2);
    sub_48C2F0();
    sub_49B270();
    this[150] = -1;
  }
  return 0;
}
