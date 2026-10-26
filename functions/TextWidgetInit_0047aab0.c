int __thiscall sub_47AAB0(_DWORD *this)
{
  int v2; // eax
  char *v3; // eax
  _BYTE v5[4]; // [esp+8h] [ebp-4h] BYREF

  v2 = this[50];
  this[56] = &dword_7C5728;
  this[57] = 0;
  this[58] = 0;
  this[59] = 0;
  this[68] = 0;
  if ( v2 )
  {
    v3 = *(char **)(v2 + 64);
    if ( !v3 )
      v3 = byte_5EA438;
    sub_498560(v3);
  }
  TextRenderToSurface(aTtgjz, v5, this + 61, 1);
  this[62] = 5;
  this[63] = 5;
  return AIOvertakeGapCalc();
}
