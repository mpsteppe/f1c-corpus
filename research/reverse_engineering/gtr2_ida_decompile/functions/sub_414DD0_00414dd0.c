char __thiscall sub_414DD0(int this)
{
  int v2; // edi
  char *v3; // ebx
  int v4; // edi
  int v5; // ecx
  int v6; // eax
  int v7; // ebp
  int v8; // ebx
  char result; // al
  char v10; // al
  int v11; // eax
  int v12; // edi
  int v13; // ecx
  int v14; // eax
  float *v15; // eax
  int v16; // edx
  long double v17; // st7
  int v18; // eax
  int v19; // ecx
  double v20; // st7
  float v21; // [esp+Ch] [ebp-70h]
  int v22; // [esp+1Ch] [ebp-60h]
  float v23; // [esp+20h] [ebp-5Ch] BYREF
  float v24; // [esp+24h] [ebp-58h] BYREF
  float v25; // [esp+28h] [ebp-54h] BYREF
  float v26; // [esp+2Ch] [ebp-50h] BYREF
  float v27; // [esp+30h] [ebp-4Ch] BYREF
  float v28; // [esp+34h] [ebp-48h] BYREF
  float v29; // [esp+38h] [ebp-44h] BYREF
  float v30; // [esp+3Ch] [ebp-40h]
  float v31; // [esp+40h] [ebp-3Ch]
  float v32; // [esp+44h] [ebp-38h] BYREF
  _BYTE v33[4]; // [esp+48h] [ebp-34h] BYREF
  _BYTE v34[4]; // [esp+4Ch] [ebp-30h] BYREF
  _BYTE v35[44]; // [esp+50h] [ebp-2Ch] BYREF

  v2 = 0;
  if ( !(unsigned __int8)sub_4735A0(off_16C9A98)
    && dword_91E07C
    && ((*((_DWORD *)dword_91E07C + 5645) & 2) == 0 || *((_DWORD *)dword_91E07C + 3705) == -1) )
  {
    v3 = dword_91E07C;
    do
    {
      v4 = sub_4108F0(*(_DWORD *)(*(&dword_91E088 + dword_91E078) + 22468), 1);
      sub_42C8A0(v4);
      sub_412180();
      v25 = *(float *)&v4;
      sub_414110();
      v5 = *(_DWORD *)(this + 8);
      if ( v5 )
        (*(void (__thiscall **)(int, float))(*(_DWORD *)v5 + 16))(v5, COERCE_FLOAT(LODWORD(v25)));
      if ( dword_FB1D04 )
        sub_5E5AE0();
      sub_562430(&dword_FAE988, 1, 0);
    }
    while ( (*((_DWORD *)dword_91E07C + 5645) & 2) == 0 && v3 != dword_91E07C );
    v2 = 0;
  }
  sub_412180();
  v6 = *(_DWORD *)(this + 8);
  v7 = 0;
  if ( v6 )
    v8 = *(_DWORD *)(v6 + 4);
  else
    v8 = 0;
  if ( !*(_DWORD *)(*(_DWORD *)(this + 32) + 8) )
  {
    v22 = 0;
    sub_4122A0();
  }
  sub_5E4D90(v8, v33, v34, v35, v22);
  v27 = -v30;
  v30 = v27;
  v28 = -v31;
  v31 = v28;
  v29 = -v32;
  v32 = v29;
  sub_562DD0(0);
  result = *(_BYTE *)(this + 49);
  if ( result )
  {
    *(_BYTE *)(this + 49) = 0;
  }
  else
  {
    v10 = *(_BYTE *)(this + 58);
    *(_DWORD *)(this + 52) = 0;
    if ( v10 )
      v11 = sub_413EC0(this);
    else
      v11 = sub_4145A0(this);
    v7 = v11;
    sub_414090((_DWORD *)this);
    if ( v7 == 1 )
    {
      *(_DWORD *)(this + 80) = 0;
      *(_DWORD *)(this + 84) = 0;
      *(_DWORD *)(this + 88) = 0;
      *(_DWORD *)(this + 92) = 0;
      if ( dword_757C10 > 0 )
      {
        do
          sub_57DF00(*(&dword_91E088 + v2++) + 16);
        while ( v2 < dword_757C10 );
      }
      (*(void (__thiscall **)(_DWORD))(**(_DWORD **)(this + 8) + 16))(*(_DWORD *)(this + 8));
    }
    result = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 8) + 12))(*(_DWORD *)(this + 8));
  }
  v12 = dword_BE1D0C;
  if ( dword_BE1D0C )
  {
    sub_5E5510(&v27, &v28, &v29, v33, v34, v35);
    v24 = -v27;
    v27 = v24;
    v25 = -v28;
    v28 = v25;
    v26 = -v29;
    v29 = v26;
    if ( v7 )
    {
      result = (*(int (__thiscall **)(int, float *, _BYTE *))(*(_DWORD *)v12 + 28))(v12, &v27, v33);
      if ( dword_BE2744 )
        return sub_548E60(&v28, &v25);
    }
    else
    {
      v13 = *(_DWORD *)(this + 8);
      if ( v13 == *(_DWORD *)(this + 32) )
      {
        v24 = *((float *)dword_91E07C + 23);
        v25 = *((float *)dword_91E07C + 24);
        v26 = *((float *)dword_91E07C + 25);
      }
      else
      {
        v14 = (*(int (__thiscall **)(int))(*(_DWORD *)v13 + 24))(v13);
        if ( v14 )
        {
          v15 = (float *)(v14 + 36);
          v24 = *v15;
          v25 = v15[1];
          v16 = *(_DWORD *)v12;
          v26 = v15[2];
          (*(void (__thiscall **)(int, float *, _BYTE *, float *))(v16 + 32))(v12, &v27, v33, &v24);
        }
      }
      v23 = 0.0;
      if ( !byte_B6413C )
      {
        v17 = sqrt(v26 * v26 + v25 * v25 + v24 * v24) / (flt_B71AB0 * 0.44704) * flt_B71AD4;
        v23 = v17;
        if ( v17 >= flt_B71ADC )
        {
          if ( v23 > (double)flt_B71AD4 )
            v23 = flt_B71AD4;
        }
        else
        {
          v23 = flt_B71ADC;
        }
      }
      v18 = *(_DWORD *)(this + 52);
      if ( v18
        || (v19 = *(_DWORD *)(this + 8)) != 0 && (v18 = (*(int (__thiscall **)(int))(*(_DWORD *)v19 + 24))(v19)) != 0 )
      {
        v20 = *(float *)(v18 + 92);
      }
      else
      {
        v20 = 0.0;
      }
      v21 = v20 + v23;
      sub_5D8D80(dword_FB1CE0, LODWORD(v21));
      return (*(int (__thiscall **)(int, float *, float *, float *))(*(_DWORD *)v12 + 32))(v12, &v26, &v32, &v23);
    }
  }
  return result;
}
