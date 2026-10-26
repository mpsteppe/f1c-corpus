int __thiscall sub_40F140(_DWORD *this, char *FileName, int a3)
{
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // eax
  int v4; // ebp
  char v5; // bl
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // edi
  _BYTE v13[4]; // [esp+28h] [ebp-68h] BYREF
  int v14; // [esp+2Ch] [ebp-64h]
  struct _EXCEPTION_REGISTRATION_RECORD *v15; // [esp+84h] [ebp-Ch]
  void *v16; // [esp+88h] [ebp-8h]
  int v17; // [esp+8Ch] [ebp-4h]

  v17 = -1;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  v16 = &loc_6E1098;
  v15 = ExceptionList;
  v4 = 0;
  v5 = 0;
  if ( FileName )
  {
    _chmod(FileName, 128);
    sub_613B30(v13);
    v17 = 0;
    if ( a3 )
      sub_6146B0(FileName, 0, 1, 1, 1);
    else
      sub_614810(FileName, 0, 1, 1);
    if ( v14 )
    {
      v7 = this[4];
      if ( v7 )
      {
        (*(void (__stdcall **)(_BYTE *, _DWORD))(*(_DWORD *)v7 + 8))(v13, 0);
        v5 = 1;
      }
      v8 = this[5];
      if ( v8 )
      {
        (*(void (__stdcall **)(_BYTE *, _DWORD))(*(_DWORD *)v8 + 8))(v13, 0);
        v5 = 1;
      }
      v9 = this[6];
      if ( v9 )
      {
        (*(void (__stdcall **)(_BYTE *, _DWORD))(*(_DWORD *)v9 + 8))(v13, 0);
        v5 = 1;
      }
      v10 = this[7];
      if ( v10 )
      {
        (*(void (__stdcall **)(_BYTE *, _DWORD))(*(_DWORD *)v10 + 8))(v13, 0);
        v5 = 1;
      }
      if ( (int)this[14] > 0 )
      {
        v5 = 1;
        v11 = 0;
        do
        {
          (*(void (__thiscall **)(int, _BYTE *, _DWORD))(*(_DWORD *)(v11 + this[8]) + 8))(v11 + this[8], v13, 0);
          ++v4;
          v11 += 204;
        }
        while ( v4 < this[14] );
      }
      sub_613C30(v13);
      if ( v5 )
      {
        v17 = -1;
        sub_614140(v13);
        return 0;
      }
    }
    v17 = -1;
    sub_614140(v13);
  }
  return 1;
}
