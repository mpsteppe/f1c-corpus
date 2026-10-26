void __fastcall sub_4DD6A0(void *a1, float *a2, float *a3)
{
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double v8; // st7
  double v9; // st7
  float v10; // [esp+8h] [ebp-24h] BYREF
  float v11; // [esp+Ch] [ebp-20h]
  float v12; // [esp+10h] [ebp-1Ch]
  float v13; // [esp+14h] [ebp-18h] BYREF
  float v14; // [esp+18h] [ebp-14h]
  float v15; // [esp+1Ch] [ebp-10h]
  float v16; // [esp+20h] [ebp-Ch] BYREF
  float v17; // [esp+24h] [ebp-8h] BYREF
  float v18; // [esp+28h] [ebp-4h] BYREF

  sub_54B420(&v16, &v17, &v18);
  sub_4DD550(a1, &v13, &v10);
  v5 = v16 + v13;
  v14 = v17 + v14;
  v15 = v18 + v15;
  v10 = v16 + v10;
  v11 = v17 + v11;
  v12 = v18 + v12;
  if ( v5 > *a2 )
    v5 = *a2;
  *a2 = v5;
  if ( a2[1] >= (double)v14 )
    v6 = v14;
  else
    v6 = a2[1];
  a2[1] = v6;
  if ( a2[2] >= (double)v15 )
    v7 = v15;
  else
    v7 = a2[2];
  a2[2] = v7;
  if ( *a3 <= (double)v10 )
    v8 = v10;
  else
    v8 = *a3;
  *a3 = v8;
  if ( a3[1] <= (double)v11 )
    v9 = v11;
  else
    v9 = a3[1];
  a3[1] = v9;
  if ( a3[2] <= (double)v12 )
    a3[2] = v12;
  else
    a3[2] = a3[2];
}
