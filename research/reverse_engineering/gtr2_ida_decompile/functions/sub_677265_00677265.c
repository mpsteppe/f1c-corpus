int __stdcall sub_677265(int a1, _DWORD *a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  int v5; // edi

  if ( !a2 )
    return -2005530516;
  v3 = operator new(0x10u);
  if ( v3 )
    v4 = sub_67724D(v3);
  else
    v4 = 0;
  if ( !v4 )
    return -2147024882;
  v5 = (*(int (__thiscall **)(_DWORD *, int))(*v4 + 24))(v4, a1);
  if ( v5 >= 0 )
  {
    *a2 = v4;
    return 0;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD *, int))(*v4 + 20))(v4, 1);
    return v5;
  }
}
