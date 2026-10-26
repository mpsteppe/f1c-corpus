int __thiscall sub_4A3710(_DWORD *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // eax
  bool v5; // sf
  int v6; // eax
  int v7; // ecx
  int v9; // [esp+8h] [ebp-8h] BYREF
  int v10; // [esp+Ch] [ebp-4h] BYREF

  v2 = sub_49D1E0(this);
  sub_4AE870(&v9, &v10);
  if ( !v2 || v2 == 7 || v2 == 6 )
  {
    if ( v9 <= this[84] || v9 >= this[86] || v10 <= this[85] || v10 >= this[87] )
    {
      if ( v9 > this[88] && v9 < this[90] && v10 > this[89] && v10 < this[91] )
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
    v3 = this[75];
    if ( this[73] != v3 )
      this[73] = v3;
    (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 44))(this, 0);
    v4 = v9;
    if ( v9 > this[92] && v9 < this[94] && v10 > this[93] && v10 < this[95] )
    {
      (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 4);
      v5 = --this[74] < 0;
      v4 = v9;
      if ( v5 )
        this[74] = 0;
    }
    if ( v4 > this[96] && v4 < this[98] && v10 > this[97] && v10 < this[99] )
    {
      (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 5);
      v6 = sub_4B15C0(this[61] + 108);
      v7 = this[74];
      if ( v7 < this[72] - (v6 - 4) )
        this[74] = v7 + 1;
    }
  }
  if ( sub_49DDD0(this) )
    (*(void (**)(void))(*this + 144))();
  return 0;
}
