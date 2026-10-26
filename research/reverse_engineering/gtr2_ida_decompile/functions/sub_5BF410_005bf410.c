char *__userpurge sub_5BF410@<eax>(
        int a1@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        __int64 a4@<esi:edi>,
        int *a5,
        int a6,
        int a7)
{
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  int v9; // edi
  char *v10; // ebx
  int i; // esi
  int v12; // ecx
  int v14; // eax
  int v15; // edi
  int k; // esi
  int v17; // ecx
  __int64 v18; // [esp+28h] [ebp-60h]
  int v19; // [esp+30h] [ebp-58h]
  int v20; // [esp+34h] [ebp-54h]
  int v21; // [esp+38h] [ebp-50h]
  void *v22; // [esp+38h] [ebp-50h]
  int v23; // [esp+3Ch] [ebp-4Ch]
  int v24; // [esp+48h] [ebp-40h]
  _BYTE v25[60]; // [esp+4Ch] [ebp-3Ch] BYREF
  int j; // [esp+A0h] [ebp+18h]
  int v27; // [esp+A4h] [ebp+1Ch]

  *(_DWORD *)&v25[56] = -1;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  *(_DWORD *)&v25[52] = &loc_6EADAB;
  *(_DWORD *)&v25[48] = ExceptionList;
  v20 = a2;
  v19 = a3;
  v18 = a4;
  if ( !*(_BYTE *)(a1 + 33) )
    sub_5BEBD0(a4, SHIDWORD(a4), v19, a2, v21, v23);
  if ( *(_BYTE *)(a1 + 31) )
    sub_643E40("- Trying to load actor '%s'...", *(const char **)(a6 + 4));
  v9 = *(_DWORD *)(a1 + 12);
  v10 = 0;
  for ( i = 0; i < v9; ++i )
  {
    v12 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 4 * i);
    if ( v12 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v12 + 8))(v12);
  }
  if ( sub_5BDE60((_DWORD *)a1, a5) )
  {
    v22 = operator new(0x22Cu);
    *(_DWORD *)&v25[56] = 0;
    if ( v22 )
      v10 = (char *)sub_5BD820();
    *(_DWORD *)&v25[56] = -1;
    while ( sub_5BE300(a1, (int)a5, (int)v10, 0, a7) )
      ;
    sub_5BE980();
    (*(void (__thiscall **)(char *, _DWORD, _DWORD, int, _DWORD, char *, _DWORD, _DWORD, int, int))(*(_DWORD *)v10 + 36))(
      v10,
      COERCE_UNSIGNED_INT64(0.0),
      HIDWORD(COERCE_UNSIGNED_INT64(0.0)),
      1,
      0,
      v10,
      v18,
      HIDWORD(v18),
      v19,
      v20);
    v24 = *((_DWORD *)v10 + 111);
    for ( j = 0; j < v24; ++j )
    {
      v14 = *(_DWORD *)(*((_DWORD *)v10 + 113) + 4 * j);
      qmemcpy(v25, (const void *)(v14 + 68), 0x40u);
      v27 = v14;
      sub_5BE470((float *)v25);
      qmemcpy((void *)(v27 + 132), v25, 0x40u);
    }
    (*(void (__thiscall **)(char *, _DWORD, _DWORD, int, _DWORD, void *))(*(_DWORD *)v10 + 36))(
      v10,
      COERCE_UNSIGNED_INT64(0.0),
      HIDWORD(COERCE_UNSIGNED_INT64(0.0)),
      1,
      0,
      v22);
    sub_5BC7F0(v10, 0, 1, 1);
    v15 = *(_DWORD *)(a1 + 12);
    for ( k = 0; k < v15; ++k )
    {
      v17 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 4 * k);
      if ( v17 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v17 + 8))(v17);
    }
    (*(void (__thiscall **)(int *))(*a5 + 112))(a5);
    return v10;
  }
  else
  {
    sub_643E40("Invalid actor file header.");
    return 0;
  }
}
