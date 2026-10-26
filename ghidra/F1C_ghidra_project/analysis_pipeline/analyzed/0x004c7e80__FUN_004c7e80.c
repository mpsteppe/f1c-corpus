// Function: FUN_004c7e80 @ 004c7e80
// Size (bytes): 166


void __fastcall FUN_004c7e80(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if (puVar1 != (undefined4 *)0x0) {
    piVar3 = (int *)*puVar1;
    while (piVar3 != (int *)0x0) {
      piVar2 = (int *)piVar3[1];
      if (((char)piVar3[2] != '\0') && ((undefined4 *)*piVar3 != (undefined4 *)0x0)) {
        (*(code *)**(undefined4 **)*piVar3)(1);
      }
      FUN_00587bcf(piVar3);
      piVar3 = piVar2;
    }
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1 = *(undefined4 **)(param_1 + 0xc);
    if (puVar1 != (undefined4 *)0x0) {
      piVar3 = (int *)*puVar1;
      while (piVar3 != (int *)0x0) {
        piVar2 = (int *)piVar3[1];
        if (((char)piVar3[2] != '\0') && ((undefined4 *)*piVar3 != (undefined4 *)0x0)) {
          (*(code *)**(undefined4 **)*piVar3)(1);
        }
        FUN_00587bcf(piVar3);
        piVar3 = piVar2;
      }
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = 0;
      FUN_00587bcf(puVar1);
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return;
}


