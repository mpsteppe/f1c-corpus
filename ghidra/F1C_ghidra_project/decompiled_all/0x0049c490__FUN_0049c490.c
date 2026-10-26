// Function: FUN_0049c490 @ 0049c490
// Strings:  [ --------,  --------]


undefined4 FUN_0049c490(int param_1)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = s__________005cce54;
  do {
    cVar1 = *pcVar2;
    pcVar2[param_1 + -0x5cce54] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if ((*(int *)(DAT_007c54e0 + 0x4064) == 0) && (*(int *)(DAT_007c54e0 + 0x40d4) != 0)) {
    FUN_0058815f(param_1,&DAT_005cce60,*(int *)(DAT_007c54e0 + 0x40d4) + 0x46f8);
  }
  return 0;
}


