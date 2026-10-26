int __cdecl sub_5DA4F0(_DWORD *a1, int a2)
{
  _DWORD *v2; // eax
  _DWORD *v3; // eax

  v2 = operator new(0x10u);
  if ( v2 )
    v3 = sub_5DA490(v2);
  else
    v3 = 0;
  *a1 = v3;
  return -(sub_5D9070(v3, a2) != 0);
}
