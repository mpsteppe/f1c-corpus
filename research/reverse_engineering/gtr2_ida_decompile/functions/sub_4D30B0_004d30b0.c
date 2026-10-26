int __thiscall sub_4D30B0(_DWORD *this, int a2, int a3)
{
  int v4; // eax
  int v5; // edi
  int v6; // ebx
  int v7; // ecx

  v4 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
  v5 = a3;
  v6 = a2;
  if ( !v4 || !(*(int (__thiscall **)(_DWORD *))(*this + 8))(this) )
  {
    a3 = 0;
    a2 = 0;
    sub_4DF1D0(v6, v5, &a3, &a2);
    v7 = a2;
    this[1] = a3;
    this[2] = v7;
  }
  sub_615860(v6);
  return sub_615860(v5);
}
