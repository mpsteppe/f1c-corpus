int __thiscall sub_4CF050(_DWORD *this)
{
  int v2; // edi
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  int v7; // eax
  int v8; // [esp+8h] [ebp-8h] BYREF
  int v9; // [esp+Ch] [ebp-4h] BYREF

  v2 = this[33];
  sub_4DE540(&v8, &v9);
  switch ( v2 )
  {
    case 0:
    case 6:
    case 7:
      if ( v8 <= this[86] || v8 >= this[88] || v9 <= this[87] || v9 >= this[89] )
      {
        if ( v8 <= this[90] || v8 >= this[92] || v9 <= this[91] || v9 >= this[93] )
          (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 44))(this, 0);
        else
          (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 7);
      }
      else
      {
        (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 6);
      }
      break;
    case 3:
    case 8:
    case 9:
      if ( v8 <= this[94] || v8 >= this[96] || v9 <= this[95] || v9 >= this[97] )
      {
        if ( v8 <= this[98] || v8 >= this[100] || v9 <= this[99] || v9 >= this[101] )
          (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 3);
        else
          (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 9);
      }
      else
      {
        (*(void (__thiscall **)(_DWORD *, int))(*this + 44))(this, 8);
      }
      break;
    default:
      break;
  }
  if ( v2 == 4 )
  {
    v7 = this[76];
    if ( v7 > 0 )
      this[76] = v7 - 1;
  }
  else if ( v2 == 5 )
  {
    v3 = sub_4E3D00(this[61] + 108);
    v4 = this[76];
    if ( v4 < this[74] - (v3 - 4) )
    {
      v5 = *this;
      this[76] = v4 + 1;
      (*(void (__thiscall **)(_DWORD *))(v5 + 160))(this);
      return 0;
    }
  }
  (*(void (__thiscall **)(_DWORD *))(*this + 160))(this);
  return 0;
}
