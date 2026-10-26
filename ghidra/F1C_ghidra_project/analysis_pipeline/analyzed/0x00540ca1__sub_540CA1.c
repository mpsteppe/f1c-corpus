// Address: 0x00540ca1
// Size: 15 bytes
// Name: sub_540CA1
// Type: int __userpurge@<eax>(int result@<eax>, int@<edx>, int@<ecx>, int)
// Source: IDA Hex-Rays decompilation

int __userpurge sub_540CA1@<eax>(int result@<eax>, int a2@<edx>, int a3@<ecx>, int a4)
{
  *(_DWORD *)(a3 + 5088) = result;
  *(_DWORD *)(a3 + 5084) = a2;
  return result;
}
