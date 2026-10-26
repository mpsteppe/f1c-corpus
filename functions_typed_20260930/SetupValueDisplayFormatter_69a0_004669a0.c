int __thiscall sub_4669A0(float *this)
{
  float v2; // edx
  int *v3; // eax
  double v4; // st7
  int v5; // eax
  _BYTE v7[61]; // [esp+8h] [ebp-40h] BYREF
  __int16 v8; // [esp+45h] [ebp-3h]
  char v9; // [esp+47h] [ebp-1h]

  v2 = *this;
  v7[0] = byte_5EA438[0];
  memset(&v7[1], 0, 0x3Cu);
  v8 = 0;
  v9 = 0;
  v3 = (int *)(*(int (__thiscall **)(float *))(LODWORD(v2) + 180))(this);
  if ( *((_BYTE *)this + 240) )
    v4 = (double)*v3 / (this[62] - this[61]);
  else
    v4 = *(float *)v3 / (this[62] - this[61]);
  v5 = CRTFtol(v4 * 100.0);
  StringFormatWithBufferOverflowCheck(v7, "%d%%", v5);
  StringCopyWithBufferRealloc(v7);
  return 0;
}

