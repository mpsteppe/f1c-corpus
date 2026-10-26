// Function: FUN_00434d40 @ 00434d40
// Size (bytes): 27


undefined4 __fastcall FUN_00434d40(int param_1)

{
  if (*(undefined4 **)(param_1 + 0xc) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0xc))(1);
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return 0;
}


