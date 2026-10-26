int __thiscall sub_6CC234(_DWORD **this)
{
  unsigned int v2; // eax
  int v3; // ecx
  int result; // eax
  int v5; // [esp-4h] [ebp-1Ch]

  v2 = *this[64] & 0xFFF00000;
  v3 = 0;
  if ( v2 != 1929379840 )
  {
    switch ( v2 )
    {
      case 0x73900000u:
        v5 = 3;
        goto LABEL_7;
      case 0x73A00000u:
        v5 = 4;
        goto LABEL_7;
      case 0x73B00000u:
        v5 = 5;
        goto LABEL_7;
    }
    if ( v2 != 1941962752 )
      goto LABEL_8;
  }
  v5 = 2;
LABEL_7:
  v3 = v5;
LABEL_8:
  result = sub_6CB0CE((int)this, (v3 << 16) | 0x29);
  if ( result >= 0 )
    return off_16C96C4();
  return result;
}
