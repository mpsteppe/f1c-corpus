// Function: FUN_00465d70 @ 00465d70
// Size (bytes): 582


undefined4 * FUN_00465d70(undefined4 *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint *puVar8;
  undefined4 *local_10;
  undefined4 *local_8;
  
  iVar4 = 0;
  puVar6 = param_1;
  if (param_1 != (undefined4 *)0x0) {
    do {
      puVar6 = (undefined4 *)puVar6[1];
      iVar4 = iVar4 + 1;
    } while (puVar6 != (undefined4 *)0x0);
    if (1 < iVar4) {
      iVar4 = iVar4 / 2 + -1;
      puVar6 = param_1;
      if (0 < iVar4) {
        do {
          iVar4 = iVar4 + -1;
          puVar6 = (undefined4 *)puVar6[1];
        } while (iVar4 != 0);
      }
      uVar1 = puVar6[1];
      puVar6[1] = 0;
      puVar5 = (undefined4 *)FUN_00465d70(param_1);
      puVar6 = (undefined4 *)FUN_00465d70(uVar1);
      if (puVar5 == (undefined4 *)0x0) {
        return puVar6;
      }
      if (puVar6 == (undefined4 *)0x0) {
        return puVar5;
      }
      uVar2 = **(uint **)*puVar5;
      local_8 = (undefined4 *)0x0;
      puVar8 = (uint *)(DAT_007cd2ac + 0xe410);
      do {
        if ((uVar2 >> 0x1d == 4) && ((uVar7 = uVar2 >> 0x12 & 0x3f, uVar7 == 0 || (uVar7 == 1))))
        break;
        uVar7 = **(uint **)*puVar6 & 0xff;
        if ((uVar2 & 0xff) != 0xff) {
          if (uVar7 != 0xff) goto LAB_00465e4e;
LAB_00465e7b:
          puVar3 = (undefined4 *)puVar6[1];
          param_1 = puVar5;
          local_8 = puVar6;
          goto joined_r0x00465e90;
        }
        if (uVar7 != 0xff) break;
LAB_00465e4e:
        if (*puVar8 == (uVar2 & 0xff)) goto LAB_00465e7b;
        if (*puVar8 == uVar7) break;
        local_8 = (undefined4 *)((int)local_8 + 1);
        puVar8 = puVar8 + 1;
      } while ((int)local_8 < 0x68);
      puVar3 = puVar6;
      param_1 = (undefined4 *)puVar5[1];
      puVar6 = puVar5;
      local_8 = puVar5;
joined_r0x00465e90:
      do {
        if (param_1 == (undefined4 *)0x0) {
          if (puVar3 != (undefined4 *)0x0) {
            puVar6[1] = puVar3;
            return local_8;
          }
LAB_00465f7f:
          puVar6[1] = 0;
          return local_8;
        }
        if (puVar3 == (undefined4 *)0x0) {
          if (param_1 != (undefined4 *)0x0) {
            puVar6[1] = param_1;
            return local_8;
          }
          goto LAB_00465f7f;
        }
        uVar2 = **(uint **)*param_1;
        iVar4 = 0;
        puVar8 = (uint *)(DAT_007cd2ac + 0xe410);
        do {
          if ((uVar2 >> 0x1d == 4) && ((uVar7 = uVar2 >> 0x12 & 0x3f, uVar7 == 0 || (uVar7 == 1))))
          break;
          uVar7 = **(uint **)*puVar3 & 0xff;
          if ((uVar2 & 0xff) != 0xff) {
            if (uVar7 != 0xff) goto LAB_00465f03;
LAB_00465f23:
            local_10 = (undefined4 *)puVar3[1];
            puVar5 = puVar3;
            goto LAB_00465f2e;
          }
          if (uVar7 != 0xff) break;
LAB_00465f03:
          if (*puVar8 == (uVar2 & 0xff)) goto LAB_00465f23;
          if (*puVar8 == uVar7) break;
          iVar4 = iVar4 + 1;
          puVar8 = puVar8 + 1;
        } while (iVar4 < 0x68);
        puVar5 = param_1;
        param_1 = (undefined4 *)param_1[1];
        local_10 = puVar3;
LAB_00465f2e:
        puVar6[1] = puVar5;
        puVar3 = local_10;
        puVar6 = puVar5;
      } while( true );
    }
  }
  return param_1;
}


