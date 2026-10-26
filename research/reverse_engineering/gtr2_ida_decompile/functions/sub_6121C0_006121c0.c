int __thiscall sub_6121C0(_DWORD *this)
{
  int *v2; // eax
  int v3; // ebx
  int v4; // edi
  int v5; // eax
  void *v6; // ebx
  int *v7; // eax
  int *v8; // eax
  int v9; // ebx
  int v10; // edi
  int v11; // eax
  void *v12; // ebx
  int *v13; // eax
  int *v14; // eax
  int v15; // ebx
  int v16; // edi
  int v17; // eax
  void *v18; // ebx
  int *v19; // eax
  int *v20; // eax
  int v21; // ebx
  int v22; // edi
  int v23; // eax
  int *v24; // eax
  int *v25; // eax
  int v26; // ebx
  int v27; // edi
  int v28; // eax
  int *v29; // eax

  v2 = (int *)this[168];
  this[170] = v2;
  if ( v2 )
  {
    v3 = *v2;
    if ( *v2 )
    {
      do
      {
        (*(void (__thiscall **)(_DWORD *, int, _DWORD))(*this + 408))(this, v3, 0);
        v4 = this[168];
        v5 = 0;
        if ( v4 )
        {
          while ( *(_DWORD *)v4 != v3 )
          {
            v5 = v4;
            v4 = *(_DWORD *)(v4 + 4);
            if ( !v4 )
              goto LABEL_18;
          }
          if ( v4 == this[170] )
            this[170] = *(_DWORD *)(v4 + 4);
          if ( v5 )
            *(_DWORD *)(v5 + 4) = *(_DWORD *)(v4 + 4);
          else
            this[168] = *(_DWORD *)(v4 + 4);
          if ( this[169] == v4 )
            this[169] = v5;
          --this[171];
          if ( *(_BYTE *)(v4 + 8) )
          {
            v6 = *(void **)v4;
            if ( *(_DWORD *)v4 )
            {
              nullsub_7(*(void **)v4);
              j__free(v6);
            }
          }
          j__free((void *)v4);
        }
LABEL_18:
        v7 = (int *)this[168];
        this[170] = v7;
        if ( !v7 )
          break;
        v3 = *v7;
      }
      while ( *v7 );
    }
  }
  v8 = (int *)this[173];
  this[175] = v8;
  if ( v8 )
  {
    v9 = *v8;
    if ( *v8 )
    {
      do
      {
        (*(void (__thiscall **)(_DWORD *, int, _DWORD))(*this + 408))(this, v9, 0);
        v10 = this[173];
        v11 = 0;
        if ( v10 )
        {
          while ( *(_DWORD *)v10 != v9 )
          {
            v11 = v10;
            v10 = *(_DWORD *)(v10 + 4);
            if ( !v10 )
              goto LABEL_37;
          }
          if ( v10 == this[175] )
            this[175] = *(_DWORD *)(v10 + 4);
          if ( v11 )
            *(_DWORD *)(v11 + 4) = *(_DWORD *)(v10 + 4);
          else
            this[173] = *(_DWORD *)(v10 + 4);
          if ( this[174] == v10 )
            this[174] = v11;
          --this[176];
          if ( *(_BYTE *)(v10 + 8) )
          {
            v12 = *(void **)v10;
            if ( *(_DWORD *)v10 )
            {
              nullsub_7(*(void **)v10);
              j__free(v12);
            }
          }
          j__free((void *)v10);
        }
LABEL_37:
        v13 = (int *)this[173];
        this[175] = v13;
        if ( !v13 )
          break;
        v9 = *v13;
      }
      while ( *v13 );
    }
  }
  v14 = (int *)this[188];
  this[190] = v14;
  if ( v14 )
  {
    v15 = *v14;
    if ( *v14 )
    {
      do
      {
        (*(void (__thiscall **)(_DWORD *, int, _DWORD))(*this + 408))(this, v15, 0);
        v16 = this[188];
        v17 = 0;
        if ( v16 )
        {
          while ( *(_DWORD *)v16 != v15 )
          {
            v17 = v16;
            v16 = *(_DWORD *)(v16 + 4);
            if ( !v16 )
              goto LABEL_56;
          }
          if ( v16 == this[190] )
            this[190] = *(_DWORD *)(v16 + 4);
          if ( v17 )
            *(_DWORD *)(v17 + 4) = *(_DWORD *)(v16 + 4);
          else
            this[188] = *(_DWORD *)(v16 + 4);
          if ( this[189] == v16 )
            this[189] = v17;
          --this[191];
          if ( *(_BYTE *)(v16 + 8) )
          {
            v18 = *(void **)v16;
            if ( *(_DWORD *)v16 )
            {
              nullsub_7(*(void **)v16);
              j__free(v18);
            }
          }
          j__free((void *)v16);
        }
LABEL_56:
        v19 = (int *)this[188];
        this[190] = v19;
        if ( !v19 )
          break;
        v15 = *v19;
      }
      while ( *v19 );
    }
  }
  v20 = (int *)this[178];
  this[180] = v20;
  if ( v20 )
  {
    v21 = *v20;
    if ( *v20 )
    {
      do
      {
        (*(void (__thiscall **)(_DWORD *, int))(*this + 448))(this, v21);
        v22 = this[178];
        v23 = 0;
        if ( v22 )
        {
          while ( *(_DWORD *)v22 != v21 )
          {
            v23 = v22;
            v22 = *(_DWORD *)(v22 + 4);
            if ( !v22 )
              goto LABEL_75;
          }
          if ( v22 == this[180] )
            this[180] = *(_DWORD *)(v22 + 4);
          if ( v23 )
            *(_DWORD *)(v23 + 4) = *(_DWORD *)(v22 + 4);
          else
            this[178] = *(_DWORD *)(v22 + 4);
          if ( this[179] == v22 )
            this[179] = v23;
          --this[181];
          if ( *(_BYTE *)(v22 + 8) && *(_DWORD *)v22 )
            j__free(*(void **)v22);
          j__free((void *)v22);
        }
LABEL_75:
        v24 = (int *)this[178];
        this[180] = v24;
        if ( !v24 )
          break;
        v21 = *v24;
      }
      while ( *v24 );
    }
  }
  v25 = (int *)this[183];
  this[185] = v25;
  if ( v25 )
  {
    v26 = *v25;
    if ( *v25 )
    {
      do
      {
        (*(void (__thiscall **)(_DWORD *, int))(*this + 448))(this, v26);
        v27 = this[183];
        v28 = 0;
        if ( v27 )
        {
          while ( *(_DWORD *)v27 != v26 )
          {
            v28 = v27;
            v27 = *(_DWORD *)(v27 + 4);
            if ( !v27 )
              goto LABEL_94;
          }
          if ( v27 == this[185] )
            this[185] = *(_DWORD *)(v27 + 4);
          if ( v28 )
            *(_DWORD *)(v28 + 4) = *(_DWORD *)(v27 + 4);
          else
            this[183] = *(_DWORD *)(v27 + 4);
          if ( this[184] == v27 )
            this[184] = v28;
          --this[186];
          if ( *(_BYTE *)(v27 + 8) && *(_DWORD *)v27 )
            j__free(*(void **)v27);
          j__free((void *)v27);
        }
LABEL_94:
        v29 = (int *)this[183];
        this[185] = v29;
        if ( !v29 )
          break;
        v26 = *v29;
      }
      while ( *v29 );
    }
  }
  return 0;
}
