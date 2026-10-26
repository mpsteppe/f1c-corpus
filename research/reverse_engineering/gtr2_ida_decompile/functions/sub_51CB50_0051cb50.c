char __thiscall sub_51CB50(float *this, float *a2, int a3)
{
  float *v5; // ebx
  float *v6; // ebp
  float *v7; // edx
  float *v8; // ecx
  float *v9; // edx
  float *v10; // ecx
  double v12; // st7
  double v14; // st6
  unsigned __int8 v15; // c0
  unsigned __int8 v16; // c2
  double v17; // st7
  double v18; // st6
  double v19; // st5
  double v20; // rt2
  double v21; // st6
  int v22; // [esp+14h] [ebp+4h]
  int v23; // [esp+14h] [ebp+4h]
  float v24; // [esp+14h] [ebp+4h]
  float v25; // [esp+14h] [ebp+4h]

  v5 = this + 3;
  v6 = a2 + 3;
  v22 = sub_51C850(this, this + 3, a2);
  if ( v22 == sub_51C850(v8, v7, v6) )
    return 0;
  v23 = sub_51C850(a2, v6, v5);
  if ( sub_51C850(v10, v9, this) == v23 )
    return 0;
  v12 = *v6 - *a2;
  v14 = a2[5] - a2[2];
  if ( v15 | v16 )
  {
    v24 = v14 / v12;
    v17 = *v5 - *this;
    v18 = (*this - *a2) * v24 + a2[2] - this[2];
    v19 = this[5] - this[2] - v17 * v24;
  }
  else
  {
    v25 = v12 / v14;
    v17 = *v5 - *this;
    v18 = (this[2] - a2[2]) * v25 + *a2 - *this;
    v19 = v17 - (this[5] - this[2]) * v25;
  }
  v20 = v18 / v19;
  v21 = v17 * v20 + *this;
  *(_DWORD *)(a3 + 4) = 0;
  *(float *)a3 = v21;
  *(float *)(a3 + 8) = (this[5] - this[2]) * v20 + this[2];
  return 1;
}
