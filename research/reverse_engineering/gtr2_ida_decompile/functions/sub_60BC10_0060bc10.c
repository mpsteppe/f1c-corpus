int __thiscall sub_60BC10(char *this, char **a2, int a3, char a4)
{
  int v4; // esi
  char *v6; // eax
  char v8; // [esp+0h] [ebp-10h]

  v4 = 0;
  if ( a2 )
  {
    if ( *a2 )
    {
      sub_60BA90(*a2);
    }
    else
    {
      v6 = (char *)operator new(0x24u);
      if ( v6 )
      {
        byte_FB2320 = 0;
        dword_FB2748 = 0;
        *(_DWORD *)v6 = 0;
        *((_DWORD *)v6 + 4) = 0;
        *((_DWORD *)v6 + 3) = 0;
        *((_DWORD *)v6 + 2) = 0;
        *((_DWORD *)v6 + 1) = 0;
        *((_DWORD *)v6 + 5) = 0;
        *((_DWORD *)v6 + 6) = 0;
        *((_DWORD *)v6 + 7) = 0;
        *((_DWORD *)v6 + 8) = 0;
        *a2 = v6;
      }
      else
      {
        *a2 = 0;
      }
    }
    if ( this[4] < 0 )
      v4 = 64;
    if ( (a4 & 1) != 0 )
      v4 |= 1u;
    if ( (a4 & 2) != 0 )
      v4 |= 2u;
    if ( (a4 & 4) != 0 )
      v4 |= 4u;
    if ( (a4 & 8) != 0 )
      v4 |= 8u;
    *(_DWORD *)*a2 = v4;
    return 0;
  }
  else
  {
    sub_5D8C80((int)(this + 4), (char *)0xFFFFFFFF, "Invalid CUBE index buffer pointer", v8);
    return -1;
  }
}
