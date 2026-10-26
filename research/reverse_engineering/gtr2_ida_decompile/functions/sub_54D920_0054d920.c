int __thiscall sub_54D920(int this, float a2)
{
  int result; // eax
  int v4; // ecx
  float *v5; // edx
  int v6; // eax
  float *v7; // edi
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  double v12; // st7
  int v13; // ecx
  int v14; // ebp
  int v15; // eax
  int v16; // eax
  int v17; // ecx
  double v18; // st7
  int v19; // ecx
  int v20; // eax
  double v21; // st7
  int v22; // eax
  int v23; // ebp
  int v24; // ecx
  double v25; // st7
  double v26; // st7
  double v27; // st7
  double v28; // st7
  double v29; // st7
  double v30; // st7
  float v31; // [esp+8h] [ebp-18h] BYREF
  float v32; // [esp+Ch] [ebp-14h] BYREF
  float v33; // [esp+10h] [ebp-10h] BYREF
  float v34; // [esp+14h] [ebp-Ch] BYREF
  float v35; // [esp+18h] [ebp-8h]
  float v36; // [esp+1Ch] [ebp-4h]

  result = *(_DWORD *)(this + 60);
  if ( result )
  {
    result = sub_405250();
    if ( (_BYTE)result )
    {
      result = sub_54D4F0(this, a2);
    }
    else
    {
      v4 = *(_DWORD *)(this + 68);
      if ( v4 )
      {
        result = sub_5BFC80(v4);
        if ( (_BYTE)result )
          result = (*(int (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(this + 68) + 20))(*(_DWORD *)(this + 68), 0);
      }
    }
  }
  if ( *(_DWORD *)(this + 32) && *(_DWORD *)(this + 84) && *(_DWORD *)(this + 88) )
  {
    if ( *(float *)(this + 16) == 0.0 && *(float *)(this + 20) == 0.0 )
    {
      v5 = (float *)(this + 160);
      *(_DWORD *)(this + 160) = *(_DWORD *)(this + 116);
      v6 = *(_DWORD *)(this + 124);
      *(_DWORD *)(this + 164) = *(_DWORD *)(this + 120);
      *(_DWORD *)(this + 168) = v6;
      v7 = (float *)(this + 172);
      *(_DWORD *)(this + 172) = *(_DWORD *)(this + 92);
      v8 = *(_DWORD *)(this + 100);
      *(_DWORD *)(this + 176) = *(_DWORD *)(this + 96);
      *(_DWORD *)(this + 180) = v8;
      *(_DWORD *)(this + 128) = 0;
      *(_DWORD *)(this + 184) = 2;
LABEL_29:
      *(_DWORD *)(this + 132) = 0;
      *(_DWORD *)(this + 188) = 0;
LABEL_30:
      if ( *(float *)(this + 136) >= (double)*v5 )
      {
        if ( *(float *)(this + 136) <= (double)*v5 )
          goto LABEL_37;
        v25 = *(float *)(this + 136) - a2;
        if ( v25 < *v5 )
          goto LABEL_35;
      }
      else
      {
        v25 = a2 + *(float *)(this + 136);
        if ( v25 > *v5 )
LABEL_35:
          v25 = *v5;
      }
      *(float *)(this + 136) = v25;
LABEL_37:
      if ( *(float *)(this + 140) >= (double)*(float *)(this + 164) )
      {
        if ( *(float *)(this + 140) <= (double)*(float *)(this + 164) )
          goto LABEL_44;
        v26 = *(float *)(this + 140) - a2;
        if ( v26 < *(float *)(this + 164) )
          goto LABEL_42;
      }
      else
      {
        v26 = a2 + *(float *)(this + 140);
        if ( v26 > *(float *)(this + 164) )
LABEL_42:
          v26 = *(float *)(this + 164);
      }
      *(float *)(this + 140) = v26;
LABEL_44:
      if ( *(float *)(this + 144) >= (double)*(float *)(this + 168) )
      {
        if ( *(float *)(this + 144) <= (double)*(float *)(this + 168) )
          goto LABEL_51;
        v27 = *(float *)(this + 144) - a2;
        if ( v27 < *(float *)(this + 168) )
          goto LABEL_49;
      }
      else
      {
        v27 = a2 + *(float *)(this + 144);
        if ( v27 > *(float *)(this + 168) )
LABEL_49:
          v27 = *(float *)(this + 168);
      }
      *(float *)(this + 144) = v27;
LABEL_51:
      if ( *(float *)(this + 148) >= (double)*v7 )
      {
        if ( *(float *)(this + 148) <= (double)*v7 )
          goto LABEL_58;
        v28 = *(float *)(this + 148) - a2;
        if ( v28 < *v7 )
          goto LABEL_56;
      }
      else
      {
        v28 = a2 + *(float *)(this + 148);
        if ( v28 > *v7 )
LABEL_56:
          v28 = *v7;
      }
      *(float *)(this + 148) = v28;
LABEL_58:
      if ( *(float *)(this + 152) >= (double)*(float *)(this + 176) )
      {
        if ( *(float *)(this + 152) <= (double)*(float *)(this + 176) )
          goto LABEL_65;
        v29 = *(float *)(this + 152) - a2;
        if ( v29 < *(float *)(this + 176) )
          goto LABEL_63;
      }
      else
      {
        v29 = a2 + *(float *)(this + 152);
        if ( v29 > *(float *)(this + 176) )
LABEL_63:
          v29 = *(float *)(this + 176);
      }
      *(float *)(this + 152) = v29;
LABEL_65:
      if ( *(float *)(this + 156) >= (double)*(float *)(this + 180) )
      {
        if ( *(float *)(this + 156) <= (double)*(float *)(this + 180) )
        {
LABEL_72:
          *(float *)(this + 200) = *(float *)(this + 128) * 0.050000001;
          *(float *)(this + 204) = *(float *)(this + 132) * 0.029999999;
          sub_5DA7A0(&v31, &v32, &v33);
          v34 = *(float *)(this + 136) - v31;
          v35 = *(float *)(this + 140) - v32;
          v36 = *(float *)(this + 144) - v33 - *(float *)(this + 200);
          sub_5C1620(&v34);
          v34 = *(float *)(this + 148) - v31;
          v35 = *(float *)(this + 152) - v32;
          v36 = *(float *)(this + 156) - v33 - *(float *)(this + 204);
          return sub_5C1620(&v34);
        }
        v30 = *(float *)(this + 156) - a2;
        if ( v30 < *(float *)(this + 180) )
          goto LABEL_70;
      }
      else
      {
        v30 = a2 + *(float *)(this + 156);
        if ( v30 > *(float *)(this + 180) )
LABEL_70:
          v30 = *(float *)(this + 180);
      }
      *(float *)(this + 156) = v30;
      goto LABEL_72;
    }
    if ( *(float *)(this + 16) <= 0.0 )
    {
      v5 = (float *)(this + 160);
      if ( *(_DWORD *)(this + 188) != 1 )
      {
        v21 = *(float *)(this + 192);
        *v5 = *(float *)(this + 104);
        v22 = *(_DWORD *)(this + 112);
        *(_DWORD *)(this + 164) = *(_DWORD *)(this + 108);
        *(_DWORD *)(this + 168) = v22;
        v23 = *(_DWORD *)(this + 92);
        v7 = (float *)(this + 172);
        *v5 = v21 + *v5;
        *(_DWORD *)(this + 172) = v23;
        v24 = *(_DWORD *)(this + 100);
        *(_DWORD *)(this + 176) = *(_DWORD *)(this + 96);
        *(_DWORD *)(this + 180) = v24;
        v11 = *(_DWORD *)(this + 20);
        *(_DWORD *)(this + 184) = 1;
        goto LABEL_28;
      }
      *v5 = *(float *)(this + 116);
      v19 = *(_DWORD *)(this + 124);
      *(_DWORD *)(this + 164) = *(_DWORD *)(this + 120);
      *(_DWORD *)(this + 168) = v19;
      v7 = (float *)(this + 172);
      *(_DWORD *)(this + 172) = *(_DWORD *)(this + 104);
      v20 = *(_DWORD *)(this + 112);
      *(_DWORD *)(this + 176) = *(_DWORD *)(this + 108);
      *(_DWORD *)(this + 180) = v20;
      *(_DWORD *)(this + 128) = 0;
    }
    else
    {
      if ( *(float *)(this + 20) <= 0.0
        || *(float *)(this + 24) < (double)*(float *)(this + 16)
        && *(float *)(this + 28) > (double)*(float *)(this + 20)
        && !*(_DWORD *)(this + 188) )
      {
        v5 = (float *)(this + 160);
        *(_DWORD *)(this + 160) = *(_DWORD *)(this + 116);
        v9 = *(_DWORD *)(this + 124);
        *(_DWORD *)(this + 164) = *(_DWORD *)(this + 120);
        *(_DWORD *)(this + 168) = v9;
        v7 = (float *)(this + 172);
        *(_DWORD *)(this + 172) = *(_DWORD *)(this + 92);
        v10 = *(_DWORD *)(this + 100);
        *(_DWORD *)(this + 176) = *(_DWORD *)(this + 96);
        *(_DWORD *)(this + 180) = v10;
        v11 = *(_DWORD *)(this + 16);
        *(_DWORD *)(this + 184) = 2;
LABEL_28:
        *(_DWORD *)(this + 128) = v11;
        goto LABEL_29;
      }
      if ( *(float *)(this + 28) < (double)*(float *)(this + 20)
        && *(float *)(this + 24) > (double)*(float *)(this + 16)
        && !*(_DWORD *)(this + 188) )
      {
        v12 = *(float *)(this + 192);
        v5 = (float *)(this + 160);
        *(_DWORD *)(this + 160) = *(_DWORD *)(this + 104);
        v13 = *(_DWORD *)(this + 112);
        *(_DWORD *)(this + 164) = *(_DWORD *)(this + 108);
        *(_DWORD *)(this + 168) = v13;
        v14 = *(_DWORD *)(this + 92);
        v7 = (float *)(this + 172);
        *(float *)(this + 160) = v12 + *(float *)(this + 160);
        *(_DWORD *)(this + 172) = v14;
        v15 = *(_DWORD *)(this + 100);
        *(_DWORD *)(this + 176) = *(_DWORD *)(this + 96);
        *(_DWORD *)(this + 180) = v15;
        *(_DWORD *)(this + 128) = *(_DWORD *)(this + 20);
        *(_DWORD *)(this + 184) = 1;
        goto LABEL_29;
      }
      v5 = (float *)(this + 160);
      *(_DWORD *)(this + 160) = *(_DWORD *)(this + 116);
      v16 = *(_DWORD *)(this + 124);
      *(_DWORD *)(this + 164) = *(_DWORD *)(this + 120);
      *(_DWORD *)(this + 168) = v16;
      v7 = (float *)(this + 172);
      *(_DWORD *)(this + 172) = *(_DWORD *)(this + 104);
      v17 = *(_DWORD *)(this + 112);
      *(_DWORD *)(this + 176) = *(_DWORD *)(this + 108);
      *(_DWORD *)(this + 180) = v17;
      *(_DWORD *)(this + 128) = *(_DWORD *)(this + 16);
    }
    v18 = *(float *)(this + 196) + *v7;
    *(_DWORD *)(this + 132) = *(_DWORD *)(this + 20);
    *(_DWORD *)(this + 184) = 2;
    *(_DWORD *)(this + 188) = 1;
    *v7 = v18;
    goto LABEL_30;
  }
  return result;
}
