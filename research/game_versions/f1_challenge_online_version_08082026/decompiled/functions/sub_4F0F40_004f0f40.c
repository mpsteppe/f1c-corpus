void __thiscall sub_4F0F40(float *this, int a2)
{
  double v2; // st7
  int v3; // eax
  double v4; // st6
  double v5; // st5
  double v6; // st4
  double v7; // st3
  float *v9; // edx
  int v10; // esi
  double v11; // st2
  double v12; // st1
  double v13; // st7
  float v14; // [esp+0h] [ebp-20h]
  float v15; // [esp+4h] [ebp-1Ch]
  float v16; // [esp+4h] [ebp-1Ch]
  float v17; // [esp+4h] [ebp-1Ch]
  int v18; // [esp+8h] [ebp-18h] BYREF
  float v19; // [esp+Ch] [ebp-14h]
  float v20; // [esp+10h] [ebp-10h]
  int v21; // [esp+14h] [ebp-Ch]
  float v22; // [esp+18h] [ebp-8h]
  float v23; // [esp+1Ch] [ebp-4h]
  float v24; // [esp+24h] [ebp+4h]
  float v25; // [esp+24h] [ebp+4h]

  v2 = 0.0;
  v3 = *((_DWORD *)this + 3247);
  v4 = 0.0;
  v14 = 0.0;
  v5 = 0.0;
  v15 = 0.86000001;
  *(float *)&v18 = 0.0;
  v6 = 0.0;
  v19 = 0.0;
  v7 = 0.0;
  v20 = 0.0;
  if ( v3 )
    v15 = 0.5;
  v9 = this + 3482;
  v10 = 4;
  do
  {
    if ( *(_DWORD *)v9 && *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v9 + 84) + 52) == a2 )
    {
      v24 = (v15 - *(v9 - 38)) * *(v9 - 39) * 0.00012207031;
      if ( v24 > (double)v14 )
        v14 = (v15 - *(v9 - 38)) * *(v9 - 39) * 0.00012207031;
      if ( v24 > 0.0 )
      {
        v2 = v2 + v24;
        v4 = v4 + (1.1 - *(v9 - 38) * 0.5 + *(v9 - 40) * 0.00390625) * v24;
        v11 = v24 * *(v9 - 55);
        v12 = v24 * *(v9 - 54);
        v23 = v24 * *(v9 - 53);
        v5 = v5 + v11;
        v6 = v6 + v12;
        v7 = v7 + v23;
      }
    }
    v9 += 62;
    --v10;
  }
  while ( v10 );
  v20 = v7;
  v19 = v6;
  *(float *)&v18 = v5;
  if ( v14 > 0.001 )
  {
    v13 = 1.0 / v2;
    v16 = v4;
    v17 = v16 * v13;
    *(float *)&v21 = *(float *)&v18 * v13;
    v18 = v21;
    v22 = v19 * v13;
    v19 = v22;
    v23 = v13 * v20;
    v20 = v23;
    if ( v14 <= 1.0 )
      v25 = v14;
    else
      v25 = 1.0;
    sub_4F8850(a2, 2, v25, v17, (int)&v18);
  }
}
