unsigned int __thiscall sub_6AA7D5(_DWORD *this)
{
  int v2; // esi
  int v3; // edx
  bool v4; // zf
  int v5; // esi
  int v6; // edi
  int v7; // eax
  unsigned int v8; // eax
  _DWORD *v9; // eax
  int v10; // esi
  unsigned int i; // eax
  int v13[4]; // [esp+Ch] [ebp-20h] BYREF
  int v14; // [esp+1Ch] [ebp-10h]
  int v15; // [esp+20h] [ebp-Ch]
  int v16; // [esp+24h] [ebp-8h]
  int v17; // [esp+28h] [ebp-4h]

  memset(v13, 0, sizeof(v13));
  this[134] = 0;
  this[135] = 0;
  v2 = 0;
  v3 = 0;
  memset(this + 126, 0, 0x20u);
  v4 = this[2] == 0;
  v16 = 0;
  v15 = 0;
  v14 = 0;
  v17 = 0;
  if ( !v4 )
  {
    while ( 1 )
    {
      v5 = *(_DWORD *)(this[5] + 4 * v17);
      v6 = *(_DWORD *)(this[4] + 4 * *(_DWORD *)(v5 + 4));
      if ( *(_DWORD *)(v5 + 8) != -1 && !v16 )
      {
        sub_686791((int)this, *(_DWORD *)(v5 + 96), 4511, "relative addressing not supported in ps_1_x");
        v16 = 1;
        v3 = 1;
      }
      v7 = *(_DWORD *)(v6 + 4);
      if ( (v7 & 0x20) != 0 )
      {
        if ( *(unsigned __int8 *)(v5 + 109) > 3u )
          goto LABEL_26;
        if ( (unsigned __int8)*(_DWORD *)(v5 + 108) == 1 )
        {
          if ( !*(_BYTE *)(v5 + 109) )
          {
            v13[*(_DWORD *)(v5 + 16)] = 1;
            v14 = *(_DWORD *)(v5 + 96);
          }
        }
        else if ( (unsigned __int8)*(_DWORD *)(v5 + 108) == 2 && !*(_BYTE *)(v5 + 109) && *(_DWORD *)(v5 + 16) && !v15 )
        {
          sub_686791((int)this, *(_DWORD *)(v5 + 96), 4528, "DEPTH must be a scalar");
          v15 = 1;
          v3 = 1;
        }
        goto LABEL_25;
      }
      if ( (v7 & 0x10) != 0 && (v7 & 0x200) == 0 )
      {
        v8 = *(unsigned __int8 *)(v5 + 109);
        if ( (unsigned __int8)*(_DWORD *)(v5 + 108) == 1 )
        {
          if ( v8 < 2 )
          {
            v9 = &this[v8 + 134];
LABEL_23:
            v10 = *(_DWORD *)(v5 + 16);
            if ( *v9 < (unsigned int)(v10 + 1) )
              *v9 = v10 + 1;
          }
        }
        else if ( (unsigned __int8)*(_DWORD *)(v5 + 108) == 3 && v8 < 8 )
        {
          v9 = &this[v8 + 126];
          goto LABEL_23;
        }
      }
LABEL_25:
      if ( (unsigned int)++v17 >= this[2] )
      {
LABEL_26:
        v2 = 0;
        break;
      }
    }
  }
  for ( i = 0; i < 4; ++i )
    v2 += v13[i] != 0;
  if ( v2 != 4 )
  {
    sub_686791((int)this, v14, 4530, "pixel shader must minimally write all four components of COLOR0");
    v3 = 1;
  }
  return v3 != 0 ? 0x80004005 : 0;
}
