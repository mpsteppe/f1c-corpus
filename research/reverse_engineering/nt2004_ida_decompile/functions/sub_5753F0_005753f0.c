int __thiscall sub_5753F0(_DWORD *this, int a2)
{
  int v3; // edi

  v3 = 2;
  if ( a2 )
  {
    sub_574CE0(this, a2);
    v3 = 0;
  }
  (*(void (__thiscall **)(_DWORD *))(*this + 56))(this);
  return v3;
}
