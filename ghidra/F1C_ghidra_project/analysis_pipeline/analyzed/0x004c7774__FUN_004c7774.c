// Function: FUN_004c7774 @ 004c7774
// Size (bytes): 81


void FUN_004c7774(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int unaff_EBX;
  int unaff_EDI;
  float10 fVar3;
  
  *(byte *)(unaff_EBX + 0x1067) = (byte)((uint)*(undefined4 *)(unaff_EDI + 0x38) >> 0x19) & 1;
  uVar2 = FUN_004b2b00();
  FUN_004c7bf0(uVar2);
  uVar1 = FUN_004b2b80();
  *(undefined2 *)(unaff_EBX + 0x48b0) = uVar1;
  *(byte *)(unaff_EBX + 0x4024) = *(byte *)(unaff_EDI + 0x3b) & 1;
  fVar3 = (float10)FUN_004b2b40();
  *(float *)(unaff_EBX + 0x4028) = (float)fVar3;
  return;
}


