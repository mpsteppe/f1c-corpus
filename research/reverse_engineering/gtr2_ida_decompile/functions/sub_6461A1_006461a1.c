int __stdcall sub_6461A1(_DWORD *a1, _DWORD *a2)
{
  void *v2; // esi
  unsigned int v4; // eax
  void *v5; // eax
  int v6; // edi

  v2 = 0;
  if ( a2 )
    *a2 = 0;
  if ( !a1 || !a2 )
    return -2005530516;
  v4 = *a1 & 0xFFFF0000;
  if ( v4 != -131072 && v4 != -65536 )
    goto LABEL_14;
  v5 = operator new(0x20u);
  if ( v5 )
    v2 = (void *)sub_67652E(v5);
  if ( !v2 )
    return -2147024882;
  v6 = sub_67654F(a1, 0);
  if ( v6 < 0 )
  {
    sub_646093(v2, 1);
    return v6;
  }
  else
  {
LABEL_14:
    *a2 = v2;
    return 0;
  }
}
