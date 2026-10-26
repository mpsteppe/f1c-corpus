// Function: FUN_0045bc10 @ 0045bc10
// Size (bytes): 58


bool FUN_0045bc10(undefined1 *param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_1 == (undefined1 *)0x0) {
    param_1 = &DAT_005ea438;
  }
  iVar1 = FUN_0058969d(param_2,param_3,&DAT_005c5b60,param_1);
  *(undefined1 *)(param_2 + -1 + param_3) = 0;
  return -1 < iVar1;
}


