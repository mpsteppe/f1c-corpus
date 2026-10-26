int __thiscall sub_4D2560(_DWORD *this)
{
  int v2; // ebx
  int v3; // ebx
  int v4; // edi
  int v5; // ebx
  int v6; // ecx
  int v7; // edi
  BOOL v8; // ebp
  int v9; // eax
  int v10; // ecx
  int v11; // edi
  int v13; // [esp+8h] [ebp-8h] BYREF
  _BYTE v14[4]; // [esp+Ch] [ebp-4h] BYREF

  v2 = (*(int (__thiscall **)(_DWORD *))(*this + 12))(this);
  v3 = v2 - (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
  if ( v3 <= 0 )
    return 0;
  v4 = v3 / 2 + (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
  sub_4DE540(&v13, v14);
  v5 = this[213];
  v6 = v13 - v4;
  v7 = this[214];
  v8 = v6 > 0;
  v9 = v6 + this[216];
  v10 = v7 * v5;
  if ( v7 * v5 > 0 )
  {
    for ( ; v9 < 0; v9 += v10 )
      ;
    for ( ; v9 > v10; v9 -= v10 )
      ;
    v11 = v9 / v7;
    if ( v11 >= 0 )
    {
      if ( v11 > v5 - 1 )
        v11 = v5 - 1;
    }
    else
    {
      v11 = 0;
    }
    while ( v11 != this[217] )
      (*(void (__thiscall **)(_DWORD *, BOOL))(*this + 180))(this, v8);
  }
  return 0;
}
