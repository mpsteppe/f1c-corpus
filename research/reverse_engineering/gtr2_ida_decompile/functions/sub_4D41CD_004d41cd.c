int __userpurge sub_4D41CD@<eax>(_DWORD *a1@<ecx>, int a2@<ebp>, int a3, int a4)
{
  _DWORD *v4; // esi
  int result; // eax
  int v6; // ebx
  int v7; // edi
  int v8; // eax
  int v9; // ecx
  int v10; // ecx
  const CHAR *v11; // eax
  int v12; // edx
  int v13; // edi
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  const char *v19; // eax
  const char *v20; // esi
  int v21; // ebx
  int v22; // eax
  int v23; // esi
  int v24; // ebx
  int v25; // edx
  int v26; // ecx
  int v27; // edi
  int v28; // esi
  bool v29; // cc
  char v30; // [esp+1h] [ebp-39h]
  int v31; // [esp+2h] [ebp-38h]
  int v32; // [esp+6h] [ebp-34h]
  int v34; // [esp+Eh] [ebp-2Ch]
  int v35; // [esp+12h] [ebp-28h]
  int v36; // [esp+16h] [ebp-24h]
  int v37; // [esp+1Ah] [ebp-20h]
  int v38; // [esp+1Eh] [ebp-1Ch]
  int v39; // [esp+22h] [ebp-18h]
  int v40; // [esp+26h] [ebp-14h]

  v4 = a1;
  v39 = a1[146];
  result = a1[37];
  v6 = 0;
  v7 = result;
  v38 = -1;
  v40 = result;
  v37 = 0;
  v36 = result;
  if ( result > 0 )
  {
    while ( 1 )
    {
      v8 = v4[36];
      v9 = 0;
      if ( v8 )
        v9 = v4[36];
      v32 = v9;
      v10 = *(_DWORD *)(a2 + 12);
      v4[146] = 0;
      if ( v10 >= 0 )
      {
        v11 = (const CHAR *)sub_4CE200((int)v4, v10);
      }
      else if ( v8 )
      {
        v11 = *(const CHAR **)(v8 + 160);
        if ( !v11 )
          v11 = WindowName;
      }
      else
      {
        v11 = 0;
      }
      sub_615860(v11);
      v12 = 0;
      v30 = 0;
      v31 = 0;
      v34 = 0;
      v35 = 0;
      if ( v7 > 0 )
      {
        while ( 1 )
        {
          v13 = 0;
          v14 = v12;
          if ( v12 >= 0 )
          {
            v15 = v4[36];
            if ( v15 )
            {
              if ( v12 > 0 )
              {
                do
                {
                  if ( !v15 )
                    break;
                  v15 = *(_DWORD *)(v15 + 140);
                  --v14;
                }
                while ( v14 > 0 );
              }
              v13 = v15;
            }
          }
          v16 = *(_DWORD *)(a2 + 12);
          v4[146] = v12;
          if ( v16 >= 0 )
            break;
          v17 = v12;
          if ( v12 >= 0 )
          {
            v18 = v4[36];
            if ( v18 )
            {
              while ( v17 > 0 )
              {
                v18 = *(_DWORD *)(v18 + 140);
                --v17;
                if ( !v18 )
                  goto LABEL_34;
              }
              v19 = *(const char **)(v18 + 160);
              if ( !v19 )
                v19 = WindowName;
              goto LABEL_28;
            }
          }
LABEL_34:
          v35 = ++v12;
          if ( v12 >= v36 )
            goto LABEL_35;
        }
        v19 = (const char *)sub_4CE200((int)v4, v16);
LABEL_28:
        v20 = v19;
        if ( v19 )
        {
          switch ( *(_DWORD *)(a2 + 8) )
          {
            case 0:
              v21 = atol(WindowName);
              if ( atol(v20) < v21 )
                goto LABEL_41;
              goto LABEL_31;
            case 1:
              v24 = atol(WindowName);
              if ( atol(v20) <= v24 )
              {
LABEL_31:
                v6 = v34;
              }
              else
              {
LABEL_41:
                v32 = v13;
                sub_615860(v20);
                v6 = v34;
                v31 = v34;
              }
              break;
            case 2:
              if ( _stricmp(v19, WindowName) < 0 )
                goto LABEL_43;
              break;
            case 3:
              if ( _stricmp(v19, WindowName) > 0 )
              {
LABEL_43:
                v32 = v13;
                sub_615860(v20);
                v31 = v6;
              }
              break;
            default:
              break;
          }
          v34 = ++v6;
        }
        v4 = a1;
        v12 = v35;
        goto LABEL_34;
      }
LABEL_35:
      if ( v31 == v39 )
        v30 = 1;
      v22 = sub_4CD3E0(v4, v32);
      v23 = 0;
      if ( v22 )
      {
        if ( v37 )
        {
          v25 = v37;
          v26 = v37 + 140;
          v23 = 1;
          if ( *(_DWORD *)(v37 + 140) )
          {
            do
            {
              v25 = *(_DWORD *)v26;
              v27 = *(_DWORD *)(*(_DWORD *)v26 + 140);
              v26 = *(_DWORD *)v26 + 140;
              ++v23;
            }
            while ( v27 );
          }
          *(_DWORD *)(v25 + 140) = v22;
        }
        else
        {
          v37 = v22;
        }
      }
      if ( v30 )
        v38 = v23;
      v28 = a1[37];
      --a1[146];
      v36 = v28;
      v6 = 0;
      v29 = v28 <= 0;
      v4 = a1;
      if ( v29 )
        break;
      v7 = v36;
    }
    result = v40;
  }
  if ( !v4[36] )
  {
    v4[36] = v37;
    v4[37] = result;
    return sub_4D4060(v4, v38, 0);
  }
  return result;
}
