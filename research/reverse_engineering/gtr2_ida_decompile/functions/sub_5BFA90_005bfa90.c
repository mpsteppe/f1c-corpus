int __userpurge sub_5BFA90@<eax>(int a1@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>, int a5@<esi>, int a6, int a7)
{
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  int v9; // ebx
  int i; // edi
  int v11; // ecx
  int v12; // ebx
  void *v13; // eax
  int v14; // edi
  int v16; // ebx
  size_t v17; // [esp-20h] [ebp-48h]
  char *v18; // [esp-1Ch] [ebp-44h]
  void *v19; // [esp-14h] [ebp-3Ch]
  int v21[9]; // [esp+0h] [ebp-28h] BYREF
  int v22; // [esp+24h] [ebp-4h]

  v22 = -1;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v21[8] = (int)&loc_6EAE08;
  v21[7] = (int)ExceptionList;
  if ( !*(_BYTE *)(a1 + 33) )
    sub_5BEBD0(a4, a5, a3, a2, v21[0], v21[1]);
  v9 = *(_DWORD *)(a1 + 12);
  for ( i = 0; i < v9; ++i )
  {
    v11 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 4 * i);
    if ( v11 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 8))(v11);
  }
  if ( *(_BYTE *)(a1 + 31) )
    sub_643E40("Trying to load motion '%s' from file '%s'...", *(const char **)(a7 + 4), *(const char **)(a6 + 4));
  sub_5BDD10();
  v18 = *(char **)(a6 + 4);
  v22 = 0;
  if ( !(unsigned __int8)sub_643F30(v18, 1, 1) )
  {
    if ( *(_BYTE *)(a1 + 31) )
      sub_643E40(
        "Failed open the file '%s' for motion '%s', motion not loaded!",
        *(const char **)(a6 + 4),
        *(const char **)(a7 + 4));
    goto LABEL_14;
  }
  v12 = sub_644190(v21);
  sub_4F14D0(v12);
  v13 = sub_5A8CE0(v17, 500, 16, 0);
  v14 = (int)v13;
  if ( !v13 )
  {
    sub_644070(v21);
LABEL_14:
    v22 = -1;
    sub_5BDD70(v21);
    return 0;
  }
  sub_644160(v13, v12);
  sub_644070(v21);
  v16 = sub_5BF810(a1, v12, a7, v14, a1, v14, v12, a7);
  sub_4F14D0(v14);
  sub_5A8D10(v19);
  if ( !v16 && *(_BYTE *)(a1 + 31) )
    sub_643E40("Failed to load motion '%s' from file '%s'", *(const char **)(a7 + 4), *(const char **)(a6 + 4));
  v22 = -1;
  sub_5BDD70(v21);
  return v16;
}
