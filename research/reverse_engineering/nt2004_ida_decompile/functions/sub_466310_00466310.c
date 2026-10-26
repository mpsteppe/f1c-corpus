char __thiscall sub_466310(_DWORD **this)
{
  int v2; // edx
  int v3; // eax
  signed int i; // esi
  LPVOID *v5; // esi
  int v6; // ecx
  int *v7; // eax
  bool v8; // zf
  int v9; // ecx
  int v10; // edx
  char *v11; // eax
  int v12; // ecx
  _DWORD *v13; // eax
  LPVOID *v14; // ebp
  _DWORD *v15; // esi
  _DWORD *v16; // ecx
  int v17; // edi
  int v18; // edx
  LPVOID *v19; // edi
  char v21; // [esp+7h] [ebp-5h]
  float v22; // [esp+8h] [ebp-4h]

  v2 = (int)*this;
  v3 = (*this)[1680];
  if ( !v3 )
    return v3;
  v22 = dbl_7DA9C0;
  if ( v3 != 2 && v3 != 1 )
  {
    v21 = 0;
LABEL_6:
    *(float *)(v2 + 656) = v22 + *(float *)(v2 + 656);
    goto LABEL_7;
  }
  v21 = 1;
  if ( sub_463BC0(this) > 1 )
    goto LABEL_6;
LABEL_7:
  if ( sub_56A630((*this)[1677]) )
  {
    sub_462430(*this, 0);
    sub_4612C0((int)*this);
    sub_461A10((int)*this);
    sub_45DD60(*this + 6929, v22);
    sub_462A30((int)*this);
    if ( *((_BYTE *)*this + 32) )
    {
      sub_461B10(*this);
      *((_BYTE *)*this + 32) = 0;
      if ( v21 )
      {
        if ( !*((_BYTE *)*this + 33) )
          sub_4625E0((int)*this);
      }
    }
  }
  else
  {
    for ( i = 0; i < (int)NumOfElements; ++i )
    {
      if ( *(_DWORD *)(dword_75AAD0[i] + 16584) == 2 )
      {
        sub_4EEC50(0);
        sub_4EEC20(0);
      }
    }
    if ( sub_41F230(dword_62A170, aConnectionLost, Destination) )
    {
      strncpy(Destination, aConnectionLost, 0x1FFu);
      byte_62A37B = 0;
    }
    sub_45D100(&byte_764D68, (int)Destination, 1, 16909060, 0);
    sub_40C450((_DWORD **)&dword_6291CC, 2);
    *((float *)*this + 161) = *((float *)*this + 161) - v22;
    if ( *((float *)*this + 161) < 0.0 || v22 <= 0.0 )
    {
      sub_4BA5F0(1);
      sub_4BA670(&unk_76612C);
      sub_4B9790(1);
    }
  }
  v5 = 0;
  *((float *)*this + 163) = v22 + *((float *)*this + 163);
  v6 = (*this)[7530];
  v7 = *this + 7530;
  if ( v6 )
  {
    v5 = *(LPVOID **)v6;
    v8 = *(_DWORD *)v6 == 0;
    *(_BYTE *)(v6 + 8) = 0;
    if ( v8 || (v9 = *v7, v10 = 0, !*v7) )
    {
LABEL_26:
      v5 = 0;
    }
    else
    {
      while ( *(LPVOID **)v9 != v5 )
      {
        v10 = v9;
        v9 = *(_DWORD *)(v9 + 4);
        if ( !v9 )
          goto LABEL_26;
      }
      if ( v9 == v7[2] )
        v7[2] = *(_DWORD *)(v9 + 4);
      v17 = *(_DWORD *)(v9 + 4);
      if ( v10 )
        *(_DWORD *)(v10 + 4) = v17;
      else
        *v7 = v17;
      if ( v7[1] == v9 )
        v7[1] = v10;
      --v7[3];
      sub_414480((LPVOID **)v9, 1);
    }
  }
  if ( v5 )
  {
    do
    {
      v11 = (char *)*v5;
      if ( !*v5 )
        v11 = &byte_629120;
      sub_4BA6B0(v11);
      if ( *v5 )
        sub_5BE8AE(*v5);
      sub_5BE8AE(v5);
      v12 = (*this)[7530];
      v13 = *this + 7530;
      v14 = 0;
      if ( v12 )
      {
        v14 = *(LPVOID **)v12;
        v8 = *(_DWORD *)v12 == 0;
        *(_BYTE *)(v12 + 8) = 0;
        if ( v8 || (v15 = (_DWORD *)*v13, v16 = 0, !*v13) )
        {
LABEL_59:
          v14 = 0;
        }
        else
        {
          while ( (LPVOID *)*v15 != v14 )
          {
            v16 = v15;
            v15 = (_DWORD *)v15[1];
            if ( !v15 )
              goto LABEL_59;
          }
          if ( v15 == (_DWORD *)v13[2] )
            v13[2] = v15[1];
          v18 = v15[1];
          if ( v16 )
            v16[1] = v18;
          else
            *v13 = v18;
          if ( (_DWORD *)v13[1] == v15 )
            v13[1] = v16;
          --v13[3];
          if ( *((_BYTE *)v15 + 8) )
          {
            v19 = (LPVOID *)*v15;
            if ( *v15 )
            {
              if ( *v19 )
                sub_5BE8AE(*v19);
              sub_5BE8AE(v19);
            }
          }
          sub_5BE8AE(v15);
        }
      }
      v5 = v14;
    }
    while ( v14 );
  }
  if ( v21 )
    sub_45E900((_BYTE *)*this + 30136);
  sub_4605C0((int)*this);
  LOBYTE(v3) = sub_460630((int)*this);
  return v3;
}
