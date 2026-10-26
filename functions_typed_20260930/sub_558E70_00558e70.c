void __thiscall sub_558E70(char *this, _DWORD *a2, _DWORD *a3)
{
  int v4; // eax
  int i; // esi
  float *v6; // ebx
  int v7; // eax
  int v8; // ecx
  int v9; // edx
  int v10; // eax
  _DWORD *v11; // edi
  int v12; // eax
  int v13; // esi
  bool v14; // cc
  int v15; // eax
  int v16; // ecx
  int v17; // edx
  int v18; // eax
  int v19; // eax
  int v20; // esi
  int v21; // edi
  float v23; // [esp+0h] [ebp-B8h]
  float v24; // [esp+4h] [ebp-B4h]
  float v25; // [esp+4h] [ebp-B4h]
  float v26; // [esp+8h] [ebp-B0h]
  float v27; // [esp+10h] [ebp-A8h] BYREF
  int v28; // [esp+14h] [ebp-A4h] BYREF
  int v29; // [esp+18h] [ebp-A0h] BYREF
  int v30; // [esp+1Ch] [ebp-9Ch] BYREF
  float v31; // [esp+20h] [ebp-98h] BYREF
  float v32; // [esp+24h] [ebp-94h] BYREF
  float *v33; // [esp+28h] [ebp-90h]
  unsigned int v34; // [esp+2Ch] [ebp-8Ch]
  int v35; // [esp+30h] [ebp-88h]
  float v36; // [esp+34h] [ebp-84h] BYREF
  float v37; // [esp+38h] [ebp-80h]
  int v38; // [esp+3Ch] [ebp-7Ch]
  int v39; // [esp+40h] [ebp-78h]
  _DWORD *v40; // [esp+44h] [ebp-74h]
  __int16 v41; // [esp+48h] [ebp-70h]
  int v42; // [esp+4Ch] [ebp-6Ch]
  _DWORD v43[10]; // [esp+50h] [ebp-68h] BYREF
  _BYTE v44[48]; // [esp+78h] [ebp-40h] BYREF

  if ( this[32] < 0 )
  {
    if ( *((_DWORD *)this + 12) )
    {
      TextureSurfaceUnlockRelease(this, 0);
      sub_55CF50(
        a2,
        *((_DWORD *)this + 20),
        *((_DWORD *)this + 12) * *((_DWORD *)this + 9),
        *((_DWORD *)this + 12) * *((_DWORD *)this + 10));
    }
  }
  else if ( *((_DWORD *)this + 12) )
  {
    F_10FloatStructInitializer(v43);
    v4 = *((_DWORD *)this + 8);
    if ( (v4 & 0x20) != 0 )
    {
      F_3FieldGetter(a3, &v32, &v27, &v31);
      v24 = -v27;
      EulerAngleToRotationMatrix((int)v43, 0.0, v24, 0.0);
    }
    else if ( (v4 & 0x10) != 0 )
    {
      F_3FieldGetter(a3, &v32, &v27, &v31);
      v26 = -v31;
      v25 = -v27;
      v23 = -v32;
      EulerAngleToRotationMatrix((int)v43, v23, v25, v26);
    }
    for ( i = 0; i < *((_DWORD *)this + 19); ++i )
    {
      *(_DWORD *)(*((_DWORD *)this + 17) + 4 * i) = 0;
      *(_DWORD *)(*((_DWORD *)this + 18) + 4 * i) = 0;
      TextureAllocationWithFormatSizeFlags(this, i);
    }
    v33 = (float *)*((_DWORD *)this + 14);
    v6 = v33;
    LinkedListTraversal(a2, 0);
    FieldGetterByIndex(2, &v36);
    if ( v6 )
    {
      while ( 1 )
      {
        if ( (this[32] & 0x30) != 0 )
        {
          qmemcpy(v6 + 14, v44, 0x30u);
          ThreeFieldAccessor((_DWORD *)v6 + 4, &v29, &v30, &v28);
          MultiFieldSetter((_DWORD *)v6 + 4, v29, v30, v28);
        }
        if ( (*(_DWORD *)v6 & 0x4000) != 0 )
        {
          TripleFieldGetter_b1d0((_DWORD *)v6 + 4, &v29, &v30, &v28);
          sub_53B330((_DWORD *)v6 + 4, v29, v30, v28);
        }
        ConditionalScaleApply(v6 + 4);
        v7 = *((_DWORD *)this + 19);
        v8 = 0;
        v39 = 0;
        if ( v7 > 0 )
        {
          v9 = 0;
          v35 = 0;
          do
          {
            v10 = *((_DWORD *)this + 20);
            v11 = *(_DWORD **)(v10 + v9 + 12);
            v12 = v9 + v10;
            v13 = *(_DWORD *)(v12 + 32) + (*(_DWORD *)(*((_DWORD *)this + 17) + 4 * v8) << 6);
            v14 = *(_DWORD *)(v12 + 8) <= 0;
            v38 = 0;
            if ( !v14 )
            {
              v40 = v6 + 14;
              do
              {
                (*(void (__cdecl **)(int, _DWORD *, int, _DWORD *))(*(_DWORD *)dword_8B8F24 + 4))(
                  dword_8B8F24,
                  v11,
                  v13,
                  v40);
                *(_DWORD *)(v13 + 32) = v11[7];
                *(_DWORD *)(v13 + 36) = v11[8];
                v15 = v11[6];
                v34 = *((_DWORD *)v6 + 3);
                v42 = v15;
                v37 = (double)HIBYTE(v34) * v36;
                v41 = (__int16)v37;
                v11 += 9;
                v13 += 64;
                v16 = v35;
                v17 = (((unsigned __int8)v34 * ((unsigned __int8)v15 + 1)) >> 8)
                    + ((((BYTE1(v34) * (BYTE1(v15) + 1)) >> 8)
                      + (((v41 << 8) + ((BYTE2(v34) * (BYTE2(v15) + 1)) >> 8)) << 8)) << 8);
                v18 = v38;
                *(_DWORD *)(v13 - 40) = v17;
                v14 = ++v18 < *(_DWORD *)(v16 + *((_DWORD *)this + 20) + 8);
                v6 = v33;
                v38 = v18;
              }
              while ( v14 );
              v8 = v39;
              v9 = v35;
            }
            *(_DWORD *)(*((_DWORD *)this + 17) + 4 * v8) += *(_DWORD *)(v9 + *((_DWORD *)this + 20) + 8);
            *(_DWORD *)(*((_DWORD *)this + 18) + 4 * v8) += *(_DWORD *)(v9 + *((_DWORD *)this + 20) + 16);
            v19 = *((_DWORD *)this + 19);
            ++v8;
            v9 += 64;
            v39 = v8;
            v35 = v9;
          }
          while ( v8 < v19 );
        }
        v33 = (float *)*((_DWORD *)v6 + 31);
        if ( !v33 )
          break;
        v6 = v33;
      }
    }
    v20 = 0;
    if ( *((int *)this + 19) > 0 )
    {
      v21 = 0;
      do
      {
        TextureSurfaceUnlockRelease(this, v20);
        sub_55CF50(
          a2,
          v21 + *((_DWORD *)this + 20),
          *(_DWORD *)(*((_DWORD *)this + 17) + 4 * v20),
          *(_DWORD *)(*((_DWORD *)this + 18) + 4 * v20));
        ++v20;
        v21 += 64;
      }
      while ( v20 < *((_DWORD *)this + 19) );
    }
    EmptyStub_b160();
  }
}

