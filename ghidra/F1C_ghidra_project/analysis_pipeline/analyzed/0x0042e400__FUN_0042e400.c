// Function: FUN_0042e400 @ 0042e400
// Size (bytes): 105


void __fastcall FUN_0042e400(int param_1)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *(undefined4 *)(param_1 + 0x1cbc) = 0x4392947b;
  *(undefined1 *)(param_1 + 0x1cb8) = 1;
  puVar1 = (undefined1 *)(param_1 + 0x1cd4);
  puVar3 = (undefined4 *)(param_1 + 0x1cec);
  puVar2 = (undefined4 *)(param_1 + 0x1cd8);
  do {
    puVar2[-5] = 0x4392947b;
    puVar1[-0x14] = 1;
    *puVar2 = 0;
    *puVar1 = 1;
    *puVar3 = 0x43b3ee14;
    puVar3[1] = 0x43b3ee14;
    puVar3[2] = 0x43b3ee14;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 3;
    puVar1[0x14] = 1;
    puVar1 = puVar1 + 1;
  } while ((int)(puVar1 + (-0x1cd4 - param_1)) < 4);
  return;
}


