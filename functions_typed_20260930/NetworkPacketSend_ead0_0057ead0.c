char __thiscall sub_57EAD0(_DWORD *this, u_long a2)
{
  void *v3; // eax
  DWORD v4; // eax
  u_long **v5; // eax
  u_long v6; // ebp
  u_long *v7; // eax
  u_long *v8; // esi
  int v9; // eax
  u_long v10; // edx
  int v11; // ecx
  void *v12; // edi
  int v14; // [esp+8h] [ebp-10h] BYREF
  u_long v15; // [esp+Ch] [ebp-Ch]

  v15 = htonl(0);
  htons(0);
  Copy4DwordsStructToStruct(this + 673, &v14);
  v3 = (void *)this[708];
  if ( !v3 )
    return 0;
  v4 = WaitForSingleObject(v3, this[709]);
  if ( v4 )
  {
    if ( v4 != 128 )
      return 0;
  }
  v5 = (u_long **)this[704];
  v6 = v15;
  if ( !v5 )
    goto LABEL_8;
  while ( !*v5 || **v5 != v15 )
  {
    v5 = (u_long **)v5[1];
    if ( !v5 )
      goto LABEL_8;
  }
  v8 = *v5;
  if ( *v5 )
  {
    v8[1] = a2;
  }
  else
  {
LABEL_8:
    v7 = (u_long *)OperatorNewNhMallocWrapper(16);
    if ( v7 )
    {
      *v7 = v6;
      v7[1] = 0;
      v7[2] = 0;
      v7[3] = 0;
      v8 = v7;
    }
    else
    {
      v8 = 0;
    }
    if ( v8 )
    {
      v9 = OperatorNewNhMallocWrapper(12);
      if ( v9 )
      {
        *(_DWORD *)v9 = v8;
        *(_DWORD *)(v9 + 4) = 0;
        *(_BYTE *)(v9 + 8) = 1;
      }
      else
      {
        v9 = 0;
      }
      if ( this[704] )
      {
        *(_DWORD *)(this[705] + 4) = v9;
      }
      else
      {
        this[704] = v9;
        this[706] = v9;
      }
      this[705] = v9;
      ++this[707];
    }
  }
  v10 = a2 + v8[2];
  v11 = v8[3] + 1;
  v8[1] = a2;
  v8[2] = v10;
  v8[3] = v11;
  v12 = (void *)this[708];
  if ( v12 )
    ReleaseMutex(v12);
  return 1;
}

