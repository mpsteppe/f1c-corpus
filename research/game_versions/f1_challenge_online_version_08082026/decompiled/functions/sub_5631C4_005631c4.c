// positive sp value has been detected, the output may be wrong!
__int64 __userpurge sub_5631C4@<edx:eax>(__int64 result@<edx:eax>, _BYTE *a2@<ebx>, int _EDI@<edi>, int a4, int a5)
{
  *a2 += BYTE5(result);
  __asm { rcr     byte ptr [edi+5Eh], 5Bh }
  return result;
}
