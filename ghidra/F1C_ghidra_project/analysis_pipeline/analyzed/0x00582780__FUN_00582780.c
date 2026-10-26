// Function: FUN_00582780 @ 00582780
// Size (bytes): 299


void __fastcall FUN_00582780(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int *local_14;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059ccf6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_14 = operator_new(4);
  puVar5 = (undefined4 *)0x0;
  local_4 = 0;
  if (local_14 == (int *)0x0) {
    local_14 = (int *)0x0;
  }
  else {
    puVar2 = operator_new(0x154);
    local_4 = CONCAT31(local_4._1_3_,1);
    if (puVar2 != (undefined4 *)0x0) {
      puVar5 = puVar2 + 1;
      *puVar2 = 4;
      FUN_0058a6eb(puVar5,0x54,4,FUN_00586700,FUN_005867b0);
    }
    *local_14 = (int)puVar5;
  }
  iVar4 = 0;
  local_4 = 0xffffffff;
  if (local_14 != (int *)0x0) {
    puVar5 = operator_new(0xc);
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      *puVar5 = local_14;
      puVar5[1] = 0;
      *(undefined1 *)(puVar5 + 2) = 1;
    }
    if (*param_1 == 0) {
      *param_1 = (int)puVar5;
      param_1[2] = (int)puVar5;
      param_1[1] = (int)puVar5;
      param_1[3] = param_1[3] + 1;
    }
    else {
      *(undefined4 **)(param_1[1] + 4) = puVar5;
      param_1[1] = (int)puVar5;
      param_1[3] = param_1[3] + 1;
    }
  }
  do {
    iVar1 = *local_14;
    if (iVar1 + iVar4 != 0) {
      piVar3 = operator_new(0xc);
      if (piVar3 == (int *)0x0) {
        piVar3 = (int *)0x0;
      }
      else {
        *piVar3 = iVar1 + iVar4;
        piVar3[1] = 0;
        *(undefined1 *)(piVar3 + 2) = 0;
      }
      if (param_1[4] == 0) {
        param_1[5] = (int)piVar3;
        param_1[6] = (int)piVar3;
      }
      else {
        piVar3[1] = param_1[4];
      }
      param_1[4] = (int)piVar3;
      param_1[7] = param_1[7] + 1;
    }
    iVar4 = iVar4 + 0x54;
  } while (iVar4 < 0x150);
  ExceptionList = local_c;
  return;
}


