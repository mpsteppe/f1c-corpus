int __userpurge sub_5F0D70@<eax>(void *a1@<ecx>, __int32 a2@<esi>, char *Str, int a4, int **a5)
{
  unsigned int v5; // kr00_4
  __int32 v6; // esi
  __int32 v9; // [esp+0h] [ebp-10h] BYREF
  int v10; // [esp+4h] [ebp-Ch]
  unsigned int v11; // [esp+8h] [ebp-8h]
  int **v12; // [esp+Ch] [ebp-4h]

  v12 = a5;
  v11 = a4;
  v10 = 0;
  v9 = a2;
  v5 = __readeflags();
  v6 = dword_16C6D74 + 1826871809;
  __writeeflags(v5);
  _InterlockedExchange(&v9, v6);
  return sub_5F0C30(a1, Str, 0, 0, v9, v10, v11, v12);
}
