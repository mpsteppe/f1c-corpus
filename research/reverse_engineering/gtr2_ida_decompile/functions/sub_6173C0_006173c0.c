char *__thiscall sub_6173C0(void *this, char *Buffer, unsigned int MaxCount)
{
  bool v5; // zf
  int v6; // eax
  const char *v7; // ecx
  unsigned int v8; // ebx
  char *v9; // esi
  int v10; // eax
  bool v11; // cc
  const char *v12; // esi
  int v13; // eax
  int v14; // ecx
  int v15; // eax

  if ( !*((_BYTE *)this + 92) )
    return sub_613DE0((int)this, Buffer, MaxCount);
  v5 = *((_DWORD *)this + 31) == -1;
  *((_BYTE *)this + 132) = 1;
  if ( v5 )
  {
    *((_DWORD *)this + 32) = (*(int (__thiscall **)(void *, _DWORD, _DWORD))(*(_DWORD *)this + 28))(
                               this,
                               *((_DWORD *)this + 29),
                               *((_DWORD *)this + 30));
    *((_DWORD *)this + 31) = 0;
  }
  v6 = *((_DWORD *)this + 31);
  if ( v6 >= *((_DWORD *)this + 32) )
    return 0;
  v7 = (const char *)(v6 + *((_DWORD *)this + 29));
  if ( strlen(v7) >= MaxCount )
    v8 = MaxCount;
  else
    v8 = strlen(v7);
  v9 = Buffer;
  sub_630FE0(Buffer);
  Buffer[v8] = 0;
  if ( (signed int)(v8 + *((_DWORD *)this + 31)) >= *((_DWORD *)this + 30) )
  {
    v10 = (*(int (__thiscall **)(void *, _DWORD, _DWORD))(*(_DWORD *)this + 28))(
            this,
            *((_DWORD *)this + 29),
            *((_DWORD *)this + 30));
    v11 = v10 < *((_DWORD *)this + 30);
    *((_DWORD *)this + 32) = v10;
    if ( v11 )
      *(_BYTE *)(v10 + *((_DWORD *)this + 29)) = 0;
    v12 = (const char *)*((_DWORD *)this + 29);
    *((_DWORD *)this + 31) = 0;
    if ( strlen(v12) >= MaxCount - v8 )
      v8 = MaxCount - v8;
    else
      v8 = strlen(v12);
    strcat(Buffer, v12);
    v9 = Buffer;
  }
  v13 = *((_DWORD *)this + 30);
  v14 = v8 + 1 + *((_DWORD *)this + 31);
  *((_DWORD *)this + 31) = v14;
  if ( v14 >= v13 )
  {
    v15 = (*(int (__thiscall **)(void *, _DWORD, int))(*(_DWORD *)this + 28))(this, *((_DWORD *)this + 29), v13);
    v11 = v15 < *((_DWORD *)this + 30);
    *((_DWORD *)this + 32) = v15;
    if ( v11 )
      *(_BYTE *)(v15 + *((_DWORD *)this + 29)) = 0;
    *((_DWORD *)this + 31) = 0;
  }
  return v9;
}
