// Address: 0x0045d130
// Size: 264 bytes
// Name: sub_45D130
// Type: int __thiscall(void *this, int)
// Source: IDA Hex-Rays decompilation

int __thiscall sub_45D130(void *this, int a2)
{
  int result; // eax
  int v4; // esi
  int i; // [esp+Ch] [ebp-F4h]
  char v6[4]; // [esp+10h] [ebp-F0h] BYREF
  _BYTE v7[32]; // [esp+14h] [ebp-ECh] BYREF
  _BYTE v8[64]; // [esp+34h] [ebp-CCh] BYREF
  char v9[4]; // [esp+74h] [ebp-8Ch] BYREF
  __int16 v10; // [esp+F4h] [ebp-Ch]
  __int16 v11; // [esp+FAh] [ebp-6h]

  result = sub_462370(&unk_7CD25C);
  v4 = 0;
  for ( i = result; v4 < i; ++v4 )
  {
    sub_461470(v9);
    if ( (unsigned __int8)sub_462410(v4, v9, v6) )
    {
      v7[0] = 0;
      v8[0] = 0;
      sub_58815F(v7, "player_%d", v4);
      sub_45CE30(this);
      sub_58815F(v7, "score_%d", v4);
      sub_58815F(v8, "%d", v10);
      sub_45CE30(this);
      sub_58815F(v7, "ping_%d", v4);
      sub_58815F(v8, "%d", v11);
      sub_45CE30(this);
    }
    nullsub_3(v9);
    result = i;
  }
  return result;
}
