char __thiscall sub_41E030(_DWORD *this, int a2, int a3, float a4, char *String1)
{
  char *v5; // edi
  const char *v6; // esi
  const char *v7; // eax
  int v9; // edi
  int v10; // eax

  v5 = String1;
  if ( !String1 )
  {
    v5 = Str;
    if ( !Str )
      v5 = (char *)WindowName;
  }
  v6 = sub_41D920(this, v5);
  if ( v6 )
  {
    v9 = a3;
  }
  else
  {
    v7 = (const char *)operator new(0x4Cu);
    v6 = v7;
    if ( !v7 )
      return 0;
    sub_630FE0(v7, v5, 63);
    v9 = a3;
    *((_BYTE *)v6 + 63) = 0;
    *((_DWORD *)v6 + 17) = a3;
    *((_DWORD *)v6 + 16) = a2;
    *((float *)v6 + 18) = a4;
    sub_5FDFB0(v6, 1);
  }
  if ( a2 == -1 )
  {
    v10 = *((_DWORD *)v6 + 16);
    if ( v10 != 1 && v10 != 2 )
      *((_DWORD *)v6 + 16) = -1;
  }
  else if ( a2 == 1 )
  {
    *((_DWORD *)v6 + 16) = 1;
  }
  else if ( a2 == 2 && *((_DWORD *)v6 + 16) != 1 )
  {
    *((_DWORD *)v6 + 16) = 2;
  }
  if ( a4 > (double)*((float *)v6 + 18) )
    *((float *)v6 + 18) = a4;
  if ( v9 < *((_DWORD *)v6 + 17) )
    *((_DWORD *)v6 + 17) = v9;
  return 1;
}
