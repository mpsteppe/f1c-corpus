char __thiscall sub_4D31A0(void *Buffer, int a2)
{
  unsigned __int8 v2; // al
  unsigned __int8 Buffera; // [esp+Fh] [ebp-101h] BYREF
  _BYTE v5[253]; // [esp+10h] [ebp-100h] BYREF
  __int16 v6; // [esp+10Dh] [ebp-3h]
  char v7; // [esp+10Fh] [ebp-1h]

  sub_57A3D0(Buffer, 4u);
  Buffera = 0;
  sub_57A3D0(&Buffera, 1u);
  v5[0] = byte_629120;
  memset(&v5[1], 0, 0xFCu);
  v6 = 0;
  v7 = 0;
  v2 = Buffera;
  if ( Buffera )
  {
    sub_57A3D0(v5, Buffera);
    v2 = Buffera;
  }
  v5[v2] = 0;
  sub_578600(v5);
  return 1;
}
