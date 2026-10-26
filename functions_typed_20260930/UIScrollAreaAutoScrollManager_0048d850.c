int __thiscall sub_48D850(_DWORD *this)
{
  int v2; // edi
  int v3; // ecx
  bool v4; // cc
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  int v9; // eax
  int v10; // [esp+8h] [ebp-8h] BYREF
  int v11; // [esp+Ch] [ebp-4h] BYREF

  v2 = ShortComputation_6720(this);
  DualFieldRead(&v10, &v11);
  switch ( v2 )
  {
    case 0:
    case 6:
    case 7:
      if ( v10 <= this[67] )
        goto LABEL_18;
      v4 = v10 <= this[66];
      if ( v10 < this[66] )
      {
        if ( v11 > this[71] && v11 < this[72] )
        {
          (*(void (__thiscall **)(_DWORD *, int))(*this + 64))(this, 6);
          goto LABEL_25;
        }
LABEL_18:
        v4 = v10 <= this[66];
      }
      if ( v4 || v10 >= this[68] || v11 <= this[71] || v11 >= this[72] )
        (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 64))(this, 0);
      else
        (*(void (__thiscall **)(_DWORD *, int))(*this + 64))(this, 7);
LABEL_25:
      if ( v2 == 4 )
      {
        v9 = this[64];
        if ( v9 > 0 )
          this[64] = v9 - 1;
      }
      else if ( v2 == 5 )
      {
        v5 = ShortComputation_adb0(this[50] + 108);
        v6 = this[64];
        if ( v6 < this[62] - (v5 - 4) )
        {
          v7 = *this;
          this[64] = v6 + 1;
          (*(void (__thiscall **)(_DWORD *))(v7 + 168))(this);
          return 0;
        }
      }
      (*(void (__thiscall **)(_DWORD *))(*this + 168))(this);
      return 0;
    case 3:
    case 8:
    case 9:
      v3 = this[67];
      if ( v10 <= v3 )
        goto LABEL_12;
      if ( v10 < this[68] && v11 > this[71] && v11 < this[70] )
      {
        (*(void (__thiscall **)(_DWORD *, int))(*this + 64))(this, 8);
        goto LABEL_25;
      }
      if ( v10 <= v3 || v10 >= this[68] || v11 <= this[70] || v11 >= this[72] )
LABEL_12:
        (*(void (__thiscall **)(_DWORD *, int))(*this + 64))(this, 3);
      else
        (*(void (__thiscall **)(_DWORD *, int))(*this + 64))(this, 9);
      goto LABEL_25;
    default:
      goto LABEL_25;
  }
}

