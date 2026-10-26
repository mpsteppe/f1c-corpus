char __thiscall sub_4F8440(_DWORD **this)
{
  double v2; // st7
  double v3; // st6
  int v4; // eax
  int i; // ebp
  _DWORD *v6; // ecx
  _DWORD **v7; // edi
  int *v8; // eax
  double v9; // st7
  double v10; // st6
  float v12; // [esp+0h] [ebp-40h]
  _DWORD *v13; // [esp+4h] [ebp-3Ch]
  float v14; // [esp+1Ch] [ebp-24h]
  float v15; // [esp+20h] [ebp-20h]
  int *v16; // [esp+24h] [ebp-1Ch]
  int v17[2]; // [esp+28h] [ebp-18h] BYREF
  float v18; // [esp+30h] [ebp-10h]
  float v19[2]; // [esp+34h] [ebp-Ch] BYREF
  float v20; // [esp+3Ch] [ebp-4h]

  v2 = *((float *)this + 10) * *((float *)this + 7)
     + *((float *)this + 9) * *((float *)this + 6)
     + *((float *)this + 5) * *((float *)this + 8);
  v3 = *((float *)this + 13) * *((float *)this + 7)
     + *((float *)this + 12) * *((float *)this + 6)
     + *((float *)this + 11) * *((float *)this + 5);
  v18 = *((float *)this + 16) * *((float *)this + 7)
      + *((float *)this + 15) * *((float *)this + 6)
      + *((float *)this + 14) * *((float *)this + 5);
  *(float *)v17 = v2 + *((float *)this + 2);
  *(float *)&v17[1] = v3 + *((float *)this + 3);
  v18 = v18 + *((float *)this + 4);
  if ( *((float *)this + 39) != 0.0 )
    PerIndexStructFieldSetter(26, 1, *((float *)this + 39), *((float *)this + 40), (int)(this + 41));
  v4 = (*this)[4655] >> 1;
  if ( ((*this)[4655] & 2) != 0 )
  {
    if ( *((_BYTE *)this + 176) )
      v16 = (int *)(this + 405);
    else
      v16 = (int *)(this + 422);
    v14 = 0.0;
    v15 = (*((float *)this + 35) - *((float *)this + 33)) * *((float *)this + 34);
    if ( *((float *)this + 35) > 0.0 )
    {
      if ( v15 >= 0.0 )
      {
        if ( v15 > 1.0 )
          v15 = 1.0;
      }
      else
      {
        v15 = 0.0;
      }
      if ( sub_4C7BD0(*this) )
        v14 = (*((float *)this + 36) * *((float *)this + 36) * *(float *)&dword_5D67A8
             + *(float *)&dword_5D67AC * v15
             + *(float *)&dword_5D67A4)
            * flt_7CF2F0
            * flt_7CF338;
      else
        v14 = (*(float *)&dword_5D679C * *((float *)this + 36) + *(float *)&dword_5D67A0 * v15 + *(float *)&dword_5D6798)
            * flt_7CF35C
            * flt_7CF2F0;
      if ( v14 >= 0.0 )
      {
        if ( v14 > 1.0 )
          v14 = 1.0;
      }
      else
      {
        v14 = 0.0;
      }
    }
    ParametricInterpolationBlending(v16, *((float *)this + 35), (int)v17, (int)(this + 17), v14);
    for ( i = 5; i < 45; ++i )
    {
      v6 = *(_DWORD **)(v16[16] + 4 * i);
      v7 = &this[8 * i];
      LOBYTE(v4) = *((_BYTE *)v7 + 180);
      if ( (_BYTE)v4 )
      {
        if ( v6 )
        {
          if ( i == 44 )
          {
            *((float *)this + 399) = flt_7CF314 * v14 * *((float *)this + 399);
            if ( *((float *)this + 399) >= 0.0 )
            {
              if ( *((float *)this + 399) > 1.0 )
                this[399] = (_DWORD *)1065353216;
            }
            else
            {
              this[399] = 0;
            }
          }
          v13 = this[8 * i + 48];
          if ( *((_BYTE *)v7 + 196) )
          {
            v8 = (int *)v19;
            v9 = *((float *)this + 10) * *((float *)v7 + 52)
               + *((float *)this + 9) * *((float *)v7 + 51)
               + *((float *)this + 8) * *((float *)v7 + 50);
            v10 = *((float *)this + 11) * *((float *)v7 + 50)
                + *((float *)this + 13) * *((float *)v7 + 52)
                + *((float *)this + 12) * *((float *)v7 + 51);
            v20 = *((float *)this + 14) * *((float *)v7 + 50)
                + *((float *)this + 16) * *((float *)v7 + 52)
                + *((float *)this + 15) * *((float *)v7 + 51);
            v19[0] = v9 + *((float *)this + 2);
            v19[1] = v10 + *((float *)this + 3);
            v20 = v20 + *((float *)this + 4);
          }
          else
          {
            v8 = v17;
          }
          v12 = flt_7CF2CC * *((float *)v7 + 47);
          LOBYTE(v4) = (*(int (__stdcall **)(_DWORD *, int *, _DWORD **, _DWORD, _DWORD *, _DWORD))(*v6 + 4))(
                         v7[46],
                         v8,
                         this + 17,
                         LODWORD(v12),
                         v13,
                         0);
        }
        *((_BYTE *)v7 + 180) = 0;
      }
      else if ( v6 && v6[5] == 1 )
      {
        LOBYTE(v4) = (*(int (__thiscall **)(_DWORD *))(*v6 + 8))(v6);
      }
    }
  }
  return v4;
}
