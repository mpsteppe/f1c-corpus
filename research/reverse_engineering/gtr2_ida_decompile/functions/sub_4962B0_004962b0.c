void __thiscall sub_4962B0(_DWORD *this, int a2, int a3)
{
  const CHAR *v4; // eax
  const CHAR *v5; // eax
  const CHAR *v6; // eax

  v4 = *(const CHAR **)dword_91CAC8;
  if ( !*(_DWORD *)dword_91CAC8 )
    v4 = WindowName;
  sub_615860(v4);
  v5 = (const CHAR *)this[157];
  if ( !v5 )
    v5 = WindowName;
  sub_615A50(v5);
  v6 = &WindowName[strlen(WindowName)];
  if ( v6 > WindowName )
  {
    while ( *v6 != 46 )
    {
      if ( --v6 <= WindowName )
        goto LABEL_10;
    }
    *v6 = 0;
  }
LABEL_10:
  sub_615A50(".txt");
  sub_630FE0(a2, WindowName, a3);
  *(_BYTE *)(a2 + a3) = 0;
}
