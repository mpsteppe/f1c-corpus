// f1c  0x004b51e0  size=179
char *__thiscall sub_4B51E0(char *this, int a2)
{
  _BYTE *v3; // ecx
  const char *v4; // edx
  const char *v5; // ecx

  sub_4B4F70(this);
  sub_587DD0(this + 1, a2 + 17952, 63);
  this[64] = 0;
  v3 = (_BYTE *)(a2 + 18196 + strlen((const char *)(a2 + 18196)));
  if ( (unsigned int)v3 > a2 + 18196 )
  {
    while ( *v3 != 92 )
    {
      if ( (unsigned int)--v3 <= a2 + 18196 )
        goto LABEL_6;
    }
    ++v3;
  }
LABEL_6:
  sub_587DD0(this + 65, v3, 31);
  this[96] = 0;
  v4 = *(const char **)(a2 + 1920);
  if ( !v4 )
    v4 = byte_5EA438;
  v5 = &v4[strlen(v4)];
  if ( v5 > v4 )
  {
    while ( *v5 != 92 )
    {
      if ( --v5 <= v4 )
        goto LABEL_13;
    }
    ++v5;
  }
LABEL_13:
  sub_587DD0(this + 97, v5, 31);
  this[128] = 0;
  *this = *(_BYTE *)(a2 + 18580);
  return this;
}
