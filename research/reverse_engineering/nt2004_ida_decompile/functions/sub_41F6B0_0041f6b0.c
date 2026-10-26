void __thiscall sub_41F6B0(int this, float a2, int a3, float a4, float a5)
{
  float *v5; // eax
  double v6; // st7
  double v7; // st7
  unsigned __int8 v9; // c0
  unsigned __int8 v10; // c3
  double v11; // st7
  double v12; // st6
  unsigned __int8 v14; // c0
  unsigned __int8 v15; // c3
  double v16; // st7
  float v17; // [esp+4h] [ebp-1Ch]
  float v18; // [esp+8h] [ebp-18h]
  float v19; // [esp+8h] [ebp-18h]
  float v20; // [esp+10h] [ebp-10h]
  float v21; // [esp+10h] [ebp-10h]
  float v22; // [esp+14h] [ebp-Ch]
  float v23; // [esp+1Ch] [ebp-4h]

  v5 = *(float **)(this + 4);
  v22 = v5[4425] * 0.2 + v5[4407];
  v23 = v5[4427] * 0.2 + v5[4409];
  v6 = a4 * a4 + a2 * a2;
  v17 = v6;
  if ( v6 == 0.0 )
    v7 = 0.0;
  else
    v7 = (v23 * a4 + v22 * a2) / v17;
  v18 = a2 * v7;
  v20 = a4 * v7;
  v11 = sqrt(v20 * v20 + v18 * v18);
  if ( v9 | v10 )
    v11 = -v11;
  *(float *)(this + 64) = v11;
  *(float *)(this + 64) = *(float *)(this + 64) - a5;
  if ( v17 == 0.0 )
    v12 = 0.0;
  else
    v12 = (v23 * a2 - v22 * a4) / v17;
  v19 = v12 * -a4;
  v21 = a2 * v12;
  v16 = sqrt(v21 * v21 + v19 * v19);
  if ( !(v14 | v15) )
    v16 = -v16;
  *(float *)(this + 56) = v16;
}
