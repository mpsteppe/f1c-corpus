// Function: FUN_004b5380 @ 004b5380
// Size (bytes): 222


void __thiscall FUN_004b5380(int param_1,float param_2)

{
  int *piVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  
  *(float *)(param_1 + 0x30) = param_2;
  piVar1 = *(int **)(param_1 + 0x20);
  *(int **)(param_1 + 0x28) = piVar1;
  if ((piVar1 != (int *)0x0) && (iVar4 = *piVar1, iVar4 != 0)) {
    while( true ) {
      cVar2 = FUN_005001d0();
      cVar3 = FUN_005001f0();
      if ((cVar2 == '\0') ||
         (((cVar3 == '\0' ||
           (*(float *)(iVar4 + 0x1bc) < param_2 == (*(float *)(iVar4 + 0x1bc) == param_2))) ||
          (*(float *)(iVar4 + 0xc) < param_2)))) {
        if ((cVar3 == '\0') || (param_2 <= *(float *)(iVar4 + 0xc))) {
          if ((cVar2 == '\0') || (*(float *)(iVar4 + 0x1bc) <= param_2)) {
            FUN_00500170();
          }
          else {
            FUN_004b3a90(iVar4 + 0x1b8);
            FUN_00500190();
          }
        }
        else {
          FUN_004b3a90(iVar4 + 8);
          FUN_005001b0();
        }
      }
      if (*(int *)(param_1 + 0x28) == 0) break;
      piVar1 = *(int **)(*(int *)(param_1 + 0x28) + 4);
      *(int **)(param_1 + 0x28) = piVar1;
      if (piVar1 == (int *)0x0) {
        return;
      }
      iVar4 = *piVar1;
      if (iVar4 == 0) {
        return;
      }
    }
  }
  return;
}


