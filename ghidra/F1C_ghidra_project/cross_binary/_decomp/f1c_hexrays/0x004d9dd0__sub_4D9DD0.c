// f1c  0x004d9dd0  size=257
int __thiscall sub_4D9DD0(float *this)
{
  int v1; // edi
  int v2; // eax
  char v3; // cl
  int v5[31]; // [esp+8h] [ebp-80h] BYREF
  char v6; // [esp+87h] [ebp-1h]

  v1 = sub_4D98A0(this);
  if ( !v1 )
  {
    sub_58815F(v5, "%c", byte_5D4AE9);
    sub_4D7E40((int)v5, 924, 858, 16711680, 0, 3, 1.0, 1.0);
    sub_4D7E40((int)v5, 1180, 858, 65280, 1, 3, 1.0, 1.0);
    if ( sub_423A00(byte_5EC4C0, byte_5EA438, byte_5EC4CC) )
    {
      v2 = 0;
      do
      {
        v3 = byte_5EA438[v2];
        byte_5EC4CC[v2++] = v3;
      }
      while ( v3 );
    }
    sub_587DD0(v5, byte_5EC4CC, 127);
    v6 = 0;
    sub_4D7E40((int)v5, 1052, 858, 16776960, 2, 0, 1.0, 1.0);
  }
  return v1;
}
