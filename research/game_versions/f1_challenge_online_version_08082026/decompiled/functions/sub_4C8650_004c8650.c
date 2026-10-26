void __thiscall sub_4C8650(void *this, float a2)
{
  int v3; // eax
  double v4; // st7
  double v5; // st6
  double v6; // st7
  bool v7; // cc
  int v8; // eax
  _DWORD *v9; // eax
  char ***v10; // esi
  char **v11; // esi
  char *v12; // eax
  int v13; // esi
  int v14; // edi
  LPVOID v15[2]; // [esp+Ch] [ebp-14h] BYREF
  int v16; // [esp+14h] [ebp-Ch]
  int v17; // [esp+18h] [ebp-8h]
  char v18; // [esp+1Ch] [ebp-4h]
  float v19; // [esp+24h] [ebp+4h]

  if ( a2 <= 0.0 )
    a2 = dbl_8AFE90;
  if ( *((_BYTE *)this + 16) && dword_8AC4C8 && *(float *)(dword_8AC4C8 + 4) > 0.0 )
  {
    if ( (*(int (**)(void))(*(_DWORD *)dword_8AC4C8 + 8))() )
    {
      v3 = *((_DWORD *)this + 5);
      if ( v3 )
      {
        v4 = *(float *)(dword_8AC4C8 + 4);
        v5 = a2 * *((float *)this + 6);
        if ( v3 == 1 )
        {
          v19 = v5 + v4;
          if ( v19 >= (double)flt_7CF380 )
          {
            v19 = flt_7CF380;
LABEL_13:
            *((_DWORD *)this + 5) = 0;
          }
        }
        else
        {
          v6 = v4 - v5;
          v19 = v6;
          if ( v6 <= 0.0 )
          {
            v19 = 0.0;
            goto LABEL_13;
          }
        }
        (*(void (__thiscall **)(int, float))(*(_DWORD *)dword_8AC4C8 + 28))(dword_8AC4C8, COERCE_FLOAT(LODWORD(v19)));
        (*(void (__thiscall **)(int))(*(_DWORD *)dword_8AC4C8 + 24))(dword_8AC4C8);
        return;
      }
    }
    else
    {
      v15[0] = 0;
      v15[1] = (LPVOID)-1;
      sub_566650(byte_5EA438);
      v7 = *((_DWORD *)this + 3) <= 0;
      v16 = -1;
      v17 = -1;
      v18 = 0;
      if ( v7 )
      {
        v13 = dword_5D3254;
        v14 = dword_5ACDEC[dword_8AC4C0];
        sub_566650(byte_5EA438);
        v7 = dword_8AC4C0 + 1 < 4;
        v16 = v14;
        v17 = v13;
        v18 = 0;
        ++dword_8AC4C0;
        if ( !v7 )
          dword_8AC4C0 = 0;
      }
      else
      {
        v8 = *((_DWORD *)this + 2);
        if ( v8 )
          *((_DWORD *)this + 2) = *(_DWORD *)(v8 + 4);
        v9 = (_DWORD *)*((_DWORD *)this + 2);
        if ( !v9 || !*v9 )
          *((_DWORD *)this + 2) = *(_DWORD *)this;
        v10 = (char ***)*((_DWORD *)this + 2);
        if ( v10 )
          v11 = *v10;
        else
          v11 = 0;
        v12 = *v11;
        if ( !*v11 )
          v12 = byte_5EA438;
        sub_566650(v12);
      }
      (*(void (__thiscall **)(int, LPVOID *, int, _DWORD))(*(_DWORD *)dword_8AC4C8 + 4))(dword_8AC4C8, v15, 1, 0);
      if ( v15[0] )
        sub_587BCF(v15[0]);
    }
    (*(void (__thiscall **)(int))(*(_DWORD *)dword_8AC4C8 + 24))(dword_8AC4C8);
  }
}
