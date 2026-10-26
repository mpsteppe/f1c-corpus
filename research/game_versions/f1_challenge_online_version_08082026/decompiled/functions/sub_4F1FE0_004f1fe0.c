void __thiscall sub_4F1FE0(_DWORD **this, float a2)
{
  int v3; // edx
  int v4; // eax
  _DWORD *v5; // edi
  _DWORD *v6; // ecx
  unsigned __int8 v8; // c0
  unsigned __int8 v9; // c3
  _DWORD *v10; // eax
  _DWORD *v11; // edx
  int v12; // ecx
  _DWORD **v13; // eax
  double v14; // st7
  float *v15; // ecx
  double v16; // st7
  double v17; // st7
  double v18; // st6
  _DWORD *v19; // edx
  _DWORD *v20; // ecx
  unsigned __int8 v22; // c0
  unsigned __int8 v23; // c3
  _DWORD *v24; // edx
  double v25; // st7
  int v26; // [esp-4h] [ebp-2Ch]
  float v27; // [esp+Ch] [ebp-1Ch]
  _DWORD v28[3]; // [esp+10h] [ebp-18h] BYREF
  float v29[3]; // [esp+1Ch] [ebp-Ch] BYREF
  float v30; // [esp+2Ch] [ebp+4h]

  v3 = (int)*this;
  v27 = *((float *)this + 4097);
  this[4097] = 0;
  v4 = *(_DWORD *)(v3 + 16484);
  if ( v4 )
  {
    if ( v4 != 2 && this[3247] == (_DWORD *)1 )
    {
      v19 = this + 3381;
      v20 = this + 4094;
      if ( v22 | v23 )
      {
        v25 = v27 + a2;
        *((float *)this + 4097) = v25;
        if ( v25 > 15.0 )
        {
          this[4097] = 0;
          this[3922] = 0;
          this[3923] = 0;
          this[3924] = 0;
          if ( dword_7C56A4 == 7 )
          {
            if ( *((_BYTE *)this + 4177) )
            {
              v26 = (int)this[1042];
              *((_BYTE *)this + 4177) = 0;
              sub_4E0ED0(this + 441, v26);
            }
          }
        }
      }
      else
      {
        *v20 = *v19;
        v24 = this[3383];
        this[4095] = this[3382];
        this[4096] = v24;
      }
    }
  }
  else
  {
    v5 = this + 3381;
    v6 = this + 4094;
    if ( !(v8 | v9) )
    {
      v10 = this[3382];
      *v6 = *v5;
      v11 = this[3383];
      this[4095] = v10;
      this[4096] = v11;
      return;
    }
    if ( this[3247] )
    {
      if ( *(float *)(v3 + 16752) < 3.4028235e38 )
        return;
    }
    else
    {
      if ( dword_7CE814 )
        return;
      v12 = 0;
      v13 = this + 522;
      do
      {
        if ( !*v13 )
          break;
        if ( !*((_BYTE *)v13 + 64) )
          break;
        ++v12;
        v13 += 74;
      }
      while ( v12 < 4 );
      if ( v12 == 4 && fabs(*((float *)this + 3685)) > 0.1 )
        return;
    }
    if ( sub_4D21D0() )
    {
      if ( (*this)[3348] != 3 && !sub_4EFFD0((float *)this) )
      {
        v14 = v27 + a2;
        *((float *)this + 4097) = v14;
        if ( v14 > flt_7D0A8C )
        {
          this[3922] = 0;
          this[3923] = 0;
          this[3924] = 0;
          v15 = sub_403640(dword_5EA2C0, (float *)this + 3381, 0);
          this[3751] = v15;
          v16 = (*((float *)this + 3383) - v15[2]) * v15[10]
              + (*((float *)this + 3382) - v15[1]) * v15[9]
              + (*(float *)v5 - *v15) * v15[8];
          if ( v16 >= 0.0 )
          {
            v30 = v16 - v15[12];
            v17 = v15[12];
            v18 = v15[23];
          }
          else
          {
            v30 = -v16 - v15[11];
            v17 = v15[11];
            v18 = v15[22];
          }
          sub_41B250((int)*this);
          if ( v30 < 7.0 || v18 <= v17 )
          {
            this[3928] = (_DWORD *)2;
            if ( dword_7C56A4 == 7 )
            {
              sub_4D1140(*this, v29, v28);
              sub_4EF7C0((int)this, v29, v28);
              sub_4A5C80((int)(this + 3248), 0);
            }
          }
          sub_4BC060((int)(*this + 4109), 1);
          if ( !this[3247] )
            dword_7CE258 = 1;
        }
      }
    }
  }
}
