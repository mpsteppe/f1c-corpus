int __thiscall sub_47BB40(_DWORD *this, int a2)
{
  int v3; // ecx
  int result; // eax
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // edi
  int v9; // ecx

  v3 = (*(int (__thiscall **)(_DWORD *))(*this + 28))(this);
  result = this[70] / 2;
  v5 = this[68] + result + v3;
  if ( a2 >= v5 )
  {
    if ( a2 <= v5 )
      return result;
    BoundedCounterUpdate(this, this[60]);
    v7 = (*(int (__thiscall **)(_DWORD *))(*this + 28))(this);
    result = this[70] / 2;
    if ( a2 > this[68] + result + v7 )
      return result;
  }
  else
  {
    BoundedCounterUpdate(this, -this[60]);
    v6 = (*(int (__thiscall **)(_DWORD *))(*this + 28))(this);
    result = this[70] / 2;
    if ( a2 < this[68] + result + v6 )
      return result;
  }
  v8 = a2 - this[70] / 2 - (*(int (__thiscall **)(_DWORD *))(*this + 28))(this);
  v9 = this[69];
  this[68] = v8;
  if ( v8 >= 0 )
  {
    if ( v8 > v9 )
      this[68] = v9;
    return sub_47BE00(this);
  }
  else
  {
    this[68] = 0;
    return sub_47BE00(this);
  }
}

