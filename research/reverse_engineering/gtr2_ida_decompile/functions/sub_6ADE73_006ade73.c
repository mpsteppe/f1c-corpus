int __thiscall sub_6ADE73(_DWORD *this)
{
  int v1; // eax
  unsigned int v3; // eax
  unsigned int v4; // eax
  int v5; // eax

  v1 = this[50];
  this[66] = v1;
  switch ( v1 )
  {
    case -65024:
      this[11] = 12;
      goto LABEL_10;
    case -65022:
      v4 = this[28] & 0xFFFFFFCE | 0x11;
      this[27] |= 0x48000100u;
      this[11] = 22;
      this[28] = v4;
      this[50] = -65023;
      goto LABEL_11;
    case -65021:
      this[11] = 32;
      this[50] = -65023;
LABEL_10:
      this[28] |= 0xAu;
      this[27] |= 0x4000102u;
      goto LABEL_11;
  }
  if ( v1 != -64769 )
  {
    sub_686791((int)this, 0, 0, "internal error: no profile exists for this pixel shader version");
    return -2147467259;
  }
  v3 = this[28] & 0xFFFFFFCF | 0x10;
  this[27] |= 0x40000100u;
  this[11] = 32;
  this[24] = 2048;
  this[28] = v3;
LABEL_11:
  v5 = this[11];
  this[27] |= 0x2000A1u;
  this[116] = v5;
  this[10] = 2;
  this[17] = 10;
  this[14] = 0x2000;
  this[18] = 4;
  this[19] = 16;
  this[25] = 1;
  return 0;
}
