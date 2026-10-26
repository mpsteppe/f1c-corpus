int __thiscall sub_5A3860(_DWORD *this)
{
  int result; // eax
  void *v3; // eax
  int *v4; // ebx
  DWORD v5; // eax
  int *v6; // edi
  int *v7; // eax
  bool v8; // zf
  int v9; // esi
  void (__thiscall **v10)(_DWORD, _DWORD, _DWORD, _DWORD); // edi
  int v11; // esi
  _DWORD *v12; // eax
  int *v13; // eax
  int v14; // eax
  int (__thiscall **v15)(void (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD)); // ebx
  int v16; // eax
  _DWORD *v17; // eax
  int *v18; // eax
  int v19; // esi
  int v20; // ebx
  int v21; // eax
  int *v22; // eax
  void *v23; // eax
  DWORD v24; // eax
  int *v25; // esi
  int v26; // eax
  int *v27; // eax
  int v28; // edi
  int **v29; // eax
  int v30; // eax
  int v31; // eax
  int *v32; // eax
  int v33; // eax
  int *v34; // [esp-14h] [ebp-54h]
  int **v35; // [esp-8h] [ebp-48h]
  void **p_Block; // [esp-4h] [ebp-44h]
  int v37; // [esp+4h] [ebp-3Ch]
  _DWORD *v38; // [esp+Ch] [ebp-34h] BYREF
  int *v39; // [esp+10h] [ebp-30h] BYREF
  int *v40; // [esp+14h] [ebp-2Ch] BYREF
  int v41; // [esp+18h] [ebp-28h] BYREF
  void *Block; // [esp+1Ch] [ebp-24h] BYREF
  int *v43; // [esp+20h] [ebp-20h]
  int v44; // [esp+28h] [ebp-18h]
  int v45; // [esp+2Ch] [ebp-14h]
  int v46; // [esp+30h] [ebp-10h]
  int v47; // [esp+3Ch] [ebp-4h]

  v38 = this;
  result = sub_5A4330(this);
  if ( result == 4 )
  {
    v3 = (void *)this[694];
    v4 = this + 690;
    v39 = v4;
    if ( v3 && ((v5 = WaitForSingleObject(v3, v4[5])) == 0 || v5 == 128) )
      v6 = v4;
    else
      v6 = 0;
    v7 = (int *)*v6;
    v8 = *v6 == 0;
    v6[2] = *v6;
    if ( v8 )
    {
      v9 = 0;
    }
    else
    {
      v9 = *v7;
      if ( *v7 )
        goto LABEL_22;
    }
    if ( (*(int (__thiscall **)(_DWORD *))(*v38 + 164))(v38) > 1 )
    {
      v10 = (void (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD))(v38 + 697);
      v11 = sub_59C4C0();
      v12 = *(_DWORD **)v11;
      *(_DWORD *)(v11 + 8) = *(_DWORD *)v11;
      if ( v12 )
      {
        if ( *v12 )
        {
          v13 = (int *)v12[1];
          *(_DWORD *)(v11 + 8) = v13;
          if ( v13 )
          {
            v14 = *v13;
            if ( v14 )
            {
              do
              {
                v15 = (int (__thiscall **)(void (__thiscall **)(_DWORD, _DWORD, _DWORD, _DWORD)))*v38;
                v16 = sub_5A6E90(v14);
                ((void (__thiscall *)(_DWORD *, int))v15[37])(v38, v16);
                v17 = *(_DWORD **)v11;
                v8 = *(_DWORD *)v11 == 0;
                *(_DWORD *)(v11 + 8) = *(_DWORD *)v11;
                if ( v8 )
                  break;
                if ( !*v17 )
                  break;
                v18 = (int *)v17[1];
                *(_DWORD *)(v11 + 8) = v18;
                if ( !v18 )
                  break;
                v14 = *v18;
              }
              while ( v14 );
              v4 = v38;
            }
          }
        }
      }
      if ( v10[4] )
        ReleaseMutex(v10[4]);
LABEL_48:
      result = v4[4];
      if ( result )
        return ReleaseMutex((HANDLE)v4[4]);
      return result;
    }
LABEL_22:
    v44 = sub_489D20();
    *(_BYTE *)(v44 + 21) = 1;
    *(_DWORD *)(v44 + 4) = v44;
    *(_DWORD *)v44 = v44;
    *(_DWORD *)(v44 + 8) = v44;
    v45 = 0;
    v47 = 0;
    if ( v9 )
    {
      do
      {
        v19 = *(_DWORD *)(v9 + 36);
        if ( v19 )
        {
          v20 = sub_5A6E90(v19);
          Block = (void *)sub_5A6E90(v19);
          p_Block = &Block;
          v35 = &v40;
          v43 = (int *)v20;
          sub_5A3120();
        }
        v21 = v6[2];
        if ( !v21 )
          break;
        v22 = *(int **)(v21 + 4);
        v6[2] = (int)v22;
        if ( !v22 )
          break;
        v9 = *v22;
      }
      while ( *v22 );
    }
    v23 = *(void **)(v37 + 2804);
    if ( v23 && ((v24 = WaitForSingleObject(v23, *(_DWORD *)(v37 + 2808))) == 0 || v24 == 128) )
      v25 = (int *)(v37 + 2788);
    else
      v25 = 0;
    v26 = *v25;
    v8 = *v25 == 0;
    v25[2] = *v25;
    if ( !v8 )
      v25[2] = *(_DWORD *)(v26 + 4);
    v27 = (int *)v25[2];
    if ( v27 )
    {
      v28 = *v27;
      if ( *v27 )
      {
        do
        {
          v38 = (_DWORD *)sub_5A6E90(v28);
          v29 = sub_4796F0(&Block, &v40, &v38);
          if ( *v29 == v43 )
          {
            v38 = *(_DWORD **)v37;
            v30 = sub_5A6E90(v28);
            ((void (__thiscall *)(int, int, int **, void **))v38[37])(v37, v30, v35, p_Block);
            v31 = *v25;
            v8 = *v25 == 0;
            v25[2] = *v25;
            if ( !v8 )
              v25[2] = *(_DWORD *)(v31 + 4);
            v32 = (int *)v25[2];
          }
          else
          {
            v33 = v25[2];
            if ( !v33 )
              break;
            v32 = *(int **)(v33 + 4);
            v25[2] = (int)v32;
          }
          if ( !v32 )
            break;
          v28 = *v32;
        }
        while ( *v32 );
      }
    }
    if ( *(_DWORD *)(v37 + 2804) )
      ReleaseMutex(*(HANDLE *)(v37 + 2804));
    v34 = *(int **)Block;
    v46 = -1;
    sub_5A31E0(&v41, &v39, v34, (int *)Block);
    j__free(Block);
    v4 = (int *)v37;
    goto LABEL_48;
  }
  return result;
}
