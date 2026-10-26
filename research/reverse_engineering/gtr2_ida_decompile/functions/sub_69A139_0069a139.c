_DWORD *__thiscall sub_69A139(_DWORD *this, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  int v6; // ebx
  int *v7; // ebx
  _DWORD *v8; // eax
  _DWORD **v9; // esi
  _DWORD *v10; // eax
  int *v11; // eax
  _DWORD *v12; // ebx
  _DWORD *v13; // eax
  _DWORD *v14; // eax
  _DWORD *v15; // esi
  _DWORD *v16; // eax
  _DWORD *v17; // eax
  int *v18; // ebx
  _DWORD *v19; // eax
  _DWORD *v20; // eax
  _DWORD *v21; // eax
  _DWORD *v22; // eax
  _DWORD *v23; // eax
  int *v24; // ebx
  _DWORD *v25; // eax
  _DWORD *v26; // eax
  _DWORD *v27; // eax
  int v28; // [esp-Ch] [ebp-34h]
  char *v29; // [esp-8h] [ebp-30h]
  int *v30; // [esp+8h] [ebp-20h] BYREF
  int *v31; // [esp+Ch] [ebp-1Ch] BYREF
  int *v32; // [esp+10h] [ebp-18h]
  int *v33; // [esp+14h] [ebp-14h]
  int *v34; // [esp+18h] [ebp-10h]
  int v35; // [esp+1Ch] [ebp-Ch]
  _DWORD *v36; // [esp+20h] [ebp-8h]
  _DWORD *v37; // [esp+24h] [ebp-4h]

  v37 = this;
  if ( a2 && a2[1] != 13 || a3 && a3[1] != 13 || a4 && a4[1] != 13 )
    return 0;
  v6 = (int)(a2 + 12);
  if ( !a2 )
    v6 = (int)(this + 8);
  v35 = v6;
  if ( a2 )
    v32 = (int *)a2[4];
  else
    v32 = 0;
  if ( a3 )
    v34 = (int *)a3[4];
  else
    v34 = 0;
  if ( a4 )
    v33 = (int *)a4[4];
  else
    v33 = 0;
  v31 = v34;
  v30 = v33;
  v7 = 0;
  v8 = (_DWORD *)sub_65B229(80);
  if ( v8 )
    v36 = sub_67F5FE(v8, 0, 24, 0, 0, 1, (const void *)v35);
  else
    v36 = 0;
  if ( !v36 )
    return 0;
  if ( !sub_695154(this, v32) )
  {
    sub_694B97((int)this, v35, 3020, "conditional must be numeric");
    return 0;
  }
  v9 = (_DWORD **)(v36 + 4);
  if ( sub_697320(v37, v34, v33, &v31, &v30, v36 + 4) < 0 )
  {
    v29 = "type mismatch between conditional values";
LABEL_39:
    sub_694B97((int)v37, v35, 3020, v29);
    return 0;
  }
  if ( *v9 )
  {
    if ( (*v9)[1] == 9 )
    {
      v10 = (_DWORD *)sub_65B229(36);
      if ( v10 )
      {
        v11 = sub_67F2D4(v10, 2, 0, (*v9)[6], (*v9)[7], 512);
LABEL_34:
        v7 = v11;
        goto LABEL_36;
      }
    }
    else
    {
      v12 = (_DWORD *)sub_65B229(36);
      if ( v12 )
      {
        v28 = sub_6951CB(v37, *v9);
        v11 = sub_67F2D4(v12, 2, 0, 1, v28, 512);
        goto LABEL_34;
      }
    }
    v7 = 0;
LABEL_36:
    if ( !v7 )
      return 0;
    if ( !sub_696CB7(v37, v7, v32, 0) )
    {
      v29 = "dimension of conditional does not match value";
      goto LABEL_39;
    }
  }
  if ( !a2 || (v13 = sub_699F10(v37, (int)v7, a2, 0, 0), (v36[8] = v13) != 0) )
  {
    v14 = (_DWORD *)sub_65B229(80);
    v15 = v14 ? sub_67F5FE(v14, 0, 0, 0, 0, 1, (const void *)v35) : 0;
    v36[9] = v15;
    if ( v15 )
    {
      v16 = (_DWORD *)sub_65B229(20);
      v17 = v16 ? sub_67ED1B(v16, 0, 0, (int)"Types") : 0;
      v15[4] = v17;
      if ( v17 )
      {
        v18 = v31;
        if ( !v31 || (*(_DWORD *)(v15[4] + 8) = (*(int (__thiscall **)(int *))(*v31 + 4))(v31)) != 0 )
        {
          v19 = (_DWORD *)sub_65B229(20);
          v20 = v19 ? sub_67ED1B(v19, 0, 0, (int)"Value") : 0;
          v15[8] = v20;
          if ( v20 )
          {
            if ( !a3
              || (v34 == v18 || sub_695259(v34, v18)
                ? (v21 = (_DWORD *)sub_67ECC3((int)a3))
                : (v21 = sub_699F10(v37, (int)v18, a3, 0, 0)),
                  (*(_DWORD *)(v15[8] + 8) = v21) != 0) )
            {
              v22 = (_DWORD *)sub_65B229(20);
              v23 = v22 ? sub_67ED1B(v22, 0, 0, (int)"Types") : 0;
              *(_DWORD *)(v15[4] + 12) = v23;
              if ( v23 )
              {
                v24 = v30;
                if ( !v30
                  || (*(_DWORD *)(*(_DWORD *)(v15[4] + 12) + 8) = (*(int (__thiscall **)(int *))(*v30 + 4))(v30)) != 0 )
                {
                  v25 = (_DWORD *)sub_65B229(20);
                  v26 = v25 ? sub_67ED1B(v25, 0, 0, (int)"Value") : 0;
                  *(_DWORD *)(v15[8] + 12) = v26;
                  if ( v26 )
                  {
                    if ( !a4
                      || (v33 == v24 || sub_695259(v33, v24)
                        ? (v27 = (_DWORD *)sub_67ECC3((int)a4))
                        : (v27 = sub_699F10(v37, (int)v24, a4, 0, 0)),
                          (*(_DWORD *)(*(_DWORD *)(v15[8] + 12) + 8) = v27) != 0) )
                    {
                      sub_695BDE(v37, v15);
                      sub_695BDE(v37, v36);
                      return v36;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}
