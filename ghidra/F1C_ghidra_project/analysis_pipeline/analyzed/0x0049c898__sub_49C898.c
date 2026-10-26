// Address: 0x0049c898
// Size: 8 bytes
// Name: sub_49C898
// Type: int __userpurge@<eax>(char@<bl>, int@<edi>, int, int)
// Source: IDA Hex-Rays decompilation

// positive sp value has been detected, the output may be wrong!
int __userpurge sub_49C898@<eax>(char a1@<bl>, int a2@<edi>, int a3, int a4)
{
  *(_BYTE *)(a2 + 51) += a1;
  return 0;
}
