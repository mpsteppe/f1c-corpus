int __thiscall sub_4AF2F0(_DWORD *this)
{
  _DWORD *v1; // ecx
  int v2; // edx
  _DWORD *v3; // esi

  sub_4AEF90(this);
  v3 = (_DWORD *)sub_4AF0A0(v1);
  if ( v2 )
    sub_4AF6E0(v2);
  for ( ; v3; v3 = (_DWORD *)v3[35] )
    (*(void (__thiscall **)(_DWORD *))(*v3 + 156))(v3);
  return 0;
}
