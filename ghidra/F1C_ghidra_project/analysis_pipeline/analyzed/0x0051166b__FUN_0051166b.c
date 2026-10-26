// Function: FUN_0051166b @ 0051166b
// Size (bytes): 56


void FUN_0051166b(int *param_1)

{
  int *unaff_retaddr;
  undefined1 auStack_d0 [192];
  undefined4 uStack_10;
  int *piStack_c;
  
  piStack_c = (int *)0x511676;
  (**(code **)(*param_1 + 8))();
  piStack_c = param_1;
  uStack_10 = 0x51167c;
  FUN_00516959();
  piStack_c = (int *)0x511685;
  FUN_00589ca4();
  (**(code **)(*unaff_retaddr + 0xc))(unaff_retaddr,auStack_d0);
  return;
}


