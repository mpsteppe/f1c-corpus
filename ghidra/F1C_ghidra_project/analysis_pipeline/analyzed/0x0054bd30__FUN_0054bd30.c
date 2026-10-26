// Function: FUN_0054bd30 @ 0054bd30
// Size (bytes): 104


void __fastcall FUN_0054bd30(int param_1)

{
  int iVar1;
  
  do {
    for (iVar1 = *(int *)(param_1 + 0x204); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {
      if ((*(uint *)(iVar1 + 0x14) & 0x80000) != 0) {
        *(int *)(*(int *)(DAT_008b8f28 + 0x150) + 0x10 + *(int *)(DAT_008b8f28 + 0x14c) * 0x18) =
             param_1;
        *(int *)(DAT_008b8f28 + 0x14c) = *(int *)(DAT_008b8f28 + 0x14c) + 1;
        break;
      }
    }
    if (*(int *)(param_1 + 0x44) != 0) {
      FUN_0054bd30();
    }
    param_1 = *(int *)(param_1 + 0x4c);
    if (param_1 == 0) {
      return;
    }
  } while( true );
}


