void __thiscall sub_57F4F0(int this, float a2)
{
  float v3; // eax
  float v4; // ecx
  int v5; // eax
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  _BYTE *v9; // ecx
  double v10; // st7
  float *v11; // edi
  int v12; // edx
  double v13; // st7
  float v14; // [esp+8h] [ebp-1Ch]
  float v15; // [esp+18h] [ebp-Ch]
  float v16; // [esp+18h] [ebp-Ch]
  float v17; // [esp+1Ch] [ebp-8h]
  float v18; // [esp+1Ch] [ebp-8h]
  float v19; // [esp+20h] [ebp-4h]
  float v20; // [esp+20h] [ebp-4h]

  v3 = *(float *)(this + 19204);
  v4 = *(float *)this;
  v14 = v3;
  *(_DWORD *)(this + 19204) = 0;
  v5 = *(_DWORD *)(LODWORD(v4) + 19380);
  if ( v5 || *(_DWORD *)(LODWORD(v4) + 15576) == 3 )
  {
    if ( v5 != 2 && *(_DWORD *)(this + 14804) == 1 )
    {
      v16 = *(float *)(this + 15972) - *(float *)(this + 19192);
      v18 = *(float *)(this + 15976) - *(float *)(this + 19196);
      v20 = *(float *)(this + 15980) - *(float *)(this + 19200);
      if ( v20 * v20 + v18 * v18 + v16 * v16 <= 1.0 )
      {
        v13 = v14 + a2;
        *(float *)(this + 19204) = v13;
        if ( v13 > 15.0 )
        {
          *(_DWORD *)(this + 19204) = 0;
          *(_DWORD *)(this + 18388) = 0;
          *(_DWORD *)(this + 18392) = 0;
          *(_DWORD *)(this + 18396) = 0;
        }
      }
      else
      {
        *(_DWORD *)(this + 19192) = *(_DWORD *)(this + 15972);
        v12 = *(_DWORD *)(this + 15980);
        *(_DWORD *)(this + 19196) = *(_DWORD *)(this + 15976);
        *(_DWORD *)(this + 19200) = v12;
      }
    }
  }
  else
  {
    v15 = *(float *)(this + 15972) - *(float *)(this + 19192);
    v17 = *(float *)(this + 15976) - *(float *)(this + 19196);
    v19 = *(float *)(this + 15980) - *(float *)(this + 19200);
    if ( v19 * v19 + v17 * v17 + v15 * v15 > 1.0 )
    {
      v6 = *(_DWORD *)(this + 15976);
      *(_DWORD *)(this + 19192) = *(_DWORD *)(this + 15972);
      v7 = *(_DWORD *)(this + 15980);
      *(_DWORD *)(this + 19196) = v6;
      *(_DWORD *)(this + 19200) = v7;
      return;
    }
    if ( *(_DWORD *)(this + 14804) )
    {
      if ( sub_573C40((float *)LODWORD(v4)) )
        return;
      goto LABEL_15;
    }
    if ( !dword_B6FA78 )
    {
      v8 = 0;
      v9 = (_BYTE *)(this + 3216);
      do
      {
        if ( !*v9 )
          break;
        ++v8;
        v9 += 296;
      }
      while ( v8 < 4 );
      if ( v8 != 4 || fabs(*(float *)(this + 17212)) <= 0.1 )
      {
LABEL_15:
        if ( sub_551A90() && !sub_577A80((float *)this) )
        {
          v10 = v14 + a2;
          *(float *)(this + 19204) = v10;
          if ( v10 > flt_B72CAC )
          {
            *(_DWORD *)(this + 18388) = 0;
            *(_DWORD *)(this + 18392) = 0;
            *(_DWORD *)(this + 18396) = 0;
            v11 = sub_402D40(&flt_91BCA0, (float *)(this + 15972), 0);
            off_16C9360(this + 15972, v11 + 1, LODWORD(a2));
          }
        }
      }
    }
  }
}
