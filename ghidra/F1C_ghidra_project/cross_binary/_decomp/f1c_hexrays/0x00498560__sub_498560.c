// f1c  0x00498560  size=105
void __thiscall sub_498560(char *this, const char *a2)
{
  _BYTE *v3; // eax
  char v4[64]; // [esp+4h] [ebp-40h] BYREF

  if ( a2 && strlen(a2) )
  {
    sub_587DD0(v4, a2, 63);
    v4[63] = 0;
    v3 = (_BYTE *)sub_566810(v4, &dword_5CC79C);
    if ( v3 )
      *v3 = 0;
    strcpy(this + 5400, v4);
  }
}
