// Address: 0x00470400
// Size: 141 bytes
// Name: sub_470400
// Type: void __thiscall(_DWORD *this)
// Source: IDA Hex-Rays decompilation

void __thiscall sub_470400(_DWORD *this)
{
  _BYTE v1[61]; // [esp+4h] [ebp-C0h] BYREF
  __int16 v2; // [esp+41h] [ebp-83h]
  char v3; // [esp+43h] [ebp-81h]
  char v4[128]; // [esp+44h] [ebp-80h] BYREF

  if ( this[193] == 435 )
  {
    if ( (unsigned __int8)sub_461DB0(&unk_7CD25C) )
    {
      v1[0] = byte_5EA438;
      memset(&v1[1], 0, 0x3Cu);
      v2 = 0;
      v3 = 0;
      sub_4B0B20(v1, 64);
      sub_45BC10(v1, v4, 128);
      sub_48B8F0(159 - strlen(v4));
    }
  }
}
