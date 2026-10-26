void __thiscall sub_43E640(int this, int a2, int a3)
{
  char *v4; // edx
  char *v5; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // edx
  int v9; // eax
  char *v10; // edx
  bool v11; // zf
  int v12; // ecx
  int v13; // edx
  int v14; // ecx
  int v15; // eax
  int v16; // edx
  double v17; // st7
  double v18; // st7
  int v19; // eax
  double v20; // st7
  char *v21; // [esp+14h] [ebp-Ch]
  char *v22; // [esp+14h] [ebp-Ch]
  int v23; // [esp+18h] [ebp-8h]
  int v24; // [esp+18h] [ebp-8h]
  char *v25; // [esp+18h] [ebp-8h]
  int v26; // [esp+1Ch] [ebp-4h]

  sub_438C10((char *)(this + 6756), (char *)(a3 + 320));
  sub_438CB0(this + 6756, (double)*(int *)(a2 + 3588) * *(double *)(a2 + 3576) + *(double *)(a2 + 3568));
  sub_438C10((char *)(this + 6880), (char *)(a3 + 420));
  sub_438CB0(this + 6880, (double)*(int *)(a2 + 3652) * *(double *)(a2 + 3640) + *(double *)(a2 + 3632));
  *(_BYTE *)(this + 7004) = *(_BYTE *)(a3 + 520);
  *(_DWORD *)(this + 7008) = 0;
  *(_DWORD *)(this + 7020) = *(_DWORD *)(a3 + 524);
  *(_DWORD *)(this + 7024) = *(_DWORD *)(a3 + 528);
  *(_DWORD *)(this + 7060) = *(_DWORD *)(a3 + 580);
  *(_DWORD *)(this + 7064) = *(_DWORD *)(a3 + 584);
  sub_438AF0(
    (double *)(this + 7068),
    *(_DWORD *)(a3 + 588),
    *(_DWORD *)(a3 + 592),
    *(double *)(a3 + 596),
    *(double *)(a3 + 604));
  v4 = (char *)(this + 7124);
  v5 = (char *)(a3 + 612);
  v23 = 6;
  do
  {
    qmemcpy(v4, v5, 0x18u);
    v5 += 24;
    v4 += 24;
    --v23;
  }
  while ( v23 );
  qmemcpy((void *)(this + 7268), (const void *)(a3 + 756), 0x18u);
  *(_DWORD *)(this + 6604) = *(_DWORD *)(a3 + 556);
  *(_DWORD *)(this + 6608) = *(_DWORD *)(a3 + 560);
  *(_DWORD *)(this + 6612) = *(_DWORD *)(a3 + 564);
  *(_DWORD *)(this + 6616) = *(_DWORD *)(a3 + 568);
  *(_DWORD *)(this + 6620) = *(_DWORD *)(a3 + 572);
  *(_DWORD *)(this + 6624) = *(_DWORD *)(a3 + 576);
  *(_DWORD *)(this + 6628) = *(_DWORD *)(a3 + 532);
  *(_DWORD *)(this + 6632) = *(_DWORD *)(a3 + 536);
  *(_DWORD *)(this + 6636) = *(_DWORD *)(a3 + 540);
  *(_DWORD *)(this + 6640) = *(_DWORD *)(a3 + 544);
  *(_DWORD *)(this + 6644) = *(_DWORD *)(a3 + 548);
  v6 = *(_DWORD *)(this + 6604);
  *(_DWORD *)(this + 6648) = *(_DWORD *)(a3 + 552);
  *(_DWORD *)(this + 7856) = *(_DWORD *)(this + 6608);
  v7 = *(_DWORD *)(this + 6632);
  *(_DWORD *)(this + 7852) = v6;
  v8 = *(_DWORD *)(this + 6628);
  *(_DWORD *)(this + 7864) = v7;
  *(_DWORD *)(this + 7860) = v8;
  sub_43E550(this, (double)*(int *)(a2 + 4740) * *(double *)(a2 + 4728) + *(double *)(a2 + 4720));
  *(_BYTE *)(this + 7292) = *(_BYTE *)(v9 + 804);
  sub_438AF0(
    (double *)(this + 7304),
    *(_DWORD *)(v9 + 856),
    *(_DWORD *)(v9 + 860),
    *(double *)(v9 + 864),
    *(double *)(v9 + 872));
  v21 = (char *)(this + 7360);
  v10 = (char *)(a3 + 880);
  v24 = 6;
  do
  {
    qmemcpy(v21, v10, 0x18u);
    v10 += 24;
    v11 = v24 == 1;
    v21 += 24;
    --v24;
  }
  while ( !v11 );
  qmemcpy((void *)(this + 7504), (const void *)(a3 + 1024), 0x18u);
  *(_DWORD *)(this + 6652) = *(_DWORD *)(a3 + 832);
  *(_DWORD *)(this + 6656) = *(_DWORD *)(a3 + 836);
  *(_DWORD *)(this + 6660) = *(_DWORD *)(a3 + 840);
  *(_DWORD *)(this + 6664) = *(_DWORD *)(a3 + 844);
  *(_DWORD *)(this + 6668) = *(_DWORD *)(a3 + 848);
  *(_DWORD *)(this + 6672) = *(_DWORD *)(a3 + 852);
  *(_DWORD *)(this + 6676) = *(_DWORD *)(a3 + 808);
  *(_DWORD *)(this + 6680) = *(_DWORD *)(a3 + 812);
  *(_DWORD *)(this + 6684) = *(_DWORD *)(a3 + 816);
  *(_DWORD *)(this + 6688) = *(_DWORD *)(a3 + 820);
  *(_DWORD *)(this + 6692) = *(_DWORD *)(a3 + 824);
  v12 = *(_DWORD *)(this + 6652);
  *(_DWORD *)(this + 6696) = *(_DWORD *)(a3 + 828);
  *(_DWORD *)(this + 7912) = *(_DWORD *)(this + 6656);
  v13 = *(_DWORD *)(this + 6680);
  *(_DWORD *)(this + 7908) = v12;
  v14 = *(_DWORD *)(this + 6676);
  *(_DWORD *)(this + 7920) = v13;
  *(_DWORD *)(this + 7916) = v14;
  sub_43E5A0((double *)this, (double)*(int *)(a2 + 4804) * *(double *)(a2 + 4792) + *(double *)(a2 + 4784));
  *(_DWORD *)(this + 6732) = *(_DWORD *)(v15 + 4952);
  *(_DWORD *)(this + 6736) = *(_DWORD *)(v15 + 4956);
  *(_DWORD *)(this + 6740) = *(_DWORD *)(v15 + 4960);
  *(_DWORD *)(this + 6744) = *(_DWORD *)(v15 + 4964);
  *(_DWORD *)(this + 7536) = *(_DWORD *)(v15 + 1080);
  *(_DWORD *)(this + 7540) = *(_DWORD *)(v15 + 1084);
  *(_DWORD *)(this + 7544) = *(_DWORD *)(v15 + 1088);
  *(_DWORD *)(this + 7548) = *(_DWORD *)(v15 + 1092);
  *(_DWORD *)(this + 7552) = *(_DWORD *)(v15 + 1096);
  *(_DWORD *)(this + 7556) = *(_DWORD *)(v15 + 1100);
  v25 = (char *)(this + 7584);
  v22 = (char *)(v15 + 1128);
  v26 = 6;
  do
  {
    qmemcpy(v25, v22, 0x18u);
    v11 = v26 == 1;
    v22 += 24;
    v25 += 24;
    --v26;
  }
  while ( !v11 );
  qmemcpy((void *)(this + 7728), (const void *)(v15 + 1272), 0x18u);
  v17 = (double)*(int *)(v16 + 4932) * *(double *)(v16 + 4920) + *(double *)(v16 + 4912);
  *(double *)(this + 6700) = v17 * *(double *)(v15 + 1404) + *(double *)(this + 7712);
  *(_DWORD *)(this + 6708) = *(_DWORD *)(v15 + 1388);
  *(_DWORD *)(this + 6712) = *(_DWORD *)(v15 + 1392);
  *(double *)(this + 6716) = v17 * *(double *)(v15 + 1396) + *(double *)(v15 + 1072);
  *(_DWORD *)(this + 6724) = *(_DWORD *)(v15 + 1380);
  *(_DWORD *)(this + 6728) = *(_DWORD *)(v15 + 1384);
  v18 = (double)(*(_DWORD *)(v16 + 4864) - 1) * *(double *)(v16 + 4856) + *(double *)(v16 + 4848);
  *(_DWORD *)(this + 7876) = *(_DWORD *)(this + 6700);
  *(_DWORD *)(this + 7880) = *(_DWORD *)(this + 6704);
  *(_DWORD *)(this + 7884) = *(_DWORD *)(this + 6716);
  *(_DWORD *)(this + 7888) = *(_DWORD *)(this + 6720);
  *(double *)(this + 6748) = v18;
  sub_43E5F0((double *)this, (double)*(int *)(v16 + 4868) * *(double *)(v16 + 4856) + *(double *)(v16 + 4848));
  *(_BYTE *)(this + 7752) = *(_BYTE *)(v19 + 1296);
  v20 = *(double *)(v19 + 1300);
  *(double *)(this + 7756) = v20;
  *(double *)(this + 7892) = v20;
  *(_DWORD *)(this + 7764) = *(_DWORD *)(v19 + 1308);
  *(_DWORD *)(this + 7768) = *(_DWORD *)(v19 + 1312);
  *(_DWORD *)(this + 7772) = *(_DWORD *)(v19 + 1316);
  *(_DWORD *)(this + 7776) = *(_DWORD *)(v19 + 1320);
  *(_DWORD *)(this + 7780) = *(_DWORD *)(v19 + 1324);
  *(_DWORD *)(this + 7784) = *(_DWORD *)(v19 + 1328);
  sub_438AF0(
    (double *)(this + 7788),
    *(_DWORD *)(v19 + 1332),
    *(_DWORD *)(v19 + 1336),
    *(double *)(v19 + 1340),
    *(double *)(v19 + 1348));
}
