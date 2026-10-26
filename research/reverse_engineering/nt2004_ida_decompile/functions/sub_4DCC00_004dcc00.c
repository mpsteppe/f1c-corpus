void __thiscall sub_4DCC00(_DWORD *this, char a2, char a3)
{
  int v4; // esi
  int v5; // [esp+0h] [ebp-10h]

  if ( dword_75CBB0 == 7 )
  {
    sub_4F81A0(*this);
    v4 = dword_7D3C44;
    if ( dword_79FC40 < 1023 )
    {
      ++dword_79FC40;
      dword_7D3C44 += 208;
    }
    *(float *)&v5 = dbl_7DA9D0;
    if ( a2 )
    {
      sub_4D0D00((_DWORD *)v4, 4, 26, 1, this[1], v5, 0);
      *(_BYTE *)(v4 + 8) = *((_BYTE *)this + 60);
    }
    else
    {
      sub_4D0D00((_DWORD *)v4, 4, 27, 0, this[1], v5, 0);
    }
    if ( a3 )
      sub_4DCA90(this, v4);
  }
}
