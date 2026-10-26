int __thiscall sub_5A5A90(char *this)
{
  char *v1; // edi
  void *v2; // eax
  char v3; // bl
  DWORD v4; // eax
  int v5; // eax
  int v6; // esi
  void *v7; // eax
  DWORD v8; // eax
  int *v9; // edi
  int v10; // esi
  void *v11; // ecx
  int v12; // eax
  void *v13; // ebp
  int result; // eax
  int v15; // [esp-8h] [ebp-1Ch]

  v1 = this + 1364;
  while ( 1 )
  {
    v2 = (void *)*((_DWORD *)v1 + 4);
    v3 = 0;
    if ( !v2 )
      break;
    v4 = WaitForSingleObject(v2, *((_DWORD *)v1 + 5));
    if ( v4 )
    {
      if ( v4 != 128 )
        break;
    }
    v5 = *(_DWORD *)v1;
    v6 = 0;
    if ( *(_DWORD *)v1 )
    {
      v6 = *(_DWORD *)v5;
      v15 = *(_DWORD *)v5;
      *(_BYTE *)(v5 + 8) = 0;
      if ( sub_59F9F0((int *)v1, v15, 1) )
      {
        if ( v6 )
          v3 = 1;
      }
      else
      {
        v6 = 0;
      }
    }
    if ( *((_DWORD *)v1 + 4) )
      ReleaseMutex(*((HANDLE *)v1 + 4));
    if ( !v3 )
      break;
    (*(void (__thiscall **)(char *, int))(*(_DWORD *)this + 92))(this, v6);
  }
  v7 = (void *)*((_DWORD *)this + 366);
  if ( v7 && ((v8 = WaitForSingleObject(v7, *((_DWORD *)this + 367))) == 0 || v8 == 128) )
    v9 = (int *)(this + 1448);
  else
    v9 = 0;
LABEL_19:
  while ( v9[3] > 0 )
  {
    v10 = *v9;
    if ( !*v9 )
      break;
    v11 = *(void **)v10;
    if ( !*(_DWORD *)v10 )
      break;
    v12 = 0;
    if ( v10 )
    {
      while ( *(void **)v10 != v11 )
      {
        v12 = v10;
        v10 = *(_DWORD *)(v10 + 4);
        if ( !v10 )
          goto LABEL_19;
      }
      if ( v10 == v9[2] )
        v9[2] = *(_DWORD *)(v10 + 4);
      if ( v12 )
        *(_DWORD *)(v12 + 4) = *(_DWORD *)(v10 + 4);
      else
        *v9 = *(_DWORD *)(v10 + 4);
      if ( v9[1] == v10 )
        v9[1] = v12;
      --v9[3];
      if ( *(_BYTE *)(v10 + 8) )
      {
        v13 = *(void **)v10;
        if ( *(_DWORD *)v10 )
        {
          sub_5A6920(*(void **)v10);
          j__free(v13);
        }
      }
      j__free((void *)v10);
    }
  }
  result = *((_DWORD *)this + 366);
  if ( result )
    return ReleaseMutex(*((HANDLE *)this + 366));
  return result;
}
