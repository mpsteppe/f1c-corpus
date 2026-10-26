// Function: FUN_0055fbe0 @ 0055fbe0
// Strings:  [CUBEMAS4.10, CUBEMAS4.10]


int __fastcall FUN_0055fbe0(int param_1)

{
  char cVar1;
  char *pcVar2;
  
  FUN_0053c2a0();
  pcVar2 = s_CUBEMAS4_10_005dbc08;
  do {
    cVar1 = *pcVar2;
    pcVar2[param_1 + -0x5dbc08] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  *(undefined4 *)(param_1 + 0x114) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined1 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(undefined4 *)(param_1 + 0x120) = 0;
  *(undefined4 *)(param_1 + 0x124) = 0;
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  *(undefined4 *)(param_1 + 0x130) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return param_1;
}


