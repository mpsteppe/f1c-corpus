// Function: FUN_0053ead0 @ 0053ead0
// Size (bytes): 157


void __fastcall FUN_0053ead0(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  FUN_0053f270(0);
  if (param_1[0x54b] != 0) {
    FUN_0053f6e0(param_1[0x54b]);
    iVar1 = param_1[0x54b];
    if (iVar1 != 0) {
      FUN_00557470();
      FUN_00587bcf(iVar1);
    }
    param_1[0x54b] = 0;
  }
  iVar1 = param_1[0x549];
  if (iVar1 != 0) {
    FUN_00557470();
    FUN_00587bcf(iVar1);
    param_1[0x549] = 0;
  }
  iVar1 = param_1[0x54a];
  if (iVar1 != 0) {
    FUN_00557470();
    FUN_00587bcf(iVar1);
    param_1[0x54a] = 0;
  }
  piVar2 = (int *)param_1[0x440];
  if (piVar2 != (int *)0x0) {
    uVar3 = (**(code **)(*piVar2 + 8))(piVar2);
    *param_1 = uVar3;
    param_1[0x440] = 0;
  }
  return;
}


