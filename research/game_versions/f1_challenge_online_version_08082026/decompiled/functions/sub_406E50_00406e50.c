int __thiscall sub_406E50(_DWORD *this)
{
  int result; // eax
  int *v3; // eax
  int v4; // ecx
  int *v5; // eax
  int v6; // edi
  _DWORD *v7; // ebp
  char v8; // al
  int v9; // edi
  LPVOID **v10; // ebx
  char v11; // al
  LPVOID *v12; // ebp
  int v13; // edi
  _DWORD **v14; // ebp
  char v15; // al
  void *v16; // ebx

  result = this[34];
  if ( result )
  {
    v3 = (int *)this[2];
    this[4] = v3;
    if ( v3 )
    {
      v4 = *v3;
      if ( *v3 )
      {
        do
        {
          (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 24))(v4);
          v5 = (int *)this[2];
          this[4] = v5;
          if ( !v5 )
            break;
          v4 = *v5;
        }
        while ( *v5 );
      }
    }
    v6 = this[6];
    while ( v6 )
    {
      v7 = (_DWORD *)v6;
      v8 = *(_BYTE *)(v6 + 8);
      v6 = *(_DWORD *)(v6 + 4);
      if ( v8 && *v7 )
        (**(void (__thiscall ***)(_DWORD, int))*v7)(*v7, 1);
      sub_587BCF(v7);
    }
    this[6] = 0;
    this[7] = 0;
    this[8] = 0;
    this[9] = 0;
    v9 = this[10];
    while ( v9 )
    {
      v10 = (LPVOID **)v9;
      v11 = *(_BYTE *)(v9 + 8);
      v9 = *(_DWORD *)(v9 + 4);
      if ( v11 )
      {
        v12 = *v10;
        if ( *v10 )
        {
          if ( *v12 )
            sub_587BCF(*v12);
          sub_587BCF(v12);
        }
      }
      sub_587BCF(v10);
    }
    this[10] = 0;
    this[11] = 0;
    this[12] = 0;
    this[13] = 0;
    v13 = this[14];
    while ( v13 )
    {
      v14 = (_DWORD **)v13;
      v15 = *(_BYTE *)(v13 + 8);
      v13 = *(_DWORD *)(v13 + 4);
      if ( v15 )
      {
        v16 = *v14;
        if ( *v14 )
        {
          sub_405410(*v14);
          sub_587BCF(v16);
        }
      }
      sub_587BCF(v14);
    }
    this[14] = 0;
    this[15] = 0;
    this[16] = 0;
    this[17] = 0;
    (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 52))(this, 0);
    if ( this[36] )
    {
      AIL_waveOutClose(this[36]);
      this[36] = 0;
    }
    result = AIL_shutdown();
    this[34] = 0;
  }
  return result;
}
