int __thiscall sub_525D30(_DWORD **this)
{
  double v2; // st7
  double v3; // st6
  int result; // eax
  _BYTE *v5; // ebp
  int v6; // ebx
  float *v7; // edi
  _DWORD *v8; // ecx
  double v9; // st7
  double v10; // st6
  float v11; // [esp+0h] [ebp-40h]
  float v12; // [esp+0h] [ebp-40h]
  int v13; // [esp+4h] [ebp-3Ch]
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
    sub_5260E0(27, 1, *((float *)this + 39), (int)this[40], (int)(this + 41));
  result = (*this)[6324] >> 1;
  if ( ((*this)[6324] & 2) != 0 )
  {
    if ( *((_BYTE *)this + 176) )
      v16 = (int *)(this + 416);
    else
      v16 = (int *)(this + 433);
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
      if ( sub_4EED40(*this) )
        v14 = (*((float *)this + 36) * *((float *)this + 36) * *(float *)&dword_614D34
             + *(float *)&dword_614D38 * v15
             + *(float *)&dword_614D30)
            * flt_767850;
      else
        v14 = (*(float *)&dword_614D28 * *((float *)this + 36) + *(float *)&dword_614D2C * v15 + *(float *)&dword_614D24)
            * flt_767874
            * flt_767850;
      if ( v14 < 0.0 )
      {
        sub_5246E0(v16, *((float *)this + 35), (int)v17, (int)(this + 17), 0.0);
        goto LABEL_20;
      }
      if ( v14 > 1.0 )
        v14 = 1.0;
    }
    sub_5246E0(v16, *((float *)this + 35), (int)v17, (int)(this + 17), v14);
LABEL_20:
    v5 = (char *)this + 182;
    v6 = 20;
    v7 = (float *)(this + 102);
    do
    {
      if ( *v5 )
      {
        v8 = *(_DWORD **)(v6 + v16[16]);
        if ( *((_BYTE *)v7 - 24) )
        {
          if ( v8 )
          {
            if ( *((_BYTE *)v7 - 8) )
            {
              v13 = *((_DWORD *)v7 - 3);
              v9 = *((float *)this + 9) * *v7 + *((float *)this + 10) * v7[1] + *((float *)this + 8) * *(v7 - 1);
              v10 = *((float *)this + 12) * *v7 + *((float *)this + 13) * v7[1] + *((float *)this + 11) * *(v7 - 1);
              v20 = *((float *)this + 15) * *v7 + *((float *)this + 16) * v7[1] + *((float *)this + 14) * *(v7 - 1);
              v19[0] = v9 + *((float *)this + 2);
              v19[1] = v10 + *((float *)this + 3);
              v20 = v20 + *((float *)this + 4);
              v11 = *(float *)&dword_76782C * *(v7 - 4);
              (*(void (__thiscall **)(_DWORD *, _DWORD, float *, _DWORD **, _DWORD, int, _DWORD))(*v8 + 4))(
                v8,
                *((_DWORD *)v7 - 5),
                v19,
                this + 17,
                LODWORD(v11),
                v13,
                0);
            }
            else
            {
              v12 = *(float *)&dword_76782C * *(v7 - 4);
              (*(void (__thiscall **)(_DWORD *, _DWORD, int *, _DWORD **, _DWORD, _DWORD, _DWORD))(*v8 + 4))(
                v8,
                *((_DWORD *)v7 - 5),
                v17,
                this + 17,
                LODWORD(v12),
                *((_DWORD *)v7 - 3),
                0);
            }
          }
          *((_BYTE *)v7 - 24) = 0;
          *v5 = 1;
        }
        else
        {
          if ( v8 && v8[5] == 1 )
            (*(void (__thiscall **)(_DWORD *))(*v8 + 8))(v8);
          *v5 = 0;
        }
      }
      result = -177 - (_DWORD)this;
      v6 += 4;
      v7 += 8;
      ++v5;
    }
    while ( (int)&v5[-177 - (_DWORD)this] < 45 );
  }
  return result;
}
