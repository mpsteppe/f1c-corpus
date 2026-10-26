void __thiscall sub_420160(float *this, float a2, int a3, float a4, float a5, int a6, float a7)
{
  double v7; // st7
  double v8; // st6
  double v9; // st5
  unsigned __int8 v11; // c0
  unsigned __int8 v12; // c3
  double v13; // st5
  double v14; // st5
  unsigned __int8 v16; // c0
  unsigned __int8 v17; // c3
  double v18; // st7
  float v19; // [esp+10h] [ebp+10h]
  float v20; // [esp+10h] [ebp+10h]
  float v21; // [esp+10h] [ebp+10h]
  float v22; // [esp+18h] [ebp+18h]
  float v23; // [esp+18h] [ebp+18h]

  v7 = *(float *)(*(_DWORD *)this + 15988) - a5;
  v8 = *(float *)(*(_DWORD *)this + 15996) - a7;
  v9 = a4 * v8 + a2 * v7;
  v19 = a2 * v9;
  v22 = a4 * v9;
  v13 = sqrt(v22 * v22 + v19 * v19);
  if ( v11 | v12 )
    v13 = -v13;
  this[3] = v13;
  v20 = -a4;
  v14 = a2 * v8 - a4 * v7;
  v21 = v20 * v14;
  v23 = a2 * v14;
  v18 = sqrt(v23 * v23 + v21 * v21);
  if ( !(v16 | v17) )
    v18 = -v18;
  this[1] = v18;
}
