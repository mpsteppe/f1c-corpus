int __thiscall sub_5E97E0(_DWORD *this, const char *a2, _DWORD *a3, int a4, int a5, const char *a6)
{
  char *v6; // esi
  _DWORD *v7; // ecx
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  _DWORD *v10; // edi
  int v11; // ecx

  v6 = 0;
  v7 = sub_5E9690(this, a2, 0, 0);
  if ( !v7 || (a5 & 0x100) != 0 )
  {
    v8 = operator new(0x450u);
    if ( v8 )
      v6 = (char *)sub_5E8AC0(v8);
    strcpy(v6 + 4, a2);
    _strupr(v6 + 4);
    if ( *((_DWORD *)v6 + 65) )
    {
      sub_5D8C80((int)v6, (char *)0xFFFFFFFF, "Number of textures stages already set for material %s", (_BYTE)v6 + 4);
    }
    else
    {
      *((_DWORD *)v6 + 64) = 1;
      v9 = operator new(0x1E8u);
      if ( v9 )
      {
        *v9 = 1;
        v10 = v9 + 1;
        sub_630A11(v9 + 1, 484, 1, sub_5E38B0, sub_5E39C0);
      }
      else
      {
        v10 = 0;
      }
      *((_DWORD *)v6 + 65) = v10;
    }
    v11 = *((_DWORD *)v6 + 63);
    if ( v11 == 1 )
    {
      *((_DWORD *)v6 + 66) = 0;
    }
    else if ( *((_DWORD *)v6 + 63) == 2 )
    {
      *((_DWORD *)v6 + 133) = 0;
    }
    else if ( *((_DWORD *)v6 + 63) == 3 )
    {
      *((_DWORD *)v6 + 200) = 0;
    }
    switch ( v11 )
    {
      case 1:
        *((_DWORD *)v6 + 67) = 1;
        break;
      case 2:
        *((_DWORD *)v6 + 134) = 1;
        break;
      case 3:
        *((_DWORD *)v6 + 201) = 1;
        break;
    }
    if ( a6 && *a6 )
    {
      strcpy((char *)(*((_DWORD *)v6 + 65) + 12), a6);
      *(_DWORD *)(*((_DWORD *)v6 + 65) + 96) = 1;
      *(_DWORD *)(*((_DWORD *)v6 + 65) + 100) = 3;
      *(_DWORD *)(*((_DWORD *)v6 + 65) + 4) = 1;
    }
    else
    {
      *(_DWORD *)(*((_DWORD *)v6 + 65) + 96) = 99;
      *(_DWORD *)(*((_DWORD *)v6 + 65) + 100) = 3;
    }
    **((_DWORD **)v6 + 65) |= a5;
    *(_DWORD *)v6 |= a4 | 3;
    sub_5FDFB0(v6, 1);
    v7 = v6;
  }
  if ( a3 )
    *a3 = v7;
  return 0;
}
