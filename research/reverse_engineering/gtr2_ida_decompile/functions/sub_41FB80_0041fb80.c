double __userpurge sub_41FB80@<st0>(float *a1@<ecx>, double a2@<st0>, float *a3)
{
  float v4; // eax
  unsigned int v7; // kr00_4
  __int32 v8; // edx
  float v9; // edx
  float v10[3]; // [esp+0h] [ebp-Ch] BYREF

  v4 = a3[29];
  v10[0] = a3[30];
  v7 = __readeflags();
  v8 = dword_16DF1F8 + dword_16C6E28;
  __writeeflags(v7);
  v9 = COERCE_FLOAT(_InterlockedExchange((volatile __int32 *)v10, v8));
  sub_575AD0(v9, (int)(a3 + 31), v4, v10[0]);
  return (a2 * a1[5180] + a1[5179]) * a1[5206] * a1[5134] * a3[34];
}
