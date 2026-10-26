// Function: FUN_00464ef0 @ 00464ef0
// Size (bytes): 89


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00464ef0(int param_1)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  iVar1 = __ftol();
  iVar2 = 0x68;
  do {
    fVar3 = (float10)FUN_00464b10(iVar1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(float *)(param_1 + 0x68) = (float)(fVar3 - (float10)iVar1 * (float10)_DAT_0059f138);
  return;
}


