char *__userpurge sub_5BF900@<eax>(
        int a1@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        __int64 a4@<esi:edi>,
        int a5,
        int a6,
        int a7)
{
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  int v8; // ebx
  int v9; // ecx
  int v10; // ebx
  void *v11; // eax
  char *v13; // ebx
  size_t v14; // [esp-20h] [ebp-48h]
  char *v15; // [esp-1Ch] [ebp-44h]
  void *v16; // [esp-14h] [ebp-3Ch]
  int v17; // [esp-Ch] [ebp-34h]
  int v18[9]; // [esp+0h] [ebp-28h] BYREF
  int v19; // [esp+24h] [ebp-4h]

  v19 = -1;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v18[8] = (int)&loc_6EAE08;
  v18[7] = (int)ExceptionList;
  v17 = HIDWORD(a4);
  HIDWORD(a4) = a1;
  if ( !*(_BYTE *)(a1 + 33) )
    sub_5BEBD0(a4, v17, a3, a2, v18[0], v18[1]);
  v8 = *(_DWORD *)(HIDWORD(a4) + 12);
  LODWORD(a4) = 0;
  if ( v8 > 0 )
  {
    do
    {
      v9 = *(_DWORD *)(*(_DWORD *)(HIDWORD(a4) + 20) + 4 * a4);
      if ( v9 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 8))(v9);
      LODWORD(a4) = a4 + 1;
    }
    while ( (int)a4 < v8 );
  }
  if ( *(_BYTE *)(HIDWORD(a4) + 31) )
    sub_643E40("Trying to load actor '%s' from file '%s'...", *(const char **)(a6 + 4), *(const char **)(a5 + 4));
  sub_5BDD10();
  v15 = *(char **)(a5 + 4);
  v19 = 0;
  if ( !(unsigned __int8)sub_643F30(v15, 1, 1) )
  {
    if ( *(_BYTE *)(HIDWORD(a4) + 31) )
      sub_643E40(
        "Failed open the file '%s' for actor '%s', actor not loaded!",
        *(const char **)(a5 + 4),
        *(const char **)(a6 + 4));
    goto LABEL_14;
  }
  v10 = sub_644190(v18);
  sub_4F14D0(v10);
  v11 = sub_5A8CE0(v14, 500, 16, 0);
  LODWORD(a4) = v11;
  if ( !v11 )
  {
    sub_644070(v18);
LABEL_14:
    v19 = -1;
    sub_5BDD70(v18);
    return 0;
  }
  sub_644160(v11, v10);
  sub_644070(v18);
  v13 = sub_5BF710(SHIDWORD(a4), v10, a6, a4, a4, v10, a6, a7);
  sub_4F14D0(a4);
  sub_5A8D10(v16);
  if ( !v13 && *(_BYTE *)(HIDWORD(a4) + 31) )
    sub_643E40("Failed to load actor '%s' from file '%s'", *(const char **)(a6 + 4), *(const char **)(a5 + 4));
  v19 = -1;
  sub_5BDD70(v18);
  return v13;
}
