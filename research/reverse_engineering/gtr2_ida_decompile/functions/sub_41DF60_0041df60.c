char __thiscall sub_41DF60(_DWORD *this, int a2, float a3, char *String1)
{
  char *v4; // edi
  const char *v5; // esi
  const char *v6; // eax
  int v8; // eax

  v4 = String1;
  if ( !String1 )
  {
    v4 = (char *)dword_B72438;
    if ( !dword_B72438 )
      v4 = (char *)WindowName;
  }
  v5 = sub_41D8B0(this, v4);
  if ( !v5 )
  {
    v6 = (const char *)operator new(0x48u);
    v5 = v6;
    if ( !v6 )
      return 0;
    sub_630FE0(v6, v4, 63);
    *((_BYTE *)v5 + 63) = 0;
    *((_DWORD *)v5 + 16) = a2;
    *((float *)v5 + 17) = a3;
    sub_5FDFB0(v5, 1);
  }
  switch ( a2 )
  {
    case 2:
      v8 = *((_DWORD *)v5 + 16);
      if ( v8 != 3 && v8 != 4 )
        *((_DWORD *)v5 + 16) = 2;
      break;
    case 3:
      if ( *((_DWORD *)v5 + 16) != 4 )
        *((_DWORD *)v5 + 16) = 3;
      break;
    case 4:
      *((_DWORD *)v5 + 16) = 4;
      break;
  }
  if ( a3 < (double)*((float *)v5 + 17) )
    *((float *)v5 + 17) = a3;
  return 1;
}
