int __thiscall sub_4B5DE0(_DWORD *this, int a2)
{
  int *v3; // ecx
  int v4; // eax
  int v5; // eax
  int v6; // eax

  v3 = (int *)this[211];
  v4 = *v3;
  if ( a2 == 1 )
    v5 = v4 + 1;
  else
    v5 = v4 - 1;
  if ( v5 >= 0 )
  {
    if ( v5 > 1 )
      v5 = 1;
  }
  else
  {
    v5 = 0;
  }
  if ( v5 )
    *v3 = 1;
  else
    *v3 = 0;
  dword_B64154 = dword_B72454;
  sub_432C90();
  v6 = dword_B71D88;
  dword_B71D80 = 0;
  if ( dword_B71D88 > 0 || (v6 = dword_B71D8C, dword_B71D8C < 0) )
    dword_B71D80 = v6;
  return (*(int (__thiscall **)(_DWORD *))(*this + 152))(this);
}
