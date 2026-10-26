int __thiscall sub_461900(int this)
{
  __int16 v2; // ax
  __int16 v3; // ax
  __int16 v4; // ax
  __int16 v5; // ax

  sub_4C5690(this + 32);
  sub_4C54F0(0);
  sub_4B1410(this + 64);
  dword_7D0A44 = *(char *)(this + 100);
  sub_47F1F0(dword_7D0A50);
  dword_7D0FC4 = *(char *)(this + 102);
  sub_47F1F0(dword_7D0FD0);
  dword_7D0C18 = *(char *)(this + 103);
  sub_47F1F0(dword_7D0C24);
  dword_7D0D14 = *(char *)(this + 104);
  sub_47F1F0(dword_7D0D20);
  dword_7D0014 = *(char *)(this + 105);
  sub_47F1F0(dword_7D0020);
  dword_7CEB10 = *(char *)(this + 106);
  sub_47F1F0(dword_7CEB1C);
  dword_7D0EBC = *(char *)(this + 107);
  sub_47F1F0(dword_7D0EC8);
  dword_7CF134 = *(char *)(this + 108);
  sub_47F1F0(dword_7CF140);
  dword_7CF038 = *(char *)(this + 109);
  sub_47F1F0(dword_7CF044);
  flt_7D084C = *(float *)(this + 96);
  sub_4646C0(flt_7D0854, flt_7D0858);
  dword_7D0F4C = *(__int16 *)(this + 116);
  sub_47F1F0(dword_7D0F58);
  v2 = *(_WORD *)(this + 118);
  if ( (v2 & 1) != 0 )
  {
    byte_7CE874 = (v2 & 0x40) != 0;
    sub_464720(byte_7CE877);
  }
  v3 = *(_WORD *)(this + 118);
  if ( (v3 & 2) != 0 )
  {
    byte_7CE88C = (v3 & 0x80) != 0;
    sub_464720(byte_7CE88F);
  }
  v4 = *(_WORD *)(this + 118);
  if ( (v4 & 4) != 0 )
  {
    dword_7CE958 = (unsigned __int16)(v4 & 0x100) >> 8;
    sub_47F1F0(dword_7CE964);
  }
  v5 = *(_WORD *)(this + 118);
  if ( (v5 & 8) != 0 )
  {
    byte_7CE97C = (v5 & 0x200) != 0;
    sub_464720(byte_7CE97F);
  }
  if ( (*(_BYTE *)(this + 118) & 0x10) != 0 )
  {
    flt_7D108C = (double)*(unsigned __int16 *)(this + 124) * 0.001;
    sub_4646C0(flt_7D1094, flt_7D1098);
  }
  dword_7CED44 = (unsigned __int16)(*(_WORD *)(this + 118) & 0x400) >> 10;
  sub_47F1F0(dword_7CED50);
  dword_7CEE40 = (unsigned __int16)(*(_WORD *)(this + 118) & 0x800) >> 11;
  sub_47F1F0(dword_7CEE4C);
  dword_7CEF3C = (unsigned __int16)(*(_WORD *)(this + 118) & 0x1000) >> 12;
  sub_47F1F0(dword_7CEF48);
  dword_7CEC30 = *(__int16 *)(this + 120);
  sub_47F1F0(dword_7CEC3C);
  dword_7CEC54 = *(__int16 *)(this + 122);
  sub_47F1F0(dword_7CEC60);
  dword_7D0134 = sub_4615F0((_BYTE *)this, 1);
  sub_47F1F0(dword_7D0140);
  return sub_4B0EF0(5);
}
