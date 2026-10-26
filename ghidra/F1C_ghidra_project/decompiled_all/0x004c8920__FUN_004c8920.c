// Function: FUN_004c8920 @ 004c8920
// Strings:  [Pit\pitSounds.mp3]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c8920(void)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int aiStack_214 [4];
  undefined1 uStack_204;
  undefined1 uStack_200;
  undefined4 uStack_1ff;
  
  if (DAT_008ac4cc != (int *)0x0) {
    aiStack_214[0] = (**(code **)(*DAT_008ac4cc + 8))();
    if (aiStack_214[0] == 0) {
      aiStack_214[1] = 0xffffffff;
      FUN_00566650(&DAT_005ea438);
      uStack_200 = DAT_005ea438;
      puVar3 = &uStack_1ff;
      for (iVar2 = 0x7f; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
      }
      *(undefined2 *)puVar3 = 0;
      *(undefined1 *)((int)puVar3 + 2) = 0;
      aiStack_214[2] = 0xffffffff;
      aiStack_214[3] = 0xffffffff;
      uStack_204 = 0;
      puVar1 = DAT_005ec3e0;
      if (DAT_005ec3e0 == (undefined1 *)0x0) {
        puVar1 = &DAT_005ea438;
      }
      FUN_0058815f(&uStack_200,&DAT_005be860,puVar1,s_Pit_pitSounds_mp3_005d336c);
      FUN_00566650(&uStack_200);
      iVar2 = 1;
      aiStack_214[2] = 0xffffffff;
      aiStack_214[3] = 0xffffffff;
      uStack_204 = 0;
      (**(code **)(*DAT_008ac4cc + 4))(aiStack_214,1,0);
      (**(code **)(*DAT_008ac4cc + 0x1c))(_DAT_007cf3a4 * DAT_007cf2cc);
      if (iVar2 != 0) {
        FUN_00587bcf(iVar2);
      }
    }
  }
  return;
}


