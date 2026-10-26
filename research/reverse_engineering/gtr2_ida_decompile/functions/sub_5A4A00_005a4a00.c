int __thiscall sub_5A4A00(char *this, int a2, char a3)
{
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  void *v5; // eax
  void *v6; // eax
  DWORD v7; // eax
  int *v8; // eax
  void *v9; // edi
  int v10; // ebp
  void *v11; // eax
  char *v12; // edi
  char v13; // bl
  DWORD v14; // eax
  char *v15; // eax
  int v16; // edx
  int v17; // ebx
  int v18; // edi
  void *v19; // eax
  char v21; // [esp+51h] [ebp-341h]
  int v22; // [esp+52h] [ebp-340h]
  void *Block[2]; // [esp+56h] [ebp-33Ch] BYREF
  void *v24; // [esp+5Eh] [ebp-334h]
  int v25; // [esp+62h] [ebp-330h]
  char *v26; // [esp+66h] [ebp-32Ch]
  _BYTE v27[784]; // [esp+6Ah] [ebp-328h] BYREF
  struct _EXCEPTION_REGISTRATION_RECORD *v28; // [esp+386h] [ebp-Ch]
  void *v29; // [esp+38Ah] [ebp-8h]
  int v30; // [esp+38Eh] [ebp-4h]

  v30 = -1;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v29 = &loc_6EA676;
  v28 = ExceptionList;
  v5 = (void *)*((_DWORD *)this + 370);
  if ( v5 )
    WaitForSingleObject(v5, *((_DWORD *)this + 371));
  if ( *((_DWORD *)this + 370) )
    ReleaseMutex(*((HANDLE *)this + 370));
  v6 = (void *)*((_DWORD *)this + 64);
  if ( v6 && ((v7 = WaitForSingleObject(v6, *((_DWORD *)this + 65))) == 0 || v7 == 128) )
    v8 = (int *)(this + 252);
  else
    v8 = 0;
  v9 = (void *)*((_DWORD *)this + 64);
  v10 = *v8;
  if ( v9 )
    ReleaseMutex(v9);
  sub_5A6CF0(v27, -1, 255, 0);
  v11 = (void *)*((_DWORD *)this + 404);
  v12 = this + 1588;
  v13 = 0;
  v30 = 0;
  v21 = 0;
  v26 = this + 1588;
  if ( v11 && ((v14 = WaitForSingleObject(v11, *((_DWORD *)this + 405))) == 0 || v14 == 128) )
    v15 = this + 1588;
  else
    v15 = 0;
  if ( a3 || v15[25] )
  {
    sub_5A7010(v27, v15);
    v13 = 1;
  }
  if ( *((_DWORD *)this + 404) )
    ReleaseMutex(*((HANDLE *)this + 404));
  Block[0] = 0;
  Block[1] = 0;
  v24 = 0;
  v25 = 0;
  v16 = *(_DWORD *)this;
  LOBYTE(v30) = 1;
  (*(void (__thiscall **)(char *))(v16 + 204))(this);
  if ( v13 )
    v21 = (*(int (__thiscall **)(char *, int, _BYTE *, int))(*(_DWORD *)this + 184))(this, v10, v27, 1);
  v17 = (*(int (__thiscall **)(char *))(*(_DWORD *)this + 164))(this);
  LOBYTE(v22) = 0;
  if ( v17 > 0 )
  {
    do
    {
      v18 = (*(int (__thiscall **)(char *))(*(_DWORD *)this + 28))(this);
      if ( !(*(unsigned __int8 (__thiscall **)(char *, int, int))(*(_DWORD *)this + 176))(this, v22, v18)
        || !a3 && !*(_BYTE *)(v18 + 25)
        || a2 == v10
        || !(unsigned __int8)sub_5FDFB0(v18, 0) )
      {
        (*(void (__thiscall **)(char *, int))(*(_DWORD *)this + 32))(this, v18);
      }
      LOBYTE(v22) = v22 + 1;
    }
    while ( (unsigned __int8)v22 < v17 );
    v12 = v26;
  }
  (*(void (__thiscall **)(char *))(*(_DWORD *)this + 208))(this);
  v27[28] = 0;
  v24 = Block[0];
  if ( v21 )
  {
    v19 = (void *)*((_DWORD *)v12 + 7);
    if ( v19 )
      WaitForSingleObject(v19, *((_DWORD *)v12 + 8));
    sub_5A6EC0(0);
    if ( *((_DWORD *)v12 + 7) )
      ReleaseMutex(*((HANDLE *)v12 + 7));
  }
  LOBYTE(v30) = 0;
  sub_59EAD0((int *)Block);
  v30 = -1;
  return sub_5A6D70(v27);
}
