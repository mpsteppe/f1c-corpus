void __thiscall sub_420040(float *this, char a2, int a3, int a4, float a5)
{
  int v5; // eax
  float *v6; // esi
  float *v7; // edx
  double v8; // st5
  unsigned __int8 v10; // c0
  unsigned __int8 v11; // c3
  double v12; // st7
  double v13; // st5
  unsigned __int8 v15; // c0
  unsigned __int8 v16; // c3
  double v17; // st7
  float v18; // [esp+4h] [ebp-10h]
  float v19; // [esp+8h] [ebp-Ch]
  float v20; // [esp+8h] [ebp-Ch]
  float v21; // [esp+10h] [ebp-4h]
  float v22; // [esp+10h] [ebp-4h]

  v5 = *((_DWORD *)this + 14);
  v6 = (float *)(*(_DWORD *)this + 16012);
  v7 = (float *)(v5 + 168);
  if ( !v5 )
    v7 = (float *)&a2;
  v18 = v7[2] * v7[2] + *v7 * *v7;
  if ( v18 == 0.0 )
    v8 = 0.0;
  else
    v8 = (*(float *)(*(_DWORD *)this + 16020) * v7[2] + *v7 * *(float *)(*(_DWORD *)this + 16012)) / v18;
  v19 = v8 * *v7;
  v21 = v8 * v7[2];
  v12 = sqrt(v21 * v21 + v19 * v19);
  if ( v10 | v11 )
    v12 = -v12;
  this[6] = v12;
  this[6] = this[6] - a5;
  if ( v18 == 0.0 )
    v13 = 0.0;
  else
    v13 = (v6[2] * *v7 - v7[2] * *v6) / v18;
  v20 = v13 * -v7[2];
  v22 = v13 * *v7;
  v17 = sqrt(v22 * v22 + v20 * v20);
  if ( !(v15 | v16) )
    v17 = -v17;
  this[4] = v17;
}
