// Address: 0x00429fc2
// Size: 12 bytes
// Name: sub_429FC2
// Type: void __usercall(char@<al>)
// Source: IDA Hex-Rays decompilation

// positive sp value has been detected, the output may be wrong!
void __usercall sub_429FC2(char a1@<al>)
{
  MEMORY[0xCE8B0875] += a1;
  JUMPOUT(0x42A206);
}
