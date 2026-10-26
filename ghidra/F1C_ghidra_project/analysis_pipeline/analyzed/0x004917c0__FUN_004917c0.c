// Function: FUN_004917c0 @ 004917c0
// Size (bytes): 259


undefined4 __fastcall FUN_004917c0(int *param_1)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  
  cVar2 = FUN_004f9b20();
  if (cVar2 != '\0') {
    piVar3 = (int *)*param_1;
    piVar3[1] = (piVar3[1] + 1) % *piVar3;
  }
  FUN_004910d0(*param_1 + 0x1c);
  FUN_004910d0(*param_1 + 0x2c);
  iVar4 = *(int *)(*param_1 + 8);
  iVar6 = *(int *)(*param_1 + 4) * 0x10;
  piVar3 = *(int **)(iVar6 + iVar4);
  piVar7 = (int *)(iVar6 + iVar4);
  piVar7[2] = (int)piVar3;
  if ((piVar3 != (int *)0x0) && (iVar4 = *piVar3, iVar4 != 0)) {
    do {
      if (*(short *)(iVar4 + 8) < 3) {
        *(short *)(iVar4 + 8) = *(short *)(iVar4 + 8) + 1;
        piVar3 = (int *)0x0;
        if (piVar7[2] == 0) break;
        piVar3 = *(int **)(piVar7[2] + 4);
        piVar7[2] = (int)piVar3;
      }
      else {
        piVar3 = (int *)0x0;
        piVar5 = (int *)*piVar7;
        if ((int *)*piVar7 == (int *)0x0) {
LAB_00491891:
          FUN_00490aa0();
          piVar3 = (int *)piVar7[2];
        }
        else {
          do {
            if (*piVar5 == iVar4) {
              if (piVar5 == (int *)piVar7[2]) {
                piVar7[2] = piVar5[1];
              }
              if (piVar3 == (int *)0x0) {
                *piVar7 = piVar5[1];
              }
              else {
                piVar3[1] = piVar5[1];
              }
              if ((int *)piVar7[1] == piVar5) {
                piVar7[1] = (int)piVar3;
              }
              piVar7[3] = piVar7[3] + -1;
              if (((char)piVar5[2] != '\0') && (*piVar5 != 0)) {
                FUN_00587bcf(*piVar5);
              }
              FUN_00587bcf(piVar5);
              goto LAB_00491891;
            }
            piVar1 = piVar5 + 1;
            piVar3 = piVar5;
            piVar5 = (int *)*piVar1;
          } while ((int *)*piVar1 != (int *)0x0);
          FUN_00490aa0();
          piVar3 = (int *)piVar7[2];
        }
      }
      if ((piVar3 == (int *)0x0) || (iVar4 = *piVar3, iVar4 == 0)) break;
    } while( true );
  }
  return CONCAT31((int3)((uint)piVar3 >> 8),1);
}


