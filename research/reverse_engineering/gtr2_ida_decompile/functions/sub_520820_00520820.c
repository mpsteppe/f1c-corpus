char __usercall sub_520820@<al>(char *FileName@<ecx>, const char *a2@<ebp>)
{
  unsigned int v2; // kr00_4
  __int32 v3; // ebp
  const char *v6; // [esp+0h] [ebp-Ch] BYREF
  size_t v7; // [esp+4h] [ebp-8h]

  v7 = 2;
  v6 = a2;
  v2 = __readeflags();
  v3 = dword_16C6CB4 - 1782831617;
  __writeeflags(v2);
  _InterlockedExchange((volatile __int32 *)&v6, v3);
  if ( strncmp(FileName, v6, v7) )
    return sub_617680(FileName);
  sub_614A60(FileName);
  return 1;
}
