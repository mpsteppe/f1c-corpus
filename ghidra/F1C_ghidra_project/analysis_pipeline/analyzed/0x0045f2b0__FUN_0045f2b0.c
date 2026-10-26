// Function: FUN_0045f2b0 @ 0045f2b0
// Size (bytes): 224


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0045f2b0(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint local_1b0 [2];
  undefined1 local_1a8;
  char local_1a7;
  undefined4 local_1a6 [105];
  
  local_1a8 = (undefined1)DAT_007c56a4;
  if (DAT_007c56a4 == 7) {
    local_1a7 = *(char *)(param_1 + 0x3fd9);
    puVar4 = (undefined4 *)(param_1 + 0x3fda);
    puVar5 = local_1a6;
    for (uVar2 = (int)local_1a7 & 0x3fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    iVar3 = local_1a7 * 4 + 2;
  }
  else {
    local_1a7 = '\0';
    iVar3 = 1;
  }
  FUN_004b33b0(4,2,iVar3,0xff,(float)_DAT_008afea0,1);
  piVar1 = (int *)FUN_0057a680();
  if (param_2 == -1) {
    *(undefined1 *)(piVar1 + 1) = 1;
  }
  else {
    (**(code **)(*piVar1 + 0xc))(param_2);
  }
  FUN_0057a6a0(local_1b0,(local_1b0[0] >> 8 & 0x3ff) + 8,piVar1,1,1,0xffffffff,0);
  FUN_0057a690(piVar1);
  return;
}


