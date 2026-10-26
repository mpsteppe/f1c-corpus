int __thiscall sub_4D4880(CHAR *this, const CHAR **a2)
{
  int result; // eax
  int v3; // ebx
  CHAR *v4; // esi
  int v5; // edi
  int v6; // edi
  const CHAR **v7; // eax
  _DWORD *v8; // eax
  const CHAR *v9; // eax
  const CHAR *v10; // eax
  _DWORD *v11; // eax
  int v12; // esi
  _DWORD *v13; // eax
  int v14; // edi
  int v15; // [esp-2h] [ebp-3Ch]
  const char *v16; // [esp+2h] [ebp-38h]
  _DWORD *v17; // [esp+6h] [ebp-34h]
  int v18; // [esp+Eh] [ebp-2Ch]
  const char *v19; // [esp+12h] [ebp-28h]
  const CHAR *v20; // [esp+16h] [ebp-24h]
  const CHAR **v21; // [esp+1Ah] [ebp-20h]
  _DWORD *v22; // [esp+1Eh] [ebp-1Ch] BYREF
  _DWORD v23[3]; // [esp+22h] [ebp-18h] BYREF
  _BYTE v24[5]; // [esp+2Eh] [ebp-Ch] BYREF
  __int16 v25; // [esp+33h] [ebp-7h]
  char v26; // [esp+35h] [ebp-5h]

  result = (int)a2;
  v3 = 0;
  v4 = this;
  v23[2] = this;
  if ( a2 )
  {
    v23[1] = 0;
    v23[0] = 0;
    v5 = sub_4CFCC0(this, 1);
    *(_DWORD *)v24 = v5 - sub_4CFCC0(v4, 0);
    sub_4CFD30(v4, 1);
    v6 = 0;
    sub_4CFD30(v4, 0);
    v20 = *a2;
    if ( !*a2 )
      v20 = WindowName;
    v7 = (const CHAR **)operator new(8u);
    if ( v7 )
    {
      *v7 = 0;
      v7[1] = (const CHAR *)-1;
    }
    else
    {
      v7 = 0;
    }
    v21 = v7;
    v8 = operator new(8u);
    if ( v8 )
    {
      *v8 = 0;
      v8[1] = -1;
      v22 = v8;
    }
    else
    {
      v22 = 0;
    }
    sub_409FB0((_DWORD *)v4 + 70);
    v9 = *(const CHAR **)(*((_DWORD *)v4 + 61) + 64);
    if ( !v9 )
      v9 = WindowName;
    sub_4DF1B0(*((_DWORD *)v4 + 12), v9);
    if ( (int)strlen(v19) > 0 )
    {
      while ( 1 )
      {
        *(_DWORD *)&v24[1] = 0;
        v25 = 0;
        v26 = 0;
        v23[0] = 0;
        v22 = 0;
        v24[0] = v19[v6];
        sub_615A50(v24);
        HIBYTE(v18) = v24[0] == 10;
        if ( v24[0] == 32 || v24[0] == 10 )
          break;
LABEL_33:
        if ( v6 == strlen(v16) - 1 )
        {
          for ( ; v3 <= v6; ++v3 )
          {
            LOBYTE(v22) = v16[v3];
            sub_615A50(&v22);
          }
          sub_5FDFB0(v17, 1);
        }
        if ( ++v6 >= (int)strlen(v16) )
          goto LABEL_38;
      }
      v10 = *v21;
      if ( !*v21 )
        v10 = WindowName;
      sub_4E08C0(*((_DWORD *)v4 + 12), v10, v23, &v22, 1, v15);
      if ( (int)v19 > (int)v21 )
      {
        sub_5FDFB0(v17, 1);
        v11 = operator new(8u);
        if ( v11 )
        {
          *v11 = 0;
          v11[1] = -1;
        }
        else
        {
          v11 = 0;
        }
        v17 = v11;
        sub_615860(WindowName);
        v12 = v3;
        if ( v3 > v6 )
        {
          v4 = (CHAR *)v20;
LABEL_28:
          if ( HIBYTE(v15) )
          {
            sub_5FDFB0(v17, 1);
            v13 = operator new(8u);
            if ( v13 )
            {
              *v13 = 0;
              v13[1] = -1;
            }
            else
            {
              v13 = 0;
            }
            v17 = v13;
            sub_615860(WindowName);
          }
          goto LABEL_33;
        }
        do
        {
          LOBYTE(v22) = v16[v12];
          sub_615A50(&v22);
          ++v12;
        }
        while ( v12 <= v6 );
        v4 = (CHAR *)v20;
      }
      for ( ; v3 <= v6; ++v3 )
      {
        LOBYTE(v22) = v16[v3];
        sub_615A50(&v22);
      }
      goto LABEL_28;
    }
LABEL_38:
    result = v18;
    if ( v18 )
    {
      v14 = sub_4CFD30(v4, 1);
      result = (v14 - sub_4CFD30(v4, 0)) / v18;
      *((_DWORD *)v4 + 77) = result;
    }
  }
  return result;
}
