// Function: FUN_0040be70 @ 0040be70
// Size (bytes): 337


undefined4 __fastcall FUN_0040be70(int param_1)

{
  char cVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  int local_4;
  
  uVar4 = 0;
  if ((*(char *)(param_1 + 0x24) == '\0') && (local_4 = 0, 0 < DAT_007cb218)) {
    puVar3 = &DAT_007cb21c;
    do {
      switch(*puVar3) {
      case 0x4a:
        FUN_0040d290(1);
        goto LAB_0040bf87;
      case 0x4e:
        FUN_0040d290(0);
        goto LAB_0040bf87;
      case 0x9c:
        FUN_0040d340();
LAB_0040bf87:
        uVar4 = 1;
        break;
      case 199:
        cVar1 = FUN_0040c720(4);
        if (cVar1 != '\0') {
          iVar2 = FUN_0040cde0(4,1);
joined_r0x0040bee8:
          if (iVar2 == 0) goto LAB_0040bf87;
        }
        break;
      case 0xc9:
        if ((((*(char *)(DAT_007c54e0 + 0x344c) == '\0') || (cVar1 = FUN_0040c720(3), cVar1 != '\0')
             ) && (iVar2 = FUN_0040cde0(3,1), iVar2 == 0)) || (DAT_007cfe88 != '\0'))
        goto LAB_0040bf87;
        break;
      case 0xd1:
        cVar1 = FUN_0040c720(5);
        if (cVar1 != '\0') {
          iVar2 = FUN_0040cde0(5,1);
          goto joined_r0x0040bee8;
        }
        break;
      case 0xd2:
        if (((*(int *)(param_1 + 8) != *(int *)(param_1 + 0x18)) ||
            (*(int *)(*(int *)(param_1 + 0x18) + 0x40) == 0)) &&
           (cVar1 = FUN_0040c720(0), cVar1 != '\0')) {
          iVar2 = FUN_0040cde0(0,1);
          goto joined_r0x0040bee8;
        }
      }
      local_4 = local_4 + 1;
      puVar3 = puVar3 + 1;
    } while (local_4 < DAT_007cb218);
  }
  if (*(char *)(param_1 + 0x2c) != '\0') {
    *(undefined1 *)(param_1 + 0x2c) = 0;
    return 1;
  }
  return uVar4;
}


