void __thiscall sub_4F1C40(int this, float a2)
{
  unsigned int v3; // ecx
  unsigned __int8 v5; // c0
  unsigned __int8 v6; // c2
  char v7; // dl
  long double v8; // st7
  int v9; // ebp
  int v10; // edi
  _DWORD *v11; // ecx
  int v12; // eax
  int v13; // edx
  int v14; // edx
  int v15; // eax
  double v16; // st7
  float v17; // edx
  double v18; // st7
  double v19; // st7
  double v20; // st7
  long double v21; // st7
  long double v22; // st6
  float v23; // [esp+4h] [ebp-58h] BYREF
  float v24; // [esp+8h] [ebp-54h] BYREF
  float v25; // [esp+Ch] [ebp-50h] BYREF
  float v26; // [esp+10h] [ebp-4Ch]
  float v27; // [esp+14h] [ebp-48h]
  float v28[3]; // [esp+18h] [ebp-44h] BYREF
  float v29[5]; // [esp+24h] [ebp-38h] BYREF
  float v30[6]; // [esp+38h] [ebp-24h] BYREF
  float v31; // [esp+50h] [ebp-Ch] BYREF
  float v32; // [esp+54h] [ebp-8h]
  float v33; // [esp+58h] [ebp-4h]

  v3 = *(_DWORD *)(this + 12988);
  if ( v3 <= 1 && (*(_DWORD *)(*(_DWORD *)this + 18620) & 8) != 0 )
  {
    if ( byte_7D0AF8 == 1 )
    {
      if ( *(float *)(this + 13504) >= 0.70710677 )
      {
        *(_DWORD *)(this + 16372) = 0;
      }
      else
      {
        v23 = a2 + *(float *)(this + 16372);
        *(float *)(this + 16372) = v23;
        if ( v5 | v6 )
        {
          v7 = 0;
          if ( !v3 && (byte_7C749F || byte_7C74A3) )
            v7 = 1;
          if ( v23 > 5.0 || v7 && v23 > 3.0 )
          {
            sub_4F2320(this);
            v8 = atan2(*(float *)(this + 13496), *(float *)(this + 13520));
            *(_DWORD *)(this + 13536) = 0;
            *(_DWORD *)(this + 13544) = 0;
            *(float *)(this + 13540) = v8;
            sub_566E40(this + 13536, this + 13488);
            sub_4EFB20((float *)this, v28, &v25);
            sub_4EF7C0(this, v28, &v25);
          }
        }
      }
      v9 = 0;
      v10 = 0;
      v11 = (_DWORD *)(this + 13928);
      v12 = this + 2088;
      v13 = 4;
      do
      {
        if ( *(_DWORD *)v12 )
        {
          if ( *(_BYTE *)(v12 + 64) )
          {
            ++v10;
            if ( !*v11 )
              ++v9;
          }
        }
        v12 += 296;
        v11 += 62;
        --v13;
      }
      while ( v13 );
      if ( v9 || v10 <= 2 )
      {
        if ( v9 == v10 )
        {
          sub_4F2320(this);
          *(_DWORD *)(this + 13524) = *(_DWORD *)(this + 16392);
          v15 = *(_DWORD *)(this + 16400);
          *(_DWORD *)(this + 13528) = *(_DWORD *)(this + 16396);
          *(_DWORD *)(this + 13532) = v15;
          sub_4EFB20((float *)this, &v25, v28);
          sub_4EF7C0(this, &v25, v28);
        }
        else if ( v9 > 1 )
        {
          v16 = *(float *)(this + 16392) - *(float *)(this + 13524);
          v30[0] = *(float *)(this + 13524);
          v25 = v16;
          v17 = *(float *)(this + 13532);
          v18 = *(float *)(this + 16396) - *(float *)(this + 13528);
          v30[1] = *(float *)(this + 13528);
          v30[2] = v17;
          v26 = v18;
          v19 = *(float *)(this + 16400);
          v32 = v26;
          v20 = v19 - *(float *)(this + 13532);
          v31 = v25;
          v27 = v20;
          v33 = v27;
          v21 = sqrt(v27 * v27 + v25 * v25) * 0.1 + v26;
          if ( v25 == 0.0 && v21 == 0.0 && v33 == 0.0 )
          {
            v31 = 0.0;
            v32 = 1.0;
            v33 = 0.0;
          }
          else
          {
            v22 = 1.0 / sqrt(v21 * v21 + v33 * v33 + v31 * v31);
            v31 = v31 * v22;
            v32 = v22 * v21;
            v33 = v22 * v33;
          }
          v30[3] = v31;
          v30[4] = v32;
          v30[5] = v33;
          sub_4ED420((float *)this, v30, &v31, &v23, &v24, 0);
          if ( v23 > 0.0 )
            v23 = 0.0;
          v29[2] = 0.5;
          LODWORD(v29[3]) = 10;
          v29[1] = -(v23 / v24);
          sub_4EBC60((void *)this, v29, 0);
          sub_4EC080((char *)this, v29);
        }
      }
      else
      {
        *(_DWORD *)(this + 16392) = *(_DWORD *)(this + 13524);
        v14 = *(_DWORD *)(this + 13532);
        *(_DWORD *)(this + 16396) = *(_DWORD *)(this + 13528);
        *(_DWORD *)(this + 16400) = v14;
      }
    }
    sub_4F1FE0(a2);
  }
}
