// f1c  0x00541f60  size=235
void __thiscall sub_541F60(float *this, int a2, float a3, float a4)
{
  double v5; // st7
  long double v6; // st7
  int v7; // [esp+0h] [ebp-24h]
  int v8; // [esp+4h] [ebp-20h]
  float v9; // [esp+8h] [ebp-1Ch]
  float v10; // [esp+14h] [ebp-10h]
  float v11; // [esp+1Ch] [ebp-8h]
  float v12; // [esp+20h] [ebp-4h]
  int v13; // [esp+28h] [ebp+4h]
  float v14; // [esp+28h] [ebp+4h]
  float v15; // [esp+2Ch] [ebp+8h]
  float v16; // [esp+30h] [ebp+Ch]

  v11 = this[9] - *(float *)&a2;
  *(float *)&v13 = this[10] - a3;
  v5 = this[11] - a4;
  v15 = v5;
  v6 = sqrt(v5 * v15 + *(float *)&v13 * *(float *)&v13 + v11 * v11);
  if ( v6 != 0.0 )
  {
    v16 = 1.0 / v6;
    sub_588570(this);
    v12 = -(v16 * *(float *)&v13);
    v14 = atan2(v16 * v15, v16 * v11) + 1.5707964;
    this[12] = -v12;
    this[13] = -v14;
    v10 = -this[14];
    v9 = this[11] - this[17];
    *(float *)&v8 = this[10] - this[16];
    *(float *)&v7 = this[9] - this[15];
    sub_541CD0(v7, v8, v9, v12, v14, v10);
  }
}
