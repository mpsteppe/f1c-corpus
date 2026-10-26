char __thiscall sub_581C20(int this)
{
  _DWORD *v1; // ebx
  int v2; // eax
  _DWORD *v3; // ebp
  int i; // esi
  _BYTE *v5; // edi
  void *v6; // ebx
  _DWORD *v7; // edi
  _BYTE *v8; // ebx
  int *v9; // ebp
  int v10; // eax
  void *v11; // esi

  v1 = (_DWORD *)this;
  LOBYTE(v2) = *(_BYTE *)(this + 40);
  if ( (_BYTE)v2 )
  {
    v2 = CloseHandle(*(HANDLE *)(this + 32));
    if ( v2 )
      v1[8] = 0;
  }
  v3 = v1 + 4;
  for ( i = v1[4]; i; LOBYTE(v2) = sub_587BCF(v5) )
  {
    v5 = (_BYTE *)i;
    i = *(_DWORD *)(i + 4);
    if ( v5[8] )
    {
      v6 = *(void **)v5;
      if ( *(_DWORD *)v5 )
      {
        sub_5867B0(*(_DWORD *)v5);
        sub_587BCF(v6);
      }
      v1 = (_DWORD *)this;
    }
  }
  *v3 = 0;
  v3[1] = 0;
  v3[2] = 0;
  v3[3] = 0;
  v7 = (_DWORD *)*v1;
  if ( *v1 )
  {
    do
    {
      v8 = v7;
      v7 = (_DWORD *)v7[1];
      if ( v8[8] )
      {
        v9 = *(int **)v8;
        if ( *(_DWORD *)v8 )
        {
          v10 = *v9;
          if ( *v9 )
          {
            v11 = (void *)(v10 - 4);
            sub_58A5F7(v10, 84, *(_DWORD *)(v10 - 4), sub_5867B0);
            sub_587BCF(v11);
          }
          sub_587BCF(v9);
        }
      }
      LOBYTE(v2) = sub_587BCF(v8);
    }
    while ( v7 );
    v1 = (_DWORD *)this;
  }
  *v1 = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[3] = 0;
  return v2;
}
