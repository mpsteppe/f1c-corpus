// f1c  0x004b43e0  size=108
int __stdcall sub_4B43E0(int a1)
{
  _DWORD v2[108]; // [esp+4h] [ebp-1B0h] BYREF

  sub_566C00(v2, 4);
  if ( (v2[0] & 0xE0000000) != 0x20000000 || (v2[0] & 0xFC0000) != 0 )
    return sub_566DF0((v2[0] >> 8) & 0x3FF);
  else
    return sub_566DF0(((v2[0] >> 8) & 0x3FF) + 1);
}
