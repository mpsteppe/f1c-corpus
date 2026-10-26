char __usercall sub_48EED6@<al>(int a1@<ecx>, int a2@<edi>)
{
  unsigned int v2; // kr00_4
  const CHAR *v3; // eax

  v2 = __getcallerseflags();
  v3 = *(const CHAR **)(dword_16C6DCC + 1821920294);
  __writeeflags(v2);
  return sub_477E25(v3, a1, a2);
}
