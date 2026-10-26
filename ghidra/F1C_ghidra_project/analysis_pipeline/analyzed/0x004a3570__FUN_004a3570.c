// Function: FUN_004a3570 @ 004a3570
// Size (bytes): 128


void __thiscall FUN_004a3570(byte *param_1,float param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
  if (((*param_1 & 1) != 0) && (0 < *(int *)(param_1 + 8))) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 0xc)) {
      iVar3 = 0;
      do {
        *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x44 + iVar3) = 0xbf800000;
        FUN_004a2840(0);
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x78;
      } while (iVar2 < *(int *)(param_1 + 0xc));
    }
  }
  if ((*param_1 & 2) != 0) {
    fVar1 = *(float *)(param_1 + 4);
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 0xc)) {
      do {
        FUN_004a2840(param_2 - fVar1);
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(param_1 + 0xc));
    }
  }
  return;
}


