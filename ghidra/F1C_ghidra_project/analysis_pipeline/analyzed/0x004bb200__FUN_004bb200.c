// Function: FUN_004bb200 @ 004bb200
// Size (bytes): 222


void __fastcall FUN_004bb200(int *param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int *local_4;
  
  local_4 = operator_new(4);
  if (local_4 == (int *)0x0) {
    local_4 = (int *)0x0;
  }
  else {
    pvVar2 = operator_new(0x180);
    if (pvVar2 == (void *)0x0) {
      pvVar2 = (void *)0x0;
    }
    else {
      iVar5 = 0x20;
      do {
        FUN_004b4450();
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    *local_4 = (int)pvVar2;
    puVar3 = operator_new(0xc);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      *puVar3 = local_4;
      puVar3[1] = 0;
      *(undefined1 *)(puVar3 + 2) = 1;
    }
    if (*param_1 == 0) {
      *param_1 = (int)puVar3;
      param_1[2] = (int)puVar3;
    }
    else {
      *(undefined4 **)(param_1[1] + 4) = puVar3;
    }
    param_1[1] = (int)puVar3;
    param_1[3] = param_1[3] + 1;
  }
  iVar5 = 0;
  do {
    iVar1 = *local_4;
    if (iVar1 + iVar5 != 0) {
      piVar4 = operator_new(0xc);
      if (piVar4 == (int *)0x0) {
        piVar4 = (int *)0x0;
      }
      else {
        *piVar4 = iVar1 + iVar5;
        piVar4[1] = 0;
        *(undefined1 *)(piVar4 + 2) = 0;
      }
      if (param_1[4] == 0) {
        param_1[5] = (int)piVar4;
        param_1[6] = (int)piVar4;
      }
      else {
        piVar4[1] = param_1[4];
      }
      param_1[4] = (int)piVar4;
      param_1[7] = param_1[7] + 1;
    }
    iVar5 = iVar5 + 0xc;
  } while (iVar5 < 0x180);
  return;
}


