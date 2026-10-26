int __thiscall sub_4CE200(int this, int a2)
{
  int v3; // ecx
  int v4; // eax
  const CHAR *v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // edi
  _BYTE v10[253]; // [esp+8h] [ebp-100h] BYREF
  __int16 v11; // [esp+105h] [ebp-3h]

  memset(v10, 0, sizeof(v10));
  v3 = *(_DWORD *)(this + 584);
  v11 = 0;
  if ( v3 < 0 )
    return 0;
  v4 = *(_DWORD *)(this + 144);
  if ( !v4 )
    return 0;
  while ( v3 > 0 )
  {
    v4 = *(_DWORD *)(v4 + 140);
    --v3;
    if ( !v4 )
      return 0;
  }
  v6 = *(const CHAR **)(v4 + 160);
  if ( !v6 )
    v6 = WindowName;
  v7 = this + 269;
  *(_BYTE *)(this + 269) = 0;
  sub_630FE0(v10, v6, 255);
  v8 = sub_6331DF(v10, &word_6FD924);
  v9 = a2;
  if ( a2 > 0 )
  {
    do
    {
      v8 = sub_6331DF(0, &word_6FD924);
      --v9;
    }
    while ( v9 );
  }
  if ( !v8 )
    return 0;
  sub_630FE0(v7, v8, 255);
  return v7;
}
