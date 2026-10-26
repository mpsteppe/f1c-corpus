int __userpurge sub_5BF810@<eax>(
        int a1@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        int a5@<esi>,
        int a6,
        size_t Size,
        int a8)
{
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  int v10; // ebx
  int i; // edi
  int v12; // ecx
  int v13; // edi
  _UNKNOWN **v16; // [esp+0h] [ebp-28h] BYREF
  int v17; // [esp+4h] [ebp-24h]
  int v18; // [esp+8h] [ebp-20h]
  int v19; // [esp+Ch] [ebp-1Ch]
  struct _EXCEPTION_REGISTRATION_RECORD *v20; // [esp+1Ch] [ebp-Ch]
  void *v21; // [esp+20h] [ebp-8h]
  int v22; // [esp+24h] [ebp-4h]

  v22 = -1;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v21 = &loc_6EADF0;
  v20 = ExceptionList;
  if ( !*(_BYTE *)(a1 + 33) )
    sub_5BEBD0(a4, a5, a3, a2, (int)v16, v17);
  v10 = *(_DWORD *)(a1 + 12);
  for ( i = 0; i < v10; ++i )
  {
    v12 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 4 * i);
    if ( v12 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v12 + 8))(v12);
  }
  if ( *(_BYTE *)(a1 + 31) )
    sub_643E40("Trying to load motion '%s' from memory location 0x%x...", *(const char **)(a8 + 4), a6);
  v16 = &off_729860;
  v17 = 0;
  v18 = 0;
  v19 = 0;
  v22 = 0;
  sub_6442F0(a6, Size);
  v13 = sub_5BF5F0(a1, (int *)&v16, a8);
  if ( !v13 && *(_BYTE *)(a1 + 31) )
    sub_643E40("Failed to load motion '%s' from memory location 0x%x", *(const char **)(a8 + 4), a6);
  v16 = &off_729860;
  v22 = 1;
  sub_644350(&v16);
  return v13;
}
