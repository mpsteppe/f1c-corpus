int __thiscall sub_55A060(_DWORD *this, const char *a2, _DWORD *a3, _DWORD *a4)
{
  const CHAR *v4; // edi
  _DWORD *v5; // esi
  int v7; // ebp
  bool v8; // zf
  float v9; // [esp+0h] [ebp-284h]
  float v10; // [esp+4h] [ebp-280h]
  float v11; // [esp+8h] [ebp-27Ch]
  float v12; // [esp+8h] [ebp-27Ch]
  int v13; // [esp+8h] [ebp-27Ch]
  float v14; // [esp+Ch] [ebp-278h]
  float v15; // [esp+Ch] [ebp-278h]
  float v16; // [esp+Ch] [ebp-278h]
  float v17; // [esp+10h] [ebp-274h]
  float v18; // [esp+10h] [ebp-274h]
  float *v19; // [esp+24h] [ebp-260h] BYREF
  float v20; // [esp+28h] [ebp-25Ch] BYREF
  float v21; // [esp+2Ch] [ebp-258h] BYREF
  float v22; // [esp+30h] [ebp-254h] BYREF
  float v23; // [esp+34h] [ebp-250h] BYREF
  int v24; // [esp+38h] [ebp-24Ch] BYREF
  int v25; // [esp+3Ch] [ebp-248h] BYREF
  float v26; // [esp+40h] [ebp-244h] BYREF
  int v27; // [esp+44h] [ebp-240h]
  int v28; // [esp+48h] [ebp-23Ch] BYREF
  int v29; // [esp+4Ch] [ebp-238h] BYREF
  int v30; // [esp+50h] [ebp-234h]
  int v31; // [esp+54h] [ebp-230h] BYREF
  _DWORD *v32; // [esp+58h] [ebp-22Ch]
  int v33; // [esp+5Ch] [ebp-228h] BYREF
  int v34; // [esp+60h] [ebp-224h] BYREF
  int v35; // [esp+64h] [ebp-220h] BYREF
  float v36; // [esp+68h] [ebp-21Ch] BYREF
  float v37; // [esp+6Ch] [ebp-218h] BYREF
  float v38; // [esp+70h] [ebp-214h] BYREF
  int v39; // [esp+74h] [ebp-210h] BYREF
  float v40; // [esp+78h] [ebp-20Ch] BYREF
  float v41; // [esp+7Ch] [ebp-208h] BYREF
  int v42; // [esp+80h] [ebp-204h] BYREF
  char v43[256]; // [esp+84h] [ebp-200h] BYREF
  CHAR v44[256]; // [esp+184h] [ebp-100h] BYREF

  v4 = a2;
  v30 = 0;
  v27 = 0;
  v5 = this;
  v32 = this;
  if ( sub_544E90(this, &v19, a2) )
    return -1;
  v31 = 0;
  v33 = 0;
  v35 = 0;
  v26 = 0.0;
  *(float *)&v24 = 0.0;
  *(float *)&v25 = 0.0;
  v23 = 0.0;
  v22 = 0.0;
  v20 = 0.0;
  v21 = 0.0;
  v34 = 72;
  v28 = 72;
  v29 = 72;
  v7 = 32;
  if ( sub_559A70(a4) != 1 )
  {
    while ( *a4 != 3 )
    {
      if ( *a4 != 2 )
      {
        if ( sub_559E20((int)a4, (int)aView, v4, 0) && sub_55A060(v4, v19, a4) )
          return -1;
        sub_559FB0(a4, (int)&off_5DC230, (float *)&v25, (float *)&v24, &v26, 0);
        sub_559FB0(a4, (int)&off_5C57FC, &v41, &v36, 0, 0);
        sub_559F00(a4, (int)aColor, &v29, &v28, &v34, 0);
        sub_559FB0(a4, (int)aClipplanes, (float *)&v42, (float *)&v39, 0, 0);
        if ( sub_559FB0(a4, (int)aOrient, (float *)&v35, (float *)&v33, (float *)&v31, 0) )
          v27 = 1;
        if ( sub_559FB0(a4, (int)aDir, &v40, &v38, &v37, 0) )
          v27 = 2;
        if ( sub_559FB0(a4, (int)aSize, &v21, &v20, 0, 0) )
        {
          if ( v21 <= 1.0 )
            v21 = (double)dword_8B8DD4 * v21;
          if ( v20 <= 1.0 )
            v20 = (double)dword_8B8DD8 * v20;
        }
        if ( sub_559FB0(a4, (int)aCenter, &v22, &v23, 0, 0) )
        {
          if ( v22 <= 1.0 )
            v22 = (double)dword_8B8DD4 * v22;
          if ( v23 <= 1.0 )
            v23 = (double)dword_8B8DD8 * v23;
        }
        if ( sub_559E20((int)a4, (int)aClear, v43, 0) )
        {
          v5 = v32;
          if ( !strcmp(v43, aTrue) )
            v7 |= 2u;
          else
            v7 &= ~2u;
        }
        if ( sub_559E20((int)a4, (int)aBgmap, v44, 0) )
          v30 = 1;
        sub_559E20((int)a4, (int)aSeparatesurfac, v43, 0);
        v4 = a2;
      }
      if ( sub_559A70(a4) == 1 )
        break;
    }
    if ( v30 && sub_53CB20((int *)v19 + 104, (int)v44, 0, 1) )
      return -1;
  }
  v14 = v36 * 0.01745433;
  v11 = v41 * 0.01745433;
  sub_542050((int)v19, v11, v14, 0);
  v10 = v23 - v20 * 0.5;
  v9 = v22 - v21 * 0.5;
  sub_542200((int)v19, v9, v10, v21, v20, 0);
  sub_5423C0((int)v19, v42, v39);
  sub_5423E0(v19, v29, v28, v34);
  v8 = v27 == 2;
  *((_DWORD *)v19 + 32) = v7;
  if ( v8 )
  {
    v17 = -v26;
    v15 = -*(float *)&v24;
    v12 = -*(float *)&v25;
    sub_541D10((int)v19, v12, v15, v17);
    v18 = -(v37 + v26);
    v16 = -(v38 + *(float *)&v24);
    *(float *)&v13 = -(v40 + *(float *)&v25);
    sub_541F60(v19, v13, v16, v18);
  }
  else
  {
    sub_541CD0(v25, v24, v26, *(float *)&v35, *(float *)&v33, *(float *)&v31);
  }
  if ( a3 )
    sub_5419D0(a3, v19);
  else
    sub_545030(v5, (int)v19);
  return 0;
}
