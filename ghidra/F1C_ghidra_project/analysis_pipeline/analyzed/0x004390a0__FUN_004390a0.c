// Function: FUN_004390a0 @ 004390a0
// Size (bytes): 357


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004390a0(int param_1)

{
  float fVar1;
  double dVar2;
  double *pdVar3;
  int iVar4;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  undefined1 local_2c [12];
  undefined1 local_20 [12];
  undefined1 local_14 [16];
  
  iVar4 = 4;
  pdVar3 = (double *)(param_1 + 0x138);
  dVar2 = _DAT_0059e430;
  do {
    iVar4 = iVar4 + -1;
    dVar2 = (double)*(int *)((int)pdVar3 + 0xc) * *pdVar3 + pdVar3[-1] + dVar2;
    pdVar3 = pdVar3 + 0x58;
  } while (iVar4 != 0);
  dVar2 = dVar2 * _DAT_0059eba0;
  FUN_004f3190((float)*(int *)(param_1 + 0xe04) * (float)*(double *)(param_1 + 0xdf8) +
               (float)*(double *)(param_1 + 0xdf0),local_34,&local_38);
  FUN_004f3190((float)*(int *)(param_1 + 0xe44) * (float)*(double *)(param_1 + 0xe38) +
               (float)*(double *)(param_1 + 0xe30),local_30,&local_3c);
  fVar1 = (float)dVar2;
  FUN_004f68b0((float)*(int *)(param_1 + 0x1284) * (float)*(double *)(param_1 + 0x1278) +
               (float)*(double *)(param_1 + 0x1270),fVar1,local_2c,&local_40);
  FUN_004f6950((float)*(int *)(param_1 + 0x12c4) * (float)*(double *)(param_1 + 0x12b8) +
               (float)*(double *)(param_1 + 0x12b0),local_20,&local_44);
  FUN_004f69e0((float)*(int *)(param_1 + 0x1344) * (float)*(double *)(param_1 + 0x1338) +
               (float)*(double *)(param_1 + 0x1330),
               (float)*(int *)(param_1 + 0x1304) * (float)*(double *)(param_1 + 0x12f8) +
               (float)*(double *)(param_1 + 0x12f0),fVar1,local_14,&local_48);
  FUN_004f6a50(fVar1,&local_4c);
  return (float10)local_4c + (float10)local_48 + (float10)local_44 + (float10)local_40 +
         (float10)local_3c + (float10)local_38;
}


