void __thiscall sub_575690(float *this)
{
  double v1; // st7
  double v3; // st7
  unsigned __int8 v4; // c0
  unsigned __int8 v5; // c2
  double v6; // st7
  double v8; // st6
  unsigned __int8 v9; // c0
  unsigned __int8 v10; // c2
  double v11; // st6
  double v13; // st5
  unsigned __int8 v14; // c0
  unsigned __int8 v15; // c2
  double v16; // st5
  double v17; // st4
  double v18; // st6
  double v19; // rt1
  double v20; // st4
  float v21; // [esp+8h] [ebp-1Ch]
  float v22; // [esp+Ch] [ebp-18h]
  float v23; // [esp+10h] [ebp-14h]
  float v24; // [esp+14h] [ebp-10h]
  float v25; // [esp+18h] [ebp-Ch]
  float v26; // [esp+18h] [ebp-Ch]
  float v27; // [esp+1Ch] [ebp-8h]
  float v28; // [esp+1Ch] [ebp-8h]
  float v29; // [esp+20h] [ebp-4h]
  float v30; // [esp+20h] [ebp-4h]

  v1 = this[4009] * -9.81;
  v22 = v1 * this[3987] + this[3990] * 0.0 + this[3984] * 0.0;
  v23 = v1 * this[3988] + this[3991] * 0.0 + this[3985] * 0.0;
  v24 = v1 * this[3989] + this[3992] * 0.0 + this[3986] * 0.0;
  v21 = this[3992] * this[4354] + this[3989] * this[4353] + this[3986] * this[4352];
  v25 = this[4002] - (this[3990] * this[4354] + this[3987] * this[4353] + this[4352] * this[3984]);
  v27 = this[4003] - (this[3991] * this[4354] + this[3988] * this[4353] + this[3985] * this[4352]);
  v29 = this[4004] - v21;
  v26 = v25 * v25;
  v28 = v27 * v27;
  v30 = v29 * v29;
  v3 = v26 * this[4355];
  if ( v4 | v5 )
    v6 = v3 + v22;
  else
    v6 = v22 - v3;
  v8 = v28 * this[4356];
  if ( v9 | v10 )
    v11 = v8 + v23;
  else
    v11 = v23 - v8;
  v13 = v30 * this[4357];
  if ( v14 | v15 )
  {
    v16 = v13 + v24;
    v17 = v11;
    v18 = v30 * this[4358];
    v19 = v17 - v18;
    v20 = v18;
    v11 = v19;
    this[4027] = v20 * this[4359] + this[4027];
  }
  else
  {
    v16 = v24 - v13;
  }
  this[4024] = v6 + this[4024];
  this[4025] = v11 + this[4025];
  this[4026] = v16 + this[4026];
}
