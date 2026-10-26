int __thiscall sub_4CE5C0(_BYTE *this)
{
  int v2; // eax
  int v3; // edx

  v2 = *(_DWORD *)this;
  this[548] = 0;
  this[549] = 0;
  this[550] = 0;
  (*(void (__stdcall **)(_DWORD))(v2 + 44))(0);
  v3 = *(_DWORD *)this;
  *((_DWORD *)this + 138) = 0;
  return (*(int (__thiscall **)(_BYTE *))(v3 + 148))(this);
}
