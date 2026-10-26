// Function: FUN_004a3320 @ 004a3320
// Size (bytes): 105


void __thiscall FUN_004a3320(int param_1,undefined4 *param_2)

{
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  if (*(int *)(param_1 + 0x14) != 0) {
    FUN_00566e40();
    FUN_00567400(0x40490fdb,&local_30);
    FUN_0054b3b0(*param_2,param_2[1],param_2[2]);
    FUN_0054b450(local_30,local_2c,local_28);
    *(undefined4 *)(param_1 + 8) = 2;
  }
  return;
}


