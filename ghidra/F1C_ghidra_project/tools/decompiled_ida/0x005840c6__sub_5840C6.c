// Address: 0x005840c6
// Size: 10 bytes
// Name: sub_5840C6
// Type: int __usercall@<eax>(char@<al>, int@<ecx>)
// Source: IDA Hex-Rays decompilation

int __usercall sub_5840C6@<eax>(char a1@<al>, int a2@<ecx>)
{
  *(_BYTE *)(a2 + 46276) += a1;
  return sub_5840D0();
}
