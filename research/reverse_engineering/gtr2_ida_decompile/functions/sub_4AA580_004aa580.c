char __thiscall sub_4AA580(_DWORD *this, int a2)
{
  int v2; // edx
  int *v3; // eax
  int v4; // esi
  const CHAR *v5; // eax
  const CHAR *v6; // esi
  const CHAR **v7; // esi
  const CHAR *v8; // eax
  const CHAR *v9; // esi
  int v10; // eax
  int v11; // eax
  int v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+4h] [ebp-8h]
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v2 = this[214];
  if ( v2 >= 0 && v2 < this[213] )
  {
    v3 = (int *)this[210];
    if ( v2 <= 0 )
    {
LABEL_6:
      if ( v3 )
      {
        v4 = *v3;
        if ( *v3 )
        {
          v5 = *(const CHAR **)(v4 + 8);
          if ( !v5 )
            v5 = WindowName;
          sub_5100A0(&byte_B6F530, v5);
          if ( (_BYTE)retaddr )
          {
            sub_53B270(&unk_BE1CFC);
            v6 = *(const CHAR **)(v4 + 8);
            if ( !v6 )
              v6 = WindowName;
            sub_5100A0(&byte_B6F530, v6);
          }
        }
      }
    }
    else
    {
      while ( v3 )
      {
        v3 = (int *)v3[1];
        if ( --v2 <= 0 )
          goto LABEL_6;
      }
    }
  }
  sub_538790(&unk_BE1CDC);
  sub_539FF0(&unk_BE1CE0);
  dword_BE1BD0 = sub_53A0E0(&unk_BE1CE0);
  v7 = (const CHAR **)sub_538790(&unk_BE1CDC);
  v8 = *v7;
  if ( !*v7 )
    v8 = WindowName;
  sub_615860(v8);
  sub_615860(v7 + 463);
  if ( *(_DWORD *)dword_B72314 != 4 && *(_DWORD *)dword_B72314 != 8 )
  {
    v9 = *v7;
    if ( !v9 )
      v9 = WindowName;
    sub_615860(v9);
  }
  LOBYTE(v10) = byte_B722E4;
  if ( byte_B722E4 )
  {
    v10 = sub_616840("SceneOrder");
    if ( v10 )
    {
      v10 = sub_616610(0);
      if ( v10 )
      {
        v11 = sub_6165E0(v10);
        sub_538860(&unk_BE1CFD, v11, v13, v14);
        LOBYTE(v10) = sub_53A160(a2);
      }
    }
  }
  return v10;
}
