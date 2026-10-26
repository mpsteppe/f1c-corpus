int __usercall sub_67EE40@<eax>(_DWORD *a1@<eax>, _DWORD *a2@<ecx>)
{
  int v2; // edx
  _BYTE *v5; // esi
  _BYTE *v6; // eax
  bool v7; // cf
  unsigned __int8 v8; // dl
  int v9; // eax
  int v10; // edx
  _BYTE *v11; // esi
  _BYTE *v12; // ecx
  unsigned __int8 v13; // dl
  _BYTE *v14; // esi
  _BYTE *v15; // ecx
  unsigned __int8 v16; // dl

  v2 = *a2;
  if ( *a2 != *a1 )
    return 0;
  if ( v2 > 8 )
  {
    v10 = v2 - 9;
    if ( v10 )
    {
      if ( v10 != 1 )
        return 1;
      v11 = (_BYTE *)a1[2];
      v12 = (_BYTE *)a2[2];
      while ( 1 )
      {
        v7 = *v12 < *v11;
        if ( *v12 != *v11 )
          break;
        if ( !*v12 )
          goto LABEL_16;
        v13 = v12[1];
        v7 = v13 < v11[1];
        if ( v13 != v11[1] )
          break;
        v12 += 2;
        v11 += 2;
        if ( !v13 )
          goto LABEL_16;
      }
    }
    else
    {
      v14 = (_BYTE *)a1[2];
      v15 = (_BYTE *)a2[2];
      while ( 1 )
      {
        v7 = *v15 < *v14;
        if ( *v15 != *v14 )
          break;
        if ( *v15 )
        {
          v16 = v15[1];
          v7 = v16 < v14[1];
          if ( v16 != v14[1] )
            break;
          v15 += 2;
          v14 += 2;
          if ( v16 )
            continue;
        }
LABEL_16:
        v9 = 0;
        return v9 == 0;
      }
    }
  }
  else
  {
    if ( v2 >= 5 )
      return *((double *)a2 + 1) == *((double *)a1 + 1);
    if ( !v2 )
      return a2[2] == a1[2];
    if ( v2 != 1 )
    {
      if ( v2 <= 1 )
        return 1;
      return a2[2] == a1[2];
    }
    v5 = a1 + 2;
    v6 = a2 + 2;
    while ( 1 )
    {
      v7 = *v6 < *v5;
      if ( *v6 != *v5 )
        break;
      if ( !*v6 )
        goto LABEL_16;
      v8 = v6[1];
      v7 = v8 < v5[1];
      if ( v8 != v5[1] )
        break;
      v6 += 2;
      v5 += 2;
      if ( !v8 )
        goto LABEL_16;
    }
  }
  v9 = -v7 - (v7 - 1);
  return v9 == 0;
}
