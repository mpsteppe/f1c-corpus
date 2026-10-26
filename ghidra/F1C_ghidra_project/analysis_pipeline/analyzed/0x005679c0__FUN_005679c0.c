// Function: FUN_005679c0 @ 005679c0
// Size (bytes): 59


int __thiscall FUN_005679c0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 8);
  if (param_2 == 0) {
    return 0;
  }
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    uVar2 = FUN_00499e20();
    iVar3 = FUN_00588410(param_2,uVar2);
    if (iVar3 == 0) break;
    iVar1 = *(int *)(iVar1 + 4);
  }
  return iVar1;
}


