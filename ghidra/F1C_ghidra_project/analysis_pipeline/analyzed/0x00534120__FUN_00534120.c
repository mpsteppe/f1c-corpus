// Function: FUN_00534120 @ 00534120
// Size (bytes): 2444


void FUN_00534120(undefined2 *param_1,undefined2 *param_2,undefined8 *param_3)

{
  undefined2 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  short sVar6;
  short sVar12;
  short sVar13;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  short sVar14;
  short sVar18;
  short sVar19;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  short sVar20;
  short sVar23;
  short sVar24;
  undefined8 uVar21;
  undefined8 uVar22;
  short sVar25;
  short sVar28;
  short sVar29;
  undefined8 uVar26;
  undefined8 uVar27;
  
  uVar16 = DAT_008d7228;
  uVar8 = DAT_008d7220;
  uVar7 = param_3[7];
  uVar15 = param_3[6];
  uVar10 = param_3[5];
  uVar11 = param_3[4];
  uVar9 = *param_3;
  uVar17 = param_3[1];
  uVar4 = param_3[2];
  uVar5 = param_3[3];
  sVar6 = (short)((ulonglong)uVar7 >> 0x30);
  sVar12 = (short)((ulonglong)uVar7 >> 0x20);
  sVar13 = (short)((ulonglong)uVar7 >> 0x10);
  uVar2 = CONCAT26((short)((ulonglong)uVar9 >> 0x30) - (short)uVar7,
                   CONCAT24((short)((ulonglong)uVar9 >> 0x20) - sVar13,
                            CONCAT22((short)((ulonglong)uVar9 >> 0x10) - sVar12,(short)uVar9 - sVar6
                                    )));
  sVar14 = (short)((ulonglong)uVar15 >> 0x30);
  sVar18 = (short)((ulonglong)uVar15 >> 0x20);
  sVar19 = (short)((ulonglong)uVar15 >> 0x10);
  uVar3 = CONCAT26((short)((ulonglong)uVar17 >> 0x30) - (short)uVar15,
                   CONCAT24((short)((ulonglong)uVar17 >> 0x20) - sVar19,
                            CONCAT22((short)((ulonglong)uVar17 >> 0x10) - sVar18,
                                     (short)uVar17 - sVar14)));
  sVar20 = (short)((ulonglong)uVar10 >> 0x30);
  sVar23 = (short)((ulonglong)uVar10 >> 0x20);
  sVar24 = (short)((ulonglong)uVar10 >> 0x10);
  uVar4 = CONCAT26((short)((ulonglong)uVar4 >> 0x30) - (short)uVar10,
                   CONCAT24((short)((ulonglong)uVar4 >> 0x20) - sVar24,
                            CONCAT22((short)((ulonglong)uVar4 >> 0x10) - sVar23,
                                     (short)uVar4 - sVar20)));
  sVar25 = (short)((ulonglong)uVar11 >> 0x30);
  sVar28 = (short)((ulonglong)uVar11 >> 0x20);
  sVar29 = (short)((ulonglong)uVar11 >> 0x10);
  uVar5 = CONCAT26((short)((ulonglong)uVar5 >> 0x30) - (short)uVar11,
                   CONCAT24((short)((ulonglong)uVar5 >> 0x20) - sVar29,
                            CONCAT22((short)((ulonglong)uVar5 >> 0x10) - sVar28,
                                     (short)uVar5 - sVar25)));
  uVar9 = *param_3;
  uVar17 = param_3[1];
  uVar9 = CONCAT26((short)((ulonglong)uVar9 >> 0x30) + (short)uVar7,
                   CONCAT24((short)((ulonglong)uVar9 >> 0x20) + sVar13,
                            CONCAT22((short)((ulonglong)uVar9 >> 0x10) + sVar12,(short)uVar9 + sVar6
                                    )));
  uVar7 = param_3[2];
  uVar17 = CONCAT26((short)((ulonglong)uVar17 >> 0x30) + (short)uVar15,
                    CONCAT24((short)((ulonglong)uVar17 >> 0x20) + sVar19,
                             CONCAT22((short)((ulonglong)uVar17 >> 0x10) + sVar18,
                                      (short)uVar17 + sVar14)));
  uVar15 = param_3[3];
  uVar10 = CONCAT26((short)((ulonglong)uVar7 >> 0x30) + (short)uVar10,
                    CONCAT24((short)((ulonglong)uVar7 >> 0x20) + sVar24,
                             CONCAT22((short)((ulonglong)uVar7 >> 0x10) + sVar23,
                                      (short)uVar7 + sVar20)));
  uVar11 = CONCAT26((short)((ulonglong)uVar15 >> 0x30) + (short)uVar11,
                    CONCAT24((short)((ulonglong)uVar15 >> 0x20) + sVar29,
                             CONCAT22((short)((ulonglong)uVar15 >> 0x10) + sVar28,
                                      (short)uVar15 + sVar25)));
  uVar7 = pmaddwd(DAT_008d7200,uVar9);
  uVar15 = pmaddwd(DAT_008d7208,uVar17);
  uVar21 = pmaddwd(DAT_008d7210,uVar10);
  uVar26 = pmaddwd(DAT_008d7218,uVar11);
  param_1[0x100] =
       (short)((int)((ulonglong)uVar21 >> 0x20) + (int)((ulonglong)uVar7 >> 0x20) +
               (int)((ulonglong)uVar26 >> 0x20) + (int)((ulonglong)uVar15 >> 0x20) +
               (int)uVar21 + (int)uVar7 + (int)uVar26 + (int)uVar15 >> 0xe);
  uVar7 = DAT_008d7258;
  uVar15 = pmaddwd(uVar8,uVar9);
  uVar16 = pmaddwd(uVar16,uVar17);
  uVar26 = pmaddwd(DAT_008d7230,uVar10);
  uVar27 = pmaddwd(DAT_008d7238,uVar11);
  uVar8 = pmaddwd(DAT_008d7240,uVar9);
  uVar21 = pmaddwd(DAT_008d7248,uVar17);
  uVar22 = pmaddwd(DAT_008d7250,uVar10);
  param_1[0xe0] =
       (short)((int)((ulonglong)uVar26 >> 0x20) + (int)((ulonglong)uVar15 >> 0x20) +
               (int)((ulonglong)uVar27 >> 0x20) + (int)((ulonglong)uVar16 >> 0x20) +
               (int)uVar26 + (int)uVar15 + (int)uVar27 + (int)uVar16 >> 0xe);
  uVar15 = DAT_008d7278;
  uVar7 = pmaddwd(uVar7,uVar11);
  uVar16 = pmaddwd(DAT_008d7260,uVar9);
  uVar26 = pmaddwd(DAT_008d7268,uVar17);
  uVar27 = pmaddwd(DAT_008d7270,uVar10);
  param_1[0xc0] =
       (short)((int)((ulonglong)uVar22 >> 0x20) + (int)((ulonglong)uVar8 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar21 >> 0x20) +
               (int)uVar22 + (int)uVar8 + (int)uVar7 + (int)uVar21 >> 0xe);
  uVar7 = DAT_008d7298;
  uVar15 = pmaddwd(uVar15,uVar11);
  uVar8 = pmaddwd(DAT_008d7280,uVar9);
  uVar21 = pmaddwd(DAT_008d7288,uVar17);
  uVar22 = pmaddwd(DAT_008d7290,uVar10);
  param_1[0xa0] =
       (short)((int)((ulonglong)uVar27 >> 0x20) + (int)((ulonglong)uVar16 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar26 >> 0x20) +
               (int)uVar27 + (int)uVar16 + (int)uVar15 + (int)uVar26 >> 0xe);
  uVar15 = DAT_008d72b8;
  uVar7 = pmaddwd(uVar7,uVar11);
  uVar16 = pmaddwd(DAT_008d72a0,uVar9);
  uVar26 = pmaddwd(DAT_008d72a8,uVar17);
  uVar27 = pmaddwd(DAT_008d72b0,uVar10);
  param_1[0x80] =
       (short)((int)((ulonglong)uVar22 >> 0x20) + (int)((ulonglong)uVar8 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar21 >> 0x20) +
               (int)uVar22 + (int)uVar8 + (int)uVar7 + (int)uVar21 >> 0xe);
  uVar7 = DAT_008d72d8;
  uVar15 = pmaddwd(uVar15,uVar11);
  uVar8 = pmaddwd(DAT_008d72c0,uVar9);
  uVar21 = pmaddwd(DAT_008d72c8,uVar17);
  uVar22 = pmaddwd(DAT_008d72d0,uVar10);
  param_1[0x60] =
       (short)((int)((ulonglong)uVar27 >> 0x20) + (int)((ulonglong)uVar16 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar26 >> 0x20) +
               (int)uVar27 + (int)uVar16 + (int)uVar15 + (int)uVar26 >> 0xe);
  uVar15 = DAT_008d72f8;
  uVar7 = pmaddwd(uVar7,uVar11);
  uVar16 = pmaddwd(DAT_008d72e0,uVar9);
  uVar26 = pmaddwd(DAT_008d72e8,uVar17);
  uVar27 = pmaddwd(DAT_008d72f0,uVar10);
  param_1[0x40] =
       (short)((int)((ulonglong)uVar22 >> 0x20) + (int)((ulonglong)uVar8 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar21 >> 0x20) +
               (int)uVar22 + (int)uVar8 + (int)uVar7 + (int)uVar21 >> 0xe);
  uVar7 = DAT_008d7318;
  uVar15 = pmaddwd(uVar15,uVar11);
  uVar8 = pmaddwd(DAT_008d7300,uVar9);
  uVar21 = pmaddwd(DAT_008d7308,uVar17);
  uVar22 = pmaddwd(DAT_008d7310,uVar10);
  param_1[0x20] =
       (short)((int)((ulonglong)uVar27 >> 0x20) + (int)((ulonglong)uVar16 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar26 >> 0x20) +
               (int)uVar27 + (int)uVar16 + (int)uVar15 + (int)uVar26 >> 0xe);
  uVar15 = DAT_008d7338;
  uVar7 = pmaddwd(uVar7,uVar11);
  uVar16 = pmaddwd(DAT_008d7320,uVar9);
  uVar26 = pmaddwd(DAT_008d7328,uVar17);
  uVar27 = pmaddwd(DAT_008d7330,uVar10);
  uVar1 = (undefined2)
          ((int)((ulonglong)uVar22 >> 0x20) + (int)((ulonglong)uVar8 >> 0x20) +
           (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar21 >> 0x20) +
           (int)uVar22 + (int)uVar8 + (int)uVar7 + (int)uVar21 >> 0xe);
  *param_1 = uVar1;
  uVar15 = pmaddwd(uVar15,uVar11);
  *param_2 = uVar1;
  uVar7 = DAT_008d7358;
  uVar8 = pmaddwd(DAT_008d7340,uVar9);
  uVar21 = pmaddwd(DAT_008d7348,uVar17);
  uVar22 = pmaddwd(DAT_008d7350,uVar10);
  param_2[0x20] =
       (short)((int)((ulonglong)uVar27 >> 0x20) + (int)((ulonglong)uVar16 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar26 >> 0x20) +
               (int)uVar27 + (int)uVar16 + (int)uVar15 + (int)uVar26 >> 0xe);
  uVar15 = DAT_008d7378;
  uVar7 = pmaddwd(uVar7,uVar11);
  uVar16 = pmaddwd(DAT_008d7360,uVar9);
  uVar26 = pmaddwd(DAT_008d7368,uVar17);
  uVar27 = pmaddwd(DAT_008d7370,uVar10);
  param_2[0x40] =
       (short)((int)((ulonglong)uVar22 >> 0x20) + (int)((ulonglong)uVar8 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar21 >> 0x20) +
               (int)uVar22 + (int)uVar8 + (int)uVar7 + (int)uVar21 >> 0xe);
  uVar7 = DAT_008d7398;
  uVar15 = pmaddwd(uVar15,uVar11);
  uVar8 = pmaddwd(DAT_008d7380,uVar9);
  uVar21 = pmaddwd(DAT_008d7388,uVar17);
  uVar22 = pmaddwd(DAT_008d7390,uVar10);
  param_2[0x60] =
       (short)((int)((ulonglong)uVar27 >> 0x20) + (int)((ulonglong)uVar16 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar26 >> 0x20) +
               (int)uVar27 + (int)uVar16 + (int)uVar15 + (int)uVar26 >> 0xe);
  uVar15 = DAT_008d73b8;
  uVar7 = pmaddwd(uVar7,uVar11);
  uVar16 = pmaddwd(DAT_008d73a0,uVar9);
  uVar26 = pmaddwd(DAT_008d73a8,uVar17);
  uVar27 = pmaddwd(DAT_008d73b0,uVar10);
  param_2[0x80] =
       (short)((int)((ulonglong)uVar22 >> 0x20) + (int)((ulonglong)uVar8 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar21 >> 0x20) +
               (int)uVar22 + (int)uVar8 + (int)uVar7 + (int)uVar21 >> 0xe);
  uVar7 = DAT_008d73d8;
  uVar15 = pmaddwd(uVar15,uVar11);
  uVar8 = pmaddwd(DAT_008d73c0,uVar9);
  uVar21 = pmaddwd(DAT_008d73c8,uVar17);
  uVar22 = pmaddwd(DAT_008d73d0,uVar10);
  param_2[0xa0] =
       (short)((int)((ulonglong)uVar27 >> 0x20) + (int)((ulonglong)uVar16 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar26 >> 0x20) +
               (int)uVar27 + (int)uVar16 + (int)uVar15 + (int)uVar26 >> 0xe);
  uVar15 = DAT_008d73f8;
  uVar7 = pmaddwd(uVar7,uVar11);
  uVar9 = pmaddwd(DAT_008d73e0,uVar9);
  uVar17 = pmaddwd(DAT_008d73e8,uVar17);
  uVar16 = pmaddwd(DAT_008d73f0,uVar10);
  param_2[0xc0] =
       (short)((int)((ulonglong)uVar22 >> 0x20) + (int)((ulonglong)uVar8 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar21 >> 0x20) +
               (int)uVar22 + (int)uVar8 + (int)uVar7 + (int)uVar21 >> 0xe);
  uVar7 = DAT_008d7018;
  uVar15 = pmaddwd(uVar15,uVar11);
  uVar10 = pmaddwd(DAT_008d7000,uVar2);
  uVar8 = pmaddwd(DAT_008d7008,uVar3);
  uVar21 = pmaddwd(DAT_008d7010,uVar4);
  param_2[0xe0] =
       (short)((int)((ulonglong)uVar16 >> 0x20) + (int)((ulonglong)uVar9 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar17 >> 0x20) +
               (int)uVar16 + (int)uVar9 + (int)uVar15 + (int)uVar17 >> 0xe);
  uVar15 = DAT_008d7038;
  uVar7 = pmaddwd(uVar7,uVar5);
  uVar11 = pmaddwd(DAT_008d7020,uVar2);
  uVar9 = pmaddwd(DAT_008d7028,uVar3);
  uVar16 = pmaddwd(DAT_008d7030,uVar4);
  param_1[0xf0] =
       (short)((int)((ulonglong)uVar21 >> 0x20) + (int)((ulonglong)uVar10 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar8 >> 0x20) +
               (int)uVar21 + (int)uVar10 + (int)uVar7 + (int)uVar8 >> 0xe);
  uVar7 = DAT_008d7058;
  uVar15 = pmaddwd(uVar15,uVar5);
  uVar10 = pmaddwd(DAT_008d7040,uVar2);
  uVar17 = pmaddwd(DAT_008d7048,uVar3);
  uVar8 = pmaddwd(DAT_008d7050,uVar4);
  param_1[0xd0] =
       (short)((int)((ulonglong)uVar16 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar9 >> 0x20) +
               (int)uVar16 + (int)uVar11 + (int)uVar15 + (int)uVar9 >> 0xe);
  uVar15 = DAT_008d7078;
  uVar7 = pmaddwd(uVar7,uVar5);
  uVar11 = pmaddwd(DAT_008d7060,uVar2);
  uVar9 = pmaddwd(DAT_008d7068,uVar3);
  uVar16 = pmaddwd(DAT_008d7070,uVar4);
  param_1[0xb0] =
       (short)((int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar10 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar17 >> 0x20) +
               (int)uVar8 + (int)uVar10 + (int)uVar7 + (int)uVar17 >> 0xe);
  uVar7 = DAT_008d7098;
  uVar15 = pmaddwd(uVar15,uVar5);
  uVar10 = pmaddwd(DAT_008d7080,uVar2);
  uVar17 = pmaddwd(DAT_008d7088,uVar3);
  uVar8 = pmaddwd(DAT_008d7090,uVar4);
  param_1[0x90] =
       (short)((int)((ulonglong)uVar16 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar9 >> 0x20) +
               (int)uVar16 + (int)uVar11 + (int)uVar15 + (int)uVar9 >> 0xe);
  uVar15 = DAT_008d70b8;
  uVar7 = pmaddwd(uVar7,uVar5);
  uVar11 = pmaddwd(DAT_008d70a0,uVar2);
  uVar9 = pmaddwd(DAT_008d70a8,uVar3);
  uVar16 = pmaddwd(DAT_008d70b0,uVar4);
  param_1[0x70] =
       (short)((int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar10 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar17 >> 0x20) +
               (int)uVar8 + (int)uVar10 + (int)uVar7 + (int)uVar17 >> 0xe);
  uVar7 = DAT_008d70d8;
  uVar15 = pmaddwd(uVar15,uVar5);
  uVar10 = pmaddwd(DAT_008d70c0,uVar2);
  uVar17 = pmaddwd(DAT_008d70c8,uVar3);
  uVar8 = pmaddwd(DAT_008d70d0,uVar4);
  param_1[0x50] =
       (short)((int)((ulonglong)uVar16 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar9 >> 0x20) +
               (int)uVar16 + (int)uVar11 + (int)uVar15 + (int)uVar9 >> 0xe);
  uVar15 = DAT_008d70f8;
  uVar7 = pmaddwd(uVar7,uVar5);
  uVar11 = pmaddwd(DAT_008d70e0,uVar2);
  uVar9 = pmaddwd(DAT_008d70e8,uVar3);
  uVar16 = pmaddwd(DAT_008d70f0,uVar4);
  param_1[0x30] =
       (short)((int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar10 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar17 >> 0x20) +
               (int)uVar8 + (int)uVar10 + (int)uVar7 + (int)uVar17 >> 0xe);
  uVar7 = DAT_008d7118;
  uVar15 = pmaddwd(uVar15,uVar5);
  uVar10 = pmaddwd(DAT_008d7100,uVar2);
  uVar17 = pmaddwd(DAT_008d7108,uVar3);
  uVar8 = pmaddwd(DAT_008d7110,uVar4);
  param_1[0x10] =
       (short)((int)((ulonglong)uVar16 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar9 >> 0x20) +
               (int)uVar16 + (int)uVar11 + (int)uVar15 + (int)uVar9 >> 0xe);
  uVar15 = DAT_008d7138;
  uVar7 = pmaddwd(uVar7,uVar5);
  uVar11 = pmaddwd(DAT_008d7120,uVar2);
  uVar9 = pmaddwd(DAT_008d7128,uVar3);
  uVar16 = pmaddwd(DAT_008d7130,uVar4);
  param_2[0x10] =
       (short)((int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar10 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar17 >> 0x20) +
               (int)uVar8 + (int)uVar10 + (int)uVar7 + (int)uVar17 >> 0xe);
  uVar7 = DAT_008d7158;
  uVar15 = pmaddwd(uVar15,uVar5);
  uVar10 = pmaddwd(DAT_008d7140,uVar2);
  uVar17 = pmaddwd(DAT_008d7148,uVar3);
  uVar8 = pmaddwd(DAT_008d7150,uVar4);
  param_2[0x30] =
       (short)((int)((ulonglong)uVar16 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar9 >> 0x20) +
               (int)uVar16 + (int)uVar11 + (int)uVar15 + (int)uVar9 >> 0xe);
  uVar15 = DAT_008d7178;
  uVar7 = pmaddwd(uVar7,uVar5);
  uVar11 = pmaddwd(DAT_008d7160,uVar2);
  uVar9 = pmaddwd(DAT_008d7168,uVar3);
  uVar16 = pmaddwd(DAT_008d7170,uVar4);
  param_2[0x50] =
       (short)((int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar10 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar17 >> 0x20) +
               (int)uVar8 + (int)uVar10 + (int)uVar7 + (int)uVar17 >> 0xe);
  uVar7 = DAT_008d7198;
  uVar15 = pmaddwd(uVar15,uVar5);
  uVar10 = pmaddwd(DAT_008d7180,uVar2);
  uVar17 = pmaddwd(DAT_008d7188,uVar3);
  uVar8 = pmaddwd(DAT_008d7190,uVar4);
  param_2[0x70] =
       (short)((int)((ulonglong)uVar16 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar9 >> 0x20) +
               (int)uVar16 + (int)uVar11 + (int)uVar15 + (int)uVar9 >> 0xe);
  uVar15 = DAT_008d71b8;
  uVar7 = pmaddwd(uVar7,uVar5);
  uVar11 = pmaddwd(DAT_008d71a0,uVar2);
  uVar9 = pmaddwd(DAT_008d71a8,uVar3);
  uVar16 = pmaddwd(DAT_008d71b0,uVar4);
  param_2[0x90] =
       (short)((int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar10 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar17 >> 0x20) +
               (int)uVar8 + (int)uVar10 + (int)uVar7 + (int)uVar17 >> 0xe);
  uVar7 = DAT_008d71d8;
  uVar15 = pmaddwd(uVar15,uVar5);
  uVar10 = pmaddwd(DAT_008d71c0,uVar2);
  uVar17 = pmaddwd(DAT_008d71c8,uVar3);
  uVar8 = pmaddwd(DAT_008d71d0,uVar4);
  param_2[0xb0] =
       (short)((int)((ulonglong)uVar16 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar9 >> 0x20) +
               (int)uVar16 + (int)uVar11 + (int)uVar15 + (int)uVar9 >> 0xe);
  uVar15 = DAT_008d71f8;
  uVar16 = pmaddwd(uVar7,uVar5);
  uVar7 = pmaddwd(DAT_008d71e0,uVar2);
  uVar11 = pmaddwd(DAT_008d71e8,uVar3);
  uVar9 = pmaddwd(DAT_008d71f0,uVar4);
  param_2[0xd0] =
       (short)((int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar10 >> 0x20) +
               (int)((ulonglong)uVar16 >> 0x20) + (int)((ulonglong)uVar17 >> 0x20) +
               (int)uVar8 + (int)uVar10 + (int)uVar16 + (int)uVar17 >> 0xe);
  uVar15 = pmaddwd(uVar15,uVar5);
  param_2[0xf0] =
       (short)((int)((ulonglong)uVar9 >> 0x20) + (int)((ulonglong)uVar7 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
               (int)uVar9 + (int)uVar7 + (int)uVar15 + (int)uVar11 >> 0xe);
  return;
}


