int __fastcall sub_4179B0(int a1, int a2)
{
  int v3; // eax
  int *v4; // eax
  int v5; // ebx
  int v6; // edi
  int v7; // esi
  float *v8; // eax
  double v9; // st7
  double v10; // st7
  float v12; // [esp+0h] [ebp-6Ch]
  float v13; // [esp+4h] [ebp-68h]
  float v14; // [esp+8h] [ebp-64h]
  float v16; // [esp+24h] [ebp-48h] BYREF
  float v17; // [esp+28h] [ebp-44h]
  float v18; // [esp+2Ch] [ebp-40h]
  float v19; // [esp+30h] [ebp-3Ch]
  float v20; // [esp+34h] [ebp-38h]
  float v21; // [esp+38h] [ebp-34h]
  float v22; // [esp+3Ch] [ebp-30h]
  float v23; // [esp+40h] [ebp-2Ch]
  float v24; // [esp+44h] [ebp-28h]
  float v25; // [esp+48h] [ebp-24h] BYREF
  float v26; // [esp+4Ch] [ebp-20h] BYREF
  float v27; // [esp+50h] [ebp-1Ch] BYREF
  float v28[6]; // [esp+54h] [ebp-18h] BYREF

  sub_56C0A0(v28);
  v16 = v28[0] + v28[3];
  v19 = v16;
  v17 = v28[1] + v28[4];
  v20 = v17;
  v18 = v28[2] + v28[5];
  v21 = v18;
  v16 = v16 * 0.5;
  v22 = v16;
  v16 = 0.0;
  v17 = v17 * 0.5;
  v23 = v17;
  v17 = 0.0;
  v18 = v18 * 0.5;
  v24 = v18;
  v3 = *(_DWORD *)(a1 + 544);
  v18 = 0.0;
  if ( v3 > 0 && (v4 = *(int **)(a1 + 532)) != 0 )
    v5 = *v4;
  else
    v5 = 0;
  v6 = sub_5EA5B0(v5);
  v7 = 0;
  if ( v6 > 0 )
  {
    do
    {
      v8 = (float *)sub_5EB140(v7++, 1);
      v16 = v16 + *v8;
      v17 = v17 + v8[1];
      v18 = v18 + v8[2];
    }
    while ( v7 < v6 );
    v9 = 1.0 / (double)v6;
    v16 = v16 * v9;
    v17 = v17 * v9;
    v18 = v9 * v18;
  }
  if ( a2 == 2 )
    v10 = 0.34999999;
  else
    v10 = 0.69999999;
  v19 = v16 * (1.0 - v10);
  v16 = v19;
  v20 = v17 * (1.0 - v10);
  v17 = v20;
  v21 = (1.0 - v10) * v18;
  v18 = v21;
  v19 = v22 * v10;
  v22 = v19;
  v20 = v23 * v10;
  v23 = v20;
  v21 = v24 * v10;
  v24 = v21;
  v19 = v16 + v19;
  v16 = v19;
  v20 = v17 + v20;
  v17 = v20;
  v21 = v18 + v21;
  v18 = v21;
  sub_5DA7A0(&v25, &v26, &v27);
  v14 = v21 + v27;
  v13 = v20 + v26;
  v12 = v19 + v25;
  sub_5DB150(LODWORD(v12), LODWORD(v13), LODWORD(v14));
  return sub_4178E0(&v16, a1, v6);
}
