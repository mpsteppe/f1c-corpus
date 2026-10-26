// Address: 0x00486ec8
// Size: 8 bytes
// Name: sub_486EC8
// Type: void __userpurge(char@<bl>, int@<edi>, int, int)
// Source: IDA Hex-Rays decompilation

// positive sp value has been detected, the output may be wrong!
void __userpurge sub_486EC8(char a1@<bl>, int a2@<edi>, int a3, int a4)
{
  *(_BYTE *)(a2 + 94) += a1;
}
