// Function: FUN_00430600 @ 00430600
// Size (bytes): 329


void __thiscall FUN_00430600(int param_1,float param_2,float *param_3,float *param_4)

{
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  undefined1 local_24 [8];
  float local_1c;
  undefined1 local_18 [8];
  float local_10;
  undefined1 local_c [8];
  float local_4;
  
  FUN_004f3190((float)*(int *)(param_1 + 0xe04) * (float)*(double *)(param_1 + 0xdf8) +
               (float)*(double *)(param_1 + 0xdf0),&local_40,&local_28);
  FUN_004f3190((float)*(int *)(param_1 + 0xe44) * (float)*(double *)(param_1 + 0xe38) +
               (float)*(double *)(param_1 + 0xe30),&param_2,&local_2c);
  FUN_004f68b0((float)*(int *)(param_1 + 0x1284) * (float)*(double *)(param_1 + 0x1278) +
               (float)*(double *)(param_1 + 0x1270),0x3ccccccd,local_c,&local_30);
  FUN_004f6950((float)*(int *)(param_1 + 0x12c4) * (float)*(double *)(param_1 + 0x12b8) +
               (float)*(double *)(param_1 + 0x12b0),local_18,&local_34);
  FUN_004f69e0((float)*(int *)(param_1 + 0x1344) * (float)*(double *)(param_1 + 0x1338) +
               (float)*(double *)(param_1 + 0x1330),
               (float)*(int *)(param_1 + 0x1304) * (float)*(double *)(param_1 + 0x12f8) +
               (float)*(double *)(param_1 + 0x12f0),0x3ccccccd,local_24,&local_38);
  FUN_004f6a50(0x3ccccccd,&local_3c);
  *param_3 = local_1c + local_10 + local_4 + param_2 + local_40;
  *param_4 = local_3c + local_38 + local_34 + local_30 + local_2c + local_28;
  return;
}


