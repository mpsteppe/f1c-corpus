// Function: FUN_004caed0 @ 004caed0
// Size (bytes): 590


uint __thiscall FUN_004caed0(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar8;
  byte *pbVar6;
  uint uVar7;
  byte *pbVar9;
  bool bVar10;
  
  uVar7 = *(uint *)(param_1 + 4);
  if (uVar7 == *(uint *)(param_2 + 4)) {
    fVar1 = *(float *)(param_1 + 0xc);
    fVar2 = *(float *)(param_2 + 0xc);
    uVar8 = (undefined2)(uVar7 >> 0x10);
    uVar7 = CONCAT22(uVar8,(ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                           (ushort)(fVar1 == fVar2) << 0xe);
    if (fVar1 == fVar2) {
      fVar1 = *(float *)(param_1 + 0x10);
      fVar2 = *(float *)(param_2 + 0x10);
      uVar7 = CONCAT22(uVar8,(ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10
                             | (ushort)(fVar1 == fVar2) << 0xe);
      if (fVar1 == fVar2) {
        fVar1 = *(float *)(param_1 + 0x14);
        fVar2 = *(float *)(param_2 + 0x14);
        uVar7 = CONCAT22(uVar8,(ushort)(fVar1 < fVar2) << 8 |
                               (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                               (ushort)(fVar1 == fVar2) << 0xe);
        if (fVar1 == fVar2) {
          fVar1 = *(float *)(param_1 + 0x18);
          fVar2 = *(float *)(param_2 + 0x18);
          uVar7 = CONCAT22(uVar8,(ushort)(fVar1 < fVar2) << 8 |
                                 (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                                 (ushort)(fVar1 == fVar2) << 0xe);
          if (fVar1 == fVar2) {
            fVar1 = *(float *)(param_1 + 0x1c);
            fVar2 = *(float *)(param_2 + 0x1c);
            uVar7 = CONCAT22(uVar8,(ushort)(fVar1 < fVar2) << 8 |
                                   (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                                   (ushort)(fVar1 == fVar2) << 0xe);
            if (fVar1 == fVar2) {
              fVar1 = *(float *)(param_1 + 0x20);
              fVar2 = *(float *)(param_2 + 0x20);
              uVar7 = CONCAT22(uVar8,(ushort)(fVar1 < fVar2) << 8 |
                                     (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                                     (ushort)(fVar1 == fVar2) << 0xe);
              if (fVar1 == fVar2) {
                fVar1 = *(float *)(param_1 + 0x24);
                fVar2 = *(float *)(param_2 + 0x24);
                uVar7 = CONCAT22(uVar8,(ushort)(fVar1 < fVar2) << 8 |
                                       (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                                       (ushort)(fVar1 == fVar2) << 0xe);
                if (fVar1 == fVar2) {
                  fVar1 = *(float *)(param_1 + 0x28);
                  fVar2 = *(float *)(param_2 + 0x28);
                  uVar7 = CONCAT22(uVar8,(ushort)(fVar1 < fVar2) << 8 |
                                         (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                                         (ushort)(fVar1 == fVar2) << 0xe);
                  if (fVar1 == fVar2) {
                    fVar1 = *(float *)(param_1 + 0x2c);
                    fVar2 = *(float *)(param_2 + 0x2c);
                    uVar7 = CONCAT22(uVar8,(ushort)(fVar1 < fVar2) << 8 |
                                           (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                                           (ushort)(fVar1 == fVar2) << 0xe);
                    if (fVar1 == fVar2) {
                      fVar1 = *(float *)(param_1 + 0x44);
                      fVar2 = *(float *)(param_2 + 0x44);
                      uVar7 = CONCAT22(uVar8,(ushort)(fVar1 < fVar2) << 8 |
                                             (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                                             (ushort)(fVar1 == fVar2) << 0xe);
                      if (fVar1 == fVar2) {
                        fVar1 = *(float *)(param_1 + 0x48);
                        fVar2 = *(float *)(param_2 + 0x48);
                        uVar7 = CONCAT22(uVar8,(ushort)(fVar1 < fVar2) << 8 |
                                               (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                                               (ushort)(fVar1 == fVar2) << 0xe);
                        if (fVar1 == fVar2) {
                          fVar1 = *(float *)(param_1 + 0x4c);
                          fVar2 = *(float *)(param_2 + 0x4c);
                          uVar7 = CONCAT22(uVar8,(ushort)(fVar1 < fVar2) << 8 |
                                                 (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                                                 (ushort)(fVar1 == fVar2) << 0xe);
                          if (fVar1 == fVar2) {
                            fVar1 = *(float *)(param_1 + 0x30);
                            fVar2 = *(float *)(param_2 + 0x30);
                            uVar7 = CONCAT22(uVar8,(ushort)(fVar1 < fVar2) << 8 |
                                                   (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                                                   (ushort)(fVar1 == fVar2) << 0xe);
                            if (fVar1 == fVar2) {
                              fVar1 = *(float *)(param_1 + 0x34);
                              fVar2 = *(float *)(param_2 + 0x34);
                              uVar7 = CONCAT22(uVar8,(ushort)(fVar1 < fVar2) << 8 |
                                                     (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                                                     (ushort)(fVar1 == fVar2) << 0xe);
                              if (fVar1 == fVar2) {
                                fVar1 = *(float *)(param_1 + 0x38);
                                fVar2 = *(float *)(param_2 + 0x38);
                                uVar7 = CONCAT22(uVar8,(ushort)(fVar1 < fVar2) << 8 |
                                                       (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                                                       (ushort)(fVar1 == fVar2) << 0xe);
                                if (fVar1 == fVar2) {
                                  fVar1 = *(float *)(param_1 + 0x3c);
                                  fVar2 = *(float *)(param_2 + 0x3c);
                                  uVar7 = CONCAT22(uVar8,(ushort)(fVar1 < fVar2) << 8 |
                                                         (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                                                         (ushort)(fVar1 == fVar2) << 0xe);
                                  if (fVar1 == fVar2) {
                                    iVar4 = *(int *)(param_2 + 0x50);
                                    iVar5 = *(int *)(param_1 + 0x50);
                                    if (*(int *)(iVar5 + 0x20) == *(int *)(iVar4 + 0x20)) {
                                      pbVar9 = (byte *)(iVar4 + 0x38);
                                      pbVar6 = (byte *)(iVar5 + 0x38);
                                      do {
                                        bVar3 = *pbVar6;
                                        bVar10 = bVar3 < *pbVar9;
                                        if (bVar3 != *pbVar9) {
LAB_004cb034:
                                          uVar7 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
                                          goto LAB_004cb039;
                                        }
                                        if (bVar3 == 0) break;
                                        bVar3 = pbVar6[1];
                                        bVar10 = bVar3 < pbVar9[1];
                                        if (bVar3 != pbVar9[1]) goto LAB_004cb034;
                                        pbVar6 = pbVar6 + 2;
                                        pbVar9 = pbVar9 + 2;
                                      } while (bVar3 != 0);
                                      uVar7 = 0;
LAB_004cb039:
                                      if ((((uVar7 == 0) &&
                                           (uVar7 = *(uint *)(iVar5 + 0x58),
                                           uVar7 == *(uint *)(iVar4 + 0x58))) &&
                                          (*(int *)(iVar5 + 0x5c) == *(int *)(iVar4 + 0x5c))) &&
                                         (((uVar7 = *(uint *)(iVar5 + 0x60),
                                           uVar7 == *(uint *)(iVar4 + 0x60) &&
                                           (*(int *)(iVar5 + 100) == *(int *)(iVar4 + 100))) &&
                                          ((uVar7 = *(uint *)(iVar5 + 0x68),
                                           uVar7 == *(uint *)(iVar4 + 0x68) &&
                                           (*(int *)(iVar5 + 0x6c) == *(int *)(iVar4 + 0x6c))))))) {
                                        pbVar9 = (byte *)(iVar4 + 0x70);
                                        pbVar6 = (byte *)(iVar5 + 0x70);
                                        do {
                                          bVar3 = *pbVar6;
                                          bVar10 = bVar3 < *pbVar9;
                                          if (bVar3 != *pbVar9) {
LAB_004cb0b4:
                                            uVar7 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
                                            goto LAB_004cb0b9;
                                          }
                                          if (bVar3 == 0) break;
                                          bVar3 = pbVar6[1];
                                          bVar10 = bVar3 < pbVar9[1];
                                          if (bVar3 != pbVar9[1]) goto LAB_004cb0b4;
                                          pbVar6 = pbVar6 + 2;
                                          pbVar9 = pbVar9 + 2;
                                        } while (bVar3 != 0);
                                        uVar7 = 0;
LAB_004cb0b9:
                                        if (uVar7 == 0) {
                                          pbVar9 = (byte *)(iVar4 + 0x90);
                                          pbVar6 = (byte *)(iVar5 + 0x90);
                                          do {
                                            bVar3 = *pbVar6;
                                            bVar10 = bVar3 < *pbVar9;
                                            if (bVar3 != *pbVar9) {
LAB_004cb0f4:
                                              uVar7 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
                                              goto LAB_004cb0f9;
                                            }
                                            if (bVar3 == 0) break;
                                            bVar3 = pbVar6[1];
                                            bVar10 = bVar3 < pbVar9[1];
                                            if (bVar3 != pbVar9[1]) goto LAB_004cb0f4;
                                            pbVar6 = pbVar6 + 2;
                                            pbVar9 = pbVar9 + 2;
                                          } while (bVar3 != 0);
                                          uVar7 = 0;
LAB_004cb0f9:
                                          if (uVar7 == 0) {
                                            iVar4 = *(int *)(param_2 + 0x58);
                                            if (*(int *)(param_1 + 0x58) < iVar4) {
                                              *(int *)(param_1 + 0x58) = iVar4;
                                            }
                                            return CONCAT31((int3)((uint)iVar4 >> 8),1);
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return uVar7 & 0xffffff00;
}


