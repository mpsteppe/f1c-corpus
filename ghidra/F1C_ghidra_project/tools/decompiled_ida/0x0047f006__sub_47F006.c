// Address: 0x0047f006
// Size: 10 bytes
// Name: sub_47F006
// Type: char __userpurge@<al>(char result@<al>, int@<ebx>, int)
// Source: IDA Hex-Rays decompilation

// positive sp value has been detected, the output may be wrong!
char __userpurge sub_47F006@<al>(char result@<al>, int a2@<ebx>, int a3)
{
  *(_BYTE *)(a2 - 963967804) += result;
  return result;
}
