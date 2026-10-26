// Function: FUN_0042ae20 @ 0042ae20
// Size (bytes): 54


void __thiscall FUN_0042ae20(int param_1,int param_2)

{
  int extraout_ECX;
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar1 = 0;
  if (param_2 == *(int *)(param_1 + 0x45fc)) {
    *(undefined4 *)(param_1 + 0x45fc) = 0;
    uVar2 = FUN_0042ad00(100);
    uVar1 = (undefined4)((ulonglong)uVar2 >> 0x20);
    param_2 = (int)uVar2;
    *(undefined4 *)(extraout_ECX + 0x4420) = uVar1;
    param_1 = extraout_ECX;
  }
  if (param_2 == *(int *)(param_1 + 0x45f8)) {
    *(undefined4 *)(param_1 + 0x45f8) = uVar1;
  }
  return;
}


