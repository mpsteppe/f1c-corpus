int __thiscall sub_437130(float *this)
{
  int v2; // ebx
  int result; // eax
  char *v4; // eax
  int v5; // eax
  signed int v6; // edx
  int v7; // eax
  int v8; // eax
  float *v9; // eax
  int v10; // ebp
  bool v11; // sf
  double v12; // st7
  int v13; // [esp-4h] [ebp-24h]
  float v14; // [esp+8h] [ebp-18h]
  float v15; // [esp+Ch] [ebp-14h]
  float v16; // [esp+10h] [ebp-10h]
  float v17; // [esp+14h] [ebp-Ch] BYREF
  float v18; // [esp+18h] [ebp-8h]
  float v19; // [esp+1Ch] [ebp-4h]

  if ( !*(_BYTE *)this )
  {
    v2 = sub_4373F0();
    sub_41BD80(&unk_629328);
    return v2;
  }
  v4 = (char *)sub_459B80(*((_DWORD *)this + 3));
  sub_40C400((int ***)&dword_6291CC, v4);
  v5 = *((_DWORD *)this + 1);
  if ( !v5 )
  {
    sub_501F60(1, 1);
    *((_DWORD *)this + 1) = 1;
    this[6] = 0.0;
    sub_459D80(0);
    this[5] = 3.5;
    *((_DWORD *)this + 8) = 1;
    return 0;
  }
  if ( v5 == 1 )
  {
    if ( this[5] <= 0.0 )
    {
      if ( !sub_419160(byte_6292D0) )
      {
        *((_DWORD *)this + 1) = 2;
        this[5] = 2.0;
      }
      result = 0;
      this[6] = dbl_7DA9C8 + this[6];
    }
    else
    {
      result = 0;
      this[5] = this[5] - dbl_7DA9C8;
      this[6] = dbl_7DA9C8 + this[6];
    }
  }
  else
  {
    if ( v5 == 2 )
    {
      v13 = *((_DWORD *)this + 7);
      *((_DWORD *)this + 1) = 4;
      sub_459D80(v13);
      sub_501F60(0, 1);
      return 0;
    }
    if ( v5 == 5 )
    {
      if ( this[5] > 0.0 )
      {
        result = 0;
        this[5] = this[5] - dbl_7DA9C8;
        return result;
      }
      if ( (unsigned __int8)sub_437A30(this) )
        return 1;
    }
    else
    {
      v6 = *((_DWORD *)this + 8);
      if ( v6 < (int)NumOfElements )
      {
        v7 = 0;
        if ( (int)NumOfElements > 0 )
        {
          while ( *(_DWORD *)(dword_75AAD0[v7] + 20884) != v6 )
          {
            if ( ++v7 >= (int)NumOfElements )
              goto LABEL_31;
          }
          v8 = dword_75AAD0[v7] + 1892;
          if ( v8 )
          {
            v9 = (float *)(v8 + 84);
            v14 = *v9;
            v15 = v9[1];
            v16 = v9[2];
            sub_459BC0(&v17, 0);
            if ( sqrt((v16 - v19) * (v16 - v19) + (v15 - v18) * (v15 - v18) + (v14 - v17) * (v14 - v17)) < 3.75 )
            {
              sub_502100(&dword_7D7978);
              sub_502100(&dword_7D7978);
              v10 = *((_DWORD *)this + 8) + 2;
              v11 = *((_DWORD *)this + 8) + 1 < 0;
              *((_DWORD *)this + 8) = v10;
              if ( v11 != __OFSUB__(v10, 1) )
              {
                *((_DWORD *)this + 8) = 1;
              }
              else if ( v10 > (int)NumOfElements )
              {
                *((_DWORD *)this + 8) = NumOfElements;
              }
            }
            if ( *((_DWORD *)this + 8) == NumOfElements )
              this[6] = 100.0;
          }
        }
      }
LABEL_31:
      v12 = dbl_7DA9C8 + this[6];
      this[6] = v12;
      if ( v12 >= 102.0 )
        *((_DWORD *)this + 1) = 5;
    }
    return 0;
  }
  return result;
}
