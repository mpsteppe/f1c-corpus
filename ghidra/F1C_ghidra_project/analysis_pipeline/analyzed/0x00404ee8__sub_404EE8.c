// Address: 0x00404ee8
// Size: 8 bytes
// Name: sub_404EE8
// Type: void __userpurge(char@<bl>, int@<edi>, int)
// Source: IDA Hex-Rays decompilation

// positive sp value has been detected, the output may be wrong!
void __userpurge sub_404EE8(char a1@<bl>, int a2@<edi>, int a3)
{
  *(_BYTE *)(a2 + 94) += a1;
}
