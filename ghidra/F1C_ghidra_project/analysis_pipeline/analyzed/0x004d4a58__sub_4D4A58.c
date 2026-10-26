// Address: 0x004d4a58
// Size: 15 bytes
// Name: sub_4D4A58
// Type: int __usercall@<eax>(int result@<eax>)
// Source: IDA Hex-Rays decompilation

int __usercall sub_4D4A58@<eax>(int result@<eax>)
{
  *(_DWORD *)(result + 4) = 4;
  *(_DWORD *)(result + 8) = 0;
  return result;
}
