bool __usercall sub_617680@<al>(char *FileName@<ecx>, __int32 a2@<edi>)
{
  unsigned int v2; // kr00_4
  __int32 v3; // edi
  __int32 v6; // [esp+0h] [ebp-8h] BYREF

  v6 = a2;
  v2 = __readeflags();
  v3 = dword_16C6DC8 - 1735383552;
  __writeeflags(v2);
  _InterlockedExchange(&v6, v3);
  _chmod(FileName, v6);
  return remove(FileName) == 0;
}
