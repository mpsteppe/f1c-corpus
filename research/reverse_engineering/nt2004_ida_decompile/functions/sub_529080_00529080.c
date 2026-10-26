void __thiscall sub_529080(int this)
{
  int v2; // ecx
  double v3; // st7
  int v4; // eax
  double v5; // st7
  long double v6; // st5
  long double v7; // st7
  double v8; // st7
  int v9; // eax
  double v10; // st7
  long double v11; // st5
  long double v12; // st7
  int v13; // ecx
  float *v14; // edx
  int v15; // ebp
  double v16; // st7
  double v17; // st6
  float v18; // eax
  double v19; // st6
  double v20; // st6
  double v21; // st7
  long double v22; // st5
  long double v23; // st7
  float *v24; // ecx
  int v25; // eax
  double v26; // st7
  double v27; // st6
  int v28; // ebp
  double v29; // st6
  double v30; // st6
  double v31; // st5
  float v32; // eax
  double v33; // st5
  double v34; // st6
  double v35; // st7
  long double v36; // st5
  long double v37; // st7
  float v38; // [esp+Ch] [ebp-48h]
  float v39; // [esp+Ch] [ebp-48h]
  float v40; // [esp+Ch] [ebp-48h]
  float v41; // [esp+Ch] [ebp-48h]
  float v42; // [esp+10h] [ebp-44h] BYREF
  int v43; // [esp+14h] [ebp-40h]
  float v44; // [esp+18h] [ebp-3Ch]
  float v45; // [esp+1Ch] [ebp-38h] BYREF
  int v46; // [esp+20h] [ebp-34h]
  float v47; // [esp+24h] [ebp-30h]
  float v48; // [esp+30h] [ebp-24h]
  float v49; // [esp+38h] [ebp-1Ch]
  float v50; // [esp+40h] [ebp-14h]
  float v51; // [esp+48h] [ebp-Ch]
  float v52; // [esp+50h] [ebp-4h]

  if ( *(_DWORD *)(this + 292) )
  {
    v2 = *(_DWORD *)(this + 296);
    if ( v2 )
    {
      if ( *(_DWORD *)(v2 + 296) && this != v2 )
      {
        sub_5299C0(&v45, 1);
        sub_5299C0(&v42, 1);
        v51 = -(v44 - v47);
        v52 = v42 - v45;
        sub_5299C0(&v42, 1);
        v49 = -(v47 - v44);
        v50 = v45 - v42;
        sub_5299C0(&v45, 1);
        sub_5299C0(&v42, 1);
        v3 = v49 * v52 - v50 * v51;
        if ( v3 <= -0.00001 || v3 >= 0.00001 )
        {
          if ( v51 == 0.0 )
            v51 = 0.0000099999997;
          v4 = *(_DWORD *)(this + 296);
          v5 = v49 * ((v44 - v47 - v52 / v51 * v42 + v52 / v51 * v45) / (v52 / v51 * v49 - v50)) + v42;
          v48 = (v44 - v47 - v52 / v51 * v42 + v52 / v51 * v45) / (v52 / v51 * v49 - v50) * v50 + v44;
          v38 = sqrt((v48 - v47) * (v48 - v47) + (v5 - v45) * (v5 - v45));
          v6 = sqrt((v48 - v44) * (v48 - v44) + (v5 - v42) * (v5 - v42));
          v7 = v6;
          if ( v4 == this )
          {
            *(_DWORD *)(this + 252) = 0;
          }
          else
          {
            if ( v38 <= v6 )
              v7 = v38;
            *(float *)(this + 252) = v7;
          }
        }
        else
        {
          *(_DWORD *)(this + 252) = 2139095039;
        }
        sub_5299C0(&v45, 0);
        sub_5299C0(&v42, 0);
        v51 = -(v44 - v47);
        v52 = v42 - v45;
        sub_5299C0(&v42, 0);
        v49 = -(v47 - v44);
        v50 = v45 - v42;
        sub_5299C0(&v45, 0);
        sub_5299C0(&v42, 0);
        v8 = v49 * v52 - v50 * v51;
        if ( v8 <= -0.00001 || v8 >= 0.00001 )
        {
          if ( v51 == 0.0 )
            v51 = 0.0000099999997;
          v9 = *(_DWORD *)(this + 296);
          v10 = v49 * ((v44 - v47 - v52 / v51 * v42 + v52 / v51 * v45) / (v52 / v51 * v49 - v50)) + v42;
          v48 = (v44 - v47 - v52 / v51 * v42 + v52 / v51 * v45) / (v52 / v51 * v49 - v50) * v50 + v44;
          v39 = sqrt((v48 - v47) * (v48 - v47) + (v10 - v45) * (v10 - v45));
          v11 = sqrt((v48 - v44) * (v48 - v44) + (v10 - v42) * (v10 - v42));
          v12 = v11;
          if ( v9 == this )
          {
            *(_DWORD *)(this + 244) = 0;
          }
          else
          {
            if ( v39 <= v11 )
              v12 = v39;
            *(float *)(this + 244) = v12;
          }
        }
        else
        {
          *(_DWORD *)(this + 244) = 2139095039;
        }
        v13 = *(_DWORD *)(this + 296);
        v45 = *(float *)(v13 + 196);
        v46 = *(_DWORD *)(v13 + 200);
        v47 = *(float *)(v13 + 204);
        v14 = (float *)(this + 196);
        v42 = *(float *)(this + 196);
        v15 = *(_DWORD *)(this + 200);
        v44 = *(float *)(this + 204);
        v43 = v15;
        v16 = -*(float *)(v13 + 220);
        v17 = *(float *)(this + 220);
        v52 = *(float *)(v13 + 212);
        v18 = *(float *)(this + 212);
        v49 = -v17;
        v50 = v18;
        v19 = v18 * *(float *)(v13 + 220) + v49 * *(float *)(v13 + 212);
        if ( v19 > -0.00001 && v19 < 0.00001 )
        {
          if ( v13 == this )
            *(_DWORD *)(this + 224) = 0;
          else
            *(_DWORD *)(this + 224) = 1232348144;
          return;
        }
        if ( v16 == 0.0 )
          v16 = 0.0000099999997;
        v20 = (v44 - v47 - v52 / v16 * v42 + v52 / v16 * v45) / (v52 / v16 * v49 - v50);
        v21 = v49 * v20 + v42;
        v48 = v20 * v50 + v44;
        v40 = sqrt((v48 - v47) * (v48 - v47) + (v21 - v45) * (v21 - v45));
        v22 = sqrt((v48 - v44) * (v48 - v44) + (v21 - v42) * (v21 - v42));
        v23 = v22;
        if ( v13 == this )
        {
          *(_DWORD *)(this + 224) = 0;
        }
        else
        {
          if ( v40 <= v22 )
            v23 = v40;
          *(float *)(this + 224) = v23;
        }
        v24 = *(float **)(this + 300);
        if ( v24 )
        {
          v25 = *(_DWORD *)(this + 292);
          if ( v25 )
          {
            v26 = *v24 - *v14;
            v27 = v24[2];
            v45 = *v14;
            v28 = *(_DWORD *)(this + 200);
            v29 = v27 - *(float *)(this + 204);
            v47 = *(float *)(this + 204);
            v46 = v28;
            v30 = -v29;
            v42 = *(float *)(v25 + 196);
            v43 = *(_DWORD *)(v25 + 200);
            v44 = *(float *)(v25 + 204);
            v31 = *(float *)(v25 + 220);
            v32 = *(float *)(v25 + 212);
            v49 = -v31;
            v50 = v32;
            v33 = v32 * *(float *)(this + 220) + v49 * *(float *)(this + 212);
            if ( v33 > -0.00001 && v33 < 0.00001 )
            {
              if ( v24 != (float *)this )
              {
                *(_DWORD *)(this + 256) = 2139095039;
                return;
              }
              goto LABEL_47;
            }
            v34 = (v44 - v47 - v26 / v30 * v42 + v26 / v30 * v45) / (v26 / v30 * v49 - v50);
            v35 = v49 * v34 + v42;
            v48 = v34 * v50 + v44;
            v41 = sqrt((v48 - v47) * (v48 - v47) + (v35 - v45) * (v35 - v45));
            v36 = sqrt((v48 - v44) * (v48 - v44) + (v35 - v42) * (v35 - v42));
            v37 = v36;
            if ( v24 == (float *)this )
            {
LABEL_47:
              *(_DWORD *)(this + 256) = 0;
              return;
            }
            if ( v41 <= v36 )
              v37 = v41;
            *(float *)(this + 256) = v37;
          }
        }
      }
    }
  }
}
