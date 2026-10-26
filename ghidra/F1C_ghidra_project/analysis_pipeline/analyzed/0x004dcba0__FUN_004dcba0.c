// Function: FUN_004dcba0 @ 004dcba0
// Size (bytes): 231


int __thiscall
FUN_004dcba0(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,int param_10
            )

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int local_4;
  
  iVar3 = 0;
  local_4 = 0;
  FUN_004dcd10();
  if (param_3 == 0) {
LAB_004dcc0b:
    iVar2 = FUN_00553980(param_1,2,*(undefined4 *)(param_1 + 4),0x20,0xc0);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x14) = param_7;
      *(undefined4 *)(param_1 + 0x18) = param_8;
      *(undefined4 *)(param_1 + 0x1c) = param_2;
      FUN_004dcdd0(param_4,param_5,param_6,param_9);
      goto LAB_004dcc5f;
    }
  }
  else {
    if (param_10 != 0) {
      FUN_0053cbc0(&local_4,param_10);
    }
    pvVar1 = operator_new(0x60);
    if (pvVar1 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_0054fe10();
    }
    *(int *)(param_1 + 4) = iVar2;
    *(uint *)(iVar2 + 0x44) = *(uint *)(iVar2 + 0x44) | 1;
    iVar2 = FUN_00550080(param_3,0,0x804);
    if (iVar2 == 0) goto LAB_004dcc0b;
  }
  iVar3 = 1;
LAB_004dcc5f:
  if (local_4 != 0) {
    FUN_0053ce40(local_4);
  }
  if (iVar3 != 0) {
    FUN_004dcd10();
  }
  return iVar3;
}


