// f1c  0x004569b0  size=130
void __thiscall sub_4569B0(float *this, float a2, int a3, float a4)
{
  double v4; // st7
  double v6; // st7
  float v7; // [esp+8h] [ebp+4h]
  float v8; // [esp+8h] [ebp+4h]
  float v9; // [esp+Ch] [ebp+8h]

  v4 = 0.5;
  if ( a3 == 1 )
    v4 = 2.0;
  if ( !LOBYTE(a2) )
    v4 = v4 * -1.0;
  v6 = v4 * a4;
  v7 = v6;
  v9 = v6 + this[40];
  this[40] = v9;
  sub_58957A(v9);
  this[40] = v9;
  v8 = v7 + this[47];
  this[47] = v8;
  sub_58957A(v8);
  this[47] = v8;
}
