int __thiscall sub_4CDDB0(_BYTE *this)
{
  int v2; // eax
  int v3; // edx

  v2 = (*(int (__thiscall **)(_BYTE *))(*(_DWORD *)this + 160))(this);
  v3 = *(_DWORD *)this;
  this[308] = v2 == 0;
  (*(void (__thiscall **)(_BYTE *))(v3 + 164))(this);
  return 0;
}
