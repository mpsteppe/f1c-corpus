void __thiscall sub_4F1120(char *this, int a2, float a3)
{
  double v3; // st7
  double v4; // st6
  double v5; // st5
  double v7; // st4
  float *v8; // edx
  int v9; // esi
  double v10; // st3
  double v11; // st2
  double v12; // st2
  double v13; // st1
  double v14; // st7
  float v15; // [esp+4h] [ebp-20h]
  float v16; // [esp+8h] [ebp-1Ch]
  int v17; // [esp+Ch] [ebp-18h] BYREF
  float v18; // [esp+10h] [ebp-14h]
  float v19; // [esp+14h] [ebp-10h]
  int v20; // [esp+18h] [ebp-Ch]
  float v21; // [esp+1Ch] [ebp-8h]
  float v22; // [esp+20h] [ebp-4h]
  float v23; // [esp+28h] [ebp+4h]
  float v24; // [esp+28h] [ebp+4h]
  float v25; // [esp+2Ch] [ebp+8h]

  v3 = 0.0;
  v4 = 0.0;
  v5 = 0.0;
  *(float *)&v17 = 0.0;
  v15 = 0.0;
  v7 = 0.0;
  v8 = (float *)(this + 13928);
  v18 = 0.0;
  v9 = 4;
  v10 = 0.0;
  v19 = 0.0;
  do
  {
    if ( *(_DWORD *)v8 && *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v8 + 84) + 48) == a2 )
    {
      if ( a3 <= 32.0 )
        v11 = a3;
      else
        v11 = 32.0;
      v23 = v11 * *(v8 - 39) * 0.0000038146973;
      if ( v23 > (double)v15 )
        v15 = v11 * *(v8 - 39) * 0.0000038146973;
      v3 = v3 + v23;
      v4 = v4 + (a3 * 0.00390625 + 0.80000001) * v23;
      v12 = v23 * *(v8 - 55);
      v13 = v23 * *(v8 - 54);
      v22 = v23 * *(v8 - 53);
      v5 = v5 + v12;
      v7 = v7 + v13;
      v10 = v10 + v22;
    }
    v8 += 62;
    --v9;
  }
  while ( v9 );
  v19 = v10;
  v18 = v7;
  *(float *)&v17 = v5;
  if ( v15 > 0.001 )
  {
    v14 = 1.0 / v3;
    *(float *)&v20 = *(float *)&v17 * v14;
    v17 = v20;
    v21 = v18 * v14;
    v18 = v21;
    v22 = v14 * v19;
    v19 = v22;
    if ( v15 <= 1.0 )
      v25 = v15;
    else
      v25 = 1.0;
    v16 = v4;
    v24 = v16 * v14;
    sub_4F8850(a2, 1, v25, v24, (int)&v17);
  }
}
