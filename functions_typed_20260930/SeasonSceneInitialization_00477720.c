int __thiscall sub_477720(int *this)
{
  _DWORD *v2; // eax
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  int v5; // edx
  int *v6; // eax
  int v7; // ebp
  int i; // eax
  const char **v9; // eax
  const char *v10; // esi
  const char *v11; // eax
  int v12; // eax
  int *v13; // eax

  v2 = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 20);
  if ( v2 )
    SeasonPathMatchSearch(v2);
  v3 = (_DWORD *)UtilityFunction_7810(this);
  v4 = v3;
  if ( v3 )
  {
    SeasonSceneSearchByName(v3);
    v5 = *this;
    this[97] = v4[93];
    (*(void (__thiscall **)(int *))(v5 + 160))(this);
  }
  v6 = (int *)this[60];
  v7 = 0;
  this[62] = (int)v6;
  if ( v6 )
  {
    for ( i = *v6; i; i = *v13 )
    {
      v9 = *(const char ***)(i + 60);
      if ( v9 )
      {
        v10 = (const char *)dword_7CE64C;
        if ( !dword_7CE64C )
          v10 = byte_5EA438;
        v11 = *v9;
        if ( !v11 )
          v11 = byte_5EA438;
        if ( !strcmp(v11, v10) )
          this[93] = v7;
      }
      v12 = this[62];
      ++v7;
      if ( !v12 )
        break;
      v13 = *(int **)(v12 + 4);
      this[62] = (int)v13;
      if ( !v13 )
        break;
    }
  }
  return UIViewportLayoutCalculator(this);
}

