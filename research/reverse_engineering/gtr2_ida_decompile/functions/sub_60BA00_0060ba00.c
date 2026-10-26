int __thiscall sub_60BA00(char *this, _DWORD *a2, int a3, int a4, char a5)
{
  int v5; // esi
  _DWORD *v7; // eax
  char v9; // [esp+0h] [ebp-Ch]

  v5 = 0;
  if ( a2 )
  {
    if ( *a2 )
    {
      sub_60B4D0();
    }
    else
    {
      v7 = operator new(0x50u);
      if ( v7 )
        *a2 = sub_60ADA0(v7);
      else
        *a2 = 0;
    }
    if ( this[4] < 0 )
      v5 = 64;
    if ( (a5 & 1) != 0 )
      v5 |= 1u;
    if ( (a5 & 2) != 0 )
      v5 |= 2u;
    if ( (a5 & 4) != 0 )
      v5 |= 4u;
    if ( (a5 & 8) != 0 )
      v5 |= 8u;
    *(_DWORD *)*a2 = v5;
    return 0;
  }
  else
  {
    sub_5D8C80((int)(this + 4), (char *)0xFFFFFFFF, "Invalid CUBE vertex buffer pointer", v9);
    return -1;
  }
}
