// Function: FUN_0051a4b7 @ 0051a4b7
// Size (bytes): 59


void FUN_0051a4b7(int param_1)

{
  int iVar1;
  char cVar2;
  
  iVar1 = *(int *)(param_1 + 0x184);
  if (*(int *)(iVar1 + 0x10) != 0) {
    if (*(char *)(param_1 + 0x49) != '\0') {
      cVar2 = FUN_00519eb7();
      if (cVar2 != '\0') {
        *(undefined1 **)(iVar1 + 0xc) = &LAB_00519f9a;
        goto LAB_0051a4e8;
      }
    }
    *(code **)(iVar1 + 0xc) = FUN_00519d51;
  }
LAB_0051a4e8:
  *(undefined4 *)(param_1 + 0x88) = 0;
  return;
}


