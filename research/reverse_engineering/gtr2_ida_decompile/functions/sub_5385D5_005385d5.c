int __usercall sub_5385D5@<eax>(__int32 a1@<eax>, char *a2, const char *a3, int a4)
{
  unsigned int v4; // kr00_4
  int v5; // eax
  __int32 v6; // eax
  int v8; // [esp+0h] [ebp-14h] BYREF
  int v9; // [esp+4h] [ebp-10h]
  int v10; // [esp+8h] [ebp-Ch]
  unsigned int v11; // [esp+Ch] [ebp-8h]
  __int32 v12; // [esp+10h] [ebp-4h] BYREF

  v12 = a1;
  v4 = __readeflags();
  v11 = v4;
  v10 = 527879464;
  v9 = 1436159335;
  v8 = 1368190600;
  v5 = sub_FF8EE0((int)dword_16C5AE0, (int)&v8);
  v10 += v9 ^ (v8 + v5);
  v6 = v10;
  __writeeflags(v11);
  _InterlockedExchange(&v12, v6);
  return sprintf(a2, a3, a4);
}
