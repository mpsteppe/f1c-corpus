// Function: FUN_00543250 @ 00543250
// Size (bytes): 153


void __thiscall
FUN_00543250(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8,undefined4 param_9)

{
  uint *puVar1;
  int iVar2;
  
  if (param_5 < 0) {
    param_2 = param_2 - param_5;
  }
  if (param_6 < 0) {
    param_3 = param_3 - param_6;
  }
  FUN_00543540(&param_2,&param_3,&param_7,&param_8);
  iVar2 = param_4;
  FUN_00543540(&param_5,&param_6,&param_7,&param_8);
  if ((0 < param_7) && (0 < param_8)) {
    FUN_00540250(param_1,param_2,param_3,iVar2,param_5,param_6,param_7,param_8,param_9);
    puVar1 = (uint *)(iVar2 + 0x18);
    *puVar1 = *puVar1 & 0xfffffbff;
  }
  return;
}


