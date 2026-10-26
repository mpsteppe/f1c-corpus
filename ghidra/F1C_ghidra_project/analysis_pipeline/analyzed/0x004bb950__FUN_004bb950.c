// Function: FUN_004bb950 @ 004bb950
// Size (bytes): 315


void __fastcall FUN_004bb950(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (*(int *)(param_1 + 0x8c) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x8c));
    *(undefined4 *)(param_1 + 0x8c) = 0;
  }
  if (*(int *)(param_1 + 0x90) != 0) {
    FUN_00587bcf(*(int *)(param_1 + 0x90));
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  iVar2 = *(int *)(param_1 + 0x94);
  *(undefined4 *)(param_1 + 0x98) = 0;
  if (iVar2 != 0) {
    iVar1 = 0;
    if (0 < *(int *)(param_1 + 8)) {
      do {
        if (*(char *)(iVar2 + iVar1) == '\x01') {
          *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + 1;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 8));
    }
    FUN_00587bcf(iVar2);
    *(undefined4 *)(param_1 + 0x94) = 0;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0xc) = 2;
  *(undefined4 *)(param_1 + 0x14) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x18) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x1c) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x20) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x6c) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x70) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x74) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x78) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x7c) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x80) = 0xbf800000;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined1 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xac) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined1 *)(param_1 + 0xb4) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined4 *)(param_1 + 200) = 0;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(undefined1 *)(param_1 + 0xd4) = 0;
  *(undefined4 *)(param_1 + 0xdc) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xc0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0xd8) = 0xffffffff;
  puVar3 = (undefined4 *)(param_1 + 0xe0);
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xffffffff;
    puVar3 = puVar3 + 1;
  }
  return;
}


