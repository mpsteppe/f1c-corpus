// f1c  0x004b4250  size=138
char __thiscall sub_4B4250(void *this, int a2)
{
  unsigned __int8 v2; // al
  unsigned __int8 v4; // [esp+Fh] [ebp-101h] BYREF
  _BYTE v5[253]; // [esp+10h] [ebp-100h] BYREF
  __int16 v6; // [esp+10Dh] [ebp-3h]
  char v7; // [esp+10Fh] [ebp-1h]

  sub_566C00(this, 4);
  v4 = 0;
  sub_566C00(&v4, 1);
  v5[0] = byte_5EA438[0];
  memset(&v5[1], 0, 0xFCu);
  v6 = 0;
  v7 = 0;
  v2 = v4;
  if ( v4 )
  {
    sub_566C00(v5, v4);
    v2 = v4;
  }
  v5[v2] = 0;
  sub_566650(v5);
  return 1;
}
