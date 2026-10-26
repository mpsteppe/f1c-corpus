// f1c  0x00531b50  size=3910
int __cdecl sub_531B50(float *a1, float *a2, float *a3)
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

  flt_8B5924 = *a3 + a3[31];
  flt_8B59A0 = (*a3 - a3[31]) * 0.50060302;
  flt_8B5928 = a3[1] + a3[30];
  flt_8B599C = (a3[1] - a3[30]) * 0.50547093;
  flt_8B592C = a3[2] + a3[29];
  flt_8B5998 = (a3[2] - a3[29]) * 0.51544732;
  flt_8B5930 = a3[3] + a3[28];
  flt_8B5994 = (a3[3] - a3[28]) * 0.53104258;
  flt_8B5934 = a3[4] + a3[27];
  flt_8B5990 = (a3[4] - a3[27]) * 0.55310392;
  flt_8B5938 = a3[5] + a3[26];
  flt_8B598C = (a3[5] - a3[26]) * 0.58293498;
  flt_8B593C = a3[6] + a3[25];
  flt_8B5988 = (a3[6] - a3[25]) * 0.62250412;
  flt_8B5940 = a3[7] + a3[24];
  flt_8B5984 = (a3[7] - a3[24]) * 0.67480832;
  flt_8B5944 = a3[8] + a3[23];
  flt_8B5980 = (a3[8] - a3[23]) * 0.74453628;
  flt_8B5948 = a3[9] + a3[22];
  flt_8B597C = (a3[9] - a3[22]) * 0.83934963;
  flt_8B594C = a3[10] + a3[21];
  flt_8B5978 = (a3[10] - a3[21]) * 0.97256821;
  flt_8B5950 = a3[11] + a3[20];
  flt_8B5974 = (a3[11] - a3[20]) * 1.1694399;
  flt_8B5954 = a3[12] + a3[19];
  flt_8B5970 = (a3[12] - a3[19]) * 1.4841646;
  flt_8B5958 = a3[13] + a3[18];
  flt_8B596C = (a3[13] - a3[18]) * 2.057781;
  flt_8B595C = a3[14] + a3[17];
  flt_8B5968 = (a3[14] - a3[17]) * 3.4076085;
  flt_8B5960 = a3[15] + a3[16];
  v3 = (a3[15] - a3[16]) * 10.190008;
  flt_8B59A4 = flt_8B5924 + flt_8B5960;
  flt_8B59E0 = (flt_8B5924 - flt_8B5960) * 0.50241929;
  flt_8B59A8 = flt_8B5928 + flt_8B595C;
  flt_8B59DC = (flt_8B5928 - flt_8B595C) * 0.52249861;
  flt_8B59AC = flt_8B592C + flt_8B5958;
  flt_8B59D8 = (flt_8B592C - flt_8B5958) * 0.56694406;
  flt_8B59B0 = flt_8B5930 + flt_8B5954;
  flt_8B59D4 = (flt_8B5930 - flt_8B5954) * 0.6468218;
  flt_8B59B4 = flt_8B5934 + flt_8B5950;
  flt_8B59D0 = (flt_8B5934 - flt_8B5950) * 0.7881546;
  flt_8B59B8 = flt_8B5938 + flt_8B594C;
  flt_8B59CC = (flt_8B5938 - flt_8B594C) * 1.0606776;
  flt_8B59BC = flt_8B593C + flt_8B5948;
  flt_8B59C8 = (flt_8B593C - flt_8B5948) * 1.7224472;
  flt_8B59C0 = flt_8B5940 + flt_8B5944;
  flt_8B59C4 = (flt_8B5940 - flt_8B5944) * 5.1011486;
  flt_8B59E4 = flt_8B59A0 + v3;
  v4 = (flt_8B59A0 - v3) * 0.50241929;
  v5 = flt_8B599C + flt_8B5968;
  flt_8B5A1C = (flt_8B599C - flt_8B5968) * 0.52249861;
  flt_8B59EC = flt_8B5998 + flt_8B596C;
  flt_8B5A18 = (flt_8B5998 - flt_8B596C) * 0.56694406;
  flt_8B59F0 = flt_8B5994 + flt_8B5970;
  flt_8B5A14 = (flt_8B5994 - flt_8B5970) * 0.6468218;
  flt_8B59F4 = flt_8B5990 + flt_8B5974;
  flt_8B5A10 = (flt_8B5990 - flt_8B5974) * 0.7881546;
  flt_8B59F8 = flt_8B598C + flt_8B5978;
  flt_8B5A0C = (flt_8B598C - flt_8B5978) * 1.0606776;
  v6 = flt_8B5988 + flt_8B597C;
  flt_8B5A08 = (flt_8B5988 - flt_8B597C) * 1.7224472;
  v7 = flt_8B5984 + flt_8B5980;
  flt_8B5A04 = (flt_8B5984 - flt_8B5980) * 5.1011486;
  flt_8B5924 = flt_8B59C0 + flt_8B59A4;
  flt_8B5940 = (flt_8B59A4 - flt_8B59C0) * 0.50979561;
  flt_8B5928 = flt_8B59BC + flt_8B59A8;
  flt_8B593C = (flt_8B59A8 - flt_8B59BC) * 0.60134488;
  flt_8B592C = flt_8B59B8 + flt_8B59AC;
  flt_8B5938 = (flt_8B59AC - flt_8B59B8) * 0.89997619;
  flt_8B5930 = flt_8B59B4 + flt_8B59B0;
  flt_8B5934 = (flt_8B59B0 - flt_8B59B4) * 2.5629156;
  flt_8B5944 = flt_8B59C4 + flt_8B59E0;
  flt_8B5960 = (flt_8B59E0 - flt_8B59C4) * 0.50979561;
  flt_8B5948 = flt_8B59C8 + flt_8B59DC;
  flt_8B595C = (flt_8B59DC - flt_8B59C8) * 0.60134488;
  flt_8B594C = flt_8B59CC + flt_8B59D8;
  flt_8B5958 = (flt_8B59D8 - flt_8B59CC) * 0.89997619;
  flt_8B5950 = flt_8B59D0 + flt_8B59D4;
  flt_8B5954 = (flt_8B59D4 - flt_8B59D0) * 2.5629156;
  flt_8B5964 = v7 + flt_8B59E4;
  flt_8B5980 = (flt_8B59E4 - v7) * 0.50979561;
  flt_8B5968 = v6 + v5;
  flt_8B597C = (v5 - v6) * 0.60134488;
  flt_8B596C = flt_8B59F8 + flt_8B59EC;
  flt_8B5978 = (flt_8B59EC - flt_8B59F8) * 0.89997619;
  flt_8B5970 = flt_8B59F4 + flt_8B59F0;
  flt_8B5974 = (flt_8B59F0 - flt_8B59F4) * 2.5629156;
  flt_8B5984 = flt_8B5A04 + v4;
  v8 = (v4 - flt_8B5A04) * 0.50979561;
  v9 = flt_8B5A08 + flt_8B5A1C;
  flt_8B599C = (flt_8B5A1C - flt_8B5A08) * 0.60134488;
  v10 = flt_8B5A0C + flt_8B5A18;
  flt_8B5998 = (flt_8B5A18 - flt_8B5A0C) * 0.89997619;
  v11 = flt_8B5A10 + flt_8B5A14;
  flt_8B5994 = (flt_8B5A14 - flt_8B5A10) * 2.5629156;
  flt_8B59A4 = flt_8B5930 + flt_8B5924;
  flt_8B59B0 = (flt_8B5924 - flt_8B5930) * 0.54119611;
  flt_8B59A8 = flt_8B592C + flt_8B5928;
  flt_8B59AC = (flt_8B5928 - flt_8B592C) * 1.306563;
  flt_8B59B4 = flt_8B5940 + flt_8B5934;
  flt_8B59C0 = (flt_8B5940 - flt_8B5934) * 0.54119611;
  flt_8B59B8 = flt_8B593C + flt_8B5938;
  flt_8B59BC = (flt_8B593C - flt_8B5938) * 1.306563;
  flt_8B59C4 = flt_8B5950 + flt_8B5944;
  flt_8B59D0 = (flt_8B5944 - flt_8B5950) * 0.54119611;
  flt_8B59C8 = flt_8B594C + flt_8B5948;
  flt_8B59CC = (flt_8B5948 - flt_8B594C) * 1.306563;
  flt_8B59D4 = flt_8B5960 + flt_8B5954;
  flt_8B59E0 = (flt_8B5960 - flt_8B5954) * 0.54119611;
  flt_8B59D8 = flt_8B595C + flt_8B5958;
  flt_8B59DC = (flt_8B595C - flt_8B5958) * 1.306563;
  flt_8B59E4 = flt_8B5964 + flt_8B5970;
  flt_8B59F0 = (flt_8B5964 - flt_8B5970) * 0.54119611;
  flt_8B59E8 = flt_8B5968 + flt_8B596C;
  flt_8B59EC = (flt_8B5968 - flt_8B596C) * 1.306563;
  flt_8B59F4 = flt_8B5974 + flt_8B5980;
  flt_8B5A00 = (flt_8B5980 - flt_8B5974) * 0.54119611;
  flt_8B59F8 = flt_8B5978 + flt_8B597C;
  flt_8B59FC = (flt_8B597C - flt_8B5978) * 1.306563;
  flt_8B5A04 = flt_8B5984 + v11;
  flt_8B5A10 = (flt_8B5984 - v11) * 0.54119611;
  flt_8B5A08 = v9 + v10;
  flt_8B5A0C = (v9 - v10) * 1.306563;
  flt_8B5A14 = flt_8B5994 + v8;
  flt_8B5A20 = (v8 - flt_8B5994) * 0.54119611;
  flt_8B5A18 = flt_8B5998 + flt_8B599C;
  flt_8B5A1C = (flt_8B599C - flt_8B5998) * 1.306563;
  flt_8B5924 = flt_8B59A8 + flt_8B59A4;
  flt_8B5928 = (flt_8B59A4 - flt_8B59A8) * 0.70710677;
  v12 = (flt_8B59B0 - flt_8B59AC) * 0.70710677;
  flt_8B5930 = v12;
  flt_8B592C = v12 + flt_8B59B0 + flt_8B59AC;
  flt_8B5938 = (flt_8B59B4 - flt_8B59B8) * 0.70710677;
  v13 = (flt_8B59C0 - flt_8B59BC) * 0.70710677;
  flt_8B5940 = v13;
  flt_8B593C = v13 + flt_8B59C0 + flt_8B59BC;
  flt_8B5934 = flt_8B593C + flt_8B59B8 + flt_8B59B4;
  flt_8B593C = flt_8B593C + flt_8B5938;
  flt_8B5938 = flt_8B5940 + flt_8B5938;
  flt_8B5944 = flt_8B59C4 + flt_8B59C8;
  flt_8B5948 = (flt_8B59C4 - flt_8B59C8) * 0.70710677;
  v14 = (flt_8B59D0 - flt_8B59CC) * 0.70710677;
  flt_8B5950 = v14;
  flt_8B594C = v14 + flt_8B59CC + flt_8B59D0;
  flt_8B5958 = (flt_8B59D4 - flt_8B59D8) * 0.70710677;
  v15 = (flt_8B59E0 - flt_8B59DC) * 0.70710677;
  flt_8B5960 = v15;
  flt_8B595C = v15 + flt_8B59DC + flt_8B59E0;
  flt_8B5954 = flt_8B595C + flt_8B59D4 + flt_8B59D8;
  flt_8B595C = flt_8B595C + flt_8B5958;
  flt_8B5958 = flt_8B5960 + flt_8B5958;
  flt_8B5964 = flt_8B59E8 + flt_8B59E4;
  flt_8B5968 = (flt_8B59E4 - flt_8B59E8) * 0.70710677;
  flt_8B5970 = (flt_8B59F0 - flt_8B59EC) * 0.70710677;
  flt_8B596C = flt_8B59F0 + flt_8B59EC + flt_8B5970;
  flt_8B5978 = (flt_8B59F4 - flt_8B59F8) * 0.70710677;
  flt_8B5980 = (flt_8B5A00 - flt_8B59FC) * 0.70710677;
  flt_8B597C = flt_8B5A00 + flt_8B59FC + flt_8B5980;
  flt_8B5974 = flt_8B59F8 + flt_8B59F4 + flt_8B597C;
  flt_8B597C = flt_8B5978 + flt_8B597C;
  flt_8B5978 = flt_8B5978 + flt_8B5980;
  flt_8B5984 = flt_8B5A04 + flt_8B5A08;
  flt_8B5988 = (flt_8B5A04 - flt_8B5A08) * 0.70710677;
  flt_8B5990 = (flt_8B5A10 - flt_8B5A0C) * 0.70710677;
  flt_8B598C = flt_8B5A0C + flt_8B5A10 + flt_8B5990;
  flt_8B5998 = (flt_8B5A14 - flt_8B5A18) * 0.70710677;
  flt_8B59A0 = (flt_8B5A20 - flt_8B5A1C) * 0.70710677;
  flt_8B599C = flt_8B5A1C + flt_8B5A20 + flt_8B59A0;
  flt_8B5994 = flt_8B5A14 + flt_8B5A18 + flt_8B599C;
  flt_8B599C = flt_8B5998 + flt_8B599C;
  flt_8B5998 = flt_8B5998 + flt_8B59A0;
  a1[256] = flt_8B5924;
  a1[192] = flt_8B5934;
  a1[128] = flt_8B592C;
  a1[64] = flt_8B593C;
  *a1 = flt_8B5928;
  *a2 = flt_8B5928;
  a2[64] = flt_8B5938;
  a2[128] = flt_8B5930;
  a2[192] = flt_8B5940;
  flt_8B5944 = flt_8B5954 + flt_8B5944;
  a1[224] = flt_8B5944;
  flt_8B5954 = flt_8B5954 + flt_8B594C;
  a1[160] = flt_8B5954;
  flt_8B594C = flt_8B595C + flt_8B594C;
  a1[96] = flt_8B594C;
  flt_8B595C = flt_8B595C + flt_8B5948;
  a1[32] = flt_8B595C;
  flt_8B5948 = flt_8B5958 + flt_8B5948;
  a2[32] = flt_8B5948;
  flt_8B5958 = flt_8B5958 + flt_8B5950;
  a2[96] = flt_8B5958;
  flt_8B5950 = flt_8B5960 + flt_8B5950;
  a2[160] = flt_8B5950;
  a2[224] = flt_8B5960;
  v16 = flt_8B5984 + flt_8B5994;
  flt_8B5984 = v16;
  a1[240] = v16 + flt_8B5964;
  a1[208] = flt_8B5984 + flt_8B5974;
  v17 = flt_8B598C + flt_8B5994;
  flt_8B5994 = v17;
  a1[176] = v17 + flt_8B5974;
  a1[144] = flt_8B5994 + flt_8B596C;
  v18 = flt_8B598C + flt_8B599C;
  flt_8B598C = v18;
  a1[112] = v18 + flt_8B596C;
  a1[80] = flt_8B598C + flt_8B597C;
  v19 = flt_8B5988 + flt_8B599C;
  flt_8B599C = v19;
  a1[48] = v19 + flt_8B597C;
  a1[16] = flt_8B599C + flt_8B5968;
  v20 = flt_8B5988 + flt_8B5998;
  flt_8B5988 = v20;
  a2[16] = v20 + flt_8B5968;
  a2[48] = flt_8B5988 + flt_8B5978;
  v21 = flt_8B5990 + flt_8B5998;
  flt_8B5998 = v21;
  a2[80] = v21 + flt_8B5978;
  a2[112] = flt_8B5998 + flt_8B5970;
  v22 = flt_8B5990 + flt_8B59A0;
  flt_8B5990 = v22;
  a2[144] = v22 + flt_8B5970;
  a2[176] = flt_8B5990 + flt_8B5980;
  a2[208] = flt_8B59A0 + flt_8B5980;
  result = LODWORD(flt_8B59A0);
  a2[240] = flt_8B59A0;
  return result;
}
