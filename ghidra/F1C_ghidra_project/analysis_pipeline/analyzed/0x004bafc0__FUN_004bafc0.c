// Function: FUN_004bafc0 @ 004bafc0
// Size (bytes): 241


void __fastcall FUN_004bafc0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int *local_4;
  
  local_4 = operator_new(4);
  if (local_4 == (int *)0x0) {
    local_4 = (int *)0x0;
  }
  else {
    puVar2 = operator_new(0x7f4);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 2;
      puVar2 = puVar2 + 1;
      iVar4 = 2;
      do {
        FUN_004b4f50();
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    *local_4 = (int)puVar2;
    puVar2 = operator_new(0xc);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = local_4;
      puVar2[1] = 0;
      *(undefined1 *)(puVar2 + 2) = 1;
    }
    if (*param_1 == 0) {
      *param_1 = (int)puVar2;
      param_1[2] = (int)puVar2;
    }
    else {
      *(undefined4 **)(param_1[1] + 4) = puVar2;
    }
    param_1[1] = (int)puVar2;
    param_1[3] = param_1[3] + 1;
  }
  iVar4 = 0;
  do {
    iVar1 = *local_4;
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
    iVar4 = iVar4 + 0x3f8;
  } while (iVar4 < 0x7f0);
  return;
}


