// Function: FUN_004ce380 @ 004ce380
// Size (bytes): 84


uint __thiscall FUN_004ce380(int param_1,int param_2)

{
  float fVar1;
  int iVar2;
  uint in_EAX;
  int *piVar3;
  int iVar4;
  ushort uVar5;
  
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x3c)) {
    piVar3 = (int *)(param_1 + 0x40);
    do {
      iVar2 = *(int *)(*piVar3 + 4);
      if (iVar2 == 0) {
        fVar1 = *(float *)(param_2 + 0x2c);
LAB_004ce3b1:
        uVar5 = (ushort)(fVar1 < DAT_0059e440) << 8 |
                (ushort)(NAN(fVar1) || NAN(DAT_0059e440)) << 10 |
                (ushort)(fVar1 == DAT_0059e440) << 0xe;
        in_EAX = (uint)uVar5;
        if (fVar1 != DAT_0059e440) {
          return CONCAT31((uint3)(byte)(uVar5 >> 8),1);
        }
      }
      else {
        if (iVar2 == 1) {
          fVar1 = *(float *)(param_2 + 0x28);
          goto LAB_004ce3b1;
        }
        in_EAX = iVar2 - 5;
        if (in_EAX == 0) {
          fVar1 = *(float *)(param_2 + 0x30);
          goto LAB_004ce3b1;
        }
      }
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x3c));
  }
  return in_EAX & 0xffffff00;
}


