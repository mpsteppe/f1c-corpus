// Function: FUN_004add50 @ 004add50
// Strings:  [quickChatText.txt, quickChatText.txt]


void FUN_004add50(void)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  char *pcVar6;
  char local_200;
  undefined4 uStack_1ff;
  char local_100;
  undefined4 local_ff;
  
  local_200 = DAT_005ea438;
  puVar4 = &uStack_1ff;
  for (iVar3 = 0x3f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined2 *)puVar4 = 0;
  *(undefined1 *)((int)puVar4 + 2) = 0;
  local_100 = DAT_005ea438;
  puVar4 = &local_ff;
  for (iVar3 = 0x3f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined2 *)puVar4 = 0;
  *(undefined1 *)((int)puVar4 + 2) = 0;
  puVar2 = DAT_005ec440;
  if (DAT_005ec440 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_0058815f(&local_100,&DAT_005be860,puVar2,s_quickChatText_txt_005c5e60);
  FUN_004b0220(&local_200,0xee);
  iVar3 = -1;
  pcVar5 = &local_200;
  do {
    pcVar6 = pcVar5;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar6 = pcVar5 + 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
  } while (cVar1 != '\0');
  *(undefined4 *)(pcVar6 + -1) = s_quickChatText_txt_005c5e60._0_4_;
  *(undefined4 *)(pcVar6 + 3) = s_quickChatText_txt_005c5e60._4_4_;
  *(undefined4 *)(pcVar6 + 7) = s_quickChatText_txt_005c5e60._8_4_;
  *(undefined4 *)(pcVar6 + 0xb) = s_quickChatText_txt_005c5e60._12_4_;
  *(undefined2 *)(pcVar6 + 0xf) = s_quickChatText_txt_005c5e60._16_2_;
  CopyFileA(&local_100,&local_200,0);
  return;
}


