// Function: FUN_0056a240 @ 0056a240
// Size (bytes): 334


void __fastcall FUN_0056a240(int param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  
  dVar1 = *(double *)(param_1 + 0x14c) -
          (*(double *)(param_1 + 0xa4) * *(double *)(param_1 + 0x84) -
          *(double *)(param_1 + 0x9c) * *(double *)(param_1 + 0x8c));
  dVar2 = *(double *)(param_1 + 0x154) -
          (*(double *)(param_1 + 0x8c) * *(double *)(param_1 + 0x94) -
          *(double *)(param_1 + 0xa4) * *(double *)(param_1 + 0x7c));
  dVar3 = *(double *)(param_1 + 0x15c) -
          (*(double *)(param_1 + 0x9c) * *(double *)(param_1 + 0x7c) -
          *(double *)(param_1 + 0x84) * *(double *)(param_1 + 0x94));
  local_38 = dVar1 * *(double *)(param_1 + 0xec) +
             dVar2 * *(double *)(param_1 + 0xf4) + dVar3 * *(double *)(param_1 + 0xfc);
  local_30 = dVar1 * *(double *)(param_1 + 0x104) +
             dVar2 * *(double *)(param_1 + 0x10c) + dVar3 * *(double *)(param_1 + 0x114);
  local_28 = dVar1 * *(double *)(param_1 + 0x11c) +
             dVar2 * *(double *)(param_1 + 0x124) + dVar3 * *(double *)(param_1 + 300);
  local_10 = *(double *)(param_1 + 0xb4);
  local_20 = local_10 * *(double *)(param_1 + 0x134);
  local_18 = local_10 * *(double *)(param_1 + 0x13c);
  local_10 = local_10 * *(double *)(param_1 + 0x144);
  FUN_0056a390(&local_38,&local_20);
  FUN_0056a5d0(&local_38);
  FUN_0056a840(&local_38,&local_20);
  FUN_0056aa60();
  FUN_0056b5d0();
  FUN_0056baf0();
  return;
}


