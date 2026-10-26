void sub_490DC6()
{
  unsigned int v0; // kr00_4
  __int32 v1; // ebx
  __int32 v2[63]; // [esp+0h] [ebp-FCh] BYREF

  v0 = __readeflags();
  v1 = __ROL4__(off_16C6DE0, *(char *)sub_4797E0);
  __writeeflags(v0);
  _InterlockedExchange(v2, v1);
}
