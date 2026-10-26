// Function: FUN_005469c0 @ 005469c0
// Size (bytes): 220


undefined4 __fastcall FUN_005469c0(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int local_4;
  
  if ((*(byte *)(param_1 + 0x9c) & 2) == 0) {
    iVar2 = *(int *)(param_1 + 0x88) + -1;
    *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + -1;
    *(int *)(param_1 + 0x88) = iVar2;
    if (iVar2 == 0) {
      local_4 = 0;
      if (0 < *(int *)(param_1 + 0xa4)) {
        piVar4 = (int *)(*(int *)(param_1 + 0xa8) + 0x8c);
        do {
          piVar3 = *(int **)(*(int *)(param_1 + 0xb8) + 0x28);
          if (piVar3 != (int *)0x0) {
            piVar1 = (int *)*piVar4;
            do {
              if (piVar3 == piVar1) {
                *piVar1 = *piVar1 + -1;
                if (*piVar1 == 0) {
                  iVar2 = 0;
                  if (0 < *(int *)(*piVar4 + 0x4c)) {
                    do {
                      FUN_005502c0();
                      iVar2 = iVar2 + 1;
                    } while (iVar2 < *(int *)(*piVar4 + 0x4c));
                  }
                  FUN_005478b0(*piVar4);
                  *piVar4 = 0;
                }
                break;
              }
              piVar3 = (int *)piVar3[0x17];
            } while (piVar3 != (int *)0x0);
          }
          piVar4 = piVar4 + 0x25;
          local_4 = local_4 + 1;
        } while (local_4 < *(int *)(param_1 + 0xa4));
      }
      *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) | 3;
      return 0;
    }
  }
  return 0xfffffffe;
}


