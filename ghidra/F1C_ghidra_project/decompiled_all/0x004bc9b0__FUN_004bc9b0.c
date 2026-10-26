// Function: FUN_004bc9b0 @ 004bc9b0
// Strings:  [Jumped start, Jumped start, Not Lined Up Properly, Not Lined Up Properly, Not Lined Up Properly, Not Lined Up Properly]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_004bc9b0(int *param_1,char param_2,char param_3)

{
  char *pcVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 in_EAX;
  undefined2 extraout_var_00;
  undefined4 uVar5;
  uint uVar6;
  undefined3 uVar8;
  int iVar7;
  undefined3 extraout_var;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  undefined1 local_3c [12];
  undefined1 local_30 [20];
  float local_1c;
  float local_10;
  float local_4;
  
  iVar7 = *param_1;
  fVar2 = *(float *)(iVar7 + 0x3500) * *(float *)(iVar7 + 0x3500) +
          *(float *)(iVar7 + 0x34fc) * *(float *)(iVar7 + 0x34fc) +
          *(float *)(iVar7 + 0x34f8) * *(float *)(iVar7 + 0x34f8);
  if ((param_2 != '\0') ||
     (uVar6 = CONCAT22((short)((uint)in_EAX >> 0x10),
                       (ushort)(fVar2 < _DAT_0059e43c) << 8 |
                       (ushort)(NAN(fVar2) || NAN(_DAT_0059e43c)) << 10 |
                       (ushort)(fVar2 == _DAT_0059e43c) << 0xe),
     fVar2 < _DAT_0059e43c || (fVar2 == _DAT_0059e43c) != 0)) {
    FUN_004d10e0(iVar7,&local_48,local_3c);
    FUN_00566e40();
    FUN_004efb20(&local_54,local_30);
    local_54 = local_54 - local_48;
    local_50 = local_50 - local_44;
    local_4c = local_4c - local_40;
    fVar4 = local_54 * -local_1c + -local_10 * local_50 + -local_4 * local_4c;
    fVar3 = -*(float *)(iVar7 + 0x34c4) * -local_1c +
            -*(float *)(iVar7 + 0x34d0) * -local_10 + -*(float *)(iVar7 + 0x34dc) * -local_4;
    if (param_2 == '\0') {
      fVar2 = local_54 * local_54 + local_50 * local_50 + local_4c * local_4c;
      uVar5 = CONCAT22(extraout_var_00,
                       (ushort)(fVar2 < _DAT_005acd70) << 8 |
                       (ushort)(NAN(fVar2) || NAN(_DAT_005acd70)) << 10 |
                       (ushort)(fVar2 == _DAT_005acd70) << 0xe);
      if (((fVar2 < _DAT_005acd70 != 0 || (fVar2 == _DAT_005acd70) != 0) &&
          (uVar5 = CONCAT22(extraout_var_00,
                            (ushort)(fVar4 < _DAT_0059f124) << 8 |
                            (ushort)(NAN(fVar4) || NAN(_DAT_0059f124)) << 10 |
                            (ushort)(fVar4 == _DAT_0059f124) << 0xe),
          fVar4 < _DAT_0059f124 != 0 || (fVar4 == _DAT_0059f124) != 0)) &&
         (uVar5 = CONCAT22(extraout_var_00,
                           (ushort)(fVar3 < _DAT_0059e908) << 8 |
                           (ushort)(NAN(fVar3) || NAN(_DAT_0059e908)) << 10 |
                           (ushort)(fVar3 == _DAT_0059e908) << 0xe), fVar3 >= _DAT_0059e908))
      goto LAB_004bcbf7;
      uVar6 = CONCAT31((int3)((uint)uVar5 >> 8),param_3);
      if ((param_3 != '\0') &&
         (uVar6 = CONCAT22((short)((uint)uVar5 >> 0x10),
                           (ushort)(fVar2 < _DAT_0059e920) << 8 |
                           (ushort)(NAN(fVar2) || NAN(_DAT_0059e920)) << 10 |
                           (ushort)(fVar2 == _DAT_0059e920) << 0xe), fVar2 < _DAT_0059e920)) {
        iVar7 = FUN_00423a00(s_Not_Lined_Up_Properly_005d2598,&DAT_005ec4cc);
        if (iVar7 != 0) {
          iVar7 = 0;
          do {
            pcVar1 = s_Not_Lined_Up_Properly_005d2598 + iVar7;
            (&DAT_005ec4cc)[iVar7] = *pcVar1;
            iVar7 = iVar7 + 1;
          } while (*pcVar1 != '\0');
        }
        uVar6 = FUN_0045bd10(&DAT_005ec4cc,2,0x1020304);
        return uVar6 & 0xffffff00;
      }
    }
    else {
      if (((fVar2 <= _DAT_0059e43c) &&
          (local_54 * local_54 + local_50 * local_50 + local_4c * local_4c <= _DAT_005acd78)) &&
         ((fVar4 <= _DAT_0059e8a4 &&
          (uVar5 = CONCAT22(extraout_var_00,
                            (ushort)(fVar3 < _DAT_0059e7fc) << 8 |
                            (ushort)(NAN(fVar3) || NAN(_DAT_0059e7fc)) << 10 |
                            (ushort)(fVar3 == _DAT_0059e7fc) << 0xe), fVar3 >= _DAT_0059e7fc)))) {
LAB_004bcbf7:
        uVar8 = (undefined3)((uint)uVar5 >> 8);
        if (param_3 != '\0') {
          iVar7 = FUN_00423a00(s_Not_Lined_Up_Properly_005d2598,&DAT_005ec4cc);
          if (iVar7 != 0) {
            iVar7 = 0;
            do {
              pcVar1 = s_Not_Lined_Up_Properly_005d2598 + iVar7;
              (&DAT_005ec4cc)[iVar7] = *pcVar1;
              iVar7 = iVar7 + 1;
            } while (*pcVar1 != '\0');
          }
          FUN_0045bde0(&DAT_005ec4cc,0);
          uVar8 = extraout_var;
        }
        return CONCAT31(uVar8,1);
      }
      uVar6 = DAT_007cef84;
      if ((DAT_007cef84 != 0) && (*(int *)(iVar7 + 13000) != 1)) {
        if (local_54 * local_54 + local_50 * local_50 + local_4c * local_4c <= _DAT_005acd74) {
          uVar6 = FUN_004bbd60(s_Jumped_start_005c2700,10);
          return uVar6 & 0xffffff00;
        }
        uVar6 = FUN_004bc0e0(s_Jumped_start_005c2700);
        return uVar6 & 0xffffff00;
      }
    }
  }
  return uVar6 & 0xffffff00;
}


