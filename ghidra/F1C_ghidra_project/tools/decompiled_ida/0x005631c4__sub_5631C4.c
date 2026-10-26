// Address: 0x005631c4
// Size: 12 bytes
// Name: sub_5631C4
// Type: __int64 __userpurge@<edx:eax>(__int64 result@<edx:eax>, _BYTE *@<ebx>, int _EDI@<edi>, int, int)
// Source: IDA Hex-Rays decompilation

// positive sp value has been detected, the output may be wrong!
__int64 __userpurge sub_5631C4@<edx:eax>(__int64 result@<edx:eax>, _BYTE *a2@<ebx>, int _EDI@<edi>, int a4, int a5)
{
  *a2 += BYTE5(result);
  __asm { rcr     byte ptr [edi+5Eh], 5Bh }
  return result;
}
