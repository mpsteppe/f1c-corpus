int __thiscall sub_462FE0(int this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  __int16 v5; // ax
  __int16 v6; // ax
  __int16 v7; // ax

  sub_4E8D60(this + 32);
  sub_4E8A30(&byte_7D6A30);
  v2 = *(char *)(this + 68);
  dword_769158 = v2;
  if ( v2 >= dword_769160 )
  {
    if ( v2 > dword_769164 )
      dword_769158 = dword_769164;
  }
  else
  {
    dword_769158 = dword_769160;
  }
  v3 = *(char *)(this + 70);
  dword_769998 = v3;
  if ( v3 >= dword_7699A0 )
  {
    if ( v3 > dword_7699A4 )
      dword_769998 = dword_7699A4;
  }
  else
  {
    dword_769998 = dword_7699A0;
  }
  v4 = *(char *)(this + 71);
  dword_769320 = v4;
  if ( v4 >= dword_769328 )
  {
    if ( v4 > dword_76932C )
      dword_769320 = dword_76932C;
  }
  else
  {
    dword_769320 = dword_769328;
  }
  dword_769464 = *(char *)(this + 72);
  sub_4CF410(dword_769470);
  *(_DWORD *)dword_7684BC = *(char *)(this + 73);
  sub_4CF410(dword_7684C8);
  dword_766C20 = *(char *)(this + 74);
  sub_4CF410(dword_766C2C);
  dword_769890 = *(char *)(this + 75);
  sub_4CF410(dword_76989C);
  dword_767508 = *(char *)(this + 76);
  sub_4CF410(dword_767514);
  dword_7673C4 = *(char *)(this + 77);
  sub_4CF410(dword_7673D0);
  dword_768EAC = *(_DWORD *)(this + 64);
  sub_466720(flt_768EB4, flt_768EB8);
  dword_769920 = *(__int16 *)(this + 84);
  sub_4CF410(dword_76992C);
  v5 = *(_WORD *)(this + 86);
  if ( (v5 & 1) != 0 )
  {
    byte_76699C = (v5 & 0x40) != 0;
    sub_466780(byte_76699F);
  }
  v6 = *(_WORD *)(this + 86);
  if ( (v6 & 2) != 0 )
  {
    byte_7669B4 = (v6 & 0x80) != 0;
    sub_466780(byte_7669B7);
  }
  v7 = *(_WORD *)(this + 86);
  if ( (v7 & 4) != 0 )
  {
    *(_DWORD *)dword_766AA4 = (unsigned __int16)(v7 & 0x100) >> 8;
    sub_4CF410(dword_766AB0);
  }
  if ( (*(_BYTE *)(this + 86) & 0x10) != 0 )
  {
    flt_769A90 = (double)*(unsigned __int16 *)(this + 88) * 0.001;
    sub_466720(flt_769A98, flt_769A9C);
  }
  dword_766EB4 = (unsigned __int16)(*(_WORD *)(this + 86) & 0x400) >> 10;
  sub_4CF410(dword_766EC0);
  dword_766FF8 = (unsigned __int16)(*(_WORD *)(this + 86) & 0x800) >> 11;
  sub_4CF410(dword_767004);
  dword_76713C = (unsigned __int16)(*(_WORD *)(this + 86) & 0x1000) >> 12;
  sub_4CF410(dword_767148);
  flt_767280 = (flt_76728C - flt_767288) * ((double)*(unsigned __int8 *)(this + 78) * 0.0039215689) + flt_767288;
  sub_466720(flt_767288, flt_76728C);
  dword_768618 = sub_462D10((_BYTE *)this, 1);
  sub_4CF410(dword_768624);
  return sub_4CE0F0(5);
}
