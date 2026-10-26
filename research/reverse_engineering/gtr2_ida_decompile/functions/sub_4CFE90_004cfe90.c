int __thiscall sub_4CFE90(_DWORD *this)
{
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax
  int v5; // eax
  const CHAR *v6; // eax
  const char *v7; // eax
  char *v8; // eax
  int v9; // ecx
  int v10; // edi
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v15; // [esp+0h] [ebp-1Ch]
  int v16; // [esp+0h] [ebp-1Ch]
  int v17; // [esp+4h] [ebp-18h]
  int v18; // [esp+8h] [ebp-14h]
  _BYTE v19[4]; // [esp+10h] [ebp-Ch] BYREF
  _BYTE v20[8]; // [esp+14h] [ebp-8h] BYREF

  v2 = (const char *)this[42];
  if ( !v2 )
    v2 = WindowName;
  if ( !_stricmp(v2, "l") )
    this[67] = 0;
  v3 = (const char *)this[42];
  if ( !v3 )
    v3 = WindowName;
  if ( !_stricmp(v3, "r") )
    this[67] = 1;
  v4 = (const char *)this[42];
  if ( !v4 )
    v4 = WindowName;
  if ( !_stricmp(v4, "c") )
    this[67] = 2;
  v5 = this[61];
  if ( v5 )
  {
    v6 = *(const CHAR **)(v5 + 64);
    if ( !v6 )
      v6 = WindowName;
  }
  else
  {
    v6 = 0;
  }
  sub_4DF1B0(this[12], v6);
  v7 = (const char *)this[40];
  if ( !v7 )
    v7 = WindowName;
  v8 = sub_41D840(&byte_91CC38, v7);
  sub_4E08C0(this[12], v8, v19, v20, 1, v18);
  if ( this[2] - this[1] <= 0 )
    v9 = 0;
  else
    v9 = this[2] - this[1] + 1;
  v17 = v9;
  if ( this[4] - this[3] <= 0 )
    v10 = 0;
  else
    v10 = this[4] - this[3] + 1;
  v11 = v15 + 5;
  v16 = v15 + 5;
  if ( v16 > v10 )
  {
    sub_4E2B30(v11, v9);
    v12 = this[67];
    if ( !v12 )
    {
      sub_4CD670(this, 0, 0);
      return 0;
    }
    v13 = v12 - 1;
    if ( !v13 )
    {
      sub_4CD670(this, v10 - v16, 0);
      return 0;
    }
    if ( v13 == 1 )
    {
      sub_4CD670(this, (v10 - v16) / 2, 0);
      return 0;
    }
    sub_4CD670(this, v17, 0);
  }
  return 0;
}
