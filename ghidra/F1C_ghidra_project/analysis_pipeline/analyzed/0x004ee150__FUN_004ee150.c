// Function: FUN_004ee150 @ 004ee150
// Size (bytes): 211


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004ee150(int param_1,int param_2)

{
  double dVar1;
  double dVar2;
  float *pfVar3;
  int iVar4;
  float10 fVar5;
  
  pfVar3 = (float *)(param_1 + 0x3d64);
  *pfVar3 = 3.4028235e+38;
  *(undefined4 *)(param_1 + 0x3d68) = 0x7f7fffff;
  *(undefined4 *)(param_1 + 0x3d6c) = 0x7f7fffff;
  *(undefined4 *)(param_1 + 0x3d70) = 0x7f7fffff;
  if ((0 < DAT_007cea5c) && (DAT_007cea5c < 3)) {
    FUN_0053ac70(2,0);
    iVar4 = 4;
    do {
      dVar1 = *(double *)(param_2 + 0x1330) * _DAT_0059e7e0;
      dVar2 = *(double *)(param_2 + 0x1338) * _DAT_0059e7e0;
      fVar5 = (float10)FUN_004b3ce0();
      fVar5 = fVar5 * (float10)dVar2 + (float10)dVar1;
      if ((DAT_007c56a4 == 7) && (DAT_007cea5c == 2)) {
        fVar5 = fVar5 / (float10)_DAT_008acf9c;
      }
      if (fVar5 <= (float10)_DAT_005ad208) {
        *pfVar3 = (float)fVar5;
      }
      else {
        *pfVar3 = 3.4028235e+38;
      }
      pfVar3 = pfVar3 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    FUN_0053ac70(1,0);
  }
  return;
}


