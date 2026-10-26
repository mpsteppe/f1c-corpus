char __thiscall sub_4B0EF0(int this, int a2)
{
  int v3; // eax
  int v4; // edx
  int v5; // edx
  int v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  unsigned __int8 v12; // dl
  int v13; // edx
  int v14; // edx
  int v15; // edx
  float v16; // edx
  int v17; // edx
  int v18; // edx
  int v19; // edx
  int v20; // eax
  int v21; // ecx
  int v22; // ecx
  int v23; // eax
  int v24; // edx
  int v25; // edx
  int v26; // eax
  int v28; // [esp-8h] [ebp-10h]
  int v29; // [esp-8h] [ebp-10h]
  int v30; // [esp-8h] [ebp-10h]
  int v31; // [esp-8h] [ebp-10h]
  float v32; // [esp-8h] [ebp-10h]
  int v33; // [esp-8h] [ebp-10h]
  int v34; // [esp-8h] [ebp-10h]

  if ( a2 < 1 || a2 >= 7 )
    return 0;
  v3 = *(_DWORD *)(this + 8068);
  v4 = *(_DWORD *)(this + 8064);
  *(_DWORD *)(this + 8056) = a2;
  sub_47F1F0((int *)(this + 8056), v4, v3);
  v28 = *(_DWORD *)(this + 1488);
  v5 = *(_DWORD *)(this + 1484);
  *(_DWORD *)(this + 1476) = *(_DWORD *)(this + 4 * (9 * a2 + 369));
  sub_47F1F0((int *)(this + 1476), v5, v28);
  v6 = this + 36 * a2;
  v7 = *(_DWORD *)(this + 2052);
  *(_DWORD *)(this + 2040) = *(_DWORD *)(v6 + 2040);
  sub_47F1F0((int *)(this + 2040), *(_DWORD *)(this + 2048), v7);
  v8 = *(_DWORD *)(this + 2304);
  *(_DWORD *)(this + 2292) = *(_DWORD *)(v6 + 2292);
  sub_47F1F0((int *)(this + 2292), *(_DWORD *)(this + 2300), v8);
  v9 = *(_DWORD *)(this + 2556);
  *(_DWORD *)(this + 2544) = *(_DWORD *)(v6 + 2544);
  sub_47F1F0((int *)(this + 2544), *(_DWORD *)(this + 2552), v9);
  v10 = *(_DWORD *)(this + 2808);
  *(_DWORD *)(this + 2796) = *(_DWORD *)(v6 + 2796);
  sub_47F1F0((int *)(this + 2796), *(_DWORD *)(this + 2804), v10);
  v11 = *(_DWORD *)(this + 3060);
  *(_DWORD *)(this + 3048) = *(_DWORD *)(v6 + 3048);
  sub_47F1F0((int *)(this + 3048), *(_DWORD *)(this + 3056), v11);
  v12 = *(_BYTE *)(this + 3303);
  *(_BYTE *)(this + 3300) = *(_BYTE *)(this + 24 * a2 + 3300);
  sub_464720((unsigned __int8 *)(this + 3300), *(_BYTE *)(this + 3302), v12);
  v29 = *(_DWORD *)(this + 8216);
  v13 = *(_DWORD *)(this + 8212);
  *(_DWORD *)(this + 8204) = *(_DWORD *)(v6 + 8204);
  sub_47F1F0((int *)(this + 8204), v13, v29);
  v30 = *(_DWORD *)(this + 8468);
  v14 = *(_DWORD *)(this + 8464);
  *(_DWORD *)(this + 8456) = *(_DWORD *)(v6 + 8456);
  sub_47F1F0((int *)(this + 8456), v14, v30);
  v31 = *(_DWORD *)(this + 8720);
  v15 = *(_DWORD *)(this + 8716);
  *(_DWORD *)(this + 8708) = *(_DWORD *)(v6 + 8708);
  sub_47F1F0((int *)(this + 8708), v15, v31);
  v16 = *(float *)(this + 8968);
  v32 = *(float *)(this + 8972);
  *(float *)(this + 8960) = *(float *)(v6 + 8960);
  sub_4646C0((float *)(this + 8960), v16, v32);
  v33 = *(_DWORD *)(this + 9476);
  v17 = *(_DWORD *)(this + 9472);
  *(_DWORD *)(this + 9464) = *(_DWORD *)(v6 + 9464);
  sub_47F1F0((int *)(this + 9464), v17, v33);
  v34 = *(_DWORD *)(this + 9944);
  v18 = *(_DWORD *)(this + 9940);
  *(_DWORD *)(this + 9932) = *(_DWORD *)(v6 + 9932);
  sub_47F1F0((int *)(this + 9932), v18, v34);
  v19 = *(_DWORD *)(this + 10196);
  *(_DWORD *)(this + 10184) = *(_DWORD *)(v6 + 10184);
  v20 = *(_DWORD *)(this + 10192);
  v21 = *(_DWORD *)(this + 10184);
  if ( v21 >= v20 )
  {
    if ( v21 > v19 )
      *(_DWORD *)(this + 10184) = v19;
  }
  else
  {
    *(_DWORD *)(this + 10184) = v20;
  }
  v22 = *(_DWORD *)(v6 + 9212);
  v23 = *(_DWORD *)(this + 9220);
  v24 = *(_DWORD *)(this + 9224);
  *(_DWORD *)(this + 9212) = v22;
  if ( v22 >= v23 )
  {
    if ( v22 > v24 )
      *(_DWORD *)(this + 9212) = v24;
  }
  else
  {
    *(_DWORD *)(this + 9212) = v23;
  }
  if ( a2 == 1 )
  {
    v26 = *(_DWORD *)(this + 7264);
    *(_DWORD *)(this + 7252) = 1;
    sub_47F1F0((int *)(this + 7252), *(_DWORD *)(this + 7260), v26);
  }
  else if ( a2 == 2 )
  {
    v25 = *(_DWORD *)(this + 7264);
    *(_DWORD *)(this + 7252) = 7;
    sub_47F1F0((int *)(this + 7252), *(_DWORD *)(this + 7260), v25);
  }
  sub_4B1190(-1.0);
  return 1;
}
