// Function: FUN_004a4710 @ 004a4710
// Size (bytes): 199


int __thiscall FUN_004a4710(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  float10 fVar4;
  float local_8;
  int local_4;
  
  local_8 = 99999.0;
  local_4 = 0;
  iVar2 = 0;
  if (*(int *)(param_1 + param_2 * 4) != 0) {
    piVar3 = &DAT_007c54f0;
    do {
      if (*(int *)(param_1 + -0x7c54f0 + (int)piVar3) == 0) {
        if (((*(int *)(*piVar3 + 13000) != 1) &&
            (fVar4 = (float10)FUN_00426cc0(*(undefined4 *)(*piVar3 + 0x3aa8)),
            fVar4 < (float10)local_8)) && ((float10)DAT_0059e440 < fVar4)) {
          local_4 = *piVar3;
          local_8 = (float)fVar4;
        }
      }
      else {
        uVar1 = FUN_0042add0();
        fVar4 = (float10)FUN_00426cc0(uVar1);
        if ((fVar4 < (float10)local_8) && ((float10)DAT_0059e440 < fVar4)) {
          local_4 = *(int *)(param_1 + -0x7c54f0 + (int)piVar3);
          local_8 = (float)fVar4;
        }
      }
      piVar3 = piVar3 + 1;
      iVar2 = local_4;
    } while ((int)piVar3 < 0x7c5690);
  }
  return iVar2;
}


