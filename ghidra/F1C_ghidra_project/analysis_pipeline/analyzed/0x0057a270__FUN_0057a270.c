// Function: FUN_0057a270 @ 0057a270
// Size (bytes): 178


void __thiscall FUN_0057a270(int param_1,int param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  
  iVar1 = param_2;
  FUN_0057a180(&param_2,param_1 + 4,4);
  FUN_0057a180(&param_2,param_1 + 8,0x20);
  FUN_0057a180(&param_2,param_1 + 0x28,1);
  FUN_0057a180(&param_2,param_1 + 0x29,1);
  FUN_0057a180(&param_2,param_1 + 0x2a,1);
  FUN_0057a180(&param_2,param_1 + 0x2b,1);
  FUN_0057a180(&param_2,(undefined1 *)(param_1 + 0x2c),1);
  FUN_0057a180(&param_2,param_1 + 0x2d,*(undefined1 *)(param_1 + 0x2c));
  *param_4 = param_2 - iVar1;
  return;
}


