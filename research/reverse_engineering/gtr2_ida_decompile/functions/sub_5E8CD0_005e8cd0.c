int __usercall sub_5E8CD0@<eax>(void *a1@<ecx>, __int32 a2@<ebx>, int a3)
{
  unsigned int v3; // kr00_4
  char *v4; // ebx
  __int32 v6[2]; // [esp+0h] [ebp-8h] BYREF

  v6[1] = -1;
  v6[0] = a2;
  v3 = __readeflags();
  v4 = (char *)off_16C6DB4 - 474901;
  __writeeflags(v3);
  _InterlockedExchange(v6, (__int32)v4);
  return sub_5E8CD7(a1, a3);
}
