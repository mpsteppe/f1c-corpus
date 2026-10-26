// Function: FUN_0043bc20 @ 0043bc20
// Size (bytes): 1572


void __thiscall FUN_0043bc20(int param_1,int param_2,int param_3)

{
  double dVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined8 uVar10;
  undefined4 *local_14;
  undefined4 *local_10;
  int local_c;
  
  FUN_004363f0();
  FUN_00436470((double)*(int *)(param_2 + 0xe04) * *(double *)(param_2 + 0xdf8) +
               *(double *)(param_2 + 0xdf0));
  FUN_004363f0();
  FUN_00436470((double)*(int *)(param_2 + 0xe44) * *(double *)(param_2 + 0xe38) +
               *(double *)(param_2 + 0xe30));
  *(undefined1 *)(param_1 + 0x1900) = *(undefined1 *)(param_3 + 0x1ec);
  *(undefined4 *)(param_1 + 0x1904) = 0;
  *(undefined4 *)(param_1 + 0x1910) = *(undefined4 *)(param_3 + 0x1f0);
  *(undefined4 *)(param_1 + 0x1914) = *(undefined4 *)(param_3 + 500);
  *(undefined4 *)(param_1 + 0x1938) = *(undefined4 *)(param_3 + 0x228);
  *(undefined4 *)(param_1 + 0x193c) = *(undefined4 *)(param_3 + 0x22c);
  *(undefined4 *)(param_1 + 0x1940) = *(undefined4 *)(param_3 + 0x230);
  *(undefined4 *)(param_1 + 0x1944) = *(undefined4 *)(param_3 + 0x234);
  puVar6 = (undefined4 *)(param_3 + 0x238);
  puVar5 = (undefined4 *)(param_1 + 0x1960);
  local_10 = (undefined4 *)0x6;
  puVar2 = puVar6;
  do {
    puVar8 = puVar2;
    puVar9 = puVar5;
    for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar9 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
    }
    puVar2 = puVar2 + 6;
    puVar5 = puVar5 + 6;
    local_10 = (undefined4 *)((int)local_10 + -1);
  } while (local_10 != (undefined4 *)0x0);
  puVar5 = (undefined4 *)(param_3 + 0x2c8);
  puVar2 = (undefined4 *)(param_1 + 0x19f0);
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(param_1 + 0x17a8) = *(undefined4 *)(param_3 + 0x210);
  *(undefined4 *)(param_1 + 0x17ac) = *(undefined4 *)(param_3 + 0x214);
  *(undefined4 *)(param_1 + 0x17b0) = *(undefined4 *)(param_3 + 0x218);
  *(undefined4 *)(param_1 + 0x17b4) = *(undefined4 *)(param_3 + 0x21c);
  *(undefined4 *)(param_1 + 0x17b8) = *(undefined4 *)(param_3 + 0x220);
  *(undefined4 *)(param_1 + 0x17bc) = *(undefined4 *)(param_3 + 0x224);
  *(undefined4 *)(param_1 + 0x17c0) = *(undefined4 *)(param_3 + 0x1f8);
  *(undefined4 *)(param_1 + 0x17c4) = *(undefined4 *)(param_3 + 0x1fc);
  *(undefined4 *)(param_1 + 0x17c8) = *(undefined4 *)(param_3 + 0x200);
  *(undefined4 *)(param_1 + 0x17cc) = *(undefined4 *)(param_3 + 0x204);
  *(undefined4 *)(param_1 + 0x17d0) = *(undefined4 *)(param_3 + 0x208);
  *(undefined4 *)(param_1 + 0x17d4) = *(undefined4 *)(param_3 + 0x20c);
  *(undefined4 *)(param_1 + 0x1c08) = *(undefined4 *)(param_1 + 0x17a8);
  *(undefined4 *)(param_1 + 0x1c0c) = *(undefined4 *)(param_1 + 0x17ac);
  *(undefined4 *)(param_1 + 0x1c10) = *(undefined4 *)(param_1 + 0x17c0);
  *(undefined4 *)(param_1 + 0x1c14) = *(undefined4 *)(param_1 + 0x17c4);
  *(undefined4 *)(param_1 + 0x1904) = 0;
  *(undefined4 *)(param_1 + 0x1910) = *(undefined4 *)(param_3 + 0x1f0);
  *(undefined4 *)(param_1 + 0x1914) = *(undefined4 *)(param_3 + 500);
  *(undefined4 *)(param_1 + 0x1938) = *(undefined4 *)(param_3 + 0x228);
  *(undefined4 *)(param_1 + 0x193c) = *(undefined4 *)(param_3 + 0x22c);
  *(undefined4 *)(param_1 + 0x1940) = *(undefined4 *)(param_3 + 0x230);
  local_14 = (undefined4 *)(param_1 + 0x1960);
  *(undefined4 *)(param_1 + 0x1944) = *(undefined4 *)(param_3 + 0x234);
  local_10 = (undefined4 *)0x6;
  do {
    puVar5 = puVar6;
    puVar2 = local_14;
    for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar2 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar2 = puVar2 + 1;
    }
    local_14 = local_14 + 6;
    puVar6 = puVar6 + 6;
    local_10 = (undefined4 *)((int)local_10 + -1);
  } while (local_10 != (undefined4 *)0x0);
  puVar6 = (undefined4 *)(param_3 + 0x2c8);
  puVar5 = (undefined4 *)(param_1 + 0x19f0);
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar5 = puVar5 + 1;
  }
  uVar10 = FUN_0043bb30((double)*(int *)(param_2 + 0x1284) * *(double *)(param_2 + 0x1278) +
                        *(double *)(param_2 + 0x1270));
  iVar7 = (int)((ulonglong)uVar10 >> 0x20);
  iVar3 = (int)uVar10;
  *(undefined1 *)(param_1 + 0x1a08) = *(undefined1 *)(iVar3 + 0x2f8);
  *(undefined4 *)(param_1 + 0x1a14) = *(undefined4 *)(iVar3 + 0x32c);
  *(undefined4 *)(param_1 + 0x1a18) = *(undefined4 *)(iVar3 + 0x330);
  local_10 = (undefined4 *)(param_1 + 0x1a34);
  local_14 = (undefined4 *)(iVar3 + 0x334);
  local_c = 6;
  do {
    puVar6 = local_14;
    puVar5 = local_10;
    for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar5 = puVar5 + 1;
    }
    local_14 = local_14 + 6;
    local_10 = local_10 + 6;
    local_c = local_c + -1;
  } while (local_c != 0);
  puVar6 = (undefined4 *)(iVar3 + 0x3c4);
  puVar5 = (undefined4 *)(param_1 + 0x1ac4);
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar5 = puVar5 + 1;
  }
  *(undefined4 *)(param_1 + 0x17d8) = *(undefined4 *)(iVar3 + 0x314);
  *(undefined4 *)(param_1 + 0x17dc) = *(undefined4 *)(iVar3 + 0x318);
  *(undefined4 *)(param_1 + 0x17e0) = *(undefined4 *)(iVar3 + 0x31c);
  *(undefined4 *)(param_1 + 0x17e4) = *(undefined4 *)(iVar3 + 800);
  *(undefined4 *)(param_1 + 0x17e8) = *(undefined4 *)(iVar3 + 0x324);
  *(undefined4 *)(param_1 + 0x17ec) = *(undefined4 *)(iVar3 + 0x328);
  *(undefined4 *)(param_1 + 0x17f0) = *(undefined4 *)(iVar3 + 0x2fc);
  *(undefined4 *)(param_1 + 0x17f4) = *(undefined4 *)(iVar3 + 0x300);
  *(undefined4 *)(param_1 + 0x17f8) = *(undefined4 *)(iVar3 + 0x304);
  *(undefined4 *)(param_1 + 0x17fc) = *(undefined4 *)(iVar3 + 0x308);
  *(undefined4 *)(param_1 + 0x1800) = *(undefined4 *)(iVar3 + 0x30c);
  *(undefined4 *)(param_1 + 0x1804) = *(undefined4 *)(iVar3 + 0x310);
  *(undefined4 *)(param_1 + 0x1c40) = *(undefined4 *)(param_1 + 0x17d8);
  *(undefined4 *)(param_1 + 0x1c44) = *(undefined4 *)(param_1 + 0x17dc);
  *(undefined4 *)(param_1 + 0x1c48) = *(undefined4 *)(param_1 + 0x17f0);
  *(undefined4 *)(param_1 + 0x1c4c) = *(undefined4 *)(param_1 + 0x17f4);
  uVar10 = FUN_0043bb80((double)*(int *)(iVar7 + 0x12c4) * *(double *)(iVar7 + 0x12b8) +
                        *(double *)(iVar7 + 0x12b0));
  iVar7 = (int)((ulonglong)uVar10 >> 0x20);
  iVar3 = (int)uVar10;
  *(undefined4 *)(param_1 + 0x1828) = *(undefined4 *)(iVar3 + 0x1300);
  *(undefined4 *)(param_1 + 0x182c) = *(undefined4 *)(iVar3 + 0x1304);
  *(undefined4 *)(param_1 + 0x1830) = *(undefined4 *)(iVar3 + 0x1308);
  *(undefined4 *)(param_1 + 0x1834) = *(undefined4 *)(iVar3 + 0x130c);
  *(undefined4 *)(param_1 + 0x1ae4) = *(undefined4 *)(iVar3 + 0x3fc);
  *(undefined4 *)(param_1 + 0x1ae8) = *(undefined4 *)(iVar3 + 0x400);
  *(undefined4 *)(param_1 + 0x1aec) = *(undefined4 *)(iVar3 + 0x404);
  *(undefined4 *)(param_1 + 0x1af0) = *(undefined4 *)(iVar3 + 0x408);
  *(undefined4 *)(param_1 + 0x1af4) = *(undefined4 *)(iVar3 + 0x40c);
  *(undefined4 *)(param_1 + 0x1af8) = *(undefined4 *)(iVar3 + 0x410);
  local_14 = (undefined4 *)(param_1 + 0x1b14);
  local_10 = (undefined4 *)(iVar3 + 0x42c);
  local_c = 6;
  do {
    puVar6 = local_10;
    puVar5 = local_14;
    for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar5 = puVar5 + 1;
    }
    local_10 = local_10 + 6;
    local_14 = local_14 + 6;
    local_c = local_c + -1;
  } while (local_c != 0);
  puVar6 = (undefined4 *)(iVar3 + 0x4bc);
  puVar5 = (undefined4 *)(param_1 + 0x1ba4);
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar5 = puVar5 + 1;
  }
  dVar1 = (double)*(int *)(iVar7 + 0x1344) * *(double *)(iVar7 + 0x1338) +
          *(double *)(iVar7 + 0x1330);
  *(double *)(param_1 + 0x1808) = dVar1 * *(double *)(iVar3 + 0x530) + *(double *)(param_1 + 0x1b94)
  ;
  *(undefined4 *)(param_1 + 0x1810) = *(undefined4 *)(iVar3 + 0x520);
  *(undefined4 *)(param_1 + 0x1814) = *(undefined4 *)(iVar3 + 0x524);
  *(double *)(param_1 + 0x1818) = dVar1 * *(double *)(iVar3 + 0x528) + *(double *)(iVar3 + 0x3f4);
  *(undefined4 *)(param_1 + 0x1820) = *(undefined4 *)(iVar3 + 0x518);
  *(undefined4 *)(param_1 + 0x1824) = *(undefined4 *)(iVar3 + 0x51c);
  *(undefined4 *)(param_1 + 0x1c20) = *(undefined4 *)(param_1 + 0x1808);
  *(undefined4 *)(param_1 + 0x1c24) = *(undefined4 *)(param_1 + 0x180c);
  *(undefined4 *)(param_1 + 0x1c28) = *(undefined4 *)(param_1 + 0x1818);
  *(undefined4 *)(param_1 + 0x1c2c) = *(undefined4 *)(param_1 + 0x181c);
  iVar3 = FUN_0043bbd0((double)*(int *)(iVar7 + 0x1304) * *(double *)(iVar7 + 0x12f8) +
                       *(double *)(iVar7 + 0x12f0));
  *(undefined1 *)(param_1 + 0x1bbc) = *(undefined1 *)(iVar3 + 0x4d4);
  uVar10 = *(undefined8 *)(iVar3 + 0x4d8);
  *(undefined8 *)(param_1 + 0x1bc0) = uVar10;
  *(undefined8 *)(param_1 + 0x1c30) = uVar10;
  *(undefined4 *)(param_1 + 0x1bc8) = *(undefined4 *)(iVar3 + 0x4e0);
  *(undefined4 *)(param_1 + 0x1bcc) = *(undefined4 *)(iVar3 + 0x4e4);
  *(undefined4 *)(param_1 + 0x1bd0) = *(undefined4 *)(iVar3 + 0x4e8);
  *(undefined4 *)(param_1 + 0x1bd4) = *(undefined4 *)(iVar3 + 0x4ec);
  *(undefined4 *)(param_1 + 0x1bd8) = *(undefined4 *)(iVar3 + 0x4f0);
  *(undefined4 *)(param_1 + 0x1bdc) = *(undefined4 *)(iVar3 + 0x4f4);
  *(undefined4 *)(param_1 + 0x1be0) = *(undefined4 *)(iVar3 + 0x4f8);
  *(undefined4 *)(param_1 + 0x1be4) = *(undefined4 *)(iVar3 + 0x4fc);
  return;
}


