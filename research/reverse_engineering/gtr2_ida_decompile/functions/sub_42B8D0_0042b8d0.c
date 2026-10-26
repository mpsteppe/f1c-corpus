int __thiscall sub_42B8D0(int *this, char a2)
{
  int result; // eax
  int v4; // esi
  int v5; // ebx
  int v6; // edi
  int v7; // edx
  int v8; // ecx
  bool v9; // zf
  int v10; // eax
  float *v11; // edx
  int v12; // edi
  long double v13; // st7
  long double v14; // st6
  long double v15; // st5
  long double v16; // st7
  long double v17; // st5
  long double v18; // st4
  long double v19; // st3
  long double v20; // st2
  int v21; // [esp+Ch] [ebp-ACh]
  int v22; // [esp+10h] [ebp-A8h]
  int v23; // [esp+14h] [ebp-A4h]
  float v24; // [esp+38h] [ebp-80h]
  float v25; // [esp+3Ch] [ebp-7Ch]
  int v26; // [esp+40h] [ebp-78h]
  float v27; // [esp+44h] [ebp-74h]
  float v28; // [esp+48h] [ebp-70h]
  float v29; // [esp+4Ch] [ebp-6Ch]
  int v30; // [esp+50h] [ebp-68h]
  int v31; // [esp+54h] [ebp-64h]
  float v32; // [esp+58h] [ebp-60h]
  float v33; // [esp+5Ch] [ebp-5Ch]
  float v34; // [esp+60h] [ebp-58h]
  float v35; // [esp+74h] [ebp-44h]
  float v36; // [esp+78h] [ebp-40h]
  float v37; // [esp+7Ch] [ebp-3Ch]
  _BYTE v38[24]; // [esp+80h] [ebp-38h] BYREF
  int v39; // [esp+98h] [ebp-20h]
  _BYTE v40[24]; // [esp+9Ch] [ebp-1Ch] BYREF
  int v41; // [esp+B4h] [ebp-4h]

  result = *this;
  if ( *this )
  {
    sub_5D7710(2, 0);
    v4 = *this;
    v30 = 0;
    v26 = 0;
    if ( *this )
    {
      v5 = 7;
      while ( 1 )
      {
        v6 = (unsigned __int64)(*(float *)(v4 + 36) * 255.0);
        v7 = (unsigned __int64)(*(float *)(v4 + 40) * 255.0);
        if ( v5 < 7 && (double)v31 > 128.0 && 0.0 == (double)(int)(unsigned __int64)(*(float *)(v4 + 40) * 255.0) )
          v7 = v31;
        v8 = -1;
        v9 = v7 == 0;
        v31 = v7;
        v39 = -1;
        if ( v7 > 0 )
        {
          if ( !v6 )
          {
            v8 = -65792 * v7 - 1;
            v39 = v8;
          }
          v9 = v7 == 0;
        }
        if ( !v9 )
          break;
        if ( v6 > 0 )
        {
          v8 -= 257 * v6;
LABEL_21:
          v39 = v8;
        }
LABEL_22:
        v11 = (float *)v26;
        if ( v26 )
        {
          if ( *(float *)(v4 + 52) >= 6.0 || a2 )
          {
            if ( v5 > 0 )
            {
              v8 &= (unsigned int)byte_FFFFFF;
              v39 = v8;
              if ( v5 < 7 )
              {
                v8 |= (255 / v5) << 24;
                v39 = v8;
              }
            }
            v41 = v30;
            if ( !v30 )
              v41 = v8;
            v12 = this[115];
            if ( v12 == 2 )
            {
              if ( v5 > 7 || v5 <= 0 )
                v8 = -14614752;
              else
                v8 = ((255 / v5) << 24) | 0x20FF20;
              v39 = v8;
            }
            v30 = v8;
            if ( v12 )
            {
              sub_42B2F0(v26, (int)v40);
              sub_42B2F0(v4, (int)v38);
              sub_546BC0(&unk_BE2728, 12, v40, v38);
            }
            v11 = (float *)v26;
            --v5;
          }
          if ( !*(_DWORD *)(v4 + 56) )
          {
            if ( dword_91E068 )
            {
              v27 = *(float *)(v4 + 12);
              v28 = *(float *)(v4 + 16);
              v29 = *(float *)(v4 + 20);
              v13 = 1.0 / sqrt(v27 * v27 + v28 * v28 + v29 * v29);
              v14 = v27 * v13;
              v15 = v13;
              v16 = v13 * v28;
              v17 = v15 * v29;
              v32 = *(float *)v4 - *v11;
              v33 = *(float *)(v4 + 4) - v11[1];
              v34 = *(float *)(v4 + 8) - v11[2];
              v18 = 1.0 / sqrt(v34 * v34 + v33 * v33 + v32 * v32);
              v19 = v32 * v18;
              v24 = v33 * v18;
              v20 = v34 * v18;
              v25 = v20;
              v35 = v20 * v16 - v24 * v17;
              v36 = v19 * v17 - v25 * v14;
              v37 = v24 * v14 - v19 * v16;
              *(float *)&v23 = v37 * *((float *)this + 112) + v17 * *((float *)this + 111) + *(float *)(v4 + 8);
              *(float *)&v22 = v36 * *((float *)this + 112) + v16 * *((float *)this + 111) + *(float *)(v4 + 4);
              *(float *)&v21 = v35 * *((float *)this + 112) + v14 * *((float *)this + 111) + *(float *)v4;
              sub_5DB2B0(v21, v22, v23, *(float *)(v4 + 24), *(float *)(v4 + 28), *(float *)(v4 + 32));
            }
          }
        }
        v26 = v4;
        v4 = *(_DWORD *)(v4 + 56);
        if ( !v4 )
          return sub_5D7710(1, 0);
      }
      if ( v7 <= 0 || v6 <= 0 )
        goto LABEL_22;
      if ( v6 <= v7 )
        v10 = 65792 * v7;
      else
        v10 = 257 * v6;
      v8 -= v10;
      goto LABEL_21;
    }
    return sub_5D7710(1, 0);
  }
  return result;
}
