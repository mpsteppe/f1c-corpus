// positive sp value has been detected, the output may be wrong!
int __userpurge sub_43306C@<eax>(
        _DWORD *a1@<eax>,
        int a2@<ecx>,
        char a3@<bl>,
        _DWORD *a4@<edi>,
        int a5@<esi>,
        double a6@<st0>,
        int a7,
        int a8)
{
  _BYTE *v8; // ecx
  const char *v10; // [esp+0h] [ebp-8h]

  v8 = (_BYTE *)_InterlockedExchange((volatile __int32 *)(*a4 + a2), *a4 + a2);
  *a1 += a1;
  *v8 ^= 0x43u;
  LOBYTE(a1) = __CFADD__(a3, a3) + ((unsigned __int8)a1 & 0x85) - 125;
  *a1 >>= 17;
  return sprintf(
           (char *const)(a5 + 31),
           "%.1f %s",
           (a6 * *(double *)(a5 + 9) + *(double *)(a5 + 1)) * 57.29577951308232,
           v10);
}
