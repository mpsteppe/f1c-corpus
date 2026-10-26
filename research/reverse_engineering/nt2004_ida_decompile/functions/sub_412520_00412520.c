char __thiscall sub_412520(_DWORD *this, int a2, int a3, _DWORD *a4)
{
  CHAR ***v6; // eax
  CHAR **v7; // eax
  int v8; // eax
  const char *v9; // eax
  double v10; // st7
  int v11; // esi
  __int64 v12; // rax
  int v13; // eax
  CHAR ***v14; // eax
  _DWORD *v16; // esi
  CHAR *v17; // eax
  _DWORD *v18; // eax
  _DWORD *v19; // esi
  _DWORD *v20; // eax
  LPVOID *v21; // edi
  CHAR **v22; // [esp+24h] [ebp+Ch]

  *a4 = 0;
  v6 = (CHAR ***)this[3];
  this[5] = v6;
  if ( !v6 )
    return 0;
  v7 = *v6;
  v22 = v7;
  if ( !v7 )
    return 0;
  while ( 1 )
  {
    if ( v7 == (CHAR **)a2 )
    {
      (**(void (__thiscall ***)(int))dword_76BB24)(dword_76BB24);
      v8 = sub_57AE50(aSponsorendcont);
      if ( v8 )
      {
        v9 = (const char *)sub_57A6D0(v8);
        v10 = atof(v9);
        v11 = this[1];
        v12 = (__int64)((double)*(unsigned __int8 *)(a2 + 14) * (double)*(int *)(a2 + 8) * v10 + 0.5);
        *a4 = v12;
        if ( v11 != (_DWORD)v12 )
          break;
      }
    }
    v13 = this[5];
    if ( v13 )
      this[5] = *(_DWORD *)(v13 + 4);
    v14 = (CHAR ***)this[5];
    if ( !v14 )
      return 0;
    v22 = *v14;
    if ( !*v14 )
      return 0;
    v7 = *v14;
  }
  if ( a3 == 1 )
  {
    this[1] -= v12;
    v16 = operator new(8u);
    if ( v16 )
    {
      v17 = *v22;
      if ( !*v22 )
        v17 = &byte_629120;
      *v16 = 0;
      v16[1] = -1;
      sub_578600(v17);
    }
    else
    {
      v16 = 0;
    }
    if ( v16 )
    {
      v18 = operator new(0xCu);
      if ( v18 )
      {
        *v18 = v16;
        v18[1] = 0;
        *((_BYTE *)v18 + 8) = 1;
      }
      else
      {
        v18 = 0;
      }
      if ( this[15] )
      {
        *(_DWORD *)(this[16] + 4) = v18;
      }
      else
      {
        this[15] = v18;
        this[17] = v18;
      }
      this[16] = v18;
      ++this[18];
    }
    if ( v22 )
    {
      v19 = (_DWORD *)this[3];
      v20 = 0;
      if ( v19 )
      {
        while ( (CHAR **)*v19 != v22 )
        {
          v20 = v19;
          v19 = (_DWORD *)v19[1];
          if ( !v19 )
            return 1;
        }
        if ( v19 == (_DWORD *)this[5] )
          this[5] = v19[1];
        if ( v20 )
          v20[1] = v19[1];
        else
          this[3] = v19[1];
        if ( (_DWORD *)this[4] == v19 )
          this[4] = v20;
        --this[6];
        if ( *((_BYTE *)v19 + 8) )
        {
          v21 = (LPVOID *)*v19;
          if ( *v19 )
          {
            if ( *v21 )
              sub_5BE8AE(*v21);
            sub_5BE8AE(v21);
          }
        }
        sub_5BE8AE(v19);
      }
    }
  }
  return 1;
}
