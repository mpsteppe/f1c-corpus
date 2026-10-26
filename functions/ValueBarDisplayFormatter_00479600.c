int __thiscall sub_479600(float *this)
{
  float *v2; // eax
  float v4; // [esp+4h] [ebp-48h]
  _BYTE v5[61]; // [esp+Ch] [ebp-40h] BYREF
  __int16 v6; // [esp+49h] [ebp-3h]
  char v7; // [esp+4Bh] [ebp-1h]

  v2 = (float *)(*(int (__thiscall **)(float *))(*(_DWORD *)this + 180))(this);
  if ( v2 )
  {
    v4 = (*v2 - this[61]) * 100.0 / (this[62] - this[61]);
    v5[0] = byte_5EA438[0];
    memset(&v5[1], 0, 0x3Cu);
    v6 = 0;
    v7 = 0;
    StringFormatWithBufferOverflowCheck(v5, "%d%%", (int)v4);
    StringCopyWithBufferRealloc(v5);
  }
  return 0;
}
