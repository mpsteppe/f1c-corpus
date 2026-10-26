// positive sp value has been detected, the output may be wrong!
char __userpurge sub_4E03A7@<al>(void *a1@<ecx>, void *a2@<esi>, const char *a3)
{
  int v4; // esi
  const CHAR *v5; // eax
  int v6; // eax
  void (__thiscall ***v7)(_DWORD, int); // esi
  char *v8; // eax
  char *v9; // edi
  int v10; // eax
  CHAR *v11; // [esp-8h] [ebp-38h]
  _DWORD v13[4]; // [esp+8h] [ebp-28h] BYREF
  int v14; // [esp+18h] [ebp-18h]
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+24h] [ebp-Ch]

  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v13[1] = a1;
  if ( !a3 )
    return 0;
  if ( sub_4DE300(a1, (int)a3) )
    return 1;
  v4 = dword_BE1D0C;
  if ( !dword_BE1D0C )
    return 0;
  v5 = (const CHAR *)dword_91CAA8;
  if ( !dword_91CAA8 )
    v5 = WindowName;
  v11 = (CHAR *)v5;
  (*(void (__thiscall **)(int))(*(_DWORD *)dword_BE1D0C + 68))(dword_BE1D0C);
  sub_40B430();
  ExceptionList = 0;
  sub_615860(a3);
  v13[2] = 0;
  v13[3] = 0;
  LOBYTE(v14) = 0;
  v6 = (*(int (__thiscall **)(int, _DWORD *, _DWORD, int))(*(_DWORD *)v4 + 92))(v4, v13, 0, 15);
  v7 = (void (__thiscall ***)(_DWORD, int))v6;
  if ( !v6 )
  {
LABEL_11:
    if ( v11 )
      j_j__free(v11);
    return 0;
  }
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 20))(v6) )
  {
    (**v7)(v7, 1);
    goto LABEL_11;
  }
  v8 = (char *)operator new(0x58u);
  if ( v8 )
  {
    *((_DWORD *)v8 + 20) = 0;
    *((_DWORD *)v8 + 21) = 0;
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  strcpy(v9, a3);
  *((_DWORD *)v9 + 20) = v7;
  v10 = *((_DWORD *)v11 + 85);
  if ( v10 )
  {
    for ( ; *(_DWORD *)(v10 + 84); v10 = *(_DWORD *)(v10 + 84) )
      ;
    *(_DWORD *)(v10 + 84) = v9;
  }
  else
  {
    *((_DWORD *)v11 + 85) = v9;
  }
  ++*((_DWORD *)v11 + 86);
  if ( a2 )
    j_j__free(a2);
  return 1;
}
