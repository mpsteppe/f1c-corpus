int __cdecl sub_5331B0(float *a1, float *a2, float *a3)
{
  double v3; // st7
  double v4; // st7
  double v5; // st6
  double v6; // st5
  double v7; // st4
  double v8; // st7
  double v9; // st6
  double v10; // st5
  double v11; // st4
  double v12; // st6
  double v13; // st5
  double v14; // st6
  double v15; // st5
  double v16; // st7
  double v17; // st7
  double v18; // st7
  double v19; // st7
  double v20; // st7
  double v21; // st7
  double v22; // st7
  int result; // eax

  flt_7E048C = *a3 + a3[31];
  flt_7E0508 = (*a3 - a3[31]) * 0.50060302;
  flt_7E0490 = a3[1] + a3[30];
  flt_7E0504 = (a3[1] - a3[30]) * 0.50547093;
  flt_7E0494 = a3[2] + a3[29];
  flt_7E0500 = (a3[2] - a3[29]) * 0.51544732;
  flt_7E0498 = a3[3] + a3[28];
  flt_7E04FC = (a3[3] - a3[28]) * 0.53104258;
  flt_7E049C = a3[4] + a3[27];
  flt_7E04F8 = (a3[4] - a3[27]) * 0.55310392;
  flt_7E04A0 = a3[5] + a3[26];
  flt_7E04F4 = (a3[5] - a3[26]) * 0.58293498;
  flt_7E04A4 = a3[6] + a3[25];
  flt_7E04F0 = (a3[6] - a3[25]) * 0.62250412;
  flt_7E04A8 = a3[7] + a3[24];
  flt_7E04EC = (a3[7] - a3[24]) * 0.67480832;
  flt_7E04AC = a3[8] + a3[23];
  flt_7E04E8 = (a3[8] - a3[23]) * 0.74453628;
  flt_7E04B0 = a3[9] + a3[22];
  flt_7E04E4 = (a3[9] - a3[22]) * 0.83934963;
  flt_7E04B4 = a3[10] + a3[21];
  flt_7E04E0 = (a3[10] - a3[21]) * 0.97256821;
  flt_7E04B8 = a3[11] + a3[20];
  flt_7E04DC = (a3[11] - a3[20]) * 1.1694399;
  flt_7E04BC = a3[12] + a3[19];
  flt_7E04D8 = (a3[12] - a3[19]) * 1.4841646;
  flt_7E04C0 = a3[13] + a3[18];
  flt_7E04D4 = (a3[13] - a3[18]) * 2.057781;
  flt_7E04C4 = a3[14] + a3[17];
  flt_7E04D0 = (a3[14] - a3[17]) * 3.4076085;
  flt_7E04C8 = a3[15] + a3[16];
  v3 = (a3[15] - a3[16]) * 10.190008;
  flt_7E050C = flt_7E048C + flt_7E04C8;
  flt_7E0548 = (flt_7E048C - flt_7E04C8) * 0.50241929;
  flt_7E0510 = flt_7E0490 + flt_7E04C4;
  flt_7E0544 = (flt_7E0490 - flt_7E04C4) * 0.52249861;
  flt_7E0514 = flt_7E0494 + flt_7E04C0;
  flt_7E0540 = (flt_7E0494 - flt_7E04C0) * 0.56694406;
  flt_7E0518 = flt_7E0498 + flt_7E04BC;
  flt_7E053C = (flt_7E0498 - flt_7E04BC) * 0.6468218;
  flt_7E051C = flt_7E049C + flt_7E04B8;
  flt_7E0538 = (flt_7E049C - flt_7E04B8) * 0.7881546;
  flt_7E0520 = flt_7E04A0 + flt_7E04B4;
  flt_7E0534 = (flt_7E04A0 - flt_7E04B4) * 1.0606776;
  flt_7E0524 = flt_7E04A4 + flt_7E04B0;
  flt_7E0530 = (flt_7E04A4 - flt_7E04B0) * 1.7224472;
  flt_7E0528 = flt_7E04A8 + flt_7E04AC;
  flt_7E052C = (flt_7E04A8 - flt_7E04AC) * 5.1011486;
  flt_7E054C = flt_7E0508 + v3;
  v4 = (flt_7E0508 - v3) * 0.50241929;
  v5 = flt_7E0504 + flt_7E04D0;
  flt_7E0584 = (flt_7E0504 - flt_7E04D0) * 0.52249861;
  flt_7E0554 = flt_7E0500 + flt_7E04D4;
  flt_7E0580 = (flt_7E0500 - flt_7E04D4) * 0.56694406;
  flt_7E0558 = flt_7E04FC + flt_7E04D8;
  flt_7E057C = (flt_7E04FC - flt_7E04D8) * 0.6468218;
  flt_7E055C = flt_7E04F8 + flt_7E04DC;
  flt_7E0578 = (flt_7E04F8 - flt_7E04DC) * 0.7881546;
  flt_7E0560 = flt_7E04F4 + flt_7E04E0;
  flt_7E0574 = (flt_7E04F4 - flt_7E04E0) * 1.0606776;
  v6 = flt_7E04F0 + flt_7E04E4;
  flt_7E0570 = (flt_7E04F0 - flt_7E04E4) * 1.7224472;
  v7 = flt_7E04EC + flt_7E04E8;
  flt_7E056C = (flt_7E04EC - flt_7E04E8) * 5.1011486;
  flt_7E048C = flt_7E0528 + flt_7E050C;
  flt_7E04A8 = (flt_7E050C - flt_7E0528) * 0.50979561;
  flt_7E0490 = flt_7E0524 + flt_7E0510;
  flt_7E04A4 = (flt_7E0510 - flt_7E0524) * 0.60134488;
  flt_7E0494 = flt_7E0520 + flt_7E0514;
  flt_7E04A0 = (flt_7E0514 - flt_7E0520) * 0.89997619;
  flt_7E0498 = flt_7E051C + flt_7E0518;
  flt_7E049C = (flt_7E0518 - flt_7E051C) * 2.5629156;
  flt_7E04AC = flt_7E052C + flt_7E0548;
  flt_7E04C8 = (flt_7E0548 - flt_7E052C) * 0.50979561;
  flt_7E04B0 = flt_7E0530 + flt_7E0544;
  flt_7E04C4 = (flt_7E0544 - flt_7E0530) * 0.60134488;
  flt_7E04B4 = flt_7E0534 + flt_7E0540;
  flt_7E04C0 = (flt_7E0540 - flt_7E0534) * 0.89997619;
  flt_7E04B8 = flt_7E0538 + flt_7E053C;
  flt_7E04BC = (flt_7E053C - flt_7E0538) * 2.5629156;
  flt_7E04CC = v7 + flt_7E054C;
  flt_7E04E8 = (flt_7E054C - v7) * 0.50979561;
  flt_7E04D0 = v6 + v5;
  flt_7E04E4 = (v5 - v6) * 0.60134488;
  flt_7E04D4 = flt_7E0560 + flt_7E0554;
  flt_7E04E0 = (flt_7E0554 - flt_7E0560) * 0.89997619;
  flt_7E04D8 = flt_7E055C + flt_7E0558;
  flt_7E04DC = (flt_7E0558 - flt_7E055C) * 2.5629156;
  flt_7E04EC = flt_7E056C + v4;
  v8 = (v4 - flt_7E056C) * 0.50979561;
  v9 = flt_7E0570 + flt_7E0584;
  flt_7E0504 = (flt_7E0584 - flt_7E0570) * 0.60134488;
  v10 = flt_7E0574 + flt_7E0580;
  flt_7E0500 = (flt_7E0580 - flt_7E0574) * 0.89997619;
  v11 = flt_7E0578 + flt_7E057C;
  flt_7E04FC = (flt_7E057C - flt_7E0578) * 2.5629156;
  flt_7E050C = flt_7E0498 + flt_7E048C;
  flt_7E0518 = (flt_7E048C - flt_7E0498) * 0.54119611;
  flt_7E0510 = flt_7E0494 + flt_7E0490;
  flt_7E0514 = (flt_7E0490 - flt_7E0494) * 1.306563;
  flt_7E051C = flt_7E04A8 + flt_7E049C;
  flt_7E0528 = (flt_7E04A8 - flt_7E049C) * 0.54119611;
  flt_7E0520 = flt_7E04A4 + flt_7E04A0;
  flt_7E0524 = (flt_7E04A4 - flt_7E04A0) * 1.306563;
  flt_7E052C = flt_7E04B8 + flt_7E04AC;
  flt_7E0538 = (flt_7E04AC - flt_7E04B8) * 0.54119611;
  flt_7E0530 = flt_7E04B4 + flt_7E04B0;
  flt_7E0534 = (flt_7E04B0 - flt_7E04B4) * 1.306563;
  flt_7E053C = flt_7E04C8 + flt_7E04BC;
  flt_7E0548 = (flt_7E04C8 - flt_7E04BC) * 0.54119611;
  flt_7E0540 = flt_7E04C4 + flt_7E04C0;
  flt_7E0544 = (flt_7E04C4 - flt_7E04C0) * 1.306563;
  flt_7E054C = flt_7E04CC + flt_7E04D8;
  flt_7E0558 = (flt_7E04CC - flt_7E04D8) * 0.54119611;
  flt_7E0550 = flt_7E04D0 + flt_7E04D4;
  flt_7E0554 = (flt_7E04D0 - flt_7E04D4) * 1.306563;
  flt_7E055C = flt_7E04DC + flt_7E04E8;
  flt_7E0568 = (flt_7E04E8 - flt_7E04DC) * 0.54119611;
  flt_7E0560 = flt_7E04E0 + flt_7E04E4;
  flt_7E0564 = (flt_7E04E4 - flt_7E04E0) * 1.306563;
  flt_7E056C = flt_7E04EC + v11;
  flt_7E0578 = (flt_7E04EC - v11) * 0.54119611;
  flt_7E0570 = v9 + v10;
  flt_7E0574 = (v9 - v10) * 1.306563;
  flt_7E057C = flt_7E04FC + v8;
  flt_7E0588 = (v8 - flt_7E04FC) * 0.54119611;
  flt_7E0580 = flt_7E0500 + flt_7E0504;
  flt_7E0584 = (flt_7E0504 - flt_7E0500) * 1.306563;
  flt_7E048C = flt_7E0510 + flt_7E050C;
  flt_7E0490 = (flt_7E050C - flt_7E0510) * 0.70710677;
  v12 = (flt_7E0518 - flt_7E0514) * 0.70710677;
  flt_7E0498 = v12;
  flt_7E0494 = v12 + flt_7E0518 + flt_7E0514;
  flt_7E04A0 = (flt_7E051C - flt_7E0520) * 0.70710677;
  v13 = (flt_7E0528 - flt_7E0524) * 0.70710677;
  flt_7E04A8 = v13;
  flt_7E04A4 = v13 + flt_7E0528 + flt_7E0524;
  flt_7E049C = flt_7E04A4 + flt_7E0520 + flt_7E051C;
  flt_7E04A4 = flt_7E04A4 + flt_7E04A0;
  flt_7E04A0 = flt_7E04A8 + flt_7E04A0;
  flt_7E04AC = flt_7E052C + flt_7E0530;
  flt_7E04B0 = (flt_7E052C - flt_7E0530) * 0.70710677;
  v14 = (flt_7E0538 - flt_7E0534) * 0.70710677;
  flt_7E04B8 = v14;
  flt_7E04B4 = v14 + flt_7E0534 + flt_7E0538;
  flt_7E04C0 = (flt_7E053C - flt_7E0540) * 0.70710677;
  v15 = (flt_7E0548 - flt_7E0544) * 0.70710677;
  flt_7E04C8 = v15;
  flt_7E04C4 = v15 + flt_7E0544 + flt_7E0548;
  flt_7E04BC = flt_7E04C4 + flt_7E053C + flt_7E0540;
  flt_7E04C4 = flt_7E04C4 + flt_7E04C0;
  flt_7E04C0 = flt_7E04C8 + flt_7E04C0;
  flt_7E04CC = flt_7E0550 + flt_7E054C;
  flt_7E04D0 = (flt_7E054C - flt_7E0550) * 0.70710677;
  flt_7E04D8 = (flt_7E0558 - flt_7E0554) * 0.70710677;
  flt_7E04D4 = flt_7E0558 + flt_7E0554 + flt_7E04D8;
  flt_7E04E0 = (flt_7E055C - flt_7E0560) * 0.70710677;
  flt_7E04E8 = (flt_7E0568 - flt_7E0564) * 0.70710677;
  flt_7E04E4 = flt_7E0568 + flt_7E0564 + flt_7E04E8;
  flt_7E04DC = flt_7E0560 + flt_7E055C + flt_7E04E4;
  flt_7E04E4 = flt_7E04E0 + flt_7E04E4;
  flt_7E04E0 = flt_7E04E0 + flt_7E04E8;
  flt_7E04EC = flt_7E056C + flt_7E0570;
  flt_7E04F0 = (flt_7E056C - flt_7E0570) * 0.70710677;
  flt_7E04F8 = (flt_7E0578 - flt_7E0574) * 0.70710677;
  flt_7E04F4 = flt_7E0574 + flt_7E0578 + flt_7E04F8;
  flt_7E0500 = (flt_7E057C - flt_7E0580) * 0.70710677;
  flt_7E0508 = (flt_7E0588 - flt_7E0584) * 0.70710677;
  flt_7E0504 = flt_7E0584 + flt_7E0588 + flt_7E0508;
  flt_7E04FC = flt_7E057C + flt_7E0580 + flt_7E0504;
  flt_7E0504 = flt_7E0500 + flt_7E0504;
  flt_7E0500 = flt_7E0500 + flt_7E0508;
  a1[256] = flt_7E048C;
  a1[192] = flt_7E049C;
  a1[128] = flt_7E0494;
  a1[64] = flt_7E04A4;
  *a1 = flt_7E0490;
  *a2 = flt_7E0490;
  a2[64] = flt_7E04A0;
  a2[128] = flt_7E0498;
  a2[192] = flt_7E04A8;
  flt_7E04AC = flt_7E04BC + flt_7E04AC;
  a1[224] = flt_7E04AC;
  flt_7E04BC = flt_7E04BC + flt_7E04B4;
  a1[160] = flt_7E04BC;
  flt_7E04B4 = flt_7E04C4 + flt_7E04B4;
  a1[96] = flt_7E04B4;
  flt_7E04C4 = flt_7E04C4 + flt_7E04B0;
  a1[32] = flt_7E04C4;
  flt_7E04B0 = flt_7E04C0 + flt_7E04B0;
  a2[32] = flt_7E04B0;
  flt_7E04C0 = flt_7E04C0 + flt_7E04B8;
  a2[96] = flt_7E04C0;
  flt_7E04B8 = flt_7E04C8 + flt_7E04B8;
  a2[160] = flt_7E04B8;
  a2[224] = flt_7E04C8;
  v16 = flt_7E04EC + flt_7E04FC;
  flt_7E04EC = v16;
  a1[240] = v16 + flt_7E04CC;
  a1[208] = flt_7E04EC + flt_7E04DC;
  v17 = flt_7E04F4 + flt_7E04FC;
  flt_7E04FC = v17;
  a1[176] = v17 + flt_7E04DC;
  a1[144] = flt_7E04FC + flt_7E04D4;
  v18 = flt_7E04F4 + flt_7E0504;
  flt_7E04F4 = v18;
  a1[112] = v18 + flt_7E04D4;
  a1[80] = flt_7E04F4 + flt_7E04E4;
  v19 = flt_7E04F0 + flt_7E0504;
  flt_7E0504 = v19;
  a1[48] = v19 + flt_7E04E4;
  a1[16] = flt_7E0504 + flt_7E04D0;
  v20 = flt_7E04F0 + flt_7E0500;
  flt_7E04F0 = v20;
  a2[16] = v20 + flt_7E04D0;
  a2[48] = flt_7E04F0 + flt_7E04E0;
  v21 = flt_7E04F8 + flt_7E0500;
  flt_7E0500 = v21;
  a2[80] = v21 + flt_7E04E0;
  a2[112] = flt_7E0500 + flt_7E04D8;
  v22 = flt_7E04F8 + flt_7E0508;
  flt_7E04F8 = v22;
  a2[144] = v22 + flt_7E04D8;
  a2[176] = flt_7E04F8 + flt_7E04E8;
  a2[208] = flt_7E0508 + flt_7E04E8;
  result = LODWORD(flt_7E0508);
  a2[240] = flt_7E0508;
  return result;
}
