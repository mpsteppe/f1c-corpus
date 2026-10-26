// Function: FUN_00585270 @ 00585270
// Size (bytes): 174


undefined4 __thiscall FUN_00585270(int *param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  cVar1 = FUN_00586ca0();
  if (cVar1 != '\0') {
    uVar2 = FUN_00585380(param_2);
    return uVar2;
  }
  if ((char)(*(int **)(param_2 + 0x48))[1] == '\0') {
    iVar3 = (**(code **)(**(int **)(param_2 + 0x48) + 0x14))();
    iVar5 = 0;
    if (0 < iVar3) {
      do {
        uVar2 = (**(code **)(**(int **)(param_2 + 0x48) + 0x18))(iVar5);
        FUN_00584130(param_2,uVar2);
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar3);
    }
  }
  else {
    iVar3 = (**(code **)(*param_1 + 0xa4))();
    iVar5 = 0;
    if (0 < iVar3) {
      do {
        iVar4 = (**(code **)(*param_1 + 0xa8))(iVar5);
        if (iVar4 != 0) {
          uVar2 = FUN_005871f0();
          FUN_00584130(param_2,uVar2);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar3);
      (**(code **)(*param_1 + 0x5c))(param_2);
      return 1;
    }
  }
  (**(code **)(*param_1 + 0x5c))(param_2);
  return 1;
}


