// Function: FUN_004979f0 @ 004979f0
// Size (bytes): 217


undefined4 __thiscall FUN_004979f0(int param_1,undefined4 param_2)

{
  undefined1 *puVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  undefined4 local_204;
  undefined1 local_200 [512];
  
  local_200[0] = 0;
  puVar1 = DAT_005ec408;
  if (DAT_005ec408 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  FUN_0058815f(local_200,&DAT_005be860,puVar1,param_2);
  iVar2 = FUN_00494fe0(local_200,&local_204);
  if (iVar2 == 0) {
    pvVar3 = operator_new(0xc);
    if (pvVar3 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_00499ab0(param_2,local_204);
    }
    if (iVar2 != 0) {
      piVar4 = operator_new(0xc);
      if (piVar4 == (int *)0x0) {
        piVar4 = (int *)0x0;
      }
      else {
        *piVar4 = iVar2;
        piVar4[1] = 0;
        *(undefined1 *)(piVar4 + 2) = 1;
      }
      if (*(int *)(param_1 + 0xf0) == 0) {
        *(int **)(param_1 + 0xf0) = piVar4;
        *(int **)(param_1 + 0xf8) = piVar4;
      }
      else {
        *(int **)(*(int *)(param_1 + 0xf4) + 4) = piVar4;
      }
      *(int **)(param_1 + 0xf4) = piVar4;
      *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
    }
    return 1;
  }
  return 0;
}


