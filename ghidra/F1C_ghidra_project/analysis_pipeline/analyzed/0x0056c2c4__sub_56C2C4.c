// Address: 0x0056c2c4
// Size: 12 bytes
// Name: sub_56C2C4
// Type: void __userpurge(char@<bl>, int, int)
// Source: IDA Hex-Rays decompilation

// positive sp value has been detected, the output may be wrong!
void __userpurge sub_56C2C4(char a1@<bl>, int a2, int a3)
{
  int v3; // [esp-8h] [ebp-8h]

  *(_BYTE *)(v3 + 94) |= a1;
}
