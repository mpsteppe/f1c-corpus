// Function: FUN_005824f0 @ 005824f0
// Size (bytes): 349


int * __fastcall FUN_005824f0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int *local_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 local_4;
  undefined3 uStack_3;
  
  puStack_8 = &LAB_0059cca9;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  local_4 = 1;
  uStack_3 = 0;
  local_18 = operator_new(4);
  local_4 = 2;
  if (local_18 == (int *)0x0) {
    local_18 = (int *)0x0;
  }
  else {
    puVar2 = operator_new(0x284);
    local_4 = 3;
    if (puVar2 == (undefined4 *)0x0) {
      *local_18 = 0;
    }
    else {
      *puVar2 = 0x10;
      FUN_0058a6eb(puVar2 + 1,0x28,0x10,&LAB_0057aec0,FUN_0057aef0);
      *local_18 = (int)(puVar2 + 1);
    }
  }
  _local_4 = CONCAT31(uStack_3,1);
  if (local_18 != (int *)0x0) {
    puVar2 = operator_new(0xc);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = local_18;
      puVar2[1] = 0;
      *(undefined1 *)(puVar2 + 2) = 1;
    }
    if (*param_1 == 0) {
      *param_1 = (int)puVar2;
      param_1[2] = (int)puVar2;
      param_1[1] = (int)puVar2;
      iVar4 = 0;
      param_1[3] = param_1[3] + 1;
      goto LAB_005825f1;
    }
    *(undefined4 **)(param_1[1] + 4) = puVar2;
    param_1[1] = (int)puVar2;
    param_1[3] = param_1[3] + 1;
  }
  iVar4 = 0;
LAB_005825f1:
  do {
    iVar1 = *local_18;
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
    iVar4 = iVar4 + 0x28;
  } while (iVar4 < 0x280);
  ExceptionList = local_c;
  return param_1;
}


