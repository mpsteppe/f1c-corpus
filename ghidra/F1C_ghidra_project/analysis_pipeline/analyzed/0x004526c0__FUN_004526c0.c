// Function: FUN_004526c0 @ 004526c0
// Size (bytes): 55


void __fastcall FUN_004526c0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0x414) = 0;
  piVar2 = (int *)(param_1 + 100);
  iVar3 = 10;
  do {
    piVar1 = (int *)*piVar2;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x2c))(piVar1);
      (**(code **)(*(int *)*piVar2 + 8))((int *)*piVar2);
      *piVar2 = 0;
    }
    piVar2 = piVar2 + 0x1a;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


