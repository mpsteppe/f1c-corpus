void __thiscall sub_4298D0(int this, float a2, int a3, int a4)
{
  int v5; // edi
  int v6; // eax
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st6
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // eax
  int v16; // eax
  double v17; // st7
  double v18; // st6
  unsigned __int8 v20; // c0
  unsigned __int8 v21; // c2
  double v22; // st6
  double v23; // st6
  double v24; // st5
  char v25; // al
  bool v26; // c0
  double v27; // st7
  double v28; // st6
  unsigned __int8 v30; // c0
  unsigned __int8 v31; // c2
  double v32; // st6
  double v33; // st6
  double v34; // st5
  float v35; // [esp+0h] [ebp-18h]
  float v36; // [esp+0h] [ebp-18h]
  float v37; // [esp+Ch] [ebp-Ch]
  float v38; // [esp+Ch] [ebp-Ch]
  float v39; // [esp+Ch] [ebp-Ch]
  float v40; // [esp+Ch] [ebp-Ch]
  float v41; // [esp+Ch] [ebp-Ch]
  float v42; // [esp+Ch] [ebp-Ch]
  float v43; // [esp+1Ch] [ebp+4h]
  float v44; // [esp+1Ch] [ebp+4h]
  float v45; // [esp+1Ch] [ebp+4h]
  float v46; // [esp+1Ch] [ebp+4h]

  v5 = (LODWORD(a2) << 7) + this;
  if ( *(_DWORD *)(v5 + 21372) == 2
    && *(float *)(v5 + 21304) > 0.0
    && *(_DWORD *)(this + 24240) != 1
    && *(float *)(*(_DWORD *)(v5 + 21256) + 24676) > (double)*(float *)(*(_DWORD *)(v5 + 21256) + 23852) )
  {
    v37 = *(float *)(this + 23764) - 0.5;
    sub_427B50((float *)this, v37);
  }
  v6 = *(_DWORD *)(v5 + 21372);
  if ( v6 )
  {
    switch ( v6 )
    {
      case 1:
        v7 = -((*(float *)(v5 + 21340) - *(float *)(this + 23764)) * *(float *)(this + 23936));
        if ( !*(_DWORD *)(*(_DWORD *)(this + 23432) + 328) && v7 < 0.0 )
          v7 = 0.0;
        v8 = v7 + *(float *)(v5 + 21356);
        if ( v8 > *(float *)(v5 + 21304) )
        {
          v38 = (*(float *)(v5 + 21304) - v8) / *(float *)(this + 23964) * *(float *)(this + 23944)
              + *(float *)(this + 23764);
          sub_427B50((float *)this, v38);
        }
        break;
      case 4:
        v39 = *(float *)(this + 23764) + *(float *)(v5 + 21316) - 2.0;
        sub_427B50((float *)this, v39);
        break;
      case 3:
        *(_DWORD *)(this + 8) = 1082130432;
        break;
      case 2:
        v43 = fabs(*(float *)(v5 + 21320));
        if ( *(_DWORD *)(this + 24244) == 1 )
          v43 = v43 * 0.25;
        if ( *(float *)(v5 + 21304) > 0.0 && *(float *)(v5 + 21304) < 10.0 )
        {
          if ( v43 >= 2.0 )
          {
            if ( v43 >= 10.0 )
              break;
            if ( *(float *)(v5 + 21304) >= 12.0 )
              v10 = *(float *)(v5 + 21340);
            else
              v10 = *(float *)(this + 23764) + *(float *)(v5 + 21316);
            v9 = v10 + 2.0 + (v43 - 2.0) * 1.25;
            if ( v9 < 20.0 )
              goto LABEL_34;
          }
          else if ( *(float *)(v5 + 21304) >= 12.0 )
          {
            v9 = *(float *)(v5 + 21340) + 2.0;
            if ( v9 < 20.0 )
              goto LABEL_34;
          }
          else
          {
            v9 = *(float *)(this + 23764) + *(float *)(v5 + 21316) + 2.0;
            if ( v9 < 20.0 )
            {
LABEL_34:
              sub_427B50((float *)this, 20.0);
              break;
            }
          }
          v44 = v9;
          sub_427B50((float *)this, v44);
        }
        break;
    }
  }
  v11 = *(_DWORD *)(v5 + 21364);
  if ( !v11 )
    return;
  if ( v11 == 1 )
  {
    v12 = sub_42B320(0.0);
    v13 = v12;
    if ( v12 >= 6 && v12 <= 11 )
    {
      if ( v12 != 11 || *(_DWORD *)(this + 23804) && *(_DWORD *)(this + 23800) )
      {
        if ( *(float *)(this + 24696) < (double)*(float *)(this + 23852) )
        {
          v14 = *(_DWORD *)(this + 24020);
          if ( v13 != v14 && v14 >= 6 && !(unsigned __int8)sub_42C150(v13, 1000593162, 0.0) )
            *(_DWORD *)(this + 24288) = -1;
        }
      }
      else
      {
        *(_DWORD *)(this + 24696) = -1082130432;
        *(_DWORD *)(this + 24288) = -1;
      }
    }
    return;
  }
  if ( v11 != 4 )
  {
    if ( v11 == 5 )
    {
      if ( *(float *)(v5 + 21320) < 2.2 )
      {
        if ( *(float *)(this + 24712) == 0.0
          && (v36 = *(float *)(this + 23728) + *(float *)(v5 + 21320),
              v16 = sub_42CC20(1, v36, *(_DWORD *)(v5 + 21348)),
              (unsigned __int8)sub_42C150(v16, 1000593162, 0.0)) )
        {
          *(_DWORD *)(this + 24680) = 1;
        }
        else
        {
          v42 = *(float *)(this + 23764) + *(float *)(v5 + 21316);
          sub_427B50((float *)this, v42);
        }
      }
      if ( fabs(*(float *)(v5 + 21296)) < 1.899999976158142 )
        goto LABEL_56;
      return;
    }
    if ( v11 == 9 )
    {
      if ( fabs(*(float *)(v5 + 21304)) >= 10.0 )
        v17 = *(float *)(v5 + 21320);
      else
        v17 = *(float *)(v5 + 21296);
      if ( *(float *)(32 * *(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + this + 21924) > 0.0 )
        return;
      if ( *(float *)(v5 + 21304) > 20.0 || *(float *)(v5 + 21304) >= 0.0 )
      {
        if ( *(float *)(v5 + 21304) > 20.0 )
        {
          v18 = 20.0;
          goto LABEL_75;
        }
        v18 = *(float *)(v5 + 21304);
        if ( v18 >= 10.0 )
        {
LABEL_75:
          v22 = 1.0 - (v18 - 10.0) * 0.1;
          if ( v20 | v21 )
            v23 = v22 * 3.2;
          else
            v23 = v22 + v22;
LABEL_82:
          if ( *(float *)(v5 + 21360) >= 5.0 || v23 > 3.2 )
          {
            if ( v23 <= 0.000001 )
              return;
          }
          else
          {
            v23 = 3.2;
          }
          v24 = *(float *)(this + 23856) * *(float *)(v5 + 21308);
          if ( v24 > 0.0 )
            v24 = 0.0;
          v45 = v24 + *(float *)(this + 23728) + v17 - v23;
          v25 = sub_427B90(this, v45, 0);
          v26 = *(float *)(*(_DWORD *)(v5 + 21256) + 23860) < (double)*(float *)(this + 23864);
LABEL_112:
          if ( v26 && v25 )
            sub_42C0B0(*(_DWORD *)(this + 68));
          else
            sub_42C0D0(*(_DWORD *)(this + 68));
          return;
        }
      }
      if ( *(float *)(this + 24728) >= (double)*(float *)(this + 23852) )
        v23 = 2.0;
      else
        v23 = 3.2;
      goto LABEL_82;
    }
    if ( v11 != 8 )
      return;
    v27 = fabs(*(float *)(v5 + 21304)) >= 10.0 ? *(float *)(v5 + 21320) : *(float *)(v5 + 21296);
    if ( *(float *)(32 * *(_DWORD *)(*(_DWORD *)(v5 + 21256) + 25248) + this + 21924) > 0.0 )
      return;
    if ( *(float *)(v5 + 21304) > 20.0 || *(float *)(v5 + 21304) >= 0.0 )
    {
      if ( *(float *)(v5 + 21304) > 20.0 )
      {
        v28 = 20.0;
        goto LABEL_98;
      }
      v28 = *(float *)(v5 + 21304);
      if ( v28 >= 10.0 )
      {
LABEL_98:
        v32 = 1.0 - (v28 - 10.0) * 0.1;
        if ( v30 | v31 )
          v33 = v32 * 2.8;
        else
          v33 = v32 + v32;
LABEL_105:
        if ( *(float *)(v5 + 21360) >= 5.0 || v33 > 2.8 )
        {
          if ( v33 <= 0.000001 )
            return;
        }
        else
        {
          v33 = 2.8;
        }
        v34 = *(float *)(this + 23856) * *(float *)(v5 + 21308);
        if ( v34 < 0.0 )
          v34 = 0.0;
        v46 = v34 + *(float *)(this + 23728) + v27 + v33;
        v25 = sub_427C20(this, v46, 0);
        v26 = *(float *)(*(_DWORD *)(v5 + 21256) + 23864) < (double)*(float *)(this + 23860);
        goto LABEL_112;
      }
    }
    if ( *(float *)(this + 24728) >= (double)*(float *)(this + 23852) )
      v33 = 2.0;
    else
      v33 = 2.8;
    goto LABEL_105;
  }
  if ( *(float *)(v5 + 21320) > -2.2 )
  {
    if ( *(float *)(this + 24712) == 0.0
      && (v35 = *(float *)(this + 23728) + *(float *)(v5 + 21320),
          v15 = sub_42CC20(0, v35, *(_DWORD *)(v5 + 21348)),
          (unsigned __int8)sub_42C150(v15, 1000593162, 0.0)) )
    {
      *(_DWORD *)(this + 24680) = -1;
    }
    else
    {
      v40 = *(float *)(this + 23764) + *(float *)(v5 + 21316);
      sub_427B50((float *)this, v40);
    }
  }
  if ( fabs(*(float *)(v5 + 21296)) > -1.899999976158142 )
  {
LABEL_56:
    if ( *(float *)(v5 + 21360) < 3.0 )
    {
      v41 = *(float *)(this + 23764) + *(float *)(v5 + 21316) - 2.0;
      sub_427B50((float *)this, v41);
    }
  }
}
