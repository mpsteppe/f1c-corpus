// Function: FUN_00516f76 @ 00516f76
// Size (bytes): 48


void FUN_00516f76(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x1c);
  *(undefined4 **)(param_1 + 0x17c) = puVar1;
  *(undefined1 *)(puVar1 + 2) = 0;
  *puVar1 = &LAB_00516e28;
  puVar1[1] = &LAB_00516f55;
  FUN_00516c7b();
  return;
}


