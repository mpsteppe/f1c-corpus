void __fastcall sub_5A6920(void *a1, __int32 a2, int a3)
{
  unsigned int v3; // kr00_4
  char *v4; // edx
  __int32 v5[2]; // [esp+0h] [ebp-8h] BYREF

  v5[1] = -1;
  v5[0] = a2;
  v3 = __readeflags();
  v4 = (char *)dword_16CBEDC + dword_16C6DF0 + 1;
  __writeeflags(v3);
  _InterlockedExchange(v5, (__int32)v4);
  sub_5A6927(a3);
}
