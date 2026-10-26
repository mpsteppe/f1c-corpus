void __thiscall __noreturn sub_42F9A0(void *this)
{
  unsigned int v1; // kr00_4
  __int32 v2; // ecx
  __int32 v3[2]; // [esp+0h] [ebp-8h] BYREF

  v3[1] = -1;
  v3[0] = (__int32)this;
  v1 = __readeflags();
  v2 = loc_5E8CD2 + dword_16C6C40;
  __writeeflags(v1);
  sub_42F9A7(_InterlockedExchange(v3, v2));
}
