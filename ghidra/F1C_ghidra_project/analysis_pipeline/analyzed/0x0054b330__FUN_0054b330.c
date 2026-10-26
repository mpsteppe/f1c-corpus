// Function: FUN_0054b330 @ 0054b330
// Size (bytes): 122


void __thiscall FUN_0054b330(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  
  while( true ) {
    *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) & ~param_2;
    if ((param_3 != 0) && (iVar1 = *(int *)(param_1 + 0x204), iVar1 != 0)) {
      *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) & ~param_3;
      for (iVar1 = *(int *)(*(int *)(param_1 + 0x204) + 0x10); iVar1 != 0;
          iVar1 = *(int *)(iVar1 + 0x10)) {
        *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) & ~param_3;
      }
    }
    if (*(int *)(param_1 + 0x44) != 0) {
      FUN_0054b330(param_2,param_3,1);
    }
    if ((param_4 == 0) || (param_1 = *(int *)(param_1 + 0x4c), param_1 == 0)) break;
    param_4 = 1;
  }
  return;
}


