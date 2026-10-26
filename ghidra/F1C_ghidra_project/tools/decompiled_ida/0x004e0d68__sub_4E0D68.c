// Address: 0x004e0d68
// Size: 8 bytes
// Name: sub_4E0D68
// Type: int __userpurge@<eax>(char@<bl>, int@<esi>, int)
// Source: IDA Hex-Rays decompilation

int __userpurge sub_4E0D68@<eax>(char a1@<bl>, int a2@<esi>, int a3)
{
  *(_BYTE *)(a2 - 125) += a1;
  return sub_4E0D70(a3);
}
