// Function: FUN_0041ef40 @ 0041ef40
// Size (bytes): 152


int __fastcall FUN_0041ef40(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == 0) {
    return param_2;
  }
  iVar3 = param_1;
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0x19c) <= *(int *)(param_1 + 0x19c)) {
      if (*(int *)(param_2 + 0x19c) < *(int *)(param_1 + 0x19c)) {
        return param_2;
      }
      iVar4 = 1;
      iVar3 = 0;
      if (0 < DAT_005c329c) {
        while( true ) {
          iVar1 = FUN_0041efe0();
          iVar2 = FUN_0041efe0();
          iVar3 = param_1;
          if (iVar2 < iVar1) break;
          iVar3 = FUN_0041efe0();
          iVar1 = FUN_0041efe0();
          if (iVar3 < iVar1) {
            return param_2;
          }
          if (iVar4 == DAT_005c329c) {
            return param_1;
          }
          iVar4 = iVar4 + 1;
          if (DAT_005c329c < iVar4) {
            return 0;
          }
        }
      }
    }
  }
  return iVar3;
}


