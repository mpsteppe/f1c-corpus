// Function: FUN_0054b2c0 @ 0054b2c0
// Size (bytes): 107


void __thiscall FUN_0054b2c0(int param_1,uint param_2,uint param_3,int param_4)

{
  uint *puVar1;
  int iVar2;
  
  while( true ) {
    *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | param_2;
    if ((param_3 != 0) && (*(int *)(param_1 + 0x204) != 0)) {
      puVar1 = (uint *)(*(int *)(param_1 + 0x204) + 0x14);
      *puVar1 = *puVar1 | param_3;
      for (iVar2 = *(int *)(*(int *)(param_1 + 0x204) + 0x10); iVar2 != 0;
          iVar2 = *(int *)(iVar2 + 0x10)) {
        *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) | param_3;
      }
    }
    if (*(int *)(param_1 + 0x44) != 0) {
      FUN_0054b2c0(param_2,param_3,1);
    }
    if ((param_4 == 0) || (param_1 = *(int *)(param_1 + 0x4c), param_1 == 0)) break;
    param_4 = 1;
  }
  return;
}


