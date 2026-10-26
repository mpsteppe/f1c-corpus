int __thiscall sub_49EEA0(_DWORD *this)
{
  _DWORD *v2; // ecx
  int v3; // edx

  if ( this[212] != *(_DWORD *)dword_B72314 )
  {
    this[212] = *(_DWORD *)dword_B72314;
    (*(void (__thiscall **)(_DWORD *))(*this + 152))(this);
  }
  v2 = (_DWORD *)this[211];
  if ( this[213] != *v2 )
  {
    v3 = *this;
    this[213] = *v2;
    (*(void (__thiscall **)(_DWORD *))(v3 + 152))(this);
  }
  return 0;
}
