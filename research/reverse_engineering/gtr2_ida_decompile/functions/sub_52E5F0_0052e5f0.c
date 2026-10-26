void __thiscall sub_52E5F0(int *this, int a2)
{
  int v3; // edi
  float *v4; // ebx
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double v8; // st7
  char v9; // dl
  unsigned __int8 v11; // c0
  unsigned __int8 v12; // c3
  int v13; // eax
  double v14; // st7
  double v15; // st6
  double v16; // st7
  double v17; // st6
  double v18; // st5
  float v19; // edx
  int v20; // ebp
  int v21; // edi
  float *v22; // eax
  double v23; // st7
  double v24; // st7
  int v25; // ecx
  double v26; // st7
  int v27; // eax
  float v28; // [esp+Ch] [ebp-44h]
  float v29; // [esp+10h] [ebp-40h]
  float v30; // [esp+14h] [ebp-3Ch]
  float v31; // [esp+18h] [ebp-38h]
  float v32; // [esp+1Ch] [ebp-34h]
  float v33; // [esp+20h] [ebp-30h]
  float *v34; // [esp+24h] [ebp-2Ch]
  int v35; // [esp+28h] [ebp-28h]
  float v36; // [esp+2Ch] [ebp-24h]
  float v37; // [esp+30h] [ebp-20h]
  float v38; // [esp+34h] [ebp-1Ch]
  float v39; // [esp+38h] [ebp-18h] BYREF
  float v40; // [esp+3Ch] [ebp-14h]
  float v41; // [esp+40h] [ebp-10h]
  float v42[3]; // [esp+44h] [ebp-Ch] BYREF

  *((_BYTE *)this + 324) = 0;
  if ( dword_B64134 != 5 )
    goto LABEL_65;
  v3 = *this + 16;
  if ( *this == -16 )
    return;
  v31 = sub_577BC0(*this + 16);
  v4 = *(float **)(v3 + 17476);
  v36 = *(float *)(v3 + 15972) - v4[1];
  v5 = *(float *)(v3 + 15976);
  v39 = v36;
  v37 = v5 - v4[2];
  v6 = *(float *)(v3 + 15980);
  v40 = v37;
  v38 = v6 - v4[3];
  v41 = v38;
  v7 = v38 * v4[11] + v37 * v4[10] + v36 * v4[9];
  v8 = v7 >= 0.0 ? v7 - v4[28] : -(v7 + v4[27]);
  v9 = *((_BYTE *)this + 324);
  if ( *(_BYTE *)(*this + 15572) )
    goto LABEL_65;
  if ( v8 >= 8.0 )
    goto LABEL_65;
  v34 = (float *)(v3 + 15996);
  if ( v11 | v12 )
    goto LABEL_65;
  v13 = *(_DWORD *)dword_B640C8;
  if ( *(_DWORD *)dword_B640C8 == 3 || *(_DWORD *)dword_B640C8 == 4 )
    v14 = 63.0;
  else
    v14 = 22.0;
  if ( v9 )
    v15 = 3.0;
  else
    v15 = 0.0;
  v16 = v14 + v15;
  v30 = v16;
  if ( *(_DWORD *)dword_B640C8 == 3 || *(_DWORD *)dword_B640C8 == 4 )
    v17 = 1.2;
  else
    v17 = 0.5;
  if ( v9 )
    v18 = 0.2;
  else
    v18 = 0.0;
  v35 = this[82];
  v39 = *(float *)(v3 + 15972);
  v19 = *(float *)(v3 + 15976);
  v41 = *(float *)(v3 + 15980);
  v29 = v16;
  v20 = 0;
  v40 = v19;
  if ( dword_757C10 > 0 )
  {
    do
    {
      if ( v20 != this[1] )
      {
        v21 = *(&dword_91E088 + v20) + 16;
        v22 = sub_401290(&v39, (float *)(*(&dword_91E088 + v20) + 15988), v42);
        if ( v30 * v30 > v22[2] * v22[2] + v22[1] * v22[1] + *v22 * *v22 )
        {
          v23 = sub_577BC0(v21);
          if ( v23 > v31 )
            v23 = v23 - flt_91BDE4;
          v28 = v31 - v23;
          if ( v28 < (double)v30 && !*(_BYTE *)(v21 + 15556) )
          {
            v24 = sub_401220((float *)(v21 + 15996));
            if ( v24 >= 5.0 )
            {
              v33 = v18 + v17;
              if ( v28 / v24 < v33 )
              {
                if ( *(_DWORD *)dword_B640C8 == 6 )
                {
                  if ( *(_DWORD *)(*(&dword_91E088 + v20) + 19324) < this[13] )
                  {
                    v25 = *(_DWORD *)(*(&dword_91E088 + v20) + 19284);
                    if ( v25 > this[3]
                      || *(_DWORD *)(*(&dword_91E088 + v20) + 19288) != this[4] && v25 > 0 && !*(_BYTE *)(*this + 15572) )
                    {
                      *((_BYTE *)this + 324) = 1;
                      if ( v28 < (double)v29 )
                      {
                        this[82] = v20;
                        v29 = v28;
                      }
                    }
                  }
                }
                else if ( this[39] != 2 && *(_DWORD *)(*(&dword_91E088 + v20) + 19428) == 2 )
                {
                  v32 = v4[36] * 0.5;
                  if ( v32 * v32 < sub_401200(v34) && !*(_BYTE *)(*this + 15572) )
                  {
                    *((_BYTE *)this + 324) = 1;
                    if ( v28 < (double)v29 )
                    {
                      this[82] = v20;
                      v29 = v28;
                    }
                  }
                }
              }
            }
          }
        }
      }
      ++v20;
    }
    while ( v20 < dword_757C10 );
    v13 = *(_DWORD *)dword_B640C8;
  }
  if ( *((_BYTE *)this + 324) && this[82] == v35 && v13 == 6 )
  {
    if ( !*(_DWORD *)(*this + 14820) )
    {
      if ( *((float *)this + 83) == 0.0 )
      {
        sub_4EE320(42, 0);
      }
      else if ( *((float *)this + 83) >= 25.0 || *(float *)&a2 + *((float *)this + 83) < 25.0 )
      {
        if ( *((float *)this + 83) < 50.0 && *(float *)&a2 + *((float *)this + 83) >= 50.0 )
          sub_4EE320(44, 0);
      }
      else
      {
        sub_4EE320(43, 0);
      }
    }
    v26 = *(float *)&a2 + *((float *)this + 83);
    *((float *)this + 83) = v26;
    if ( v26 <= 75.0 || !dword_B704D4 )
      goto LABEL_66;
    sub_52BC40();
    if ( !*(_DWORD *)(*this + 14820) )
      sub_4EE320(35, 0);
    goto LABEL_65;
  }
  if ( *((float *)this + 83) != 0.0 )
LABEL_65:
    this[83] = 0;
LABEL_66:
  v27 = this[27];
  if ( v27 != 1
    && v27 != 3
    && dword_B704D4 >= 2
    && dword_B640C0 == 5
    && (dword_B64134 == 3 || dword_B64134 == 5 || dword_B64134 == 6 || dword_B64134 == 8) )
  {
    if ( dword_FADE9C )
      sub_52E240(this, a2);
  }
}
