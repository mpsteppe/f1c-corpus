void __thiscall sub_48CD76(void *this)
{
  unsigned int v1; // kr00_4
  void *v2; // [esp+0h] [ebp-120h] BYREF

  v2 = this;
  v1 = __readeflags();
  _InterlockedExchange((volatile __int32 *)&v2, ~dword_16C6D8C ^ 0x6C92C025);
  __writeeflags(v1);
}
