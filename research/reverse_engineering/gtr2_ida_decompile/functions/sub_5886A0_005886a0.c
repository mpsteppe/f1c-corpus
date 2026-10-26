int __fastcall sub_5886A0(int a1, __int32 a2, int a3, int a4, int a5)
{
  unsigned int v5; // kr00_4
  __int32 v6; // edx
  __int32 var8[3]; // [esp+0h] [ebp-8h] BYREF

  var8[1] = -1;
  var8[0] = a2;
  v5 = __readeflags();
  v6 = (char *)off_16C6E18 - (char *)&dword_16CB854;
  __writeeflags(v5);
  _InterlockedExchange(var8, v6);
  return sub_5886AD(a3, a4, a5);
}
