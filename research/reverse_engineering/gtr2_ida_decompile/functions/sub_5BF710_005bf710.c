char *__userpurge sub_5BF710@<eax>(
        int a1@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        __int64 a4@<esi:edi>,
        int a5,
        size_t Size,
        int a7,
        int a8)
{
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  int v9; // ebx
  int v10; // ecx
  char *v11; // edi
  int v13; // [esp-Ch] [ebp-34h]
  _UNKNOWN **v14; // [esp+0h] [ebp-28h] BYREF
  int v15; // [esp+4h] [ebp-24h]
  int v16; // [esp+8h] [ebp-20h]
  int v17; // [esp+Ch] [ebp-1Ch]
  struct _EXCEPTION_REGISTRATION_RECORD *v18; // [esp+1Ch] [ebp-Ch]
  void *v19; // [esp+20h] [ebp-8h]
  int v20; // [esp+24h] [ebp-4h]

  v20 = -1;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v19 = &loc_6EADF0;
  v18 = ExceptionList;
  v13 = HIDWORD(a4);
  HIDWORD(a4) = a1;
  if ( !*(_BYTE *)(a1 + 33) )
    sub_5BEBD0(a4, v13, a3, a2, (int)v14, v15);
  v9 = *(_DWORD *)(HIDWORD(a4) + 12);
  LODWORD(a4) = 0;
  if ( v9 > 0 )
  {
    do
    {
      v10 = *(_DWORD *)(*(_DWORD *)(HIDWORD(a4) + 20) + 4 * a4);
      if ( v10 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 8))(v10);
      LODWORD(a4) = a4 + 1;
    }
    while ( (int)a4 < v9 );
  }
  if ( *(_BYTE *)(HIDWORD(a4) + 31) )
    sub_643E40("Trying to load actor '%s' from memory location 0x%x...", *(const char **)(a7 + 4), a5);
  v14 = &off_729860;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v20 = 0;
  sub_6442F0(a5, Size);
  v11 = sub_5BF410(SHIDWORD(a4), a5, a7, a4, (int *)&v14, a7, a8);
  if ( !v11 && *(_BYTE *)(HIDWORD(a4) + 31) )
    sub_643E40("Failed to load actor '%s' from memory location 0x%x", *(const char **)(a7 + 4), a5);
  sub_644350(&v14);
  v14 = &off_729860;
  v20 = 1;
  sub_644350(&v14);
  return v11;
}
