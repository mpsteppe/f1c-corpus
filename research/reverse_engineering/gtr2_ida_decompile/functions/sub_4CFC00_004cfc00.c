char *__userpurge sub_4CFC00@<eax>(int a1@<ecx>, __int32 a2@<ebp>, int a3)
{
  unsigned int v3; // kr00_4
  char *result; // eax
  __int32 v5; // [esp+0h] [ebp-4h] BYREF

  if ( a3 < 0 || a3 > *(_DWORD *)(a1 + 64) - 1 || (result = *(char **)sub_5F6B50(a3)) == 0 )
  {
    result = (char *)off_16C9A64[0];
    v5 = a2;
    v3 = __readeflags();
    _InterlockedExchange(&v5, dword_16C6D88 - 1721752065);
    __writeeflags(v3);
  }
  return result;
}
