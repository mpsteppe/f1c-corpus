char __thiscall sub_4B1F80(char *this, float a2)
{
  double v2; // st7
  double v3; // st7
  double v4; // st7
  __int16 *v5; // esi
  float *v6; // edi
  __int16 v7; // bp
  char v8; // bl
  double v9; // st6
  double v10; // st6
  __int64 v11; // rax
  int v13; // [esp+0h] [ebp-4h]
  int i; // [esp+8h] [ebp+4h]

  if ( *this )
    v2 = a2 + *((float *)this + 1);
  else
    v2 = *((float *)this + 1) - a2;
  *((float *)this + 1) = v2;
  if ( *((float *)this + 1) >= 0.0 )
  {
    if ( *((float *)this + 1) > 2.0 )
      *((_DWORD *)this + 1) = 0x40000000;
  }
  else
  {
    *((_DWORD *)this + 1) = 0;
  }
  *((float *)this + 2) = *((float *)this + 2) - a2;
  if ( *((float *)this + 2) >= 0.0 )
  {
    if ( *((float *)this + 2) > 2.0 )
      *((_DWORD *)this + 2) = 0x40000000;
  }
  else
  {
    *((_DWORD *)this + 2) = 0;
  }
  if ( *((float *)this + 1) > 0.0 )
  {
    if ( *((float *)this + 1) >= 0.33399999 )
    {
      *((_DWORD *)this + 11) = 1065353216;
      *((_DWORD *)this + 10) = 1065353216;
    }
    else
    {
      v3 = *((float *)this + 1) * 2.9940121;
      *((float *)this + 11) = v3;
      *((float *)this + 10) = v3;
    }
    v4 = a2 * 7.5;
    v5 = (__int16 *)(this + 16);
    v6 = (float *)(this + 28);
    for ( i = 2; i; --i )
    {
      v7 = v5[2];
      if ( *v5 == v7 )
      {
        *v6 = 0.0;
      }
      else
      {
        if ( *v5 >= v7 )
        {
          v8 = 0;
          v9 = -v4;
        }
        else
        {
          v8 = 1;
          v9 = v4;
        }
        v10 = v9 + *v6;
        v13 = *v5;
        *v6 = v10;
        v11 = (__int64)((double)v13 + v10);
        *v5 = v11;
        if ( v8 )
        {
          if ( (__int16)v11 > v7 )
            goto LABEL_26;
        }
        else if ( (__int16)v11 < v7 )
        {
LABEL_26:
          *v5 = v7;
        }
      }
      ++v6;
      ++v5;
    }
  }
  return 1;
}
