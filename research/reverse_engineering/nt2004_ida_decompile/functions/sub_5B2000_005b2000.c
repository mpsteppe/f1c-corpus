int __thiscall sub_5B2000(_DWORD *this, char *String, _DWORD *a3, _DWORD *a4)
{
  char *v4; // edi
  _DWORD *v5; // esi
  int v7; // ebp
  bool v8; // zf
  float v9; // [esp+0h] [ebp-284h]
  float v10; // [esp+4h] [ebp-280h]
  float v11; // [esp+8h] [ebp-27Ch]
  float v12; // [esp+8h] [ebp-27Ch]
  float v13; // [esp+8h] [ebp-27Ch]
  float v14; // [esp+Ch] [ebp-278h]
  float v15; // [esp+Ch] [ebp-278h]
  float v16; // [esp+Ch] [ebp-278h]
  float v17; // [esp+10h] [ebp-274h]
  float v18; // [esp+10h] [ebp-274h]
  int v19; // [esp+24h] [ebp-260h] BYREF
  float v20; // [esp+28h] [ebp-25Ch] BYREF
  float v21; // [esp+2Ch] [ebp-258h] BYREF
  int v22; // [esp+30h] [ebp-254h] BYREF
  int v23; // [esp+34h] [ebp-250h] BYREF
  int v24; // [esp+38h] [ebp-24Ch] BYREF
  int v25; // [esp+3Ch] [ebp-248h] BYREF
  float v26; // [esp+40h] [ebp-244h] BYREF
  int v27; // [esp+44h] [ebp-240h]
  int v28; // [esp+48h] [ebp-23Ch] BYREF
  int v29; // [esp+4Ch] [ebp-238h] BYREF
  int v30; // [esp+50h] [ebp-234h]
  float v31; // [esp+54h] [ebp-230h] BYREF
  _DWORD *v32; // [esp+58h] [ebp-22Ch]
  float v33; // [esp+5Ch] [ebp-228h] BYREF
  int v34; // [esp+60h] [ebp-224h] BYREF
  float v35; // [esp+64h] [ebp-220h] BYREF
  int v36; // [esp+68h] [ebp-21Ch] BYREF
  int v37; // [esp+6Ch] [ebp-218h] BYREF
  int v38; // [esp+70h] [ebp-214h] BYREF
  int v39; // [esp+74h] [ebp-210h] BYREF
  int v40; // [esp+78h] [ebp-20Ch] BYREF
  int v41; // [esp+7Ch] [ebp-208h] BYREF
  int v42; // [esp+80h] [ebp-204h] BYREF
  char v43[256]; // [esp+84h] [ebp-200h] BYREF
  char v44[256]; // [esp+184h] [ebp-100h] BYREF

  v4 = String;
  v30 = 0;
  v27 = 0;
  v5 = this;
  v32 = this;
  if ( sub_597100(this, &v19, String) )
    return -1;
  v31 = 0.0;
  v33 = 0.0;
  v35 = 0.0;
  v26 = 0.0;
  *(float *)&v24 = 0.0;
  *(float *)&v25 = 0.0;
  *(float *)&v23 = 0.0;
  *(float *)&v22 = 0.0;
  v20 = 0.0;
  v21 = 0.0;
  v34 = 72;
  v28 = 72;
  v29 = 72;
  v7 = 32;
  if ( sub_5B1A10(a4) != 1 )
  {
    while ( *a4 != 3 )
    {
      if ( *a4 != 2 )
      {
        if ( sub_5B1DC0((int)a4, aView, v4, 0) && sub_5B2000(v4, v19, (int)a4) )
          return -1;
        sub_5B1F50((int)a4, off_6110A4, (float *)&v25, (float *)&v24, &v26, 0);
        sub_5B1F50((int)a4, off_5FFA3C, (float *)&v41, (float *)&v36, 0, 0);
        sub_5B1EA0((int)a4, EndPtr, &v29, &v28, &v34, 0);
        sub_5B1F50((int)a4, aClipplanes, (float *)&v42, (float *)&v39, 0, 0);
        if ( sub_5B1F50((int)a4, aOrient, &v35, &v33, &v31, 0) )
          v27 = 1;
        if ( sub_5B1F50((int)a4, off_61BD64, (float *)&v40, (float *)&v38, (float *)&v37, 0) )
          v27 = 2;
        if ( sub_5B1F50((int)a4, aSize, &v21, &v20, 0, 0) )
        {
          if ( v21 <= 1.0 )
            v21 = (double)dword_7E8CE8 * v21;
          if ( v20 <= 1.0 )
            v20 = (double)dword_7E8CEC * v20;
        }
        if ( sub_5B1F50((int)a4, aCenter, (float *)&v22, (float *)&v23, 0, 0) )
        {
          if ( *(float *)&v22 <= 1.0 )
            *(float *)&v22 = (double)dword_7E8CE8 * *(float *)&v22;
          if ( *(float *)&v23 <= 1.0 )
            *(float *)&v23 = (double)dword_7E8CEC * *(float *)&v23;
        }
        if ( sub_5B1DC0((int)a4, aClear_0, v43, 0) )
        {
          v5 = v32;
          if ( !strcmp(v43, aTrue) )
            v7 |= 2u;
          else
            v7 &= ~2u;
        }
        if ( sub_5B1DC0((int)a4, aBgmap, v44, 0) )
          v30 = 1;
        sub_5B1DC0((int)a4, aSeparatesurfac, v43, 0);
        v4 = String;
      }
      if ( sub_5B1A10(a4) == 1 )
        break;
    }
    if ( v30 && sub_5922A0((void **)(v19 + 608), (int)v44, 0, 1) )
      return -1;
  }
  sub_593AF0((_DWORD *)v19, 0);
  v10 = *(float *)&v23 - v20 * 0.5;
  v9 = *(float *)&v22 - v21 * 0.5;
  sub_593B30(v19, v9, v10, v21, v20, 0);
  v14 = *(float *)&v36 * 0.01745433;
  v11 = *(float *)&v41 * 0.01745433;
  sub_593820(v19, v11, v14, 0);
  sub_593D20(v19, v42, v39);
  sub_593D50((_DWORD *)v19, v29, v28, v34);
  v8 = v27 == 2;
  *(_DWORD *)(v19 + 128) = v7;
  if ( v8 )
  {
    v17 = -v26;
    v15 = -*(float *)&v24;
    v12 = -*(float *)&v25;
    sub_5934E0(v19, v12, v15, v17);
    v18 = -(*(float *)&v37 + v26);
    v16 = -(*(float *)&v38 + *(float *)&v24);
    v13 = -(*(float *)&v40 + *(float *)&v25);
    sub_593730((float *)v19, v13, v16, v18);
  }
  else
  {
    sub_5934A0(v25, v24, v26, v35, v33, v31);
  }
  if ( a3 )
    sub_593120(a3, (_DWORD *)v19);
  else
    sub_5972A0(v5, v19);
  return 0;
}
