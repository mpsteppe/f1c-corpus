BOOL __thiscall sub_4069F0(_DWORD *this, const CHAR *a2, LONG a3)
{
  int v4; // eax
  _BYTE v6[32]; // [esp+4h] [ebp-20h] BYREF

  if ( this[23] != -1 )
    sub_406A70(this);
  v4 = StringFormatWith0x40Size(a2, 0x8000, 256);
  this[23] = v4;
  if ( v4 != -1 )
  {
    sub_58C724(v4, a3, 0);
    StringFormatWithBufferOverflowCheck(v6, "%s%d,%d.mp3", asc_5BE820, this[23], this[7]);
    StringCopyWithBufferRealloc(v6);
  }
  return this[23] != -1;
}

