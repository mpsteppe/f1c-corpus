// Address: 0x0042ed44
// Size: 12 bytes
// Name: sub_42ED44
// Type: char __userpurge@<al>(char result@<al>, _BYTE *@<ecx>, _BYTE *@<esi>, int, int, int)
// Source: IDA Hex-Rays decompilation

// positive sp value has been detected, the output may be wrong!
char __userpurge sub_42ED44@<al>(char result@<al>, _BYTE *a2@<ecx>, _BYTE *a3@<esi>, int a4, int a5, int a6)
{
  *a2 += result;
  *a3 = 1;
  return result;
}
