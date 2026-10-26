void __thiscall sub_4DD490(_DWORD *this, float a2, float a3, int a4, int a5)
{
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  char v10; // bl
  int v11; // eax
  int v12; // edi
  double v13; // st7
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // ebx
  int *v18; // edi
  int v19; // eax
  int v20; // eax
  _DWORD *v21; // [esp-10h] [ebp-14h]
  _DWORD *v22; // [esp-10h] [ebp-14h]

  v6 = *this;
  if ( *(_DWORD *)(*this + 16584) == 3 )
  {
    if ( !a4 && !*(_DWORD *)(v6 + 5284) )
      sub_50C9A0(1);
    return;
  }
  if ( !a4 )
  {
    if ( !*(_DWORD *)(v6 + 5284) )
      sub_50C9A0(1);
    *((_BYTE *)this + 36) = 0;
    byte_7D78D4 = 1;
    if ( (unsigned __int8)sub_4EED40(*this) )
      sub_4C1970((int *)(*this + 16588), 0);
    if ( this[2] == 9 )
    {
      v7 = *this;
      this[2] = 5;
      sub_421590(v7, 16, 0);
    }
    ++this[70];
    if ( !dword_7D7540 || dword_7D7540 == 7 )
    {
      sub_4DEA70(0);
      if ( (unsigned __int8)sub_4EED40(*this) )
        sub_51F3D0(0, 4);
    }
    else if ( dword_7D7540 >= 1 )
    {
      if ( dword_7D7540 == 1 && (v8 = 0, (int)NumOfElements > 0) )
      {
        while ( 1 )
        {
          v9 = dword_75AAD0[v8];
          if ( v9 != *this && a5 + 1 <= *(_DWORD *)(v9 + 20848) )
            break;
          if ( ++v8 >= (int)NumOfElements )
            goto LABEL_20;
        }
      }
      else
      {
LABEL_20:
        v10 = sub_4DEB10(this);
        sub_4DEA70(1);
        if ( !v10 )
        {
          v11 = *this;
          this[70] = 0;
          if ( !*(_BYTE *)(v11 + 17412) )
            sub_4F7F20(v11, a3);
          flt_5FD0F0 = dbl_7DA9D0 + 2.0;
        }
        if ( (unsigned __int8)sub_4EED40(*this) )
        {
          if ( !*(_BYTE *)(*this + 17412) )
          {
            sub_51F3D0(1, 4);
            if ( !v10 )
              sub_41BA10(2, -1);
          }
        }
      }
    }
    v12 = this[3];
    this[4] = 0;
    if ( v12 < 999 )
    {
      if ( v12 < 0 )
      {
LABEL_43:
        if ( this[29] )
        {
          v21 = (_DWORD *)*this;
          this[3] = a5 + 1;
          sub_41AB40(v21);
          if ( dword_75CBB0 > 0 )
          {
            if ( dword_75CBB0 <= 6 )
            {
              if ( this[14] != 1 && (this[3] >= dword_7D74B8 || flt_7D74C0 <= (double)a3) )
              {
                sub_4DC390(this);
                if ( dword_75CBB0 == 5 && this[1] == *(_DWORD *)(dword_75AAD0[dword_75AAC8] + 25248) && sub_42DBA0() )
                  sub_4BA1A0(1, -1.0);
              }
            }
            else if ( dword_75CBB0 == 7 )
            {
              if ( dword_75CBB4 == 8 )
              {
                sub_4DC390(this);
                v22 = (_DWORD *)*this;
                *((float *)this + 38) = a3 - flt_7D74BC;
                sub_4BA0E0(&byte_766124, v22);
              }
              else if ( this[3] < dword_7D74B8 )
              {
                sub_4BA080(*this);
              }
              else
              {
                sub_4DC390(this);
                *((float *)this + 38) = a3 - flt_7D74BC;
                sub_42F950(&dword_75CBA8, 8);
                sub_4BA0E0(&byte_766124, (_DWORD *)*this);
              }
              v17 = 0;
              if ( (int)this[16] > 0 )
              {
                v18 = this + 18;
                do
                {
                  if ( !(unsigned __int8)sub_4DEB10(this) )
                  {
                    v19 = *v18;
                    if ( *v18 && (v19 != 1 || *(_BYTE *)(*this + 17412)) )
                    {
                      *v18 = v19 - 1;
                    }
                    else
                    {
                      if ( *(_DWORD *)(*this + 16584) <= 1u )
                        sub_4DCCC0(this, aIgnoredStopGoP);
                      *v18 = 0;
                    }
                  }
                  if ( this[14] )
                    sub_4DFED0(this);
                  ++v17;
                  v18 += 3;
                }
                while ( v17 < this[16] );
              }
            }
          }
          if ( !byte_7D74C8 )
            byte_7D74C8 = this[3] >= (dword_7D74B8 + 1) >> 1;
        }
        v20 = this[3];
        this[29] = 2;
        *((float *)this + 30) = a3;
        if ( v20 > 0 && v20 <= this[39] )
          *(float *)(this[40] + 4 * v20 - 4) = a3;
        sub_4DCE30(this);
        return;
      }
    }
    else
    {
      v12 = 999;
    }
    if ( v12 < this[39] )
    {
      *(_BYTE *)(v12 + this[42]) = *((_BYTE *)this + 48);
      if ( (unsigned __int8)sub_4FAE50(*this) )
        ++this[43];
      if ( a2 > 0.0 )
      {
        *(float *)(this[41] + 4 * v12) = a2;
        v13 = *((float *)this + 31);
        *((float *)this + 6) = a2;
        if ( v13 < 0.0 || a2 < (double)*((float *)this + 31) )
        {
          v14 = this[30];
          *((float *)this + 31) = a2;
          this[37] = v14;
        }
        if ( *((float *)this + 34) <= 0.0 || *((float *)this + 34) > (double)a2 )
        {
          v15 = this[7];
          v16 = this[8];
          this[34] = this[6];
          this[35] = v15;
          this[36] = v16;
        }
      }
    }
    goto LABEL_43;
  }
  this[4] = a4;
  if ( a2 > 0.0 )
  {
    if ( *(float *)&this[a4 + 31] < 0.0 || a2 < (double)*(float *)&this[a4 + 31] )
      *(float *)&this[a4 + 31] = a2;
    *(float *)&this[this[4] + 6] = a2;
  }
  if ( !this[29] && this[4] == 1 )
    this[29] = 1;
}
