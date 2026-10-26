int __stdcall sub_542790(int a1, float *a2, float *a3)
{
  float v5; // [esp+10h] [ebp-18h]
  float v6; // [esp+10h] [ebp-18h]
  float v7; // [esp+14h] [ebp-14h]
  float v8; // [esp+14h] [ebp-14h]
  float v9; // [esp+18h] [ebp-10h]
  float v10; // [esp+18h] [ebp-10h]
  float v11; // [esp+1Ch] [ebp-Ch]
  float v12; // [esp+1Ch] [ebp-Ch]
  float v13; // [esp+20h] [ebp-8h]
  float v14; // [esp+20h] [ebp-8h]
  float v15; // [esp+24h] [ebp-4h]
  float v16; // [esp+24h] [ebp-4h]

  v11 = *a3 + *(float *)(a1 + 44);
  v13 = *(float *)(a1 + 48) + a3[1];
  v15 = *(float *)(a1 + 52) + a3[2];
  sub_5FCE00(*(_DWORD *)a1, 1, v11, v13, v15, *(_DWORD *)(a1 + 96));
  v5 = v11 - *a2;
  v7 = v13 - a2[1];
  v9 = v15 - a2[2];
  sub_5FCE00(*(_DWORD *)a1, 2, v5, v7, v9, *(_DWORD *)(a1 + 96));
  v12 = *(float *)(a1 + 44) - *a3;
  v14 = *(float *)(a1 + 48) - a3[1];
  v16 = *(float *)(a1 + 52) - a3[2];
  sub_5FCE00(*(_DWORD *)a1, 0, v12, v14, v16, *(_DWORD *)(a1 + 96));
  v6 = v12 - *a2;
  v8 = v14 - a2[1];
  v10 = v16 - a2[2];
  return sub_5FCE00(*(_DWORD *)a1, 3, v6, v8, v10, *(_DWORD *)(a1 + 96));
}
