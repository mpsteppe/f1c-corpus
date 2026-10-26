// Function: FUN_0049a210 @ 0049a210
// Size (bytes): 64


int __thiscall FUN_0049a210(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 != 0) {
    iVar3 = *param_1;
    while (iVar3 != 0) {
      uVar1 = FUN_00499e20();
      iVar2 = FUN_00588410(param_2,uVar1);
      if (iVar2 == 0) {
        return iVar3;
      }
      iVar3 = FUN_00499e00();
    }
  }
  return 0;
}


