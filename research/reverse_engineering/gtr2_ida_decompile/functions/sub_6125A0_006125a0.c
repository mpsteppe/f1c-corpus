int *__thiscall sub_6125A0(_DWORD *this)
{
  _DWORD **v2; // eax
  _DWORD *v3; // ebx
  int v4; // eax
  int v5; // edi
  int v6; // eax
  _DWORD *v7; // ebp
  _DWORD **v8; // eax
  _DWORD **v9; // eax
  _DWORD *v10; // ebx
  int v11; // eax
  int v12; // edi
  int v13; // eax
  _DWORD *v14; // ebp
  _DWORD **v15; // eax
  _DWORD **v16; // eax
  _DWORD *v17; // ebx
  int v18; // eax
  int v19; // edi
  int v20; // eax
  _DWORD *v21; // ebp
  _DWORD **v22; // eax
  int *v23; // eax
  int v24; // ebx
  int v25; // eax
  int v26; // edi
  int v27; // eax
  int *v28; // eax
  int *result; // eax
  int i; // ebx
  int v31; // eax
  int v32; // edi
  int v33; // eax

  v2 = (_DWORD **)this[168];
  this[170] = v2;
  if ( v2 )
  {
    v3 = *v2;
    if ( *v2 )
    {
      do
      {
        if ( (*v3 & 0x20000) != 0 || !v3[3] )
        {
          sub_60B4D0();
          v5 = this[168];
          v6 = 0;
          if ( v5 )
          {
            while ( *(_DWORD **)v5 != v3 )
            {
              v6 = v5;
              v5 = *(_DWORD *)(v5 + 4);
              if ( !v5 )
                goto LABEL_22;
            }
            if ( v5 == this[170] )
              this[170] = *(_DWORD *)(v5 + 4);
            if ( v6 )
              *(_DWORD *)(v6 + 4) = *(_DWORD *)(v5 + 4);
            else
              this[168] = *(_DWORD *)(v5 + 4);
            if ( this[169] == v5 )
              this[169] = v6;
            --this[171];
            if ( *(_BYTE *)(v5 + 8) )
            {
              v7 = *(_DWORD **)v5;
              if ( *(_DWORD *)v5 )
              {
                nullsub_7(*(void **)v5);
                j__free(v7);
              }
            }
            j__free((void *)v5);
          }
LABEL_22:
          nullsub_7(v3);
          j__free(v3);
        }
        else
        {
          v4 = this[170];
          if ( v4 )
            this[170] = *(_DWORD *)(v4 + 4);
        }
        v8 = (_DWORD **)this[170];
        if ( !v8 )
          break;
        v3 = *v8;
      }
      while ( *v8 );
    }
  }
  v9 = (_DWORD **)this[173];
  this[175] = v9;
  if ( v9 )
  {
    v10 = *v9;
    if ( *v9 )
    {
      do
      {
        if ( (*v10 & 0x20000) != 0 || !v10[3] )
        {
          sub_60B4D0();
          v12 = this[173];
          v13 = 0;
          if ( v12 )
          {
            while ( *(_DWORD **)v12 != v10 )
            {
              v13 = v12;
              v12 = *(_DWORD *)(v12 + 4);
              if ( !v12 )
                goto LABEL_46;
            }
            if ( v12 == this[175] )
              this[175] = *(_DWORD *)(v12 + 4);
            if ( v13 )
              *(_DWORD *)(v13 + 4) = *(_DWORD *)(v12 + 4);
            else
              this[173] = *(_DWORD *)(v12 + 4);
            if ( this[174] == v12 )
              this[174] = v13;
            --this[176];
            if ( *(_BYTE *)(v12 + 8) )
            {
              v14 = *(_DWORD **)v12;
              if ( *(_DWORD *)v12 )
              {
                nullsub_7(*(void **)v12);
                j__free(v14);
              }
            }
            j__free((void *)v12);
          }
LABEL_46:
          nullsub_7(v10);
          j__free(v10);
        }
        else
        {
          v11 = this[175];
          if ( v11 )
            this[175] = *(_DWORD *)(v11 + 4);
        }
        v15 = (_DWORD **)this[175];
        if ( !v15 )
          break;
        v10 = *v15;
      }
      while ( *v15 );
    }
  }
  v16 = (_DWORD **)this[188];
  this[190] = v16;
  if ( v16 )
  {
    v17 = *v16;
    if ( *v16 )
    {
      do
      {
        if ( (*v17 & 0x20000) != 0 || !v17[3] )
        {
          sub_60B4D0();
          v19 = this[188];
          v20 = 0;
          if ( v19 )
          {
            while ( *(_DWORD **)v19 != v17 )
            {
              v20 = v19;
              v19 = *(_DWORD *)(v19 + 4);
              if ( !v19 )
                goto LABEL_70;
            }
            if ( v19 == this[190] )
              this[190] = *(_DWORD *)(v19 + 4);
            if ( v20 )
              *(_DWORD *)(v20 + 4) = *(_DWORD *)(v19 + 4);
            else
              this[188] = *(_DWORD *)(v19 + 4);
            if ( this[189] == v19 )
              this[189] = v20;
            --this[191];
            if ( *(_BYTE *)(v19 + 8) )
            {
              v21 = *(_DWORD **)v19;
              if ( *(_DWORD *)v19 )
              {
                nullsub_7(*(void **)v19);
                j__free(v21);
              }
            }
            j__free((void *)v19);
          }
LABEL_70:
          nullsub_7(v17);
          j__free(v17);
        }
        else
        {
          v18 = this[190];
          if ( v18 )
            this[190] = *(_DWORD *)(v18 + 4);
        }
        v22 = (_DWORD **)this[190];
        if ( !v22 )
          break;
        v17 = *v22;
      }
      while ( *v22 );
    }
  }
  v23 = (int *)this[178];
  this[180] = v23;
  if ( v23 )
  {
    v24 = *v23;
    if ( *v23 )
    {
      do
      {
        if ( (*(_DWORD *)v24 & 0x20000) != 0 || !*(_DWORD *)(v24 + 12) )
        {
          sub_60BA90((char *)v24);
          v26 = this[178];
          v27 = 0;
          if ( v26 )
          {
            while ( *(_DWORD *)v26 != v24 )
            {
              v27 = v26;
              v26 = *(_DWORD *)(v26 + 4);
              if ( !v26 )
                goto LABEL_94;
            }
            if ( v26 == this[180] )
              this[180] = *(_DWORD *)(v26 + 4);
            if ( v27 )
              *(_DWORD *)(v27 + 4) = *(_DWORD *)(v26 + 4);
            else
              this[178] = *(_DWORD *)(v26 + 4);
            if ( this[179] == v26 )
              this[179] = v27;
            --this[181];
            if ( *(_BYTE *)(v26 + 8) && *(_DWORD *)v26 )
              j__free(*(void **)v26);
            j__free((void *)v26);
          }
LABEL_94:
          j__free((void *)v24);
        }
        else
        {
          v25 = this[180];
          if ( v25 )
            this[180] = *(_DWORD *)(v25 + 4);
        }
        v28 = (int *)this[180];
        if ( !v28 )
          break;
        v24 = *v28;
      }
      while ( *v28 );
    }
  }
  result = (int *)this[183];
  this[185] = result;
  if ( result )
  {
    for ( i = *result; *result; i = *result )
    {
      if ( (*(_DWORD *)i & 0x20000) != 0 || !*(_DWORD *)(i + 12) )
      {
        sub_60BA90((char *)i);
        v32 = this[183];
        v33 = 0;
        if ( v32 )
        {
          while ( *(_DWORD *)v32 != i )
          {
            v33 = v32;
            v32 = *(_DWORD *)(v32 + 4);
            if ( !v32 )
              goto LABEL_118;
          }
          if ( v32 == this[185] )
            this[185] = *(_DWORD *)(v32 + 4);
          if ( v33 )
            *(_DWORD *)(v33 + 4) = *(_DWORD *)(v32 + 4);
          else
            this[183] = *(_DWORD *)(v32 + 4);
          if ( this[184] == v32 )
            this[184] = v33;
          --this[186];
          if ( *(_BYTE *)(v32 + 8) && *(_DWORD *)v32 )
            j__free(*(void **)v32);
          j__free((void *)v32);
        }
LABEL_118:
        j__free((void *)i);
      }
      else
      {
        v31 = this[185];
        if ( v31 )
          this[185] = *(_DWORD *)(v31 + 4);
      }
      result = (int *)this[185];
      if ( !result )
        break;
    }
  }
  return result;
}
