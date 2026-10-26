_DWORD *__thiscall sub_69D249(_DWORD *this, int a2, int a3, int a4)
{
  int v4; // ebx
  int v5; // eax
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  BOOL v9; // esi
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // esi
  int i; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // edx
  int *v18; // ebx
  int v19; // eax
  _DWORD *v20; // eax
  _DWORD *v21; // eax
  _DWORD *v22; // eax
  _DWORD *v23; // eax
  _DWORD *v24; // eax
  _DWORD *v25; // eax
  _DWORD *v26; // eax
  _DWORD *v27; // eax
  _DWORD *v28; // eax
  _DWORD *v29; // esi
  int v30; // eax
  _DWORD *v31; // eax
  _DWORD *v32; // eax
  _DWORD *v33; // eax
  int v34; // eax
  int v35; // ecx
  const char *v36; // eax
  int v38; // [esp+4h] [ebp-30h]
  int v39; // [esp+8h] [ebp-2Ch] BYREF
  int v40; // [esp+Ch] [ebp-28h] BYREF
  int v41; // [esp+10h] [ebp-24h]
  int *v42; // [esp+14h] [ebp-20h]
  int *v43; // [esp+18h] [ebp-1Ch]
  unsigned int v44; // [esp+1Ch] [ebp-18h] BYREF
  int *v45; // [esp+20h] [ebp-14h] BYREF
  unsigned int v46; // [esp+24h] [ebp-10h] BYREF
  int v47; // [esp+28h] [ebp-Ch]
  int v48; // [esp+2Ch] [ebp-8h]
  int v49; // [esp+30h] [ebp-4h]
  int *v50; // [esp+3Ch] [ebp+8h]

  v49 = (int)this;
  v46 = 0;
  v44 = 0;
  v45 = 0;
  v40 = 0;
  v39 = 0;
  if ( !a2 || *(_DWORD *)(a2 + 4) != 3 )
    return 0;
  v4 = a2 + 16;
  v5 = this[6];
  v48 = a2 + 16;
  if ( v5 )
    v6 = *(_DWORD *)(v5 + 28);
  else
    v6 = 0;
  v7 = 6;
  if ( a4 )
    v7 = 22;
  v8 = sub_69974C((void *)v49, 2, (const char **)v4, v6, a3, *(_DWORD *)(v49 + 16), v7, (int *)&v46, &v45);
  if ( v8 >= 0 )
  {
    v9 = v8 == 0;
    if ( !a4 )
    {
      if ( !v8 )
      {
LABEL_27:
        v13 = a3;
        v43 = &v40;
        v42 = &v39;
        for ( i = *(_DWORD *)(v46 + 36); ; i = *(_DWORD *)(v47 + 12) )
        {
          v47 = i;
          if ( !i )
            break;
          v15 = *(_DWORD *)(v47 + 8);
          v16 = *(_DWORD *)(v47 + 12);
          v17 = 0;
          v38 = v15;
          if ( v16 )
          {
            v4 = v48;
            if ( *(_DWORD *)(*(_DWORD *)(v16 + 8) + 4) == 12 )
            {
              v17 = 1;
              v47 = *(_DWORD *)(v47 + 12);
            }
          }
          if ( !a4 || (*(_BYTE *)(*(_DWORD *)(v15 + 24) + 28) & 0x40) != 0 )
          {
            if ( v13 )
            {
              v18 = *(int **)(*(_DWORD *)(v15 + 24) + 32);
              v41 = *(_DWORD *)(v15 + 24);
              v19 = *(_DWORD *)(v13 + 8);
              if ( v19 )
                v50 = *(int **)(v19 + 16);
              else
                v50 = 0;
              v20 = (_DWORD *)sub_65B229(20);
              if ( v20 )
                v21 = sub_67ED1B(v20, 0, 0, (int)"Inputs");
              else
                v21 = 0;
              *v43 = (int)v21;
              if ( !v21 )
                return 0;
              v22 = (_DWORD *)sub_65B229(20);
              v23 = v22 ? sub_67ED1B(v22, 0, 0, (int)"Outputs") : 0;
              *v42 = (int)v23;
              if ( !v23 )
                return 0;
              if ( (*(_BYTE *)(v41 + 28) & 0x10) != 0 )
              {
                if ( !sub_696CB7((void *)v49, v18, v50, 0) )
                {
                  sub_696FEF((void *)v49, v48, *(const char **)(v48 + 8), v18, v50, 0);
                  return 0;
                }
                v24 = sub_699F10((int *)v49, (int)v18, *(_DWORD **)(v13 + 8), 0, 0);
                *(_DWORD *)(*v43 + 8) = v24;
              }
              if ( (*(_BYTE *)(v41 + 28) & 0x20) != 0 )
              {
                if ( sub_6950BD((_DWORD *)v49, v50) || !sub_696CB7((void *)v49, v50, v18, 0) )
                {
                  sub_696FEF((void *)v49, v48, *(const char **)(v48 + 8), v50, v18, 0);
                  return 0;
                }
                v25 = sub_699E09((int *)v49, *(_DWORD *)(v38 + 20), v41);
                if ( !v25 )
                  return 0;
                v26 = sub_699F10((int *)v49, (int)v50, v25, 0, 0);
                if ( !v26 )
                  return 0;
                v27 = sub_69C457((char *)v49, 21, *(_DWORD **)(v13 + 8), v26, 1);
                if ( !v27 )
                  return 0;
                *(_DWORD *)(*v42 + 8) = v27;
              }
              v13 = *(_DWORD *)(v13 + 12);
              v4 = v48;
              v43 = (int *)(*v43 + 12);
              v42 = (int *)(*v42 + 12);
            }
            else if ( !v17 )
            {
              goto LABEL_60;
            }
          }
        }
        if ( !v13 )
        {
LABEL_60:
          if ( !v47 )
          {
            v28 = (_DWORD *)sub_65B229(80);
            if ( v28 )
              v29 = sub_67F5FE(v28, 0, (v44 != 0) + 25, 0, 0, 1, (const void *)v4);
            else
              v29 = 0;
            if ( v29 )
            {
              if ( !*(_DWORD *)(v46 + 32)
                || (v30 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(v46 + 32) + 4))(*(_DWORD *)(v46 + 32)),
                    (v29[4] = v30) != 0) )
              {
                v29[8] = v45;
                v31 = (_DWORD *)sub_65B229(20);
                v32 = v31 ? sub_67ED1B(v31, 0, 0, (int)"Parameters") : 0;
                v29[9] = v32;
                if ( v32 )
                {
                  v32[2] = v40;
                  *(_DWORD *)(v29[9] + 12) = v39;
                  sub_695BDE((_DWORD *)v49, v29);
                  if ( sub_695AC0(v29) )
                  {
                    v33 = sub_69BD09((_DWORD *)v49, v29);
                    if ( v33 )
                      return v33;
                  }
                  return v29;
                }
              }
            }
            return 0;
          }
        }
        v34 = a3;
        v35 = 0;
        while ( v34 )
        {
          v34 = *(_DWORD *)(v34 + 12);
          ++v35;
        }
        v36 = "s";
        if ( v44 )
        {
          if ( v35 == 1 )
            v36 = WindowName;
          sub_694B97(
            v49,
            v4,
            3013,
            "'%s': intrinsic function does not take %u parameter%s",
            *(_DWORD *)(v4 + 8),
            v35,
            v36);
        }
        else
        {
          if ( v35 == 1 )
            v36 = WindowName;
          sub_694B97(v49, v4, 3013, "'%s': function does not take %u parameter%s", *(_DWORD *)(v4 + 8), v35, v36);
        }
        return 0;
      }
      v10 = sub_69631A((_DWORD *)v49, (_DWORD *)v4, a3, &v44, &v45);
      if ( v10 < 0 )
        return 0;
      if ( v10 )
      {
LABEL_15:
        v11 = sub_69974C((void *)v49, 2, (const char **)v4, 0, 0, *(_DWORD *)(v49 + 16), 2, (int *)&v46, &v45);
        if ( v11 < 0 )
          return 0;
        if ( !v11 )
          v9 = 1;
LABEL_18:
        if ( !a4 )
        {
          if ( v9 )
          {
LABEL_25:
            if ( v44 )
              v46 = v44;
            goto LABEL_27;
          }
          v12 = sub_69631A((_DWORD *)v49, (_DWORD *)v4, 0, &v44, &v45);
          if ( v12 < 0 )
            return 0;
          if ( v12 )
            goto LABEL_24;
          v9 = 1;
        }
        if ( !v9 )
        {
LABEL_24:
          sub_694B97(v49, a2 + 16, 3004, "undeclared identifier '%s'", *(const char **)(a2 + 24));
          return 0;
        }
        goto LABEL_25;
      }
      v9 = 1;
    }
    if ( v9 )
      goto LABEL_18;
    goto LABEL_15;
  }
  return 0;
}
