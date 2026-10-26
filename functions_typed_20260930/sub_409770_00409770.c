int __thiscall sub_409770(_DWORD *this, LPCSTR lpFileName, int a3)
{
  char v3; // bl
  int v5; // ecx
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  int v9; // ebp
  int v10; // edi
  int v12[7]; // [esp+28h] [ebp-1Ch] BYREF

  v3 = 0;
  if ( lpFileName )
  {
    ToggleFileReadOnlyAttributeViaWin32API(lpFileName, 128);
    ZeroInitSmallStruct(v12);
    if ( a3 )
      sub_566940(v12, lpFileName, 0, 1, 1);
    else
      sub_566A70(v12, lpFileName, 0, 1, 1);
    if ( v12[0] )
    {
      v5 = this[4];
      if ( v5 )
      {
        (*(void (__thiscall **)(int, int *, _DWORD))(*(_DWORD *)v5 + 8))(v5, v12, 0);
        v3 = 1;
      }
      v6 = this[5];
      if ( v6 )
      {
        (*(void (__thiscall **)(int, int *, _DWORD))(*(_DWORD *)v6 + 8))(v6, v12, 0);
        v3 = 1;
      }
      v7 = this[6];
      if ( v7 )
      {
        (*(void (__thiscall **)(int, int *, _DWORD))(*(_DWORD *)v7 + 8))(v7, v12, 0);
        v3 = 1;
      }
      v8 = this[7];
      if ( v8 )
      {
        (*(void (__thiscall **)(int, int *, _DWORD))(*(_DWORD *)v8 + 8))(v8, v12, 0);
        v3 = 1;
      }
      v9 = 0;
      if ( (int)this[14] > 0 )
      {
        v3 = 1;
        v10 = 0;
        do
        {
          (*(void (__thiscall **)(int, int *, _DWORD))(*(_DWORD *)(v10 + this[8]) + 8))(v10 + this[8], v12, 0);
          ++v9;
          v10 += 200;
        }
        while ( v9 < this[14] );
      }
      ConditionalFileHandleCloseWithFlagDispatch(v12);
      if ( v3 )
      {
        SubCallWithConditionalFieldFree(v12);
        return 0;
      }
    }
    SubCallWithConditionalFieldFree(v12);
  }
  return 1;
}

