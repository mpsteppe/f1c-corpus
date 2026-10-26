// Function: FUN_0041ed20 @ 0041ed20
// Size (bytes): 14


undefined4 __fastcall FUN_0041ed20(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0xd8 + param_2 * 4);
  }
  return uVar1;
}


