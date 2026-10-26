// Function: FUN_004d23d0 @ 004d23d0
// Size (bytes): 120


void __thiscall FUN_004d23d0(int param_1,int param_2)

{
  float fVar1;
  int iVar2;
  
  *(undefined1 *)(param_1 + 0xc1) = 0;
  *(undefined4 *)(param_1 + 0xd8) = *(undefined4 *)(param_2 + 8);
  fVar1 = *(float *)(param_2 + 0xc);
  *(float *)(param_1 + 0xb0) = fVar1;
  *(undefined1 *)(param_1 + 0xc2) = 0;
  *(float *)(param_1 + 0xb4) = fVar1 + *(float *)(param_1 + 0xb8);
  FUN_0042d140(4);
  iVar2 = 0;
  if (0 < DAT_005c329c) {
    do {
      FUN_004bc2d0(*(undefined4 *)(param_1 + 0xb0));
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_005c329c);
  }
  return;
}


