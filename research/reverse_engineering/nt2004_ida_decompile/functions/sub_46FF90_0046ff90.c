int __thiscall sub_46FF90(_BYTE *this)
{
  int v2; // eax

  this[864] = 0;
  sub_49EC10();
  v2 = *(_DWORD *)this;
  *((_DWORD *)this + 207) = 0;
  (*(void (__thiscall **)(_BYTE *))(v2 + 180))(this);
  return 0;
}
