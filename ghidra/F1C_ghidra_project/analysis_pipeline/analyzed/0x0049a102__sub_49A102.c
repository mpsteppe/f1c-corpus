// Address: 0x0049a102
// Size: 14 bytes
// Name: sub_49A102
// Type: int __userpurge@<eax>(int@<eax>, _DWORD *@<edx>, int@<ecx>, int, _DWORD *)
// Source: IDA Hex-Rays decompilation

int __userpurge sub_49A102@<eax>(int a1@<eax>, _DWORD *a2@<edx>, int a3@<ecx>, int a4, _DWORD *a5)
{
  int result; // eax

  *a2 = a1;
  result = *(_DWORD *)(a3 + 100);
  *a5 = result;
  return result;
}
