// Function: FUN_0059a8fa @ 0059a8fa
// Size (bytes): 78


void __fastcall FUN_0059a8fa(int param_1)

{
  uint uVar1;
  
  FUN_0059a54d();
  uVar1 = *(uint *)(param_1 + 0x24);
  while (uVar1 < 8) {
    if ((*(int *)(&DAT_008d4618 + *(int *)(param_1 + 0x24) * 4) == 0) ||
       (*(int *)(&DAT_008d4618 + *(int *)(param_1 + 0x24) * 4) == param_1)) break;
    uVar1 = *(int *)(param_1 + 0x24) + 1;
    *(uint *)(param_1 + 0x24) = uVar1;
  }
  *(int *)(&DAT_008d4618 + *(int *)(param_1 + 0x24) * 4) = param_1;
  (&DAT_008d463c)[*(int *)(param_1 + 0x24)] = (&DAT_008d463c)[*(int *)(param_1 + 0x24)] + '\x01';
  FUN_0059a5e9();
  return;
}


