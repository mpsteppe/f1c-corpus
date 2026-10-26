// Function: FUN_0058bdcd @ 0058bdcd
// Size (bytes): 97


int FUN_0058bdcd(undefined8 *param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined1 local_2c [24];
  int local_14 [4];
  
  FUN_00595621(*param_1,local_14,local_2c);
  FUN_005955aa((uint)(0 < param_3) + param_2 + (uint)(local_14[0] == 0x2d),param_3 + 1,local_14);
  FUN_0058be2e(param_2,param_3,param_4,local_14,0);
  return param_2;
}


