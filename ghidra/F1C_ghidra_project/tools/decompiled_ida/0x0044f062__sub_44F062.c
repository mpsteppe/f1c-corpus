// Address: 0x0044f062
// Size: 14 bytes
// Name: sub_44F062
// Type: int __userpurge@<eax>(char@<bl>, int@<edi>, int, int, int)
// Source: IDA Hex-Rays decompilation

// positive sp value has been detected, the output may be wrong!
int __userpurge sub_44F062@<eax>(char a1@<bl>, int a2@<edi>, int a3, int a4, int a5)
{
  *(_BYTE *)(a2 + 94) += a1;
  return -1;
}
