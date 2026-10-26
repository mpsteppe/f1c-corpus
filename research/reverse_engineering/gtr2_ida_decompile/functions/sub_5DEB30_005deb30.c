int __stdcall sub_5DEB30(_DWORD *a1, int a2, int a3)
{
  _DWORD *v3; // eax
  _DWORD *v4; // eax

  v3 = operator new(0x344u);
  if ( v3 )
    v4 = sub_5DE340(v3);
  else
    v4 = 0;
  *a1 = v4;
  *v4 |= a3;
  if ( sub_5DCEF0((_DWORD *)*a1, a2, a3) )
    return -1;
  sub_5FDFB0(*a1, 1);
  return 0;
}
