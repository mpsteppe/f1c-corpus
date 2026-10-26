int __fastcall sub_492360(int a1, int a2)
{
  int result; // eax
  const char *v4; // ebx
  char *v5; // edx
  unsigned int v6; // eax
  char *v7; // edi
  char *v9; // edi
  unsigned int v11; // kr00_4
  __int32 v12; // ebx
  const char *v13; // [esp+4h] [ebp-10Ch] BYREF
  char v14; // [esp+Fh] [ebp-101h] BYREF
  char v15[256]; // [esp+10h] [ebp-100h] BYREF

  sub_45DCB0((int)flt_B6966C, a2, 1);
  sub_45DC70(flt_B6966C, 0.30000001, 0.039999999);
  result = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a1 + 48) + 28))(*(_DWORD *)(a1 + 48), 26);
  v4 = (const char *)result;
  if ( result )
  {
    strcpy(v15, sub_41D840(&byte_91CC38, "CHATBOX - MAIN ("));
    v13 = v4;
    v11 = __readeflags();
    v12 = dword_16C6EA8 - *(_DWORD *)((char *)sub_436D50 + 1);
    __writeeflags(v11);
    _InterlockedExchange((volatile __int32 *)&v13, v12);
    v5 = sub_41D840(&byte_91CC38, v13);
    v6 = strlen(v5) + 1;
    v7 = &v14;
    while ( *++v7 )
      ;
    qmemcpy(v7, v5, v6);
    v9 = &v14;
    while ( *++v9 )
      ;
    *(_WORD *)v9 = 41;
    return sub_615860(v15);
  }
  return result;
}
