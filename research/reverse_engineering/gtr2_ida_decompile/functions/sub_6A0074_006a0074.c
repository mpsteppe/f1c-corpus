int __thiscall sub_6A0074(_BYTE *this)
{
  int result; // eax
  bool v3; // zf
  _DWORD *v4; // edi
  int v5; // ebx
  int v6; // eax
  int v7; // ecx
  unsigned int j; // eax
  _DWORD *v9; // edi
  int v10; // eax
  unsigned int v11; // eax
  int v12; // eax
  unsigned int i; // edi
  int v14; // ecx
  int *v15; // eax
  int v16; // edx
  int v17; // ebx
  int v18; // [esp-Ch] [ebp-70h]
  int v19[16]; // [esp+4h] [ebp-60h] BYREF
  int v20; // [esp+44h] [ebp-20h]
  int v21; // [esp+48h] [ebp-1Ch]
  int v22; // [esp+4Ch] [ebp-18h]
  int v23; // [esp+50h] [ebp-14h]
  int v24; // [esp+54h] [ebp-10h]
  int v25; // [esp+58h] [ebp-Ch]
  unsigned int v26; // [esp+5Ch] [ebp-8h]
  int v27; // [esp+60h] [ebp-4h]

  result = 0;
  if ( !*((_DWORD *)this + 86) )
  {
    v3 = (this[112] & 0x40) == 0;
    v27 = 0;
    v26 = 0;
    v24 = 0;
    if ( v3 )
    {
      memset(v19, 0, sizeof(v19));
      v20 = 0;
      v21 = 0;
      v22 = 0;
      v3 = *((_DWORD *)this + 2) == 0;
      v23 = 0;
      if ( !v3 )
      {
        do
        {
          v9 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v26);
          if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v9[1]) + 4) & 0x20) != 0 )
          {
            v10 = (*(int (__thiscall **)(_BYTE *, _DWORD))(*(_DWORD *)this + 84))(this, v9[27]);
            v18 = v9[27];
            v25 = v10;
            v11 = (*(int (__thiscall **)(_BYTE *, int))(*(_DWORD *)this + 88))(this, v18);
            if ( v25 == 11 )
            {
              if ( v11 < 4 )
              {
                v12 = 4 * v11;
                v19[v12 + v9[4]] = 1;
                *(int *)((char *)&v20 + v12) = v9[24];
              }
            }
            else if ( v25 == 13 && !v11 && v9[4] && !v24 )
            {
              sub_686791((int)this, v9[24], 4528, "DEPTH must be a scalar");
              v24 = 1;
              v27 = 1;
            }
          }
          ++v26;
        }
        while ( v26 < *((_DWORD *)this + 2) );
      }
      v24 = 0;
      v25 = 1;
      for ( i = 0; i < 4; ++i )
      {
        v14 = 0;
        v15 = &v19[4 * i];
        v16 = 4;
        do
        {
          v17 = *v15++ != 0;
          v14 += v17;
          --v16;
        }
        while ( v16 );
        if ( v14 )
        {
          if ( v14 != 4 )
          {
            sub_686791((int)this, *(&v20 + i), 4529, "COLOR%d must be a four-component vector", i);
            v27 = 1;
          }
          if ( v24 )
            v25 = 0;
        }
        else
        {
          if ( !i )
          {
            sub_686791((int)this, v20, 4530, "pixel shader must minimally write all four components of COLOR0");
            v27 = 1;
          }
          v24 = 1;
        }
      }
      if ( v25 )
        return v27 != 0 ? 0x80004005 : 0;
      sub_686791((int)this, 0, 4538, "COLOR outputs must be contiguous from COLOR0 to COLORn");
    }
    else
    {
      v3 = *((_DWORD *)this + 2) == 0;
      v20 = 0;
      v21 = 0;
      v22 = 0;
      v25 = 0;
      v23 = 0;
      if ( !v3 )
      {
        do
        {
          v4 = *(_DWORD **)(*((_DWORD *)this + 5) + 4 * v26);
          if ( (*(_BYTE *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * v4[1]) + 4) & 0x20) != 0 )
          {
            v5 = (*(int (__thiscall **)(_BYTE *, _DWORD))(*(_DWORD *)this + 84))(this, v4[27]);
            v6 = (*(int (__thiscall **)(_BYTE *, _DWORD))(*(_DWORD *)this + 88))(this, v4[27]);
            if ( v5 == 1 )
            {
              if ( !v6 )
              {
                *(&v20 + v4[4]) = 1;
                v24 = v4[24];
              }
            }
            else if ( v5 == 5 && !v6 && v4[4] && !v25 )
            {
              sub_686791((int)this, v4[24], 4540, "PSIZE must be a scalar");
              v25 = 1;
              v27 = 1;
            }
          }
          ++v26;
        }
        while ( v26 < *((_DWORD *)this + 2) );
      }
      v7 = 0;
      for ( j = 0; j < 4; ++j )
      {
        if ( *(&v20 + j) )
          ++v7;
      }
      if ( v7 == 4 )
        return v27 != 0 ? 0x80004005 : 0;
      sub_686791((int)this, v24, 4541, "vertex shader must minimally write all four components of POSITION");
    }
    v27 = 1;
    return v27 != 0 ? 0x80004005 : 0;
  }
  return result;
}
