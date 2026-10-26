int __thiscall sub_4AEFE0(void *this)
{
  int v1; // ebx
  char *v2; // eax
  int v3; // esi
  int v4; // ebp
  int v5; // edi
  const CHAR *v6; // edx
  const CHAR *v7; // eax
  const CHAR *v8; // eax
  const CHAR *v9; // esi
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // eax
  char v14; // bl
  const char *v15; // eax
  bool v16; // zf
  char v17; // al
  char v19[8]; // [esp+Ah] [ebp-40Ch] BYREF
  void *v20; // [esp+12h] [ebp-404h]
  char v21[500]; // [esp+16h] [ebp-400h] BYREF
  char Buffer[524]; // [esp+20Ah] [ebp-20Ch] BYREF

  v20 = this;
  v19[6] = 0;
  v19[7] = 0;
  v1 = sub_532D20(&unk_B76270);
  v2 = dword_B6F6EC;
  if ( !dword_B6F6EC )
    v2 = (char *)WindowName;
  v3 = sub_539670(v2);
  if ( sub_616480(v3 + 2172, "2ndCar") )
  {
    v4 = 0;
    if ( dword_BE1BD4 > 0 )
    {
      v5 = 0;
      do
      {
        v3 = v5 + dword_BE1BD8;
        v6 = dword_B6F6EC;
        if ( !dword_B6F6EC )
          v6 = WindowName;
        v7 = *(const CHAR **)(v3 + 2716);
        if ( !v7 )
          v7 = WindowName;
        if ( sub_616480(v7, v6) )
          break;
        ++v4;
        v5 += 2824;
      }
      while ( v4 < dword_BE1BD4 );
    }
  }
  v8 = *(const CHAR **)v3;
  if ( !*(_DWORD *)v3 )
    v8 = WindowName;
  sub_615860(v8);
  v9 = *(const CHAR **)v3;
  if ( !v9 )
    v9 = WindowName;
  sub_615860(v9);
  dword_B72934 = 1065353216;
  if ( flt_B7293C <= 1.0 )
  {
    if ( flt_B72940 < 1.0 )
      dword_B72934 = LODWORD(flt_B72940);
  }
  else
  {
    dword_B72934 = LODWORD(flt_B7293C);
  }
  dword_B72A00 = 1065353216;
  if ( flt_B72A08 <= 1.0 )
  {
    if ( flt_B72A0C < 1.0 )
      dword_B72A00 = LODWORD(flt_B72A0C);
  }
  else
  {
    dword_B72A00 = LODWORD(flt_B72A08);
  }
  sub_616930("Game Filter");
  sub_501CC0(&byte_B6F530, 1);
  sprintf(Buffer, "%s NOT: 2ndCar", v19);
  sub_53BDE0(&unk_BE1CE0, Buffer);
  v10 = sub_5A6E90(&unk_BE1CE0);
  v11 = dword_B72C00;
  v12 = v10 - 1;
  dword_B72BF8 = v12;
  if ( v12 < dword_B72C00 || (v11 = dword_B72C04, v12 > dword_B72C04) )
    dword_B72BF8 = v11;
  if ( !v1 )
    return 0;
  v13 = *(_DWORD *)(v1 + 95732);
  v14 = 1;
  if ( v13 != 2 )
    v14 = (unsigned int)v21 >> 16;
  if ( v13 != 3 )
    goto LABEL_34;
  v15 = Str;
  if ( !Str )
    v15 = WindowName;
  v16 = strstr(v15, "Custom") == 0;
  v17 = 1;
  if ( v16 )
LABEL_34:
    v17 = (unsigned int)v21 >> 24;
  if ( v14 )
  {
    sub_4E1810("CHAMPIONSHIP START NEW SEASON WANING", 0);
    return -1;
  }
  if ( !v17 )
    return 0;
  sub_4E1810("CHAMPIONSHIP CONFIRM NEW SEASON WARNING", 0);
  return -1;
}
