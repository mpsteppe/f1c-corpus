bool __thiscall sub_4127D0(int this)
{
  _DWORD *v2; // esi
  void *v3; // edi
  _DWORD *v4; // esi
  void *v5; // edi
  int v6; // eax
  int v7; // esi
  int v8; // ebp
  int v9; // esi
  unsigned __int8 v10; // bl
  int v11; // eax
  const char *v12; // eax
  int v13; // eax
  const char *v14; // eax
  int v15; // eax
  const char *v16; // eax
  const char ***v17; // eax
  const char **v18; // eax
  const char *v19; // edi
  int v20; // eax
  const char ***v21; // eax
  double v22; // st7
  void *v23; // eax
  int v24; // esi
  int v25; // eax
  int *v26; // eax
  const char ***v27; // eax
  const char **i; // ebx
  const char ***v29; // eax
  const char **v30; // edi
  const char *v31; // esi
  const char *v32; // eax
  int v33; // eax
  const char ***v34; // ecx
  const char ***v35; // eax
  const char **v36; // edx
  int v37; // eax
  const char ***v38; // eax
  const char **v39; // edi
  const char *v40; // esi
  const char *v41; // ecx
  const char ***v42; // ecx
  const char ***v43; // edx
  int v44; // eax
  const char **v45; // eax
  char v47; // [esp+11h] [ebp-17h]
  unsigned __int8 v48; // [esp+12h] [ebp-16h]
  unsigned __int8 v49; // [esp+13h] [ebp-15h]
  int v51; // [esp+18h] [ebp-10h]
  int v52; // [esp+1Ch] [ebp-Ch]
  float v53; // [esp+20h] [ebp-8h]
  float v54; // [esp+24h] [ebp-4h]

  v2 = *(_DWORD **)(this + 28);
  while ( v2 )
  {
    v3 = v2;
    v2 = (_DWORD *)v2[1];
    sub_4145A0(v3);
    sub_5BE8AE(v3);
  }
  *(_DWORD *)(this + 28) = 0;
  *(_DWORD *)(this + 32) = 0;
  *(_DWORD *)(this + 36) = 0;
  *(_DWORD *)(this + 40) = 0;
  v4 = *(_DWORD **)(this + 44);
  while ( v4 )
  {
    v5 = v4;
    v4 = (_DWORD *)v4[1];
    sub_4145A0(v5);
    sub_5BE8AE(v5);
  }
  *(_DWORD *)(this + 44) = 0;
  *(_DWORD *)(this + 48) = 0;
  *(_DWORD *)(this + 52) = 0;
  *(_DWORD *)(this + 56) = 0;
  sub_410460((_DWORD *)this);
  v49 = sub_410520(this);
  (**(void (__thiscall ***)(int))dword_76BB24)(dword_76BB24);
  v6 = sub_57AE50(aSponsors);
  v51 = v6;
  if ( v6 )
  {
    v48 = 0;
    if ( sub_57A6E0(v6) > 0 )
    {
      v7 = 0;
      do
      {
        v8 = sub_57A700(v7);
        if ( v8 )
        {
          v9 = 0;
          v10 = 0;
          v52 = 0;
          v47 = 0;
          v11 = sub_57A720(aReputation);
          if ( v11 )
          {
            v12 = (const char *)sub_57A6D0(v11);
            v10 = atoi(v12);
          }
          v13 = sub_57A720(aPerrace);
          if ( v13 )
          {
            v14 = (const char *)sub_57A6D0(v13);
            v9 = atoi(v14);
            v52 = v9;
          }
          v15 = sub_57A720(aContractlength);
          if ( v15 )
          {
            v16 = (const char *)sub_57A6D0(v15);
            v47 = atoi(v16);
          }
          if ( v9 && v10 && v47 && *(_BYTE *)(this + 8) >= v10 )
          {
            v17 = *(const char ****)(this + 60);
            *(_DWORD *)(this + 68) = v17;
            if ( v17 && (v18 = *v17) != 0 )
            {
              while ( 1 )
              {
                v19 = *v18;
                if ( !*v18 )
                  v19 = &byte_629120;
                if ( !strcmp(v19, (const char *)sub_57A6D0(v8)) )
                  break;
                v20 = *(_DWORD *)(this + 68);
                if ( v20 )
                  *(_DWORD *)(this + 68) = *(_DWORD *)(v20 + 4);
                v21 = *(const char ****)(this + 68);
                if ( v21 )
                {
                  v18 = *v21;
                  if ( v18 )
                    continue;
                }
                goto LABEL_28;
              }
            }
            else
            {
LABEL_28:
              v54 = (float)(*(unsigned __int8 *)(this + 8) - 5 * v49);
              v22 = flt_7D3C54[(unsigned __int8)dword_7D3C50++] * 100.0;
              v23 = operator new(0x18u);
              if ( v23 )
                v24 = sub_413AC0(v23);
              else
                v24 = 0;
              v25 = sub_57A6D0(v8);
              sub_578600(v25);
              *(_BYTE *)(v24 + 13) = v47;
              *(_DWORD *)(v24 + 8) = v52;
              *(_BYTE *)(v24 + 12) = v10;
              v53 = v22;
              if ( v53 > (double)v54 )
              {
                if ( *(_DWORD *)v24 )
                  sub_5BE8AE(*(LPVOID *)v24);
                sub_5BE8AE((LPVOID)v24);
              }
              else
              {
                v26 = (int *)operator new(0xCu);
                if ( v26 )
                {
                  *v26 = v24;
                  v26[1] = 0;
                  *((_BYTE *)v26 + 8) = 1;
                }
                else
                {
                  v26 = 0;
                }
                if ( *(_DWORD *)(this + 44) )
                {
                  *(_DWORD *)(*(_DWORD *)(this + 48) + 4) = v26;
                }
                else
                {
                  *(_DWORD *)(this + 44) = v26;
                  *(_DWORD *)(this + 52) = v26;
                }
                *(_DWORD *)(this + 48) = v26;
                ++*(_DWORD *)(this + 56);
              }
            }
          }
        }
        v7 = ++v48;
      }
      while ( v48 < sub_57A6E0(v51) );
    }
  }
  v27 = *(const char ****)(this + 12);
  *(_DWORD *)(this + 20) = v27;
  if ( v27 )
  {
    for ( i = *v27; i; i = (const char **)sub_50EE10(this + 12) )
    {
      v29 = *(const char ****)(this + 28);
      *(_DWORD *)(this + 36) = v29;
      if ( v29 )
      {
        v30 = *v29;
        if ( *v29 )
        {
          do
          {
            v31 = *i;
            if ( !*i )
              v31 = &byte_629120;
            v32 = *v30;
            if ( !*v30 )
              v32 = &byte_629120;
            v33 = strcmp(v32, v31);
            if ( v33 )
            {
              v37 = *(_DWORD *)(this + 36);
              if ( v37 )
                *(_DWORD *)(this + 36) = *(_DWORD *)(v37 + 4);
              v35 = *(const char ****)(this + 36);
            }
            else
            {
              v34 = *(const char ****)(this + 28);
              if ( v34 )
              {
                while ( *v34 != v30 )
                {
                  v33 = (int)v34;
                  v34 = (const char ***)v34[1];
                  if ( !v34 )
                  {
                    v35 = *(const char ****)(this + 28);
                    *(_DWORD *)(this + 36) = v35;
                    goto LABEL_68;
                  }
                }
                if ( v34 == *(const char ****)(this + 36) )
                  *(_DWORD *)(this + 36) = v34[1];
                v36 = v34[1];
                if ( v33 )
                  *(_DWORD *)(v33 + 4) = v36;
                else
                  *(_DWORD *)(this + 28) = v36;
                if ( *(const char ****)(this + 32) == v34 )
                  *(_DWORD *)(this + 32) = v33;
                --*(_DWORD *)(this + 40);
                sub_414480(1);
              }
              v35 = *(const char ****)(this + 28);
              *(_DWORD *)(this + 36) = v35;
            }
LABEL_68:
            if ( !v35 )
              break;
            v30 = *v35;
          }
          while ( *v35 );
        }
      }
      v38 = *(const char ****)(this + 44);
      *(_DWORD *)(this + 52) = v38;
      if ( v38 )
      {
        v39 = *v38;
        if ( *v38 )
        {
          do
          {
            v40 = *i;
            if ( !*i )
              v40 = &byte_629120;
            v41 = *v39;
            if ( !*v39 )
              v41 = &byte_629120;
            if ( !strcmp(v41, v40) )
            {
              v42 = *(const char ****)(this + 44);
              v43 = 0;
              if ( v42 )
              {
                while ( *v42 != v39 )
                {
                  v43 = v42;
                  v42 = (const char ***)v42[1];
                  if ( !v42 )
                    goto LABEL_80;
                }
                if ( v42 == *(const char ****)(this + 52) )
                  *(_DWORD *)(this + 52) = v42[1];
                v45 = v42[1];
                if ( v43 )
                  v43[1] = v45;
                else
                  *(_DWORD *)(this + 44) = v45;
                if ( *(const char ****)(this + 48) == v42 )
                  *(_DWORD *)(this + 48) = v43;
                --*(_DWORD *)(this + 56);
                sub_414480(1);
              }
LABEL_80:
              v44 = sub_414470(this + 44);
            }
            else
            {
              v44 = sub_50EE10(this + 44);
            }
            v39 = (const char **)v44;
          }
          while ( v44 );
        }
      }
    }
  }
  return *(int *)(this + 40) > 0 || *(int *)(this + 56) > 0;
}
