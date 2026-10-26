// Address: 0x00469872
// Size: 74 bytes
// Name: sub_469872
// Type: int()
// Source: IDA Hex-Rays decompilation

// bad sp value at call has been detected, the output may be wrong!
// positive sp value has been detected, the output may be wrong!
int sub_469872()
{
  int v1; // [esp-8h] [ebp-8h]

  (*(void (**)(void))(v1 - 117))();
  __asm { icebp }
  sub_4893C0();
  *(_DWORD *)(v1 + 384) = 0;
  *(_DWORD *)(v1 + 388) = -1;
  *(_DWORD *)v1 = &off_59F7C8;
  *(_DWORD *)(v1 + 372) = 0;
  *(_DWORD *)(v1 + 376) = 0;
  *(_BYTE *)(v1 + 380) = 1;
  sub_566650(0);
  return v1;
}
