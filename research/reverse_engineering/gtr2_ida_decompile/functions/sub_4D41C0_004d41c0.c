int __userpurge sub_4D41C0@<eax>(__int32 a1@<ebx>, int a2, int a3)
{
  unsigned int v3; // kr00_4
  __int32 v4; // ebx
  __int32 var8[3]; // [esp+0h] [ebp-8h] BYREF

  var8[1] = -1;
  var8[0] = a1;
  v3 = __readeflags();
  v4 = dword_16C6EAC + 1839716864;
  __writeeflags(v3);
  _InterlockedExchange(var8, v4);
  return sub_4D41CD(a2, a3);
}
