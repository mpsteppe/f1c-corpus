// Function: FUN_00569410 @ 00569410
// Size (bytes): 208


void __fastcall FUN_00569410(int param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  
  dVar1 = (*(double *)(param_1 + 0x7c) * *(double *)(param_1 + 0x1c) +
          *(double *)(param_1 + 0x34) * *(double *)(param_1 + 0x84) +
          *(double *)(param_1 + 0x4c) * *(double *)(param_1 + 0x8c)) * *(double *)(param_1 + 0xbc);
  dVar2 = (*(double *)(param_1 + 0x3c) * *(double *)(param_1 + 0x84) +
          *(double *)(param_1 + 0x54) * *(double *)(param_1 + 0x8c) +
          *(double *)(param_1 + 0x24) * *(double *)(param_1 + 0x7c)) * *(double *)(param_1 + 0xc4);
  dVar3 = (*(double *)(param_1 + 0x44) * *(double *)(param_1 + 0x84) +
          *(double *)(param_1 + 0x5c) * *(double *)(param_1 + 0x8c) +
          *(double *)(param_1 + 0x2c) * *(double *)(param_1 + 0x7c)) * *(double *)(param_1 + 0xcc);
  *(double *)(param_1 + 0x94) =
       dVar1 * *(double *)(param_1 + 0x1c) +
       dVar2 * *(double *)(param_1 + 0x24) + dVar3 * *(double *)(param_1 + 0x2c);
  *(double *)(param_1 + 0x9c) =
       dVar1 * *(double *)(param_1 + 0x34) +
       dVar2 * *(double *)(param_1 + 0x3c) + dVar3 * *(double *)(param_1 + 0x44);
  *(double *)(param_1 + 0xa4) =
       dVar1 * *(double *)(param_1 + 0x4c) +
       dVar2 * *(double *)(param_1 + 0x54) + dVar3 * *(double *)(param_1 + 0x5c);
  return;
}


