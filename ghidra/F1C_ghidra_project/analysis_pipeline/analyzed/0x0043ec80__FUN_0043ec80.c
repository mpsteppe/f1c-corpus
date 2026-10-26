// Function: FUN_0043ec80 @ 0043ec80
// Size (bytes): 660


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0043ec80(int param_1)

{
  double dVar1;
  int extraout_ECX;
  int extraout_ECX_00;
  
  if (*(double *)(param_1 + 0x1c08) <= *(double *)(param_1 + 0x17a8)) {
    if (*(double *)(param_1 + 0x1c08) < *(double *)(param_1 + 0x17a8)) {
      *(undefined4 *)(param_1 + 0x17a8) = *(undefined4 *)(param_1 + 0x1c08);
      *(undefined4 *)(param_1 + 0x17ac) = *(undefined4 *)(param_1 + 0x1c0c);
    }
  }
  else {
    *(double *)(param_1 + 0x17a8) = *(double *)(param_1 + 0x1c08);
  }
  if (*(double *)(param_1 + 0x1c10) <= *(double *)(param_1 + 0x17c0)) {
    if (*(double *)(param_1 + 0x1c10) < *(double *)(param_1 + 0x17c0)) {
      *(undefined4 *)(param_1 + 0x17c0) = *(undefined4 *)(param_1 + 0x1c10);
      *(undefined4 *)(param_1 + 0x17c4) = *(undefined4 *)(param_1 + 0x1c14);
    }
  }
  else {
    *(double *)(param_1 + 0x17c0) = *(double *)(param_1 + 0x1c10);
  }
  FUN_0043bb30(*(undefined4 *)(param_1 + 0x1c00),*(undefined4 *)(param_1 + 0x1c04));
  dVar1 = *(double *)(extraout_ECX + 0x1c20) + _DAT_0059ec60;
  if (*(double *)(extraout_ECX + 0x1c20) <= *(double *)(extraout_ECX + 0x1808)) {
    if (dVar1 < *(double *)(extraout_ECX + 0x1808)) {
      *(double *)(extraout_ECX + 0x1808) = dVar1;
    }
  }
  else {
    *(double *)(extraout_ECX + 0x1808) = *(double *)(extraout_ECX + 0x1c20);
  }
  dVar1 = *(double *)(extraout_ECX + 0x1c28) + _DAT_0059ec90;
  if (*(double *)(extraout_ECX + 0x1c28) <= *(double *)(extraout_ECX + 0x1818)) {
    if (dVar1 < *(double *)(extraout_ECX + 0x1818)) {
      *(double *)(extraout_ECX + 0x1818) = dVar1;
    }
  }
  else {
    *(double *)(extraout_ECX + 0x1818) = *(double *)(extraout_ECX + 0x1c28);
  }
  FUN_0043bbd0(*(undefined4 *)(extraout_ECX + 0x1c18),*(undefined4 *)(extraout_ECX + 0x1c1c));
  dVar1 = *(double *)(extraout_ECX_00 + 0x1c30) + _DAT_0059eb50;
  if (*(double *)(extraout_ECX_00 + 0x1c30) <= *(double *)(extraout_ECX_00 + 0x1bc0)) {
    if (dVar1 < *(double *)(extraout_ECX_00 + 0x1bc0)) {
      *(double *)(extraout_ECX_00 + 0x1bc0) = dVar1;
    }
  }
  else {
    *(double *)(extraout_ECX_00 + 0x1bc0) = *(double *)(extraout_ECX_00 + 0x1c30);
  }
  if (*(double *)(extraout_ECX_00 + 0x1c40) <= *(double *)(extraout_ECX_00 + 0x17d8)) {
    if (*(double *)(extraout_ECX_00 + 0x1c40) < *(double *)(extraout_ECX_00 + 0x17d8)) {
      *(undefined4 *)(extraout_ECX_00 + 0x17d8) = *(undefined4 *)(extraout_ECX_00 + 0x1c40);
      *(undefined4 *)(extraout_ECX_00 + 0x17dc) = *(undefined4 *)(extraout_ECX_00 + 0x1c44);
    }
  }
  else {
    *(double *)(extraout_ECX_00 + 0x17d8) = *(double *)(extraout_ECX_00 + 0x1c40);
  }
  if (*(double *)(extraout_ECX_00 + 0x1c48) <= *(double *)(extraout_ECX_00 + 0x17f0)) {
    if (*(double *)(extraout_ECX_00 + 0x1c48) < *(double *)(extraout_ECX_00 + 0x17f0)) {
      *(undefined4 *)(extraout_ECX_00 + 0x17f0) = *(undefined4 *)(extraout_ECX_00 + 0x1c48);
      *(undefined4 *)(extraout_ECX_00 + 0x17f4) = *(undefined4 *)(extraout_ECX_00 + 0x1c4c);
    }
  }
  else {
    *(double *)(extraout_ECX_00 + 0x17f0) = *(double *)(extraout_ECX_00 + 0x1c48);
  }
  FUN_0043bb80(*(undefined4 *)(extraout_ECX_00 + 0x1c38),*(undefined4 *)(extraout_ECX_00 + 0x1c3c));
  return;
}


