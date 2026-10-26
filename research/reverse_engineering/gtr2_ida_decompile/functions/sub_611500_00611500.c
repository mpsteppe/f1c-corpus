int __thiscall sub_611500(int this, char **a2, int a3, int a4)
{
  int v4; // edi
  char *v6; // eax
  char *v7; // eax
  char v9; // [esp+0h] [ebp-10h]

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
    v7 = *a2;
    *((_DWORD *)v7 + 4) = 0;
    *((_DWORD *)v7 + 3) = 0;
    *((_DWORD *)v7 + 2) = 0;
    *((_DWORD *)v7 + 1) = 0;
    *((_DWORD *)v7 + 5) = 0;
    *((_DWORD *)v7 + 6) = 0;
    *((_DWORD *)v7 + 7) = 0;
    *((_DWORD *)v7 + 8) = 0;
    if ( *(char *)(this + 4) < 0 )
      v4 = 64;
    if ( (a4 & 1) != 0 )
      v4 |= 1u;
    if ( (a4 & 2) != 0 )
      v4 |= 2u;
    if ( (a4 & 4) != 0 )
      v4 |= 4u;
    if ( (a4 & 8) != 0 )
      v4 |= 8u;
    if ( (a4 & 0x40000) != 0 )
      v4 |= 0x40000u;
    *(_DWORD *)*a2 = v4;
    if ( sub_60AE10((int *)*a2, *(_DWORD *)(this + 9548), a3) )
    {
      sub_5D8C80(this + 4, (char *)0xFFFFFFFF, "Error creating DirectX index buffer", v9);
      return -1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    sub_5D8C80(this + 4, (char *)0xFFFFFFFF, "Invalid CUBE index buffer pointer", v9);
    return -1;
  }
}
