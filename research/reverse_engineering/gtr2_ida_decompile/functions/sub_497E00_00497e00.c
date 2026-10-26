void __thiscall sub_497E00(_BYTE *this)
{
  int v2; // eax
  const CHAR *v3; // eax
  int v4; // [esp+28h] [ebp-170h]
  void *Block; // [esp+30h] [ebp-168h]
  char *Str[3]; // [esp+3Ch] [ebp-15Ch] BYREF
  _BYTE v7[61]; // [esp+48h] [ebp-150h] BYREF
  __int16 v8; // [esp+85h] [ebp-113h]
  char v9; // [esp+87h] [ebp-111h]
  char v10; // [esp+88h] [ebp-110h]
  _BYTE v11[124]; // [esp+89h] [ebp-10Fh] BYREF
  __int16 v12; // [esp+105h] [ebp-93h]
  char v13; // [esp+107h] [ebp-91h]
  char v14; // [esp+108h] [ebp-90h]
  _BYTE v15[124]; // [esp+109h] [ebp-8Fh] BYREF
  __int16 v16; // [esp+185h] [ebp-13h]
  char v17; // [esp+187h] [ebp-11h]
  int v18; // [esp+194h] [ebp-4h]

  memset(v7, 0, sizeof(v7));
  v8 = 0;
  v9 = 0;
  v2 = sub_4CE170(this);
  this[524] = 0;
  if ( v2 )
  {
    sub_630FE0(v7, v2, 63);
    v9 = 0;
  }
  sub_4D0AC0(v4);
  sub_615FC0(&unk_FAECBC);
  Str[0] = 0;
  Str[1] = (char *)-1;
  v3 = *(const CHAR **)dword_91CAC8;
  v18 = 0;
  if ( !*(_DWORD *)dword_91CAC8 )
    v3 = WindowName;
  sub_615860(v3);
  sub_615FE0("*.dst", 1, (char *)WindowName, 0);
  sub_615F10(0);
  sub_615D10(&unk_FAECBC);
  while ( sub_615CC0(&unk_FAECBC) )
  {
    v10 = 0;
    memset(v11, 0, sizeof(v11));
    v12 = 0;
    v13 = 0;
    v14 = 0;
    memset(v15, 0, sizeof(v15));
    v16 = 0;
    v17 = 0;
    sub_497BA0();
    if ( strlen(&v7[52]) )
      sub_4D93B0(&v7[52], 0, 0, &v11[115], 0, 0, -1, -1, -1, -1);
    if ( !strcmp((const char *)Str + 2, &v7[54]) )
    {
      sub_630FE0(Str, &v7[52], 63);
      v7[51] = 0;
    }
    sub_615CE0(&unk_FAECBC);
  }
  if ( strlen((const char *)Str) )
    sub_4D4150(this, Str);
  else
    sub_4D4060(1, 0);
  sub_615FC0(&unk_FAECBC);
  if ( Block )
    j_j__free(Block);
}
