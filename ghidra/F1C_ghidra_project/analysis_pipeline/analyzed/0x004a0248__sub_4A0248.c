// Address: 0x004a0248
// Size: 8 bytes
// Name: sub_4A0248
// Type: void __usercall(int@<ecx>, char@<bl>)
// Source: IDA Hex-Rays decompilation

void __usercall sub_4A0248(int a1@<ecx>, char a2@<bl>)
{
  *(_BYTE *)(a1 - 61) += a2;
}
