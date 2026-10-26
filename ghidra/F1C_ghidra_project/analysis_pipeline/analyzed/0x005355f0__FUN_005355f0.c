// Function: FUN_005355f0 @ 005355f0
// Size (bytes): 39


void __fastcall FUN_005355f0(undefined4 param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = 4;
  do {
    FUN_00589898(param_2 & 0xff,param_1);
    param_2 = param_2 >> 8;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


