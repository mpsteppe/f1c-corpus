void __thiscall sub_4BC4E0(_DWORD **this, float a2, float a3, int a4, int a5)
{
  int v6; // eax
  int v7; // edi
  float v8; // ecx
  _DWORD *v9; // eax
  double v10; // st7
  _DWORD *v11; // eax
  _DWORD *v12; // ecx
  _DWORD *v13; // ecx
  int v14; // eax
  int v15; // edx
  int v16; // ebp
  int *v17; // edi
  int v18; // eax
  int v19; // eax
  char v20; // cl
  int v21; // ecx
  int v22; // eax
  int v23; // edx
  int v24; // eax
  _DWORD *v25; // ecx
  int v26; // esi
  char v27[80]; // [esp+10h] [ebp-50h] BYREF

  if ( (*this)[3250] == 3 )
    return;
  if ( !a4 )
  {
    v6 = (int)this[2];
    this[3] = 0;
    if ( v6 >= 127 )
    {
      v7 = 127;
    }
    else
    {
      v7 = v6;
      if ( v6 < 0 )
        goto LABEL_14;
    }
    if ( v7 < (int)this[34] )
    {
      if ( a2 > 0.0 )
      {
        *(float *)&this[36][v7] = a2;
        if ( *((float *)this + 26) < 0.0 || a2 < (double)*((float *)this + 26) )
        {
          v8 = *(float *)this;
          this[32] = this[25];
          v9 = this[3];
          *((float *)this + 26) = a2;
          sub_4D1C40(v9, *(_DWORD *)(LODWORD(v8) + 18580), 0);
        }
        v10 = *((float *)this + 29);
        *((float *)this + 6) = a2;
        if ( v10 <= 0.0 || *((float *)this + 29) > (double)a2 )
        {
          v11 = this[7];
          v12 = this[8];
          this[29] = this[6];
          this[30] = v11;
          this[31] = v12;
        }
      }
      *((_BYTE *)this[37] + v7) = sub_4D1BC0(*((_BYTE *)this + 4));
    }
LABEL_14:
    v13 = this[24];
    if ( !v13 )
      goto LABEL_64;
    v14 = a5 + 1;
    this[2] = (_DWORD *)(a5 + 1);
    v15 = dword_7C56A4;
    switch ( dword_7C56A4 )
    {
      case 0:
        sub_4199E0((int)*this);
        goto LABEL_62;
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
        if ( this[12] == (_DWORD *)1 )
        {
          if ( dword_7C56A4 == 5 && v14 > dword_8ACF8C && dword_7CE814 && (*this)[3250] <= 1u )
          {
            if ( sub_423A00(byte_5EC4C0, aLaps_1, byte_5EC4CC) )
            {
              v19 = 0;
              do
              {
                v20 = aLaps_1[v19];
                byte_5EC4CC[v19++] = v20;
              }
              while ( v20 );
            }
            sub_58815F(v27, "%d %s", this[2], byte_5EC4CC);
            sub_4BC0E0((int *)this, v27);
          }
        }
        else
        {
          if ( v13 == (_DWORD *)2 )
          {
            sub_4199E0((int)*this);
            v15 = dword_7C56A4;
          }
          v21 = (int)this[2];
          if ( (v21 >= dword_8ACF8C || flt_8ACF94 <= (double)a3) && this[12] != (_DWORD *)3 )
          {
            this[12] = (_DWORD *)1;
            v15 = dword_7C56A4;
          }
          if ( (v21 >= dword_8ACF8C - 1 || flt_8ACF94 <= (double)a3)
            && v15 == 5
            && this[1] == *(_DWORD **)(dword_7C54F0[dword_7C54E4] + 18580) )
          {
            sub_4A0C60();
          }
        }
        goto LABEL_62;
      case 7:
        if ( dword_7C56A8 == 8 )
        {
          if ( this[12] != (_DWORD *)3 )
            this[12] = (_DWORD *)1;
          *((float *)this + 33) = a3 - flt_8ACF90;
        }
        else
        {
          if ( v14 < dword_8ACF8C && flt_8ACF94 > (double)a3 )
          {
            sub_4A0B20(*this);
            sub_4199E0((int)*this);
LABEL_28:
            v16 = 0;
            if ( (int)this[15] > 0 )
            {
              v17 = (int *)(this + 16);
              do
              {
                v18 = *v17;
                if ( *v17 && (v18 != 1 || *((_BYTE *)*this + 13388)) )
                {
                  *v17 = v18 - 1;
                }
                else
                {
                  if ( (*this)[3250] <= 1u )
                    sub_4BC0E0((int *)this, aIgnoredStopGoP);
                  *v17 = 0;
                }
                if ( this[12] )
                  *((float *)this + 33) = (double)(v17[1] + 15) + *((float *)this + 33);
                ++v16;
                v17 += 2;
              }
              while ( v16 < (int)this[15] );
            }
LABEL_62:
            if ( !byte_8ACFA0 )
              byte_8ACFA0 = (int)this[2] >= (dword_8ACF8C + 1) >> 1;
LABEL_64:
            *((float *)this + 25) = a3;
            v22 = (int)this[2];
            this[24] = (_DWORD *)2;
            if ( v22 > 0 && v22 <= (int)this[34] )
              *(float *)&this[35][v22 - 1] = a3;
            sub_4BC240(this);
            return;
          }
          if ( this[12] != (_DWORD *)3 )
            this[12] = (_DWORD *)1;
          *((float *)this + 33) = a3 - flt_8ACF90;
          sub_42D140(&dword_7C569C, 8u);
        }
        sub_4A0BA0(&unk_7CE24C, *this);
        goto LABEL_28;
      default:
        goto LABEL_62;
    }
  }
  this[3] = (_DWORD *)a4;
  if ( a2 > 0.0 )
  {
    if ( *(float *)&this[a4 + 26] < 0.0 || a2 < (double)*(float *)&this[a4 + 26] )
      *(float *)&this[a4 + 26] = a2;
    *(float *)&this[(_DWORD)this[3] + 6] = a2;
    sub_4D1C40(this[3], (*this)[4645], 0);
    sub_419500((int)*this, (int)this[3]);
  }
  if ( !this[24] && this[3] == (_DWORD *)1 )
    this[24] = (_DWORD *)1;
  if ( a4 == 2 )
  {
    v23 = (int)this[15];
    v24 = 0;
    if ( v23 > 0 )
    {
      v25 = this + 16;
      while ( *v25 != 1 )
      {
        ++v24;
        v25 += 2;
        if ( v24 >= v23 )
          goto LABEL_83;
      }
      sub_41A8C0((int)*this);
    }
  }
LABEL_83:
  v26 = (int)*this;
  if ( !*(_DWORD *)(v26 + 13000) )
    sub_4A6D50((_DWORD *)(v26 + 13004));
}
