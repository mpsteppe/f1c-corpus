int __thiscall sub_4B3060(_DWORD *this, int a2)
{
  int v3; // ecx
  int result; // eax
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // edi
  int v9; // ecx
  int v10; // [esp-4h] [ebp-Ch]
  int v11; // [esp-4h] [ebp-Ch]

  v3 = (*(int (__thiscall **)(_DWORD *))(*this + 8))(this);
  result = this[81] / 2;
  v5 = this[79] + result + v3;
  if ( a2 >= v5 )
  {
    if ( a2 <= v5 )
      return result;
    v11 = this[71];
    sub_4B3000();
    v7 = (*(int (__thiscall **)(_DWORD *, int))(*this + 8))(this, v11);
    result = this[81] / 2;
    if ( a2 > this[79] + result + v7 )
      return result;
  }
  else
  {
    v10 = -this[71];
    sub_4B3000();
    v6 = (*(int (__thiscall **)(_DWORD *, int))(*this + 8))(this, v10);
    result = this[81] / 2;
    if ( a2 < this[79] + result + v6 )
      return result;
  }
  v8 = a2 - this[81] / 2 - (*(int (__thiscall **)(_DWORD *))(*this + 8))(this);
  v9 = this[80];
  this[79] = v8;
  if ( v8 >= 0 )
  {
    if ( v8 > v9 )
      this[79] = v9;
    return sub_4A2120(this);
  }
  else
  {
    this[79] = 0;
    return sub_4A2120(this);
  }
}
