int __thiscall sub_5326E0(char *this, int a2)
{
  int v3; // edx
  _BYTE *v4; // eax
  int v5; // ecx
  int v6; // edi
  int v7; // eax
  char *v8; // esi
  char *v9; // eax
  int v10; // eax
  int v12; // [esp+Ch] [ebp-28h]
  int v13; // [esp+10h] [ebp-24h]
  _BYTE v14[32]; // [esp+14h] [ebp-20h] BYREF

  v12 = 0;
  if ( !a2 )
    return 0;
  v3 = 0;
  v4 = this + 840;
  v5 = 103;
  do
  {
    if ( *v4 )
      ++v3;
    v4 += 920;
    --v5;
  }
  while ( v5 );
  v6 = 0;
  v13 = v3 + 1;
  if ( v3 + 1 > 0 )
  {
    while ( v6 )
    {
      v7 = v6 - 1;
      if ( v6 - 1 >= 0 && v7 <= 102 )
      {
        v8 = &this[920 * v7];
        goto LABEL_12;
      }
LABEL_19:
      if ( ++v6 >= v13 )
        return v12;
    }
    v8 = this + 94760;
LABEL_12:
    if ( v8 )
    {
      v9 = (char *)*((_DWORD *)v8 + 2);
      v14[0] = 0;
      if ( !v9 )
        v9 = (char *)WindowName;
      sub_539600(v9);
      v10 = sub_538790(&unk_BE1CDC);
      if ( v10 )
      {
        sub_630FE0(v14, v10 + 1724, 31);
        v14[31] = 0;
      }
      if ( sub_616480(v14, a2) )
        v12 = (unsigned __int64)((double)v12 + *((float *)v8 + 198));
    }
    goto LABEL_19;
  }
  return 0;
}
