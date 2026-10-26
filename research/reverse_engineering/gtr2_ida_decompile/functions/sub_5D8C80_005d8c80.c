int __cdecl sub_5D8C80(int a1, char *Buffer, char *Format, char ArgList)
{
  unsigned int v4; // kr00_4
  __int32 v5; // eax
  char *v7; // [esp+0h] [ebp-Ch] BYREF
  const char *v8; // [esp+4h] [ebp-8h]
  va_list p_ArgList; // [esp+8h] [ebp-4h]

  p_ArgList = &ArgList;
  v8 = Format;
  v7 = Buffer;
  v4 = __readeflags();
  v5 = dword_16C6F30 - (dword_16D6736 + 1);
  __writeeflags(v4);
  dword_FB2748 = _InterlockedExchange((volatile __int32 *)&v7, v5);
  return vsprintf(v7, v8, p_ArgList);
}
