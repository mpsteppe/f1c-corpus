int __thiscall sub_4D2250(_DWORD *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // [esp+4h] [ebp-8h] BYREF
  int v13; // [esp+8h] [ebp-4h] BYREF

  sub_4DE540(&v12, &v13);
  v2 = this[205];
  if ( !v2 )
  {
    v9 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
    if ( v12 >= v9 || (v10 = sub_4CFCC0(this, 3), v12 <= v10) )
    {
      v11 = (*(int (__thiscall **)(_DWORD *))(*this + 12))(this);
      return (v12 <= v11) + 1;
    }
    return 0;
  }
  v3 = v2 - 1;
  if ( !v3 )
  {
    v7 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
    if ( v12 >= v7 )
    {
      v8 = (*(int (__thiscall **)(_DWORD *))(*this + 12))(this);
      return (v12 >= v8) + 1;
    }
    return 0;
  }
  if ( v3 != 1 )
    return v13;
  v4 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
  if ( v12 > v4 )
    return 1;
  v6 = (*(int (__thiscall **)(_DWORD *))(*this + 12))(this);
  return v12 > v6 ? 0 : 2;
}
