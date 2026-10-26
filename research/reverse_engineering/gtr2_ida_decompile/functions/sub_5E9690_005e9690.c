_DWORD *__thiscall sub_5E9690(_DWORD *this, const char *a2, _DWORD *a3, int a4)
{
  _DWORD **v5; // eax
  _DWORD *v6; // edi
  int v7; // eax
  char v8; // cl
  _BYTE *v9; // esi
  char *v10; // eax
  bool v11; // cf
  unsigned __int8 v12; // dl
  int v13; // eax
  char *v14; // esi
  _BYTE *v15; // eax
  unsigned __int8 v16; // dl
  int v17; // eax
  _DWORD **v18; // eax
  char String[256]; // [esp+10h] [ebp-200h] BYREF
  _BYTE v22[256]; // [esp+110h] [ebp-100h] BYREF

  strcpy(String, a2);
  _strupr(String);
  v5 = (_DWORD **)this[9];
  this[11] = v5;
  if ( !v5 )
    return 0;
  v6 = *v5;
  if ( !*v5 )
    return 0;
  while ( 1 )
  {
    if ( (*v6 & 0x200) != 0 )
    {
      v7 = 0;
      do
      {
        v8 = String[v7];
        v22[v7++] = v8;
      }
      while ( v8 );
      String[strlen(String) + 252] = 0;
      v9 = v22;
      v10 = String;
      while ( 1 )
      {
        v11 = (unsigned __int8)*v10 < *v9;
        if ( *v10 != *v9 )
          break;
        if ( *v10 )
        {
          v12 = v10[1];
          v11 = v12 < v9[1];
          if ( v12 != v9[1] )
            break;
          v10 += 2;
          v9 += 2;
          if ( v12 )
            continue;
        }
        v13 = 0;
        goto LABEL_19;
      }
    }
    else
    {
      v14 = String;
      v15 = v6 + 1;
      while ( 1 )
      {
        v11 = *v15 < (unsigned __int8)*v14;
        if ( *v15 != *v14 )
          break;
        if ( *v15 )
        {
          v16 = v15[1];
          v11 = v16 < (unsigned __int8)v14[1];
          if ( v16 != v14[1] )
            break;
          v15 += 2;
          v14 += 2;
          if ( v16 )
            continue;
        }
        v13 = 0;
        goto LABEL_19;
      }
    }
    v13 = -v11 - (v11 - 1);
LABEL_19:
    if ( !v13 && (!a3 || sub_5E9340(a3, (int)v6, a4)) )
      return v6;
    v17 = this[11];
    if ( v17 )
      this[11] = *(_DWORD *)(v17 + 4);
    v18 = (_DWORD **)this[11];
    if ( v18 )
    {
      v6 = *v18;
      if ( *v18 )
        continue;
    }
    return 0;
  }
}
