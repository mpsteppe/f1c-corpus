void __thiscall sub_495FF0(const char **this)
{
  const CHAR *v2; // edx
  const char **v3; // ebp
  const char *v4; // eax
  int v5; // eax
  const CHAR *v6; // eax
  const char *v7; // eax
  const CHAR *v8; // eax
  int i; // eax
  char *v10; // eax
  const CHAR *v11; // eax
  bool v12; // zf
  char *v13; // eax
  char *v14; // eax
  char *v15; // esi
  const CHAR *v16; // eax
  int v17; // eax
  const CHAR *v18; // [esp-1Ch] [ebp-154h]
  int v19; // [esp-4h] [ebp-13Ch]
  char v20; // [esp+14h] [ebp-124h] BYREF
  __int16 v21; // [esp+15h] [ebp-123h]
  char v22; // [esp+17h] [ebp-121h]
  void *Block; // [esp+18h] [ebp-120h]
  int v24; // [esp+1Ch] [ebp-11Ch]
  char *Str; // [esp+20h] [ebp-118h]
  int v26; // [esp+24h] [ebp-114h]
  char v27[260]; // [esp+28h] [ebp-110h] BYREF
  int v28; // [esp+134h] [ebp-4h]

  v2 = this[149];
  v3 = this + 149;
  v4 = v2;
  if ( !v2 )
    v4 = WindowName;
  v5 = strlen(v4);
  if ( v5 > 0 )
  {
    if ( !v2 )
      v2 = WindowName;
    if ( v2[v5 - 1] != 92 )
      sub_615A50(word_6F1F78);
  }
  Str = 0;
  v26 = -1;
  v6 = *(const CHAR **)dword_91CAC8;
  v28 = 0;
  if ( !*(_DWORD *)dword_91CAC8 )
    v6 = WindowName;
  sub_615860(v6);
  v7 = *v3;
  if ( !*v3 )
    v7 = WindowName;
  Block = (void *)strlen(v7);
  if ( Block )
  {
    v8 = *v3;
    if ( !*v3 )
      v8 = WindowName;
    sub_615A50(v8);
  }
  sub_615FE0("*.txt", 0, (char *)WindowName, 1);
  sub_615F10(0);
  v21 = 0;
  v20 = 0;
  v22 = 0;
  sub_4CE140(this, &v20);
  sub_4D0AC0(v19);
  sub_615D10(&unk_FAECBC);
  for ( i = sub_615D40(&unk_FAECBC); i; i = sub_615D40(&unk_FAECBC) )
  {
    sub_630FE0(v27, i, 255);
    v27[255] = 0;
    v10 = &v27[strlen(v27)];
    if ( v10 > v27 )
    {
      while ( *v10 != 46 )
      {
        if ( --v10 <= v27 )
          goto LABEL_22;
      }
      *v10 = 0;
    }
LABEL_22:
    Block = 0;
    v24 = -1;
    v11 = *v3;
    v12 = *v3 == 0;
    LOBYTE(v28) = 1;
    if ( v12 )
      v11 = WindowName;
    sub_615860(v11);
    v13 = &v27[strlen(v27)];
    if ( v13 > v27 )
    {
      while ( *v13 != 92 )
      {
        if ( --v13 <= v27 )
          goto LABEL_29;
      }
      ++v13;
    }
LABEL_29:
    sub_615A50(v13);
    v14 = &v27[strlen(v27)];
    if ( v14 > v27 )
    {
      while ( *v14 != 92 )
      {
        if ( --v14 <= v27 )
          goto LABEL_34;
      }
      ++v14;
    }
LABEL_34:
    v15 = v14 + 3;
    v16 = (const CHAR *)Block;
    if ( !Block )
      v16 = WindowName;
    v18 = v16;
    v17 = sub_4CF8C0(this);
    sub_4D93B0(v15, 0, v17, v18, 0, 0, -1, -1, -1, -1);
    sub_615CE0(&unk_FAECBC);
    LOBYTE(v28) = 0;
    if ( Block )
      j_j__free(Block);
  }
  sub_4D4060(1, 1);
  this[139] = (const char *)sub_4CE1B0(this);
  if ( Str )
    j_j__free(Str);
}
