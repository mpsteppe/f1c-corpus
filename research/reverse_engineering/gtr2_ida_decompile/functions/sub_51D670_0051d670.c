void __usercall sub_51D670(void *a1@<ecx>, __int32 a2@<ebx>, int a3)
{
  unsigned int v3; // kr00_4
  __int32 v4; // ebx
  __int32 v5[2]; // [esp+0h] [ebp-8h] BYREF

  v5[1] = -1;
  v5[0] = a2;
  v3 = __readeflags();
  v4 = dword_16C6CC4 + 1378867713;
  __writeeflags(v3);
  _InterlockedExchange(v5, v4);
  sub_51D677(a1, a3);
}
