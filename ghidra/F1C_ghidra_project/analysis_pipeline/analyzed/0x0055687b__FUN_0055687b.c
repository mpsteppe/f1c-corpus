// Function: FUN_0055687b @ 0055687b
// Size (bytes): 27


undefined8 __fastcall
FUN_0055687b(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined8 uVar1;
  undefined4 in_EAX;
  
  uVar1 = rdtsc();
  *param_4 = (int)uVar1;
  *param_3 = (int)((ulonglong)uVar1 >> 0x20);
  return CONCAT44(param_2,in_EAX);
}


