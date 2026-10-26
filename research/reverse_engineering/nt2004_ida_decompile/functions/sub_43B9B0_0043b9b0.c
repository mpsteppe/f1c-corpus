double __stdcall sub_43B9B0(int a1, int a2)
{
  double v2; // st7
  int v3; // eax
  int v4; // ecx
  double v5; // st6
  float v7; // [esp+0h] [ebp-74h]
  float v8; // [esp+4h] [ebp-70h]
  float v9; // [esp+4h] [ebp-70h]
  float v10; // [esp+8h] [ebp-6Ch]
  float v11; // [esp+8h] [ebp-6Ch]
  float v12; // [esp+8h] [ebp-6Ch]
  float v13; // [esp+24h] [ebp-50h]
  int v14; // [esp+30h] [ebp-44h] BYREF
  int v15; // [esp+34h] [ebp-40h] BYREF
  int v16; // [esp+38h] [ebp-3Ch] BYREF
  int v17; // [esp+3Ch] [ebp-38h] BYREF
  int v18; // [esp+40h] [ebp-34h] BYREF
  int v19; // [esp+44h] [ebp-30h] BYREF
  int v20; // [esp+48h] [ebp-2Ch] BYREF
  int v21; // [esp+4Ch] [ebp-28h] BYREF
  int v22[3]; // [esp+50h] [ebp-24h] BYREF
  int v23[3]; // [esp+5Ch] [ebp-18h] BYREF
  int v24[3]; // [esp+68h] [ebp-Ch] BYREF

  v2 = 0.0;
  v3 = a1 + 312;
  v4 = 4;
  do
  {
    v5 = (double)*(int *)(v3 + 12);
    v3 += 704;
    --v4;
    v2 = v2 + v5 * *(double *)(v3 - 704) + *(double *)(v3 - 712);
  }
  while ( v4 );
  v10 = (double)*(int *)(a1 + 3588) * *(double *)(a1 + 3576) + *(double *)(a1 + 3568);
  sub_520570(v10, (int)&v20, (int)&v19);
  v11 = (double)*(int *)(a1 + 3652) * *(double *)(a1 + 3640) + *(double *)(a1 + 3632);
  sub_520570(v11, (int)&v21, (int)&v18);
  v13 = v2 * 0.1;
  v8 = (double)*(int *)(a1 + 4740) * *(double *)(a1 + 4728) + *(double *)(a1 + 4720);
  sub_524210(v8, v13, (int)v22, (int)&v17);
  v12 = (double)*(int *)(a1 + 4804) * *(double *)(a1 + 4792) + *(double *)(a1 + 4784);
  sub_5242B0(v12, (int)v23, (int)&v16);
  v9 = (double)*(int *)(a1 + 4868) * *(double *)(a1 + 4856) + *(double *)(a1 + 4848);
  v7 = (double)*(int *)(a1 + 4932) * *(double *)(a1 + 4920) + *(double *)(a1 + 4912);
  sub_524340(v7, v9, v13, (int)v24, (int)&v15);
  sub_5243B0(v13, (int)&v14);
  return *(float *)&v14 + *(float *)&v15 + *(float *)&v16 + *(float *)&v17 + *(float *)&v18 + *(float *)&v19;
}
