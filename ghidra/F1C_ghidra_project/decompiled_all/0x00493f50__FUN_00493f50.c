// Function: FUN_00493f50 @ 00493f50
// Strings:  [Log\osc.information, Log\osc.information, Log\osc.err, Log\osc.err]


void __fastcall FUN_00493f50(undefined4 *param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = "Log\\osc.information";
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  do {
    cVar1 = *pcVar2;
    *(char *)((int)(param_1 + -0x16b1e0) + (int)pcVar2) = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcVar2 = "Log\\osc.err";
  do {
    cVar1 = *pcVar2;
    *(char *)((int)(param_1 + -0x16b1c5) + (int)pcVar2) = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  param_1[99] = 0;
  param_1[100] = 0;
  param_1[0x65] = 0;
  param_1[0x67] = 0;
  *(undefined1 *)(param_1 + 0x66) = 0;
  *(undefined1 *)((int)param_1 + 0x199) = 0;
  *(undefined1 *)((int)param_1 + 0x19a) = 0;
  return;
}


