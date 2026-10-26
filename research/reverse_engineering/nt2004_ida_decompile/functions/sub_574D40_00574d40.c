bool __thiscall sub_574D40(_DWORD *this, _DWORD *a2)
{
  bool v3; // bl
  void *v4; // eax
  DWORD v5; // eax
  int *v6; // eax
  int v7; // ebx
  int v8; // esi
  int v9; // eax
  void *v10; // edi

  v3 = 0;
  v4 = (void *)this[341];
  if ( v4 )
  {
    v5 = WaitForSingleObject(v4, this[342]);
    if ( !v5 || v5 == 128 )
    {
      v6 = (int *)this[337];
      v7 = 0;
      if ( v6 )
      {
        *((_BYTE *)v6 + 8) = 0;
        v7 = *v6;
        if ( *v6 && (v8 = this[337], v9 = 0, v8) )
        {
          while ( *(_DWORD *)v8 != v7 )
          {
            v9 = v8;
            v8 = *(_DWORD *)(v8 + 4);
            if ( !v8 )
              goto LABEL_9;
          }
          if ( v8 == this[339] )
            this[339] = *(_DWORD *)(v8 + 4);
          if ( v9 )
            *(_DWORD *)(v9 + 4) = *(_DWORD *)(v8 + 4);
          else
            this[337] = *(_DWORD *)(v8 + 4);
          if ( this[338] == v8 )
            this[338] = v9;
          --this[340];
          if ( *(_BYTE *)(v8 + 8) && *(_DWORD *)v8 )
          {
            sub_576830(*(void **)v8);
            sub_5BE8AE();
          }
          sub_5BE8AE();
        }
        else
        {
LABEL_9:
          v7 = 0;
        }
      }
      *a2 = v7;
      v3 = v7 != 0;
      v10 = (void *)this[341];
      if ( v10 )
        ReleaseMutex(v10);
    }
  }
  return v3;
}
