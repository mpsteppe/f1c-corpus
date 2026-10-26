BOOL __thiscall sub_40D950(_DWORD *this, char *FileName, int a3)
{
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  int v4; // ebp
  char v5; // bl
  int v8; // edi
  _BYTE v9[4]; // [esp+8h] [ebp-68h] BYREF
  int v10; // [esp+Ch] [ebp-64h]
  struct _EXCEPTION_REGISTRATION_RECORD *v11; // [esp+64h] [ebp-Ch]
  void *v12; // [esp+68h] [ebp-8h]
  int v13; // [esp+6Ch] [ebp-4h]

  v13 = -1;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v12 = &loc_6E1098;
  v11 = ExceptionList;
  v4 = 0;
  v5 = 0;
  if ( !FileName || !this[3] )
    return 1;
  _chmod(FileName, 128);
  sub_613B30(v9);
  v13 = 0;
  if ( a3 )
    sub_6146B0(FileName, 0, 1, 1, 1);
  else
    sub_614810(FileName, 0, 1, 1);
  if ( !v10 )
  {
    v13 = -1;
    sub_614140(v9);
    return 1;
  }
  if ( (int)this[4] > 0 )
  {
    v8 = 0;
    do
    {
      if ( !(*(int (__thiscall **)(int, _BYTE *, _DWORD))(*(_DWORD *)(this[3] + v8) + 8))(this[3] + v8, v9, 0) )
        v5 = 1;
      ++v4;
      v8 += 164;
    }
    while ( v4 < this[4] );
  }
  sub_613C30(v9);
  v13 = -1;
  sub_614140(v9);
  return !v5;
}
