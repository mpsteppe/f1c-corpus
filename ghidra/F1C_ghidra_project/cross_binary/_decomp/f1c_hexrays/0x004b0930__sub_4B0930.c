// f1c  0x004b0930  size=102
int __thiscall sub_4B0930(_DWORD *this)
{
  CHAR FileName[253]; // [esp+8h] [ebp-100h] BYREF
  __int16 v4; // [esp+105h] [ebp-3h]
  char v5; // [esp+107h] [ebp-1h]

  sub_4B0E30(this);
  FileName[0] = byte_5EA438[0];
  memset(&FileName[1], 0, 0xFCu);
  v4 = 0;
  v5 = 0;
  sub_4B02B0(this, FileName, 0x100u);
  sub_58BA36(FileName, 128);
  sub_4C2700(FileName);
  return 0;
}
