int __thiscall sub_4A59F0(_DWORD *this, char *String2, int a3)
{
  int v4; // eax
  int v5; // edi
  char *v6; // ebx
  char *v7; // ecx

  v4 = (*(int (__thiscall **)(_DWORD *))(*this + 4))(this);
  v5 = a3;
  v6 = String2;
  if ( !v4 || !(*(int (__thiscall **)(_DWORD *))(*this + 8))(this) )
  {
    a3 = 0;
    String2 = 0;
    sub_4AE370(v6, v5, (int)&a3, (int)&String2);
    v7 = String2;
    this[1] = a3;
    this[2] = v7;
  }
  sub_578600(v6);
  return sub_578600(v5);
}
