int __thiscall sub_43BC20(int this, int a2, int a3)
{
  int v4; // ecx
  int v5; // ecx
  char *v6; // eax
  char *v7; // edx
  int v8; // ecx
  int v9; // edx
  int v10; // ecx
  int v11; // edx
  char *v12; // edx
  bool v13; // zf
  int v14; // eax
  int v15; // edx
  int v16; // eax
  int v17; // edx
  double v18; // st7
  int result; // eax
  double v20; // st7
  char *v21; // [esp+14h] [ebp-Ch]
  char *v22; // [esp+14h] [ebp-Ch]
  char *v23; // [esp+14h] [ebp-Ch]
  int v24; // [esp+18h] [ebp-8h]
  int v25; // [esp+18h] [ebp-8h]
  char *v26; // [esp+18h] [ebp-8h]
  char *v27; // [esp+18h] [ebp-8h]
  int v28; // [esp+1Ch] [ebp-4h]
  int v29; // [esp+1Ch] [ebp-4h]

  CollisionStructCopy((_DWORD *)(this + 6200), a3 + 324);
  QuadraticSpringEval(v4, (double)*(int *)(a2 + 3588) * *(double *)(a2 + 3576) + *(double *)(a2 + 3568));
  CollisionStructCopy((_DWORD *)(this + 6300), a3 + 408);
  QuadraticSpringEval(v5, (double)*(int *)(a2 + 3652) * *(double *)(a2 + 3640) + *(double *)(a2 + 3632));
  *(_BYTE *)(this + 6400) = *(_BYTE *)(a3 + 492);
  *(_DWORD *)(this + 6404) = 0;
  *(_DWORD *)(this + 6416) = *(_DWORD *)(a3 + 496);
  *(_DWORD *)(this + 6420) = *(_DWORD *)(a3 + 500);
  *(_DWORD *)(this + 6456) = *(_DWORD *)(a3 + 552);
  *(_DWORD *)(this + 6460) = *(_DWORD *)(a3 + 556);
  *(_DWORD *)(this + 6464) = *(_DWORD *)(a3 + 560);
  *(_DWORD *)(this + 6468) = *(_DWORD *)(a3 + 564);
  v6 = (char *)(a3 + 568);
  v7 = (char *)(this + 6496);
  v24 = 6;
  do
  {
    qmemcpy(v7, v6, 0x18u);
    v6 += 24;
    v7 += 24;
    --v24;
  }
  while ( v24 );
  qmemcpy((void *)(this + 6640), (const void *)(a3 + 712), 0x18u);
  *(_DWORD *)(this + 6056) = *(_DWORD *)(a3 + 528);
  *(_DWORD *)(this + 6060) = *(_DWORD *)(a3 + 532);
  *(_DWORD *)(this + 6064) = *(_DWORD *)(a3 + 536);
  *(_DWORD *)(this + 6068) = *(_DWORD *)(a3 + 540);
  *(_DWORD *)(this + 6072) = *(_DWORD *)(a3 + 544);
  *(_DWORD *)(this + 6076) = *(_DWORD *)(a3 + 548);
  *(_DWORD *)(this + 6080) = *(_DWORD *)(a3 + 504);
  *(_DWORD *)(this + 6084) = *(_DWORD *)(a3 + 508);
  *(_DWORD *)(this + 6088) = *(_DWORD *)(a3 + 512);
  *(_DWORD *)(this + 6092) = *(_DWORD *)(a3 + 516);
  *(_DWORD *)(this + 6096) = *(_DWORD *)(a3 + 520);
  v8 = *(_DWORD *)(this + 6056);
  *(_DWORD *)(this + 6100) = *(_DWORD *)(a3 + 524);
  v9 = *(_DWORD *)(this + 6060);
  *(_DWORD *)(this + 7176) = v8;
  v10 = *(_DWORD *)(this + 6080);
  *(_DWORD *)(this + 7180) = v9;
  v11 = *(_DWORD *)(this + 6084);
  *(_DWORD *)(this + 7184) = v10;
  *(_DWORD *)(this + 7188) = v11;
  *(_DWORD *)(this + 6404) = 0;
  *(_DWORD *)(this + 6416) = *(_DWORD *)(a3 + 496);
  *(_DWORD *)(this + 6420) = *(_DWORD *)(a3 + 500);
  *(_DWORD *)(this + 6456) = *(_DWORD *)(a3 + 552);
  *(_DWORD *)(this + 6460) = *(_DWORD *)(a3 + 556);
  *(_DWORD *)(this + 6464) = *(_DWORD *)(a3 + 560);
  *(_DWORD *)(this + 6468) = *(_DWORD *)(a3 + 564);
  v12 = (char *)(a3 + 568);
  v21 = (char *)(this + 6496);
  v25 = 6;
  do
  {
    qmemcpy(v21, v12, 0x18u);
    v12 += 24;
    v13 = v25 == 1;
    v21 += 24;
    --v25;
  }
  while ( !v13 );
  qmemcpy((void *)(this + 6640), (const void *)(a3 + 712), 0x18u);
  QuadFunctionEval((double *)this, (double)*(int *)(a2 + 4740) * *(double *)(a2 + 4728) + *(double *)(a2 + 4720));
  *(_BYTE *)(this + 6664) = *(_BYTE *)(v14 + 760);
  *(_DWORD *)(this + 6676) = *(_DWORD *)(v14 + 812);
  *(_DWORD *)(this + 6680) = *(_DWORD *)(v14 + 816);
  v26 = (char *)(this + 6708);
  v22 = (char *)(v14 + 820);
  v28 = 6;
  do
  {
    qmemcpy(v26, v22, 0x18u);
    v13 = v28 == 1;
    v22 += 24;
    v26 += 24;
    --v28;
  }
  while ( !v13 );
  qmemcpy((void *)(this + 6852), (const void *)(v14 + 964), 0x18u);
  *(_DWORD *)(this + 6104) = *(_DWORD *)(v14 + 788);
  *(_DWORD *)(this + 6108) = *(_DWORD *)(v14 + 792);
  *(_DWORD *)(this + 6112) = *(_DWORD *)(v14 + 796);
  *(_DWORD *)(this + 6116) = *(_DWORD *)(v14 + 800);
  *(_DWORD *)(this + 6120) = *(_DWORD *)(v14 + 804);
  *(_DWORD *)(this + 6124) = *(_DWORD *)(v14 + 808);
  *(_DWORD *)(this + 6128) = *(_DWORD *)(v14 + 764);
  *(_DWORD *)(this + 6132) = *(_DWORD *)(v14 + 768);
  *(_DWORD *)(this + 6136) = *(_DWORD *)(v14 + 772);
  *(_DWORD *)(this + 6140) = *(_DWORD *)(v14 + 776);
  *(_DWORD *)(this + 6144) = *(_DWORD *)(v14 + 780);
  *(_DWORD *)(this + 6148) = *(_DWORD *)(v14 + 784);
  *(_DWORD *)(this + 7232) = *(_DWORD *)(this + 6104);
  *(_DWORD *)(this + 7236) = *(_DWORD *)(this + 6108);
  *(_DWORD *)(this + 7240) = *(_DWORD *)(this + 6128);
  *(_DWORD *)(this + 7244) = *(_DWORD *)(this + 6132);
  QuadraticForceTorqueCalculator(
    (double *)this,
    (double)*(int *)(v15 + 4804) * *(double *)(v15 + 4792) + *(double *)(v15 + 4784));
  *(_DWORD *)(this + 6184) = *(_DWORD *)(v16 + 4864);
  *(_DWORD *)(this + 6188) = *(_DWORD *)(v16 + 4868);
  *(_DWORD *)(this + 6192) = *(_DWORD *)(v16 + 4872);
  *(_DWORD *)(this + 6196) = *(_DWORD *)(v16 + 4876);
  *(_DWORD *)(this + 6884) = *(_DWORD *)(v16 + 1020);
  *(_DWORD *)(this + 6888) = *(_DWORD *)(v16 + 1024);
  *(_DWORD *)(this + 6892) = *(_DWORD *)(v16 + 1028);
  *(_DWORD *)(this + 6896) = *(_DWORD *)(v16 + 1032);
  *(_DWORD *)(this + 6900) = *(_DWORD *)(v16 + 1036);
  *(_DWORD *)(this + 6904) = *(_DWORD *)(v16 + 1040);
  v23 = (char *)(this + 6932);
  v27 = (char *)(v16 + 1068);
  v29 = 6;
  do
  {
    qmemcpy(v23, v27, 0x18u);
    v13 = v29 == 1;
    v27 += 24;
    v23 += 24;
    --v29;
  }
  while ( !v13 );
  qmemcpy((void *)(this + 7076), (const void *)(v16 + 1212), 0x18u);
  v18 = (double)*(int *)(v17 + 4932) * *(double *)(v17 + 4920) + *(double *)(v17 + 4912);
  *(double *)(this + 6152) = v18 * *(double *)(v16 + 1328) + *(double *)(this + 7060);
  *(_DWORD *)(this + 6160) = *(_DWORD *)(v16 + 1312);
  *(_DWORD *)(this + 6164) = *(_DWORD *)(v16 + 1316);
  *(double *)(this + 6168) = v18 * *(double *)(v16 + 1320) + *(double *)(v16 + 1012);
  *(_DWORD *)(this + 6176) = *(_DWORD *)(v16 + 1304);
  *(_DWORD *)(this + 6180) = *(_DWORD *)(v16 + 1308);
  *(_DWORD *)(this + 7200) = *(_DWORD *)(this + 6152);
  *(_DWORD *)(this + 7204) = *(_DWORD *)(this + 6156);
  *(_DWORD *)(this + 7208) = *(_DWORD *)(this + 6168);
  *(_DWORD *)(this + 7212) = *(_DWORD *)(this + 6172);
  SpringDamperCompute((double *)this, (double)*(int *)(v17 + 4868) * *(double *)(v17 + 4856) + *(double *)(v17 + 4848));
  *(_BYTE *)(this + 7100) = *(_BYTE *)(result + 1236);
  v20 = *(double *)(result + 1240);
  *(double *)(this + 7104) = v20;
  *(double *)(this + 7216) = v20;
  *(_DWORD *)(this + 7112) = *(_DWORD *)(result + 1248);
  *(_DWORD *)(this + 7116) = *(_DWORD *)(result + 1252);
  *(_DWORD *)(this + 7120) = *(_DWORD *)(result + 1256);
  *(_DWORD *)(this + 7124) = *(_DWORD *)(result + 1260);
  *(_DWORD *)(this + 7128) = *(_DWORD *)(result + 1264);
  *(_DWORD *)(this + 7132) = *(_DWORD *)(result + 1268);
  *(_DWORD *)(this + 7136) = *(_DWORD *)(result + 1272);
  *(_DWORD *)(this + 7140) = *(_DWORD *)(result + 1276);
  return result;
}

