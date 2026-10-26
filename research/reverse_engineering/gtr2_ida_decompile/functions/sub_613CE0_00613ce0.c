int __thiscall sub_613CE0(_DWORD *this, int a2, int a3)
{
  int v3; // eax

  v3 = this[5];
  if ( !v3 )
    return sub_6318A2(a2, 1, a3, this[1]);
  if ( v3 == 5 )
    return sub_613A50((_DWORD *)this[1], a2, a3);
  return sub_62AD40(a3);
}
