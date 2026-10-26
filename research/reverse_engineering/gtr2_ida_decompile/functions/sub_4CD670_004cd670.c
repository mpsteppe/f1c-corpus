int __thiscall sub_4CD670(_DWORD *this, int a2, int a3)
{
  int v4; // ebp
  int v5; // edx
  int v6; // ecx
  int v7; // edi
  int v8; // edi

  v4 = this[1];
  v5 = this[3];
  v6 = this[4];
  v7 = a3 + this[2];
  this[1] = a3 + v4;
  this[2] = v7;
  v8 = this[36];
  this[3] = a2 + v5;
  for ( this[4] = a2 + v6; v8; v8 = *(_DWORD *)(v8 + 140) )
    sub_4CD670(a2, a3);
  return (*(int (__thiscall **)(_DWORD *))(*this + 152))(this);
}
