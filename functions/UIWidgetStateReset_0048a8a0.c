int __thiscall sub_48A8A0(_BYTE *this)
{
  int v2; // eax
  int v3; // edx

  v2 = *(_DWORD *)this;
  this[324] = 0;
  this[325] = 0;
  this[326] = 0;
  (*(void (__stdcall **)(_DWORD))(v2 + 64))(0);
  v3 = *(_DWORD *)this;
  *((_DWORD *)this + 82) = 0;
  return (*(int (__thiscall **)(_BYTE *))(v3 + 156))(this);
}
