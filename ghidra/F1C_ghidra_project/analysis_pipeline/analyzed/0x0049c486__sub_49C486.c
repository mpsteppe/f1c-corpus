// Address: 0x0049c486
// Size: 10 bytes
// Name: sub_49C486
// Type: char __userpurge@<al>(char result@<al>, int@<ebx>, int, int)
// Source: IDA Hex-Rays decompilation

// positive sp value has been detected, the output may be wrong!
char __userpurge sub_49C486@<al>(char result@<al>, int a2@<ebx>, int a3, int a4)
{
  *(_BYTE *)(a2 - 1070395196) += result;
  return result;
}
