// Function: FUN_00438930 @ 00438930
// Size (bytes): 117


void __fastcall FUN_00438930(int param_1)

{
  int iVar1;
  double dVar2;
  
  iVar1 = *(int *)(param_1 + 0x15c);
  dVar2 = *(double *)(iVar1 + 0x1c) * *(double *)(iVar1 + 0x14c) +
          *(double *)(iVar1 + 0x34) * *(double *)(iVar1 + 0x154) +
          *(double *)(iVar1 + 0x4c) * *(double *)(iVar1 + 0x15c);
  *(double *)(iVar1 + 0x14c) = *(double *)(iVar1 + 0x14c) - dVar2 * *(double *)(iVar1 + 0x1c);
  *(double *)(iVar1 + 0x154) = *(double *)(iVar1 + 0x154) - dVar2 * *(double *)(iVar1 + 0x34);
  *(double *)(iVar1 + 0x15c) = *(double *)(iVar1 + 0x15c) - dVar2 * *(double *)(iVar1 + 0x4c);
  return;
}


