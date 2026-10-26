void __thiscall sub_51D8D0(char *this)
{
  double v1; // st7
  double v2; // st6
  double v3; // st5
  char *v4; // edx
  int v5; // esi
  double v6; // st4
  double v7; // st3
  int v8; // eax
  long double v9; // st2
  double v10; // st2
  double v11; // st1
  double v12; // st7
  int v13; // [esp+4h] [ebp-20h]
  float v14; // [esp+4h] [ebp-20h]
  int v15; // [esp+4h] [ebp-20h]
  float v16; // [esp+8h] [ebp-1Ch]
  int v17; // [esp+Ch] [ebp-18h] BYREF
  float v18; // [esp+10h] [ebp-14h]
  float v19; // [esp+14h] [ebp-10h]
  int v20; // [esp+18h] [ebp-Ch]
  float v21; // [esp+1Ch] [ebp-8h]
  float v22; // [esp+20h] [ebp-4h]

  v1 = 0.0;
  v2 = 0.0;
  v16 = 0.0;
  v3 = 0.0;
  v4 = this + 17772;
  *(float *)&v17 = 0.0;
  v5 = 4;
  v6 = 0.0;
  v18 = 0.0;
  v7 = 0.0;
  v19 = 0.0;
  do
  {
    v8 = *((_DWORD *)v4 + 38);
    if ( v8 && *(_DWORD *)(*(_DWORD *)(v8 + 84) + 48) == 22 && *(float *)v4 > -0.22 && *(float *)v4 < 0.81 )
    {
      if ( *(float *)v4 <= 0.47 )
        v9 = (0.47 - *(float *)v4) * 4.5530329 + 3.1415927;
      else
        v9 = (0.81 - *(float *)v4) * 9.2399788;
      *(float *)&v13 = (1.0 - cos(v9)) * 0.5 * *((float *)v4 - 1) * 0.000061035156;
      if ( *(float *)&v13 > (double)v16 )
        v16 = *(float *)&v13;
      if ( *(float *)&v13 > 0.0 )
      {
        v1 = v1 + *(float *)&v13;
        v2 = v2 + (1.05 - *(float *)v4 * 0.25 + *((float *)v4 - 2) * 0.001953125) * *(float *)&v13;
        v10 = *(float *)&v13 * *((float *)v4 - 17);
        v11 = *(float *)&v13 * *((float *)v4 - 16);
        v22 = *(float *)&v13 * *((float *)v4 - 15);
        v3 = v3 + v10;
        v6 = v6 + v11;
        v7 = v7 + v22;
      }
    }
    v4 += 248;
    --v5;
  }
  while ( v5 );
  v19 = v7;
  v18 = v6;
  *(float *)&v17 = v3;
  if ( v16 > 0.001 )
  {
    v12 = 1.0 / v1;
    v14 = v2;
    *(float *)&v15 = v14 * v12;
    *(float *)&v20 = *(float *)&v17 * v12;
    v17 = v20;
    v21 = v18 * v12;
    v18 = v21;
    v22 = v12 * v19;
    v19 = v22;
    if ( v16 <= 1.0 )
      sub_5260E0(21, 2, v16, v15, (int)&v17);
    else
      sub_5260E0(21, 2, 1.0, v15, (int)&v17);
  }
}
