int __thiscall sub_4CF1D0(_DWORD *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // eax
  bool v5; // sf
  int v6; // eax
  int v7; // ecx
  int v9; // [esp+8h] [ebp-8h] BYREF
  int v10; // [esp+Ch] [ebp-4h] BYREF

  v2 = this[33];
  sub_4DE540(&v9, &v10);
  if ( !v2 || v2 == 7 || v2 == 6 )
  {
    if ( v9 <= this[86] || v9 >= this[88] || v10 <= this[87] || v10 >= this[89] )
    {
      if ( v9 > this[90] && v9 < this[92] && v10 > this[91] && v10 < this[93] )
      {
        (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 2);
        (*(void (__thiscall **)(_DWORD *, int))(*this + 168))(this, 1);
      }
    }
    else
    {
      (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 1);
      (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 168))(this, 0);
    }
  }
  else
  {
    v3 = this[77];
    if ( this[75] != v3 )
      this[75] = v3;
    (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 44))(this, 0);
    v4 = v9;
    if ( v9 > this[94] && v9 < this[96] && v10 > this[95] && v10 < this[97] )
    {
      (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 4);
      v5 = --this[76] < 0;
      v4 = v9;
      if ( v5 )
        this[76] = 0;
    }
    if ( v4 > this[98] && v4 < this[100] && v10 > this[99] && v10 < this[101] )
    {
      (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 5);
      v6 = sub_4E3D00(this[61] + 108);
      v7 = this[76];
      if ( v7 < this[74] - (v6 - 4) )
        this[76] = v7 + 1;
    }
  }
  if ( !*((_BYTE *)this + 100) )
    (*(void (__thiscall **)(_DWORD *))(*this + 144))(this);
  return 0;
}
