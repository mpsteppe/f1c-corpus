// Function: FUN_00495ae0 @ 00495ae0
// Size (bytes): 70


void __fastcall FUN_00495ae0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x14) != 0) && (*(int *)(*(int *)(param_1 + 0x14) + 100) != 0)) {
    iVar1 = *(int *)(param_1 + 0x18);
    iVar2 = *(int *)(iVar1 + 0x68);
    *(int *)(param_1 + 0x18) = iVar2;
    *(undefined4 *)(iVar2 + 100) = 0;
    FUN_00499050(*(undefined4 *)(iVar1 + 4),*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0xc),
                 *(undefined4 *)(iVar1 + 0x10));
    *(undefined4 *)(iVar1 + 100) = 0;
    *(undefined4 *)(iVar1 + 0x68) = 0;
  }
  return;
}


