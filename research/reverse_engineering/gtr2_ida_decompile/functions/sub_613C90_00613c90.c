int __thiscall sub_613C90(_DWORD *this, int a2, int a3)
{
  int v3; // eax
  int v5; // ecx

  v3 = this[5];
  if ( !v3 )
    return sub_631E50(a2, 1, a3, this[1]);
  v5 = this[1];
  if ( v3 != 5 )
    return sub_62A860(a3);
  sub_613900(v5, a2, a3);
  return a3;
}
