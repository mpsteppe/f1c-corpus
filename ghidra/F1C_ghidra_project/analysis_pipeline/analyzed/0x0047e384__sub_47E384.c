// Address: 0x0047e384
// Size: 12 bytes
// Name: sub_47E384
// Type: void __usercall(char@<bl>, int@<edi>)
// Source: IDA Hex-Rays decompilation

// positive sp value has been detected, the output may be wrong!
void __usercall sub_47E384(char a1@<bl>, int a2@<edi>)
{
  *(_BYTE *)(a2 + 94) += a1;
}
