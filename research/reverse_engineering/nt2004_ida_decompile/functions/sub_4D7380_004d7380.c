char __thiscall sub_4D7380(int *this, char a2)
{
  int v3; // eax
  int *v4; // ebp
  int v5; // eax
  float *v6; // edi
  bool v7; // zf
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  float **v12; // eax
  float **v13; // eax
  float *v14; // ecx
  float *v16; // [esp-10h] [ebp-18h]
  float *v17; // [esp-10h] [ebp-18h]

  v3 = sub_4D6280(this);
  if ( v3 != this[331] && !a2 || v3 <= 0 )
    return 0;
  v4 = this + 12;
  while ( 1 )
  {
    v5 = *v4;
    v6 = 0;
    v7 = *v4 == 0;
    this[14] = this[12];
    if ( !v7 )
    {
      v6 = *(float **)v5;
      v16 = *(float **)v5;
      *(_BYTE *)(v5 + 8) = 0;
      if ( !(unsigned __int8)sub_4DAD10(v16, 1) )
        v6 = 0;
    }
    if ( !v6 )
    {
      v8 = operator new(4u) ? sub_4DB0B0(0) : 0;
      sub_4DBA10(v8, 0);
      v6 = 0;
      sub_414470(this + 12);
      v9 = this[14];
      if ( v9 )
      {
        v6 = *(float **)v9;
        v17 = *(float **)v9;
        *(_BYTE *)(v9 + 8) = 0;
        if ( !(unsigned __int8)sub_4DAD10(v17, 1) )
          v6 = 0;
      }
    }
    v10 = sub_4D3AB0((_BYTE *)(this[330] + (this[333] << 7)), (int)(this + 221), v6);
    if ( v10 <= 0 )
      break;
    v11 = v10 + this[513];
    ++this[512];
    this[513] = v11;
    if ( v6 )
    {
      v12 = (float **)operator new(0x10u);
      if ( v12 )
      {
        *v12 = v6;
        v12[1] = 0;
        v12[2] = 0;
        *((_BYTE *)v12 + 12) = 0;
      }
      else
      {
        v12 = 0;
      }
      if ( this[233] )
      {
        *(_DWORD *)(this[234] + 4) = v12;
        v12[2] = (float *)this[234];
      }
      else
      {
        this[233] = (int)v12;
        this[235] = (int)v12;
      }
      this[234] = (int)v12;
      ++this[236];
    }
  }
  sub_4D33C0(v6);
  if ( v6 )
  {
    v13 = (float **)operator new(0xCu);
    if ( v13 )
    {
      *v13 = v6;
      v13[1] = 0;
      *((_BYTE *)v13 + 8) = 0;
    }
    else
    {
      v13 = 0;
    }
    v14 = (float *)this[12];
    if ( v14 )
    {
      v13[1] = v14;
    }
    else
    {
      this[13] = (int)v13;
      this[14] = (int)v13;
    }
    this[12] = (int)v13;
    ++this[15];
  }
  sub_4D6390(this);
  return 1;
}
