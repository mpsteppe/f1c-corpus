// Function: FUN_004d7a50 @ 004d7a50
// Size (bytes): 70


undefined4 __thiscall FUN_004d7a50(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  if (*param_1 < param_2) {
    return 0;
  }
  do {
    iVar1 = param_3 + 1;
    param_3 = FUN_00587c20(iVar1,&DAT_005c2aac);
  } while (param_3 != 0);
  FUN_004d7aa0(param_1,s___12_12s_5d__005d4a38,iVar1,param_4);
  return 1;
}


