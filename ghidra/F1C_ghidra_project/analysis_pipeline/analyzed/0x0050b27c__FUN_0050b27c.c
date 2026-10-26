// Function: FUN_0050b27c @ 0050b27c
// Size (bytes): 257


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0050b27c(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = _DAT_0059e8d8;
  if ((*(int *)(param_1 + 4) != 0x32545844) && (*(int *)(param_1 + 4) != 0x33545844)) {
    uVar1 = DAT_0059fec8;
  }
  *(undefined4 *)(param_1 + 0x106c) = uVar1;
  *(float *)(param_1 + 0x1070) = 1.0 / *(float *)(param_1 + 0x106c);
  *(float *)(param_1 + 0x1c) =
       (float)(int)ROUND(*(float *)(param_1 + 0x1c) * _DAT_005accd0 + _DAT_0059e450) * _DAT_005accd4
  ;
  *(float *)(param_1 + 0x20) =
       (float)(int)ROUND(*(float *)(param_1 + 0x20) * _DAT_005accd8 + _DAT_0059e450) * _DAT_005accdc
  ;
  *(float *)(param_1 + 0x24) =
       (float)(int)ROUND(*(float *)(param_1 + 0x24) * _DAT_005accd0 + _DAT_0059e450) * _DAT_005accd4
  ;
  *(float *)(param_1 + 0x28) =
       (float)(int)ROUND(*(float *)(param_1 + 0x106c) * *(float *)(param_1 + 0x28) + _DAT_0059e450)
       * *(float *)(param_1 + 0x1070);
  return;
}


