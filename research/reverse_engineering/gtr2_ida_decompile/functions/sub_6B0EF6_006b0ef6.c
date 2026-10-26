unsigned int __thiscall sub_6B0EF6(_DWORD *this)
{
  unsigned int result; // eax
  bool v3; // zf
  _DWORD *v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // ecx
  unsigned int i; // eax
  int v9; // [esp-Ch] [ebp-38h]
  _DWORD v10[4]; // [esp+4h] [ebp-28h] BYREF
  int v11; // [esp+14h] [ebp-18h]
  int v12; // [esp+18h] [ebp-14h]
  int v13; // [esp+1Ch] [ebp-10h]
  int v14; // [esp+20h] [ebp-Ch]
  int v15; // [esp+24h] [ebp-8h]
  unsigned int v16; // [esp+28h] [ebp-4h]

  result = 0;
  if ( !this[86] )
  {
    v3 = this[2] == 0;
    memset(v10, 0, sizeof(v10));
    v14 = 0;
    v13 = 0;
    v15 = 0;
    v12 = 0;
    v16 = 0;
    if ( !v3 )
    {
      do
      {
        v4 = *(_DWORD **)(this[5] + 4 * v16);
        if ( (*(_BYTE *)(*(_DWORD *)(this[4] + 4 * v4[1]) + 4) & 0x20) != 0 )
        {
          v5 = (*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 84))(this, v4[27]);
          v9 = v4[27];
          v11 = v5;
          v6 = (*(int (__thiscall **)(_DWORD *, int))(*this + 88))(this, v9);
          if ( v11 == 1 )
          {
            if ( !v6 )
            {
              v10[v4[4]] = 1;
              v12 = v4[24];
            }
            goto LABEL_18;
          }
          if ( v11 == 5 )
          {
            if ( v6 || !v4[4] || v13 )
              goto LABEL_18;
            sub_686791((int)this, v4[24], 4540, "PSIZE must be a scalar");
            v13 = 1;
          }
          else
          {
            if ( v11 != 12 || v6 || !v4[4] || v14 )
              goto LABEL_18;
            sub_686791((int)this, v4[24], 4540, "FOG must be a scalar");
            v14 = 1;
          }
          v15 = 1;
        }
LABEL_18:
        ++v16;
      }
      while ( v16 < this[2] );
    }
    v7 = 0;
    for ( i = 0; i < 4; ++i )
    {
      if ( v10[i] )
        ++v7;
    }
    if ( v7 != 4 )
    {
      sub_686791((int)this, v12, 4541, "vertex shader must minimally write all four components of POSITION");
      v15 = 1;
    }
    return v15 != 0 ? 0x80004005 : 0;
  }
  return result;
}
