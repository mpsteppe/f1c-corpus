// Address: 0x0057a0e6
// Size: 10 bytes
// Name: sub_57A0E6
// Type: char __userpurge@<al>(char result@<al>, int@<ebx>, int, int, int, int)
// Source: IDA Hex-Rays decompilation

// positive sp value has been detected, the output may be wrong!
char __userpurge sub_57A0E6@<al>(char result@<al>, int a2@<ebx>, int a3, int a4, int a5, int a6)
{
  *(_BYTE *)(a2 + 1583287492) += result;
  return result;
}
