// f1c  0x0049b200  size=360
int __stdcall sub_49B200(int a1, int a2, float a3)
{
  double v3; // st7
  double v4; // st7
  char v5; // al
  unsigned __int16 v6; // cx
  char v7; // al
  int v8; // ecx
  int v10; // [esp+Ch] [ebp+8h]
  float v11; // [esp+10h] [ebp+Ch]
  int v12; // [esp+10h] [ebp+Ch]

  v3 = dbl_8AFEA0 + a3;
  sub_58957A(v3);
  if ( v3 >= 0.5 )
    v4 = 1.0 - (v3 - 0.5 + v3 - 0.5);
  else
    v4 = v3 + v3;
  v11 = v4;
  if ( v11 >= 0.0 )
  {
    if ( v11 > 1.0 )
      v4 = 1.0;
  }
  else
  {
    v4 = 0.0;
  }
  v5 = sub_587BDC(v4);
  LOBYTE(v6) = 0;
  HIBYTE(v6) = v5;
  v12 = v6;
  v7 = sub_587BDC(v4);
  v8 = v12;
  LOBYTE(v8) = v7;
  v10 = ((unsigned __int8)sub_587BDC(v4) | (v8 << 8)) << 8;
  return (unsigned __int8)sub_587BDC(v4) | v10;
}
