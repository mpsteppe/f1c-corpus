// Function: FUN_0045b430 @ 0045b430
// Size (bytes): 69


void __thiscall FUN_0045b430(int param_1,int param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  
  puVar1 = (undefined1 *)(param_2 * 0x5c + 0x3c + param_1);
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 0x50) = 0xffffffff;
  *(undefined4 *)(puVar1 + 0x54) = 0xbf800000;
  *(undefined4 *)(puVar1 + 0x58) = 3;
  if (param_2 == *(int *)(param_1 + 0x31c)) {
    uVar2 = *(int *)(param_1 + 0x31c) + 1U & 0x80000007;
    if ((int)uVar2 < 0) {
      uVar2 = (uVar2 - 1 | 0xfffffff8) + 1;
    }
    *(uint *)(param_1 + 0x31c) = uVar2;
  }
  return;
}


