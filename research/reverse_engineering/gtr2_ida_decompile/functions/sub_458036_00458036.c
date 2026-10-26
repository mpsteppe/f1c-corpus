// positive sp value has been detected, the output may be wrong!
int __usercall sub_458036@<eax>(const char *a1@<ebp>)
{
  unsigned int v1; // kr00_4
  __int32 v2; // ebx
  char *v3; // eax
  char *v4; // eax
  const char *v6; // [esp-114h] [ebp-118h] BYREF
  char *v7; // [esp-108h] [ebp-10Ch]
  char v8[128]; // [esp-FCh] [ebp-100h] BYREF
  char v9[124]; // [esp-7Ch] [ebp-80h] BYREF

  v1 = __readeflags();
  v2 = dword_16C6D00 - (_DWORD)off_16DB06C;
  __writeeflags(v1);
  _InterlockedExchange((volatile __int32 *)&v6, v2);
  v3 = sub_41D840(&byte_91CC38, v6);
  sub_41D810(v8, 0x7Fu, "%s", v3);
  if ( byte_B722E4 )
  {
    sub_41D810(v9, 0x7Fu, "%s", v8);
  }
  else
  {
    v7 = v8;
    v4 = sub_41D840(&byte_91CC38, a1);
    sub_41D810(v9, 0x7Fu, "%s - %s", v4, v7);
  }
  sub_4CE020(v9);
  return 0;
}
