void __thiscall sub_4FCEE0(int this)
{
  double v2; // st7
  _DWORD *v3; // esi
  int v4; // eax
  int v5; // ecx
  int v6; // edx
  _DWORD *v7; // esi
  double v8; // st7
  int *v9; // eax
  int v10; // edi
  int v11; // esi
  int v12; // eax
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v17; // st7
  unsigned __int8 v18; // c0
  unsigned __int8 v19; // c2
  int v20; // ecx
  float v21; // edi
  int v22; // eax
  int i; // edi
  int v24; // eax
  double v25; // st7
  double v26; // st7
  double v27; // st7
  double v28; // st6
  double v29; // st7
  __int16 v30; // ax
  double v31; // st7
  int v32; // ecx
  int v33; // edx
  int v34; // eax
  int v35; // edx
  int v36; // eax
  float v37; // [esp+0h] [ebp-40h]
  float v38; // [esp+4h] [ebp-3Ch]
  __int16 v39; // [esp+4h] [ebp-3Ch]
  float v40; // [esp+8h] [ebp-38h]
  __int16 v41; // [esp+8h] [ebp-38h]
  float v42; // [esp+1Ch] [ebp-24h]
  float v43; // [esp+1Ch] [ebp-24h]
  float v44; // [esp+20h] [ebp-20h] BYREF
  float v45; // [esp+24h] [ebp-1Ch] BYREF
  float v46; // [esp+28h] [ebp-18h]
  float v47; // [esp+2Ch] [ebp-14h]
  float v48; // [esp+30h] [ebp-10h] BYREF
  _DWORD v49[3]; // [esp+34h] [ebp-Ch] BYREF

  v2 = *(float *)(this + 4) - dbl_8AFE98;
  *(float *)(this + 4) = v2;
  if ( (dword_7C56A0 & 1) != 0 && dword_8AB6E4 != 2 )
  {
    if ( v2 < 0.0 )
    {
      if ( *(_BYTE *)(this + 64) )
      {
        *(_BYTE *)(this + 64) = 0;
        StringCopyWithRingBuffer((const char *)(this + 264));
        *(_DWORD *)(this + 68) = -8388609;
      }
      v38 = dbl_8AFEA0 * *(float *)this;
      v37 = (1.0 - *(float *)(this + 4)) * *(float *)this;
      AudioADSREnvelope(v37, v38, dword_5C329C);
      *(_DWORD *)(this + 4) = 1065353216;
      sub_4FC870((float *)(this + 32), v49);
      v45 = dbl_8AFEA0;
      if ( fabs(dbl_8AFEA0 - *(float *)(this + 68)) > 2.5 || memcmp((const void *)(this + 72), v49, 0xCu) )
      {
        v3 = (_DWORD *)dword_8AAE64;
        if ( dword_83EE60 < 1023 )
        {
          ++dword_83EE60;
          dword_8AAE64 += 432;
        }
        ProgressBarEventEncode(v3, 2, 4, 12, 255, SLODWORD(v45), 0);
        v4 = v49[0];
        v5 = v49[1];
        v6 = v49[2];
        v7 = v3 + 2;
        *v7 = v49[0];
        v7[1] = v5;
        v7[2] = v6;
        v8 = dbl_8AFEA0;
        *(_DWORD *)(this + 72) = v4;
        *(_DWORD *)(this + 76) = v5;
        *(float *)(this + 68) = v8;
        *(_DWORD *)(this + 80) = v6;
      }
    }
    v9 = *(int **)(this + 92);
    if ( v9 )
    {
      v10 = *v9;
      if ( *v9 )
      {
        v45 = dbl_8AFEA0;
        if ( dbl_8AFEA0 > *(float *)v10 )
        {
          v11 = dword_8AAE64;
          if ( dword_83EE60 < 1023 )
          {
            ++dword_83EE60;
            dword_8AAE64 += 432;
          }
          if ( *(_DWORD *)(v10 + 4) == 1 )
            ProgressBarEventEncode((_DWORD *)v11, 2, 6, 1, 255, SLODWORD(v45), 0);
          else
            ProgressBarEventEncode((_DWORD *)v11, 3, 6, 1, 255, SLODWORD(v45), 0);
          *(_BYTE *)(v11 + 8) = CRTFtol(*(float *)(v10 + 8) * 255.0);
          v12 = *(_DWORD *)(this + 92);
          if ( v12 )
            *(_DWORD *)(this + 92) = *(_DWORD *)(v12 + 4);
        }
      }
    }
  }
  if ( *(float *)(this + 4) > 0.0 )
  {
    v13 = dbl_8AFE98 / (dbl_8AFE98 + *(float *)(this + 4));
    *(float *)(this + 8) = (1.0 - v13) * *(float *)(this + 8) + v13 * *(float *)(this + 32);
  }
  else
  {
    *(_DWORD *)(this + 8) = *(_DWORD *)(this + 32);
  }
  if ( *(float *)(this + 8) >= 1.0 )
    v14 = 1.0 - *(float *)(this + 252) - (*(float *)(this + 256) - *(float *)(this + 252)) * *(float *)(this + 36);
  else
    v14 = 1.0 - *(float *)(this + 252) * *(float *)(this + 8);
  v42 = v14;
  if ( flt_7CFEC4 < 1.0 )
  {
    v48 = dbl_8AFEA0;
    v15 = dbl_8AFEA0 * *(float *)this + flt_8ACFB0;
    InterruptDispatch(v15);
    v44 = v15;
    if ( v15 >= 14400.0 )
    {
      v17 = v44;
      if ( v18 | v19 )
      {
        v45 = (v17 - 14400.0) * 0.00013888889;
      }
      else if ( v17 >= 64800.0 )
      {
        if ( v44 >= 72000.0 )
          v45 = flt_7CFEC4;
        else
          v45 = (72000.0 - v44) * 0.00013888889;
      }
      else
      {
        v45 = 1.0;
      }
    }
    else
    {
      v45 = flt_7CFEC4;
    }
    v42 = v45 * v42;
    RenderColorUpdate((_DWORD *)(this + 264), v45);
    v20 = 0;
    if ( v44 < 19800.0 || v44 > 66600.0 )
      v20 = 1;
    if ( *(_DWORD *)(this + 16) != v20 )
    {
      *(_DWORD *)(this + 16) = v20;
      CameraPositionGetter(&v48, &v45, &v44);
      v21 = 0.0;
      if ( SLODWORD(v45) > 0 )
      {
        do
        {
          v22 = LinkedListNthElement(LODWORD(v21));
          if ( !sub_588640(v22 + 88, aNightlight, 10) )
            BitFlagSetterWithDXUpdate(*(_DWORD *)(this + 16));
          ++LODWORD(v21);
        }
        while ( SLODWORD(v21) < SLODWORD(v45) );
      }
      for ( i = 0; i < SLODWORD(v44); ++i )
      {
        v24 = LinkedIndexedAccess(i);
        if ( !sub_588640(v24 + 88, aNightlight, 10) )
          BitFlagSetterWithDXUpdate(*(_DWORD *)(this + 16));
      }
    }
  }
  if ( *(float *)(this + 28) != 0.0 )
  {
    if ( dword_7CF8A8 > 1 )
      v42 = (1.0 - v42) * *(float *)(this + 28) + v42;
    *(_DWORD *)(this + 28) = 0;
  }
  if ( fabs(*(float *)(this + 12) - v42) > 0.017999999 )
  {
    LinkedListTraversal(0);
    if ( v42 >= 0.0 )
    {
      if ( v42 > 1.0 )
        v42 = 1.0;
    }
    else
    {
      v42 = 0.0;
    }
    *(float *)(this + 12) = v42;
    UIPropertyValueSetter(2, LODWORD(v42));
  }
  v25 = (*(float *)(this + 44) - *(float *)(this + 40)) * 4.0;
  v44 = v25;
  if ( v25 >= 0.0 )
  {
    if ( v44 > 1.0 )
      v44 = 1.0;
  }
  else
  {
    v44 = 0.0;
  }
  if ( fabs(*(float *)(this + 164) - v44) > 0.003 )
  {
    v40 = v44;
    *(float *)(this + 164) = v44;
    StridedArraySearchAndCall(&dword_8ACEA0, 10, v40);
  }
  v26 = (*(float *)(this + 44) + *(float *)(this + 40)) * 0.5 * 0.44999999
      + *(float *)(this + 36) * 0.47499999
      + *(float *)(this + 8) * 0.075000003;
  if ( v26 >= 0.0 )
  {
    if ( v26 > 1.0 )
      v26 = 1.0;
  }
  else
  {
    v26 = 0.0;
  }
  if ( v26 >= *(float *)(this + 168) )
  {
    v29 = (v26 - *(float *)(this + 168)) * *(float *)(this + 176);
    v44 = (*(float *)(this + 240) - *(float *)(this + 228)) * v29 + *(float *)(this + 228);
    v45 = (*(float *)(this + 244) - *(float *)(this + 232)) * v29 + *(float *)(this + 232);
    v43 = (*(float *)(this + 248) - *(float *)(this + 236)) * v29 + *(float *)(this + 236);
    v48 = (*(float *)(this + 204) - *(float *)(this + 192)) * v29 + *(float *)(this + 192);
    v47 = (*(float *)(this + 208) - *(float *)(this + 196)) * v29 + *(float *)(this + 196);
    v28 = (*(float *)(this + 212) - *(float *)(this + 200)) * v29 + *(float *)(this + 200);
  }
  else
  {
    v27 = v26 * *(float *)(this + 172);
    v44 = (*(float *)(this + 228) - *(float *)(this + 216)) * v27 + *(float *)(this + 216);
    v45 = (*(float *)(this + 232) - *(float *)(this + 220)) * v27 + *(float *)(this + 220);
    v43 = (*(float *)(this + 236) - *(float *)(this + 224)) * v27 + *(float *)(this + 224);
    v48 = (*(float *)(this + 192) - *(float *)(this + 180)) * v27 + *(float *)(this + 180);
    v47 = (*(float *)(this + 196) - *(float *)(this + 184)) * v27 + *(float *)(this + 184);
    v28 = (*(float *)(this + 200) - *(float *)(this + 188)) * v27 + *(float *)(this + 188);
  }
  v46 = v28;
  AudioPanUpdate(v44, v45);
  BoundedFloatSetterWithFlag(v43);
  v41 = CRTFtol(v46 * 255.0);
  v39 = CRTFtol(v47 * 255.0);
  v30 = CRTFtol(v48 * 255.0);
  UIElementPositionSetter(v30, v39, v41);
  if ( *(float *)(this + 44) > 0.0 )
    *(_DWORD *)(this + 20) = 1;
  if ( fabs(*(float *)(this + 40) - *(float *)(this + 24)) > 0.0099999998 )
  {
    v31 = *(float *)(this + 40);
    v32 = dword_8ACEA8;
    *(float *)(this + 24) = *(float *)(this + 40);
    if ( v31 <= 0.029999999 )
    {
      if ( v32 > 0 )
      {
        v35 = 0;
        do
        {
          v36 = v35 + dword_8ACEAC;
          if ( *(_DWORD *)(v35 + dword_8ACEAC + 48) == 7 )
            *(_DWORD *)(v36 + 48) = 6;
          if ( *(_DWORD *)(v36 + 52) == 22 )
            *(_DWORD *)(v36 + 52) = 21;
          v35 += 108;
          --v32;
        }
        while ( v32 );
      }
    }
    else if ( v32 > 0 )
    {
      v33 = 0;
      do
      {
        v34 = v33 + dword_8ACEAC;
        if ( *(_DWORD *)(v33 + dword_8ACEAC + 48) == 6 )
          *(_DWORD *)(v34 + 48) = 7;
        if ( *(_DWORD *)(v34 + 52) == 21 )
          *(_DWORD *)(v34 + 52) = 22;
        v33 += 108;
        --v32;
      }
      while ( v32 );
    }
  }
}

