// f1c  0x0040e2b0  size=449
int __fastcall sub_40E2B0(int a1, int a2)
{
  int v3; // eax
  int v4; // edi
  int v5; // esi
  float *v6; // eax
  double v7; // st7
  double v8; // st7
  float v10; // [esp+0h] [ebp-6Ch]
  float v11; // [esp+4h] [ebp-68h]
  float v12; // [esp+8h] [ebp-64h]
  float v14; // [esp+24h] [ebp-48h]
  float v15; // [esp+24h] [ebp-48h]
  float v16; // [esp+28h] [ebp-44h]
  float v17; // [esp+28h] [ebp-44h]
  float v18; // [esp+2Ch] [ebp-40h]
  float v19; // [esp+2Ch] [ebp-40h]
  float v20; // [esp+30h] [ebp-3Ch]
  float v21; // [esp+34h] [ebp-38h]
  float v22; // [esp+38h] [ebp-34h]
  float v23; // [esp+38h] [ebp-34h]
  float v24; // [esp+3Ch] [ebp-30h] BYREF
  float v25; // [esp+40h] [ebp-2Ch] BYREF
  float v26; // [esp+44h] [ebp-28h] BYREF
  float v27[6]; // [esp+48h] [ebp-24h] BYREF
  float v28; // [esp+60h] [ebp-Ch] BYREF
  float v29; // [esp+64h] [ebp-8h]
  float v30; // [esp+68h] [ebp-4h]

  sub_4DD550(v27);
  v14 = 0.0;
  v16 = 0.0;
  v18 = 0.0;
  v30 = v27[2] + v27[5];
  v20 = (v27[0] + v27[3]) * 0.5;
  v21 = (v27[1] + v27[4]) * 0.5;
  v22 = v30 * 0.5;
  v3 = sub_54C230(0);
  v4 = sub_54E100(v3);
  v5 = 0;
  if ( v4 > 0 )
  {
    do
    {
      v6 = (float *)sub_54E120(v5++);
      v14 = v14 + *v6;
      v16 = v16 + v6[1];
      v18 = v18 + v6[2];
    }
    while ( v5 < v4 );
    v7 = 1.0 / (double)v4;
    v14 = v14 * v7;
    v16 = v16 * v7;
    v18 = v7 * v18;
  }
  if ( a2 == 2 )
    v8 = 0.34999999;
  else
    v8 = 0.69999999;
  v28 = v14 * (1.0 - v8);
  v29 = v16 * (1.0 - v8);
  v23 = v22 * v8;
  v15 = v20 * v8 + v28;
  v28 = v15;
  v17 = v21 * v8 + v29;
  v29 = v17;
  v19 = v23 + (1.0 - v8) * v18;
  v30 = v19;
  sub_54B420(&v24, &v25, &v26);
  v12 = v19 + v26;
  v11 = v17 + v25;
  v10 = v15 + v24;
  sub_54B3B0(LODWORD(v10), LODWORD(v11), LODWORD(v12));
  return sub_40E1F0(a1, &v28);
}
