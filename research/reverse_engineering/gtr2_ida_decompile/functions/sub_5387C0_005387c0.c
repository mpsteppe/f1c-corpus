int __usercall sub_5387C0@<eax>(char *a1@<ebp>)
{
  unsigned int v1; // kr00_4
  __int32 v2; // ebp
  int v3; // eax
  char *v5; // [esp+0h] [ebp-8h] BYREF

  v5 = a1;
  v1 = __readeflags();
  v2 = dword_16C6F10 - 1821700133;
  __writeeflags(v1);
  _InterlockedExchange((volatile __int32 *)&v5, v2);
  v3 = sub_616840(v5);
  if ( v3 )
    return sub_6165F0(v3);
  else
    return 0;
}
