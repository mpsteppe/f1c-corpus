// Address: 0x0053c102
// Size: 14 bytes
// Name: sub_53C102
// Type: void __userpurge(int@<ecx>, double@<st2>, int, int, int, int)
// Source: IDA Hex-Rays decompilation

void __userpurge sub_53C102(int a1@<ecx>, double a2@<st2>, int a3, int a4, int a5, int a6)
{
  *(float *)(a1 + 8) = a2;
}
