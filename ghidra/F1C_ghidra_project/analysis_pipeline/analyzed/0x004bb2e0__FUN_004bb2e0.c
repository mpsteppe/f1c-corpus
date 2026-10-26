// Function: FUN_004bb2e0 @ 004bb2e0
// Size (bytes): 229


undefined4 * FUN_004bb2e0(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  iVar3 = 0;
  puVar5 = param_1;
  if (param_1 != (undefined4 *)0x0) {
    do {
      puVar5 = (undefined4 *)puVar5[1];
      iVar3 = iVar3 + 1;
    } while (puVar5 != (undefined4 *)0x0);
    if (1 < iVar3) {
      iVar3 = iVar3 / 2 + -1;
      puVar5 = param_1;
      if (0 < iVar3) {
        do {
          iVar3 = iVar3 + -1;
          puVar5 = (undefined4 *)puVar5[1];
        } while (iVar3 != 0);
      }
      uVar1 = puVar5[1];
      puVar5[1] = 0;
      puVar4 = (undefined4 *)FUN_004bb2e0(param_1);
      puVar5 = (undefined4 *)FUN_004bb2e0(uVar1);
      param_1 = puVar5;
      if ((puVar4 != (undefined4 *)0x0) && (param_1 = puVar4, puVar5 != (undefined4 *)0x0)) {
        if (*(float *)*puVar5 <= *(float *)*puVar4) {
          puVar2 = (undefined4 *)puVar5[1];
          puVar8 = puVar4;
          puVar4 = puVar5;
        }
        else {
          puVar2 = puVar5;
          puVar8 = (undefined4 *)puVar4[1];
          puVar5 = puVar4;
        }
        do {
          if (puVar8 == (undefined4 *)0x0) {
            if (puVar2 != (undefined4 *)0x0) {
              puVar5[1] = puVar2;
              return puVar4;
            }
LAB_004bb3ac:
            puVar5[1] = 0;
            return puVar4;
          }
          if (puVar2 == (undefined4 *)0x0) {
            if (puVar8 != (undefined4 *)0x0) {
              puVar5[1] = puVar8;
              return puVar4;
            }
            goto LAB_004bb3ac;
          }
          if (*(float *)*puVar2 <= *(float *)*puVar8) {
            puVar7 = (undefined4 *)puVar2[1];
            puVar6 = puVar2;
          }
          else {
            puVar6 = puVar8;
            puVar7 = puVar2;
            puVar8 = (undefined4 *)puVar8[1];
          }
          puVar5[1] = puVar6;
          puVar2 = puVar7;
          puVar5 = puVar6;
        } while( true );
      }
    }
  }
  return param_1;
}


