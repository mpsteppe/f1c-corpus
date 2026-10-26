void __thiscall sub_4EFA90(int this, float a2)
{
  int v3; // eax
  double v4; // st7
  double v5; // st6
  double v6; // st7
  const char *v7; // eax
  CHAR *v8; // esi
  int v9; // eax
  _DWORD *v10; // eax
  const char ***v11; // esi
  const char **v12; // esi
  const char *v13; // esi
  int v14; // edi
  int v15; // esi
  bool v16; // cc
  _DWORD v17[2]; // [esp+Ch] [ebp-38h] BYREF
  int v18; // [esp+14h] [ebp-30h]
  _off_t st_size; // [esp+18h] [ebp-2Ch]
  char v20; // [esp+1Ch] [ebp-28h]
  struct _stat32 Stat; // [esp+20h] [ebp-24h] BYREF
  float v22; // [esp+48h] [ebp+4h]

  if ( a2 <= 0.0 )
    a2 = dbl_7DA9C0;
  if ( *(_BYTE *)(this + 20) && dword_7D6BB4 && *(float *)(dword_7D6BB4 + 4) > 0.0 )
  {
    if ( (*(int (**)(void))(*(_DWORD *)dword_7D6BB4 + 8))() )
    {
      v3 = *(_DWORD *)(this + 24);
      if ( v3 )
      {
        v4 = *(float *)(dword_7D6BB4 + 4);
        v5 = a2 * *(float *)(this + 28);
        if ( v3 == 1 )
        {
          v22 = v5 + v4;
          if ( v22 >= (double)flt_767898 )
          {
            v22 = flt_767898;
LABEL_13:
            *(_DWORD *)(this + 24) = 0;
          }
        }
        else
        {
          v6 = v4 - v5;
          v22 = v6;
          if ( v6 <= 0.0 )
          {
            v22 = 0.0;
            goto LABEL_13;
          }
        }
        (*(void (__thiscall **)(int, float))(*(_DWORD *)dword_7D6BB4 + 32))(dword_7D6BB4, COERCE_FLOAT(LODWORD(v22)));
        (*(void (__thiscall **)(int))(*(_DWORD *)dword_7D6BB4 + 24))(dword_7D6BB4);
        return;
      }
    }
    else
    {
      v17[0] = 0;
      v17[1] = -1;
      sub_578600(&byte_629120);
      v7 = *(const char **)(this + 32);
      v18 = -1;
      st_size = -1;
      v20 = 0;
      if ( !v7 )
        v7 = &byte_629120;
      if ( strlen(v7) )
      {
        v8 = *(CHAR **)(this + 32);
        if ( !v8 )
          v8 = &byte_629120;
        sub_578600(v8);
      }
      else if ( *(int *)(this + 16) <= 0 )
      {
        v14 = dword_5EA788[dword_7D6BAC];
        v15 = dword_611130;
        sub_578600(&byte_629120);
        v16 = dword_7D6BAC + 1 < 4;
        v18 = v14;
        st_size = v15;
        v20 = 0;
        ++dword_7D6BAC;
        if ( !v16 )
          dword_7D6BAC = 0;
      }
      else
      {
        if ( byte_611138 )
        {
          byte_611138 = 0;
        }
        else
        {
          v9 = *(_DWORD *)(this + 12);
          if ( v9 )
            *(_DWORD *)(this + 12) = *(_DWORD *)(v9 + 4);
          v10 = *(_DWORD **)(this + 12);
          if ( !v10 || !*v10 )
            *(_DWORD *)(this + 12) = *(_DWORD *)(this + 4);
        }
        v11 = *(const char ****)(this + 12);
        if ( v11 )
          v12 = *v11;
        else
          v12 = 0;
        v13 = *v12;
        if ( !v13 )
          v13 = &byte_629120;
        sub_578600(v13);
        if ( sub_579060(v13, aDjs) && !_stat(v13, &Stat) )
        {
          v18 = 0;
          st_size = Stat.st_size;
          v20 = 1;
        }
      }
      (*(void (__thiscall **)(int, _DWORD *, int, _DWORD))(*(_DWORD *)dword_7D6BB4 + 4))(dword_7D6BB4, v17, 1, 0);
      if ( v17[0] )
        sub_5BE8AE();
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)dword_7D6BB4 + 24))(dword_7D6BB4);
  }
}
