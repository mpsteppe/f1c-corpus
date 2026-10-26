// Address: 0x0045cf50
// Size: 378 bytes
// Name: sub_45CF50
// Type: int __thiscall(void *this, int)
// Source: IDA Hex-Rays decompilation

int __thiscall sub_45CF50(void *this, int a2)
{
  unsigned __int16 v4; // [esp+6h] [ebp-112h] BYREF
  _BYTE v5[16]; // [esp+8h] [ebp-110h] BYREF
  _BYTE v6[32]; // [esp+18h] [ebp-100h] BYREF
  _BYTE v7[96]; // [esp+38h] [ebp-E0h] BYREF
  _BYTE v8[125]; // [esp+98h] [ebp-80h] BYREF
  __int16 v9; // [esp+115h] [ebp-3h]
  char v10; // [esp+117h] [ebp-1h]

  sub_461550(v6);
  if ( (unsigned __int8)sub_4627C0(v6, &v4) )
  {
    sub_45CE30(this);
    v5[0] = 0;
    sub_58815F(v5, "%d", v4);
    sub_45CE30(this);
    sub_4C5690(v7);
    if ( dword_8AC490 + 396 * dword_8AC48C )
    {
      v8[0] = byte_5EA438;
      memset(&v8[1], 0, 0x7Cu);
      v9 = 0;
      v10 = 0;
      sub_4C5900(v8, 128);
      sub_45CE30(this);
    }
    sub_58815F(v5, "%d", v7[68] + v7[69] + 1);
    sub_45CE30(this);
    sub_58815F(v5, "%d", v7[70]);
    sub_45CE30(this);
    sub_462A00(&unk_7CD25C);
    sub_45CE30(this);
  }
  return nullsub_3(v6);
}
