// Function: FUN_00553d70 @ 00553d70
// Size (bytes): 54


void __fastcall
FUN_00553d70(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,undefined4 param_6)

{
  int iVar1;
  
  iVar1 = param_3;
  if (param_3 < param_2) {
    iVar1 = param_2;
    param_2 = param_3;
  }
  FUN_00561af8(param_2 * param_5 + param_1,(iVar1 - param_2) + 1,param_4,param_5,param_6);
  return;
}


