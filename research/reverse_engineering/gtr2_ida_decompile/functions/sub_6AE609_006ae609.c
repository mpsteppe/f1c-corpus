unsigned int __thiscall sub_6AE609(_DWORD *this)
{
  unsigned int result; // eax
  bool v3; // zf
  _DWORD *v4; // edi
  int v5; // eax
  int v6; // ebx
  unsigned int v7; // eax
  unsigned int v8; // eax
  int v9; // ebx
  unsigned int v10; // eax
  _DWORD *v11; // eax
  int v12; // edi
  unsigned int i; // edi
  int v14; // ecx
  _DWORD *v15; // eax
  int v16; // edx
  _DWORD v17[16]; // [esp+4h] [ebp-60h] BYREF
  int v18[4]; // [esp+44h] [ebp-20h] BYREF
  int v19; // [esp+54h] [ebp-10h]
  int v20; // [esp+58h] [ebp-Ch]
  unsigned int v21; // [esp+5Ch] [ebp-8h]
  int v22; // [esp+60h] [ebp-4h]

  result = 0;
  if ( !this[86] )
  {
    memset(v17, 0, sizeof(v17));
    memset(v18, 0, sizeof(v18));
    this[134] = 0;
    this[135] = 0;
    memset(this + 126, 0, 0x20u);
    v3 = this[2] == 0;
    v22 = 0;
    v20 = 0;
    v21 = 0;
    if ( !v3 )
    {
      do
      {
        v4 = *(_DWORD **)(this[5] + 4 * v21);
        v5 = *(_DWORD *)(*(_DWORD *)(this[4] + 4 * v4[1]) + 4);
        if ( (v5 & 0x20) != 0 )
        {
          v6 = (*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 84))(this, v4[27]);
          v7 = (*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 88))(this, v4[27]);
          if ( v6 == 11 )
          {
            if ( v7 < 4 )
            {
              v8 = v7;
              v17[v8 * 4 + v4[4]] = 1;
              v18[v8] = v4[24];
            }
          }
          else if ( v6 == 13 && !v7 && v4[4] && !v20 )
          {
            sub_686791((int)this, v4[24], 4528, "DEPTH must be a scalar");
            v20 = 1;
            v22 = 1;
          }
        }
        else if ( (v5 & 0x10) != 0 && (v5 & 0x200) == 0 )
        {
          v9 = (*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 84))(this, v4[27]);
          v10 = (*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 88))(this, v4[27]);
          if ( v9 == 6 )
          {
            if ( v10 < 8 )
            {
              v11 = &this[v10 + 126];
LABEL_20:
              v12 = v4[4];
              if ( *v11 < (unsigned int)(v12 + 1) )
                *v11 = v12 + 1;
            }
          }
          else if ( v9 == 11 && v10 < 2 )
          {
            v11 = &this[v10 + 134];
            goto LABEL_20;
          }
        }
        ++v21;
      }
      while ( v21 < this[2] );
    }
    v21 = 0;
    v19 = 1;
    for ( i = 0; i < 4; ++i )
    {
      v14 = 0;
      v15 = &v17[4 * i];
      v20 = 4;
      do
      {
        v16 = *v15++ != 0;
        v14 += v16;
        --v20;
      }
      while ( v20 );
      if ( v14 )
      {
        if ( v14 != 4 )
        {
          sub_686791((int)this, v18[i], 4529, "COLOR%d must be a four-component vector", i);
          v22 = 1;
        }
        if ( v21 )
          v19 = 0;
      }
      else
      {
        if ( !i )
        {
          sub_686791((int)this, v18[0], 4530, "pixel shader must minimally write all four components of COLOR0");
          v22 = 1;
        }
        v21 = 1;
      }
    }
    if ( !v19 )
    {
      sub_686791((int)this, 0, 4538, "COLOR outputs must be contiguous from COLOR0 to COLORn");
      v22 = 1;
    }
    return v22 != 0 ? 0x80004005 : 0;
  }
  return result;
}
