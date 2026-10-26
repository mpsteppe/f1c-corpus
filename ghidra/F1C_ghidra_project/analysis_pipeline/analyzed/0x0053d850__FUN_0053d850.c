// Function: FUN_0053d850 @ 0053d850
// Size (bytes): 40


undefined4 __fastcall FUN_0053d850(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  FUN_00540760();
  piVar1 = (int *)param_1[0x43f];
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 8))(piVar1);
    *param_1 = uVar2;
    param_1[0x43f] = 0;
  }
  return 0;
}


