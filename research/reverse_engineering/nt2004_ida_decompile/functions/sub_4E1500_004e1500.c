double __thiscall sub_4E1500(int this, int a2, float a3)
{
  double v5; // st7
  int v6; // eax
  int v8; // [esp+10h] [ebp+4h]
  float v9; // [esp+10h] [ebp+4h]
  int v10; // [esp+10h] [ebp+4h]
  int v11; // [esp+10h] [ebp+4h]
  float v12; // [esp+14h] [ebp+8h]

  if ( *(_BYTE *)(this + 387) )
    v8 = dword_7D6710;
  else
    v8 = *(int *)(a2 + 23968);
  v9 = (double)(rand() % 40) * 0.0099999998 - 0.0099999998 + 1.0 - *(float *)&v8;
  if ( v9 <= 1.0 )
  {
    if ( v9 < 0.0 )
      v9 = 0.0;
  }
  else
  {
    v9 = 1.0;
  }
  *(float *)&v10 = pow(v9, 1.333999991416931);
  v5 = (double)(rand() % 50) * 0.0099999998 + 0.5;
  if ( v5 > 1.0 )
    v5 = 1.0;
  v12 = a3 * *(float *)(this + 400) * (v5 * *(float *)&v10) - 0.15000001 + a3;
  *(float *)&v11 = *(float *)(a2 + 23976) * *(float *)(a2 + 23976) * *(float *)(a2 + 23976);
  v6 = rand();
  if ( *(_DWORD *)(a2 + 20884) == 1 && (double)(v6 % 100) * 0.0099999998 > *(float *)&v11 )
    v12 = (1.0 - *(float *)&v11 + 1.5) * v12;
  if ( rand() % 60 )
    return v12;
  else
    return v12 * 1.7;
}
