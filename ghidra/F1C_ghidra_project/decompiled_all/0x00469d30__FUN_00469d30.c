// Function: FUN_00469d30 @ 00469d30
// Strings:  [Experience (Laps):, Best Lap:, Circuit:]


undefined4 __fastcall FUN_00469d30(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x44);
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && (piVar2 = (int *)*piVar3, piVar2 != (int *)0x0)) {
      if (*piVar2 != 0) {
        FUN_00587bcf(*piVar2);
      }
      FUN_00587bcf(piVar2);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar1;
  }
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  FUN_00486f30(s_Circuit__005c6920,0xffffffff);
  FUN_00486f30(s_Experience__Laps___005c6900,0xffffffff);
  FUN_00486f30(s_Best_Lap__005c6914,0xffffffff);
  FUN_00489cb0();
  FUN_00469900();
  FUN_0048a3b0(0);
  return 0;
}


