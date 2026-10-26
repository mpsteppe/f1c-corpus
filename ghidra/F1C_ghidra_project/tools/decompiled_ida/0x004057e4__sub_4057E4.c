// Address: 0x004057e4
// Size: 12 bytes
// Name: sub_4057E4
// Type: __int64 __usercall@<edx:eax>(__int64 result@<edx:eax>, _BYTE *@<ebx>, int@<esi>)
// Source: IDA Hex-Rays decompilation

// positive sp value has been detected, the output may be wrong!
__int64 __usercall sub_4057E4@<edx:eax>(__int64 result@<edx:eax>, _BYTE *a2@<ebx>, int a3@<esi>)
{
  *a2 += BYTE5(result);
  *(_BYTE *)(a3 + 112) = 0;
  return result;
}
