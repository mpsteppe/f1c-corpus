int __thiscall sub_4ACA10(int this)
{
  const char *v2; // eax
  double v3; // st7
  char *v4; // eax
  const CHAR **v5; // esi
  const CHAR *v6; // eax
  int result; // eax
  const CHAR *v8; // esi

  v2 = *(const char **)(this + 160);
  if ( !v2 )
    v2 = WindowName;
  v3 = atof(v2);
  *(float *)(this + 276) = v3;
  if ( v3 == 0.0 )
    *(_DWORD *)(this + 276) = 1084227584;
  v4 = dword_B6F708;
  if ( !dword_B6F708 )
    v4 = (char *)WindowName;
  sub_539600(v4);
  sub_538790(&unk_BE1CDC);
  sub_539FF0(&unk_BE1CE0);
  dword_BE1BD0 = sub_53A0E0(&unk_BE1CE0);
  v5 = (const CHAR **)sub_538790(&unk_BE1CDC);
  v6 = *v5;
  if ( !*v5 )
    v6 = WindowName;
  sub_615860(v6);
  sub_615860(v5 + 463);
  result = *(_DWORD *)dword_B72314;
  if ( *(_DWORD *)dword_B72314 != 4 && *(_DWORD *)dword_B72314 != 8 )
  {
    v8 = *v5;
    if ( !v8 )
      v8 = WindowName;
    return sub_615860(v8);
  }
  return result;
}
