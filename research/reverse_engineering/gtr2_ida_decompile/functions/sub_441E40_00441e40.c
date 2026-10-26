void __thiscall sub_441E40(int this, int a2, int a3)
{
  double *v4; // ebp
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double v8; // st6
  double v9; // st7
  double v10; // st7
  double v11; // st6
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  unsigned __int8 v18; // c0
  unsigned __int8 v19; // c3
  double v20; // st7
  double v21; // st7
  double v22; // st6

  v4 = (double *)(this + 7376);
  sub_43BB60((double *)(this + 7376), a3 + 328);
  v5 = (double)*(int *)(a2 + 3652) * *(double *)(a2 + 3640) + *(double *)(a2 + 3632);
  v4[7] = v5 * v4[3] * v5 + v5 * v4[2] + v4[1];
  v4[8] = v5 * v4[6] * v5 + v5 * v4[5] + v4[4];
  sub_43BB60((double *)(this + 7504), a3 + 432);
  v6 = (double)*(int *)(a2 + 3716) * *(double *)(a2 + 3704) + *(double *)(a2 + 3696);
  *(double *)(this + 7560) = v6 * *(double *)(this + 7528) * v6
                           + v6 * *(double *)(this + 7520)
                           + *(double *)(this + 7512);
  *(double *)(this + 7568) = v6 * *(double *)(this + 7552) * v6
                           + v6 * *(double *)(this + 7544)
                           + *(double *)(this + 7536);
  *(_BYTE *)(this + 7632) = *(_BYTE *)(a3 + 536);
  *(_DWORD *)(this + 7636) = 0;
  *(double *)(this + 7648) = *(double *)(a3 + 544);
  *(double *)(this + 7688) = *(double *)(a3 + 600);
  v7 = *(double *)(a3 + 624);
  v8 = *(double *)(a3 + 616);
  *(double *)(this + 7696) = *(double *)(a3 + 608);
  *(double *)(this + 7704) = v8 + v8;
  if ( v8 <= 0.0 )
    *(double *)(this + 7712) = 0.0;
  else
    *(double *)(this + 7712) = 3.141592653589793 / v8;
  *(double *)(this + 7720) = (v7 - 1.0) * 0.5;
  *(_DWORD *)(this + 7752) = *(_DWORD *)(a3 + 632);
  *(_DWORD *)(this + 7756) = *(_DWORD *)(a3 + 636);
  *(_DWORD *)(this + 7760) = *(_DWORD *)(a3 + 640);
  *(_DWORD *)(this + 7764) = *(_DWORD *)(a3 + 644);
  *(_DWORD *)(this + 7768) = *(_DWORD *)(a3 + 648);
  *(_DWORD *)(this + 7772) = *(_DWORD *)(a3 + 652);
  *(_DWORD *)(this + 7776) = *(_DWORD *)(a3 + 656);
  *(_DWORD *)(this + 7780) = *(_DWORD *)(a3 + 660);
  *(_DWORD *)(this + 7784) = *(_DWORD *)(a3 + 664);
  *(_DWORD *)(this + 7788) = *(_DWORD *)(a3 + 668);
  *(_DWORD *)(this + 7792) = *(_DWORD *)(a3 + 672);
  *(_DWORD *)(this + 7796) = *(_DWORD *)(a3 + 676);
  *(_DWORD *)(this + 7800) = *(_DWORD *)(a3 + 680);
  *(_DWORD *)(this + 7804) = *(_DWORD *)(a3 + 684);
  *(_DWORD *)(this + 7808) = *(_DWORD *)(a3 + 688);
  *(_DWORD *)(this + 7812) = *(_DWORD *)(a3 + 692);
  *(_DWORD *)(this + 7816) = *(_DWORD *)(a3 + 696);
  *(_DWORD *)(this + 7820) = *(_DWORD *)(a3 + 700);
  *(_DWORD *)(this + 7824) = *(_DWORD *)(a3 + 704);
  *(_DWORD *)(this + 7828) = *(_DWORD *)(a3 + 708);
  *(_DWORD *)(this + 7832) = *(_DWORD *)(a3 + 712);
  *(_DWORD *)(this + 7836) = *(_DWORD *)(a3 + 716);
  *(_DWORD *)(this + 7840) = *(_DWORD *)(a3 + 720);
  *(_DWORD *)(this + 7844) = *(_DWORD *)(a3 + 724);
  *(_DWORD *)(this + 7848) = *(_DWORD *)(a3 + 728);
  *(_DWORD *)(this + 7852) = *(_DWORD *)(a3 + 732);
  *(_DWORD *)(this + 7856) = *(_DWORD *)(a3 + 736);
  *(_DWORD *)(this + 7860) = *(_DWORD *)(a3 + 740);
  *(_DWORD *)(this + 7864) = *(_DWORD *)(a3 + 744);
  *(_DWORD *)(this + 7868) = *(_DWORD *)(a3 + 748);
  *(_DWORD *)(this + 7872) = *(_DWORD *)(a3 + 752);
  *(_DWORD *)(this + 7876) = *(_DWORD *)(a3 + 756);
  *(_DWORD *)(this + 7880) = *(_DWORD *)(a3 + 760);
  *(_DWORD *)(this + 7884) = *(_DWORD *)(a3 + 764);
  *(_DWORD *)(this + 7888) = *(_DWORD *)(a3 + 768);
  *(_DWORD *)(this + 7892) = *(_DWORD *)(a3 + 772);
  *(_DWORD *)(this + 7896) = *(_DWORD *)(a3 + 776);
  *(_DWORD *)(this + 7900) = *(_DWORD *)(a3 + 780);
  *(_DWORD *)(this + 7904) = *(_DWORD *)(a3 + 784);
  *(_DWORD *)(this + 7908) = *(_DWORD *)(a3 + 788);
  *(_DWORD *)(this + 7912) = *(_DWORD *)(a3 + 792);
  *(_DWORD *)(this + 7916) = *(_DWORD *)(a3 + 796);
  *(double *)(this + 7224) = *(double *)(a3 + 576);
  *(double *)(this + 7232) = *(double *)(a3 + 584);
  *(double *)(this + 7240) = *(double *)(a3 + 592);
  *(double *)(this + 7248) = *(double *)(a3 + 552);
  *(double *)(this + 7256) = *(double *)(a3 + 560);
  *(double *)(this + 7264) = *(double *)(a3 + 568);
  *(double *)(this + 8568) = *(double *)(this + 7224);
  *(double *)(this + 8576) = *(double *)(this + 7248);
  v9 = (double)*(int *)(a2 + 4804) * *(double *)(a2 + 4792) + *(double *)(a2 + 4784);
  *(double *)(this + 8560) = v9;
  *(double *)(this + 7680) = v9 * *(double *)(this + 7240) * v9
                           + v9 * *(double *)(this + 7232)
                           + *(double *)(this + 7224);
  *(double *)(this + 7888) = v9 * *(double *)(this + 7264) * v9
                           + v9 * *(double *)(this + 7256)
                           + *(double *)(this + 7248);
  *(_BYTE *)(this + 7920) = *(_BYTE *)(a3 + 824);
  v10 = *(double *)(a3 + 896);
  v11 = *(double *)(a3 + 888);
  *(double *)(this + 7936) = *(double *)(a3 + 880);
  *(double *)(this + 7944) = v11 + v11;
  if ( v11 <= 0.0 )
    *(double *)(this + 7952) = 0.0;
  else
    *(double *)(this + 7952) = 3.141592653589793 / v11;
  *(double *)(this + 7960) = (v10 - 1.0) * 0.5;
  *(_DWORD *)(this + 7992) = *(_DWORD *)(a3 + 904);
  *(_DWORD *)(this + 7996) = *(_DWORD *)(a3 + 908);
  *(_DWORD *)(this + 8000) = *(_DWORD *)(a3 + 912);
  *(_DWORD *)(this + 8004) = *(_DWORD *)(a3 + 916);
  *(_DWORD *)(this + 8008) = *(_DWORD *)(a3 + 920);
  *(_DWORD *)(this + 8012) = *(_DWORD *)(a3 + 924);
  *(_DWORD *)(this + 8016) = *(_DWORD *)(a3 + 928);
  *(_DWORD *)(this + 8020) = *(_DWORD *)(a3 + 932);
  *(_DWORD *)(this + 8024) = *(_DWORD *)(a3 + 936);
  *(_DWORD *)(this + 8028) = *(_DWORD *)(a3 + 940);
  *(_DWORD *)(this + 8032) = *(_DWORD *)(a3 + 944);
  *(_DWORD *)(this + 8036) = *(_DWORD *)(a3 + 948);
  *(_DWORD *)(this + 8040) = *(_DWORD *)(a3 + 952);
  *(_DWORD *)(this + 8044) = *(_DWORD *)(a3 + 956);
  *(_DWORD *)(this + 8048) = *(_DWORD *)(a3 + 960);
  *(_DWORD *)(this + 8052) = *(_DWORD *)(a3 + 964);
  *(_DWORD *)(this + 8056) = *(_DWORD *)(a3 + 968);
  *(_DWORD *)(this + 8060) = *(_DWORD *)(a3 + 972);
  *(_DWORD *)(this + 8064) = *(_DWORD *)(a3 + 976);
  *(_DWORD *)(this + 8068) = *(_DWORD *)(a3 + 980);
  *(_DWORD *)(this + 8072) = *(_DWORD *)(a3 + 984);
  *(_DWORD *)(this + 8076) = *(_DWORD *)(a3 + 988);
  *(_DWORD *)(this + 8080) = *(_DWORD *)(a3 + 992);
  *(_DWORD *)(this + 8084) = *(_DWORD *)(a3 + 996);
  *(_DWORD *)(this + 8088) = *(_DWORD *)(a3 + 1000);
  *(_DWORD *)(this + 8092) = *(_DWORD *)(a3 + 1004);
  *(_DWORD *)(this + 8096) = *(_DWORD *)(a3 + 1008);
  *(_DWORD *)(this + 8100) = *(_DWORD *)(a3 + 1012);
  *(_DWORD *)(this + 8104) = *(_DWORD *)(a3 + 1016);
  *(_DWORD *)(this + 8108) = *(_DWORD *)(a3 + 1020);
  *(_DWORD *)(this + 8112) = *(_DWORD *)(a3 + 1024);
  *(_DWORD *)(this + 8116) = *(_DWORD *)(a3 + 1028);
  *(_DWORD *)(this + 8120) = *(_DWORD *)(a3 + 1032);
  *(_DWORD *)(this + 8124) = *(_DWORD *)(a3 + 1036);
  *(_DWORD *)(this + 8128) = *(_DWORD *)(a3 + 1040);
  *(_DWORD *)(this + 8132) = *(_DWORD *)(a3 + 1044);
  *(_DWORD *)(this + 8136) = *(_DWORD *)(a3 + 1048);
  *(_DWORD *)(this + 8140) = *(_DWORD *)(a3 + 1052);
  *(_DWORD *)(this + 8144) = *(_DWORD *)(a3 + 1056);
  *(_DWORD *)(this + 8148) = *(_DWORD *)(a3 + 1060);
  *(_DWORD *)(this + 8152) = *(_DWORD *)(a3 + 1064);
  *(_DWORD *)(this + 8156) = *(_DWORD *)(a3 + 1068);
  *(double *)(this + 7272) = *(double *)(a3 + 856);
  *(double *)(this + 7280) = *(double *)(a3 + 864);
  *(double *)(this + 7288) = *(double *)(a3 + 872);
  *(double *)(this + 7296) = *(double *)(a3 + 832);
  *(double *)(this + 7304) = *(double *)(a3 + 840);
  *(double *)(this + 7312) = *(double *)(a3 + 848);
  *(double *)(this + 8624) = *(double *)(this + 7272);
  *(double *)(this + 8632) = *(double *)(this + 7296);
  v12 = (double)*(int *)(a2 + 4868) * *(double *)(a2 + 4856) + *(double *)(a2 + 4848);
  *(double *)(this + 8616) = v12;
  *(double *)(this + 7928) = v12 * *(double *)(this + 7288) * v12
                           + v12 * *(double *)(this + 7280)
                           + *(double *)(this + 7272);
  *(double *)(this + 8128) = v12 * *(double *)(this + 7312) * v12
                           + v12 * *(double *)(this + 7304)
                           + *(double *)(this + 7296);
  *(double *)(this + 7352) = *(double *)(a3 + 5072);
  *(double *)(this + 7360) = *(double *)(a3 + 5080);
  *(double *)(this + 8168) = *(double *)(a3 + 1104);
  *(double *)(this + 8176) = *(double *)(a3 + 1112);
  *(double *)(this + 8184) = *(double *)(a3 + 1120);
  *(_DWORD *)(this + 8216) = *(_DWORD *)(a3 + 1152);
  *(_DWORD *)(this + 8220) = *(_DWORD *)(a3 + 1156);
  *(_DWORD *)(this + 8224) = *(_DWORD *)(a3 + 1160);
  *(_DWORD *)(this + 8228) = *(_DWORD *)(a3 + 1164);
  *(_DWORD *)(this + 8232) = *(_DWORD *)(a3 + 1168);
  *(_DWORD *)(this + 8236) = *(_DWORD *)(a3 + 1172);
  *(_DWORD *)(this + 8240) = *(_DWORD *)(a3 + 1176);
  *(_DWORD *)(this + 8244) = *(_DWORD *)(a3 + 1180);
  *(_DWORD *)(this + 8248) = *(_DWORD *)(a3 + 1184);
  *(_DWORD *)(this + 8252) = *(_DWORD *)(a3 + 1188);
  *(_DWORD *)(this + 8256) = *(_DWORD *)(a3 + 1192);
  *(_DWORD *)(this + 8260) = *(_DWORD *)(a3 + 1196);
  *(_DWORD *)(this + 8264) = *(_DWORD *)(a3 + 1200);
  *(_DWORD *)(this + 8268) = *(_DWORD *)(a3 + 1204);
  *(_DWORD *)(this + 8272) = *(_DWORD *)(a3 + 1208);
  *(_DWORD *)(this + 8276) = *(_DWORD *)(a3 + 1212);
  *(_DWORD *)(this + 8280) = *(_DWORD *)(a3 + 1216);
  *(_DWORD *)(this + 8284) = *(_DWORD *)(a3 + 1220);
  *(_DWORD *)(this + 8288) = *(_DWORD *)(a3 + 1224);
  *(_DWORD *)(this + 8292) = *(_DWORD *)(a3 + 1228);
  *(_DWORD *)(this + 8296) = *(_DWORD *)(a3 + 1232);
  *(_DWORD *)(this + 8300) = *(_DWORD *)(a3 + 1236);
  *(_DWORD *)(this + 8304) = *(_DWORD *)(a3 + 1240);
  *(_DWORD *)(this + 8308) = *(_DWORD *)(a3 + 1244);
  *(_DWORD *)(this + 8312) = *(_DWORD *)(a3 + 1248);
  *(_DWORD *)(this + 8316) = *(_DWORD *)(a3 + 1252);
  *(_DWORD *)(this + 8320) = *(_DWORD *)(a3 + 1256);
  *(_DWORD *)(this + 8324) = *(_DWORD *)(a3 + 1260);
  *(_DWORD *)(this + 8328) = *(_DWORD *)(a3 + 1264);
  *(_DWORD *)(this + 8332) = *(_DWORD *)(a3 + 1268);
  *(_DWORD *)(this + 8336) = *(_DWORD *)(a3 + 1272);
  *(_DWORD *)(this + 8340) = *(_DWORD *)(a3 + 1276);
  *(_DWORD *)(this + 8344) = *(_DWORD *)(a3 + 1280);
  *(_DWORD *)(this + 8348) = *(_DWORD *)(a3 + 1284);
  *(_DWORD *)(this + 8352) = *(_DWORD *)(a3 + 1288);
  *(_DWORD *)(this + 8356) = *(_DWORD *)(a3 + 1292);
  *(_DWORD *)(this + 8360) = *(_DWORD *)(a3 + 1296);
  *(_DWORD *)(this + 8364) = *(_DWORD *)(a3 + 1300);
  *(_DWORD *)(this + 8368) = *(_DWORD *)(a3 + 1304);
  *(_DWORD *)(this + 8372) = *(_DWORD *)(a3 + 1308);
  *(_DWORD *)(this + 8376) = *(_DWORD *)(a3 + 1312);
  *(_DWORD *)(this + 8380) = *(_DWORD *)(a3 + 1316);
  v13 = (double)*(int *)(a2 + 4996) * *(double *)(a2 + 4984) + *(double *)(a2 + 4976);
  *(double *)(this + 7320) = v13 * *(double *)(a3 + 1496) + *(double *)(this + 8344);
  *(double *)(this + 7328) = *(double *)(a3 + 1480);
  *(double *)(this + 7336) = v13 * *(double *)(a3 + 1488) + *(double *)(a3 + 1096);
  *(double *)(this + 7344) = *(double *)(a3 + 1472);
  *(double *)(this + 7368) = (double)(*(_DWORD *)(a2 + 4928) - 1) * *(double *)(a2 + 4920) + *(double *)(a2 + 4912);
  *(double *)(this + 8592) = *(double *)(this + 7320);
  *(double *)(this + 8600) = *(double *)(this + 7336);
  v14 = (double)*(int *)(a2 + 4932) * *(double *)(a2 + 4920) + *(double *)(a2 + 4912);
  *(double *)(this + 8584) = v14;
  *(double *)(this + 8344) = v14 * *(double *)(this + 7328) + *(double *)(this + 7320);
  *(double *)(this + 8160) = v14 * *(double *)(this + 7344) + *(double *)(this + 7336);
  *(double *)(this + 8984) = v14 * *(double *)(this + 7360) + *(double *)(this + 7352);
  *(_BYTE *)(this + 8384) = *(_BYTE *)(a3 + 1320);
  v15 = *(double *)(a3 + 1328);
  *(double *)(this + 8392) = v15;
  *(double *)(this + 8608) = v15;
  *(double *)(this + 8400) = *(double *)(a3 + 1336);
  *(double *)(this + 8408) = *(double *)(a3 + 1344);
  *(double *)(this + 8416) = *(double *)(a3 + 1352);
  *(double *)(this + 8424) = *(double *)(a3 + 1360);
  *(double *)(this + 8432) = *(double *)(a3 + 1368);
  *(double *)(this + 8440) = *(double *)(a3 + 1376);
  *(double *)(this + 8448) = *(double *)(a3 + 1384);
  *(double *)(this + 8456) = *(double *)(a3 + 1392);
  v16 = *(double *)(a3 + 1400);
  *(double *)(this + 8464) = v16;
  if ( v18 | v19 )
  {
    *(double *)(this + 8464) = 0.0;
    *(double *)(this + 8472) = 0.0;
    *(double *)(this + 8480) = 0.0;
  }
  else
  {
    v20 = -1.0 / (v16 * v16);
    *(double *)(this + 8480) = v20;
    *(double *)(this + 8472) = v20 * *(double *)(this + 8464) * -2.0;
  }
  *(double *)(this + 8488) = *(double *)(a3 + 1408);
  *(double *)(this + 8472) = *(double *)(this + 8472) * *(double *)(a3 + 1416);
  *(double *)(this + 8480) = *(double *)(this + 8480) * *(double *)(a3 + 1416);
  *(double *)(this + 8496) = 1.0 - *(double *)(a3 + 1416);
  v21 = *(double *)(a3 + 1440);
  v22 = *(double *)(a3 + 1432);
  *(double *)(this + 8504) = *(double *)(a3 + 1424);
  *(double *)(this + 8512) = v22 + v22;
  if ( v22 <= 0.0 )
    *(double *)(this + 8520) = 0.0;
  else
    *(double *)(this + 8520) = 3.141592653589793 / v22;
  *(double *)(this + 8528) = (v21 - 1.0) * 0.5;
}
