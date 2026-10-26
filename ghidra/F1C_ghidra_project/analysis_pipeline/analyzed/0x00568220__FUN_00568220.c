// Function: FUN_00568220 @ 00568220
// Size (bytes): 244


int __thiscall FUN_00568220(int param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = -1;
  if (param_2 != 0) {
    puVar3 = *(undefined4 **)(param_1 + 0x24);
    *(undefined4 **)(param_1 + 0x2c) = puVar3;
    if ((puVar3 != (undefined4 *)0x0) &&
       (puVar3 = (undefined4 *)*puVar3, puVar3 != (undefined4 *)0x0)) {
      while( true ) {
        puVar2 = (undefined1 *)*puVar3;
        if (puVar2 == (undefined1 *)0x0) {
          puVar2 = &DAT_005ea438;
        }
        iVar1 = FUN_00588410(puVar2,param_2);
        if (iVar1 == 0) break;
        if (*(int *)(param_1 + 0x2c) != 0) {
          *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(*(int *)(param_1 + 0x2c) + 4);
        }
        if ((*(undefined4 **)(param_1 + 0x2c) == (undefined4 *)0x0) ||
           (puVar3 = (undefined4 *)**(undefined4 **)(param_1 + 0x2c), puVar3 == (undefined4 *)0x0))
        goto LAB_00568285;
      }
      if (puVar3[2] != -1) {
        return puVar3[2];
      }
    }
LAB_00568285:
    puVar3 = operator_new(0xc);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x34);
      *(int *)(param_1 + 0x34) = iVar1 + 1;
      *puVar3 = 0;
      puVar3[1] = 0xffffffff;
      FUN_00566650(param_2);
      puVar3[2] = iVar1;
    }
    if (puVar3 != (undefined4 *)0x0) {
      puVar4 = operator_new(0xc);
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        *puVar4 = puVar3;
        puVar4[1] = 0;
        *(undefined1 *)(puVar4 + 2) = 1;
      }
      if (*(int *)(param_1 + 0x24) == 0) {
        *(undefined4 **)(param_1 + 0x24) = puVar4;
        *(undefined4 **)(param_1 + 0x2c) = puVar4;
        *(undefined4 **)(param_1 + 0x28) = puVar4;
        *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
        return puVar3[2];
      }
      *(undefined4 **)(*(int *)(param_1 + 0x28) + 4) = puVar4;
      *(undefined4 **)(param_1 + 0x28) = puVar4;
      *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
    }
    iVar1 = puVar3[2];
  }
  return iVar1;
}


