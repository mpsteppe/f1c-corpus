// Function: FUN_00497100 @ 00497100
// Size (bytes): 314


void __thiscall FUN_00497100(int param_1,char param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  
  if (param_2 != '\0') {
    FUN_004950e0();
    piVar3 = *(int **)(param_1 + 0x18bc);
    *(int **)(param_1 + 0x18c4) = piVar3;
    if ((piVar3 != (int *)0x0) && (piVar3 = (int *)*piVar3, piVar3 != (int *)0x0)) {
      while( true ) {
        (**(code **)(*piVar3 + 0x44))();
        if (*(int *)(param_1 + 0x18c4) == 0) break;
        puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x18c4) + 4);
        *(undefined4 **)(param_1 + 0x18c4) = puVar1;
        if ((puVar1 == (undefined4 *)0x0) || (piVar3 = (int *)*puVar1, piVar3 == (int *)0x0)) break;
      }
    }
    piVar3 = *(int **)(param_1 + 0x18bc);
    while (piVar3 != (int *)0x0) {
      piVar2 = (int *)piVar3[1];
      if (((char)piVar3[3] != '\0') && ((undefined4 *)*piVar3 != (undefined4 *)0x0)) {
        (*(code *)**(undefined4 **)*piVar3)(1);
      }
      FUN_00587bcf(piVar3);
      piVar3 = piVar2;
    }
    *(undefined4 *)(param_1 + 0x18bc) = 0;
    *(undefined4 *)(param_1 + 0x18c0) = 0;
    *(undefined4 *)(param_1 + 0x18c4) = 0;
    *(undefined4 *)(param_1 + 0x18c8) = 0;
    piVar3 = *(int **)(param_1 + 0x18cc);
    *(int **)(param_1 + 0x18d4) = piVar3;
    if ((piVar3 != (int *)0x0) && (piVar3 = (int *)*piVar3, piVar3 != (int *)0x0)) {
      while( true ) {
        (**(code **)(*piVar3 + 0x44))();
        if (*(int *)(param_1 + 0x18d4) == 0) break;
        puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x18d4) + 4);
        *(undefined4 **)(param_1 + 0x18d4) = puVar1;
        if ((puVar1 == (undefined4 *)0x0) || (piVar3 = (int *)*puVar1, piVar3 == (int *)0x0)) break;
      }
    }
    piVar3 = *(int **)(param_1 + 0x18cc);
    while (piVar3 != (int *)0x0) {
      piVar2 = (int *)piVar3[1];
      if (((char)piVar3[3] != '\0') && ((undefined4 *)*piVar3 != (undefined4 *)0x0)) {
        (*(code *)**(undefined4 **)*piVar3)(1);
      }
      FUN_00587bcf(piVar3);
      piVar3 = piVar2;
    }
    *(undefined4 *)(param_1 + 0x18cc) = 0;
    *(undefined4 *)(param_1 + 0x18d0) = 0;
    *(undefined4 *)(param_1 + 0x18d4) = 0;
    *(undefined4 *)(param_1 + 0x18d8) = 0;
    FUN_004f9b30(0);
  }
  FUN_00490920();
  FUN_004917c0();
  return;
}


