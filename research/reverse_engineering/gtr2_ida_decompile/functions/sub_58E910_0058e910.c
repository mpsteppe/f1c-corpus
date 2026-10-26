char __thiscall sub_58E910(float *this)
{
  float v2; // eax
  double v3; // st7
  double v4; // st7
  float v5; // ecx
  int i; // ebx
  _DWORD *v7; // ebp
  int *v8; // edi
  float v10; // [esp+14h] [ebp-3Ch]
  float v11; // [esp+14h] [ebp-3Ch]
  float v12; // [esp+30h] [ebp-20h]
  float v13; // [esp+34h] [ebp-1Ch]
  int v14[3]; // [esp+38h] [ebp-18h] BYREF
  float v15[3]; // [esp+44h] [ebp-Ch] BYREF

  sub_416420(this + 8, this + 2, this + 5, (float *)v14);
  if ( this[42] != 0.0 )
  {
    *((_BYTE *)this + 293) = 1;
    sub_58C630(this, 40);
    *((_BYTE *)this + 1608) = 1;
    this[403] = this[44];
    this[404] = this[45];
    this[405] = this[46];
  }
  v2 = *this;
  if ( (*(_DWORD *)(*(_DWORD *)this + 22580) & 2) != 0 )
  {
    if ( *((_BYTE *)this + 252) )
      LODWORD(v13) = this + 550;
    else
      LODWORD(v13) = this + 610;
    v12 = 0.0;
    v3 = (this[39] - this[33]) * this[34];
    if ( this[39] > 0.0 )
    {
      if ( v3 >= 0.0 )
      {
        if ( v3 > 1.0 )
          v3 = 1.0;
      }
      else
      {
        v3 = 0.0;
      }
      v4 = (this[40] * this[36] + v3 * this[37] + this[35]) * this[62] * flt_B7096C;
      v12 = v4;
      if ( v4 >= 0.0 )
      {
        if ( v12 > 1.0 )
          v12 = 1.0;
      }
      else
      {
        v12 = 0.0;
      }
    }
    LODWORD(v5) = this + 610;
    if ( !byte_B70930 )
      v5 = v13;
    sub_58BCF0((void *)LODWORD(v5), *((_DWORD *)this + 38), this[39], this[40], (int)v14, (int)(this + 17), v12);
    if ( this[51] != 0.0 )
      sub_58E5B0(v13);
    for ( i = 10; i < 59; ++i )
    {
      LOBYTE(v2) = *((_BYTE *)this + i + 253);
      if ( LOBYTE(v2) )
      {
        v7 = *(_DWORD **)(*(_DWORD *)(LODWORD(v13) + 236) + 4 * i);
        v8 = (int *)&this[8 * i];
        LOBYTE(v2) = *((_BYTE *)v8 + 312);
        if ( LOBYTE(v2) )
        {
          if ( v7 )
          {
            if ( i == 58 )
            {
              this[544] = flt_B70990 * v12 * this[544];
              if ( this[544] >= 0.0 )
              {
                if ( this[544] > 1.0 )
                  this[544] = 1.0;
              }
              else
              {
                this[544] = 0.0;
              }
            }
            if ( *((_BYTE *)v8 + 328) )
            {
              sub_416420(this + 8, this + 2, (float *)v8 + 83, v15);
              v10 = *(float *)&dword_B70948 * this[8 * i + 80];
              LOBYTE(v2) = (*(int (__thiscall **)(_DWORD *, int, float *, int *, _DWORD, int, _DWORD))(*v7 + 4))(
                             v7,
                             v8[79],
                             v15,
                             (int *)this + 17,
                             LODWORD(v10),
                             v8[81],
                             0);
            }
            else
            {
              v11 = *(float *)&dword_B70948 * this[8 * i + 80];
              LOBYTE(v2) = (*(int (__thiscall **)(_DWORD *, int, int *, int *, _DWORD, int, _DWORD))(*v7 + 4))(
                             v7,
                             v8[79],
                             v14,
                             (int *)this + 17,
                             LODWORD(v11),
                             v8[81],
                             0);
            }
          }
          *((_BYTE *)v8 + 312) = 0;
          *((_BYTE *)this + i + 253) = 1;
        }
        else
        {
          if ( v7 && v7[5] == 1 )
            LOBYTE(v2) = (*(int (__thiscall **)(_DWORD *))(*v7 + 8))(v7);
          *((_BYTE *)this + i + 253) = 0;
        }
      }
    }
  }
  return LOBYTE(v2);
}
