int __thiscall sub_5B8280(int this, _DWORD *a2, int a3)
{
  int v4; // eax
  bool v5; // zf
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  double v8; // st7
  _DWORD *v9; // eax
  long double v10; // st7
  _DWORD *v11; // eax
  double *v12; // eax
  _DWORD *v13; // eax
  _DWORD *v14; // eax
  _DWORD *v16; // eax
  _DWORD *v17; // eax
  double v18; // st7
  _DWORD *v19; // eax
  long double v20; // st7
  _DWORD *v21; // eax
  double *v22; // eax
  _DWORD *v23; // eax
  _DWORD *v24; // eax
  _DWORD *v25; // eax
  float v26; // [esp+0h] [ebp-128h]
  float v27; // [esp+0h] [ebp-128h]
  int v28; // [esp+4h] [ebp-124h]
  float v29; // [esp+4h] [ebp-124h]
  int v30; // [esp+4h] [ebp-124h]
  float v31; // [esp+4h] [ebp-124h]
  int v32; // [esp+8h] [ebp-120h]
  int v33; // [esp+8h] [ebp-120h]
  float v34; // [esp+18h] [ebp-110h]
  float v35; // [esp+18h] [ebp-110h]
  float v36; // [esp+18h] [ebp-110h]
  float v37; // [esp+18h] [ebp-110h]
  float v38; // [esp+1Ch] [ebp-10Ch] BYREF
  float v39; // [esp+20h] [ebp-108h] BYREF
  float v40; // [esp+24h] [ebp-104h] BYREF
  char Buffer[256]; // [esp+28h] [ebp-100h] BYREF

  v4 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 28) + 312) + 64);
  if ( !v4 || !*(_DWORD *)(v4 + 560) )
  {
    if ( (*(_BYTE *)(this + 40) & 1) != 0 )
      goto LABEL_15;
    sprintf(Buffer, "SHADOWVIEW%.3d", *(_DWORD *)(this + 44));
    v16 = operator new(0x27Cu);
    if ( v16 )
      v17 = sub_592FE0(v16);
    else
      v17 = 0;
    *(_DWORD *)(this + 16) = v17;
    *v17 = a2;
    sub_593010(*(_DWORD *)(this + 16), Buffer);
    sub_593AF0(*(_DWORD **)(this + 16), 1u);
    v18 = *(float *)(*(_DWORD *)(this + 28) + 24) + *(float *)(*(_DWORD *)(this + 28) + 24);
    *(float *)&v33 = flt_61C20C + v18;
    *(float *)&v30 = flt_61C20C - v18;
    sub_593D20(*(_DWORD *)(this + 16), v30, v33);
    sub_593D50(*(_DWORD **)(this + 16), 0, 0, 0);
    v19 = (_DWORD *)sub_597AE0(a2, 0);
    sub_5B5C30(v19, &v38, &v39, &v40);
    v31 = atan2(-v38, v40);
    v27 = asin(v39);
    sub_593580(*(_DWORD *)(this + 16), v27, v31, 0.0);
    v20 = fabs(atan2(*(float *)(*(_DWORD *)(this + 28) + 24) * 1.2, flt_61C20C));
    v36 = v20 + v20;
    sub_593820(*(_DWORD *)(this + 16), v36, v36, 1);
    v37 = (float)dword_7E8D08;
    sub_593B30(*(_DWORD *)(this + 16), 0.0, 0.0, v37, v37, 1);
    v21 = operator new(0x4Cu);
    if ( v21 )
      v22 = (double *)sub_5AC560(v21);
    else
      v22 = 0;
    *(_DWORD *)(this + 32) = v22;
    sub_5AC5A0(v22, 1);
    v23 = operator new(8u);
    if ( v23 )
      v24 = sub_5B81D0(v23, 384);
    else
      v24 = 0;
    *(_DWORD *)(this + 36) = v24;
    v25 = operator new(0x24u);
    if ( v25 )
    {
      v25[5] = 0;
      v25[4] = 0;
      v25[3] = 0;
      v25[2] = 0;
      v25[1] = 0;
      *v25 = 0;
      v25[7] = 0;
      v25[6] = 0;
      v25[8] = 0;
    }
    else
    {
      v25 = 0;
    }
    *(_DWORD *)(this + 12) = v25;
    *v25 = 34;
    *(_DWORD *)(*(_DWORD *)(this + 12) + 12) = 1152;
    *(_DWORD *)(*(_DWORD *)(this + 12) + 4) = 66;
    *(_DWORD *)(*(_DWORD *)(this + 12) + 8) = 16;
    if ( sub_5A7F10(dword_7E6B48, *(int **)(this + 12)) )
    {
      sub_591C60(
        this,
        -1,
        "Error creating shadow vertex buffer for instance %s",
        *(const char **)(*(_DWORD *)(this + 28) + 312));
      return -1;
    }
    goto LABEL_14;
  }
  v5 = (*(_BYTE *)(this + 40) & 1) == 0;
  *(_DWORD *)(this + 40) |= 4u;
  if ( v5 )
  {
    sprintf(Buffer, "SHADOWVIEW%.3d", *(_DWORD *)(this + 44));
    v6 = operator new(0x27Cu);
    if ( v6 )
      v7 = sub_592FE0(v6);
    else
      v7 = 0;
    *(_DWORD *)(this + 16) = v7;
    *v7 = a2;
    sub_593010(*(_DWORD *)(this + 16), Buffer);
    sub_593AF0(*(_DWORD **)(this + 16), 1u);
    v8 = *(float *)(*(_DWORD *)(this + 28) + 24) + *(float *)(*(_DWORD *)(this + 28) + 24);
    *(float *)&v32 = flt_61C20C + v8;
    *(float *)&v28 = flt_61C20C - v8;
    sub_593D20(*(_DWORD *)(this + 16), v28, v32);
    sub_593D50(*(_DWORD **)(this + 16), 0, 0, 0);
    v9 = (_DWORD *)sub_597AE0(a2, 0);
    sub_5B5C30(v9, &v38, &v39, &v40);
    v29 = atan2(-v38, v40);
    v26 = asin(v39);
    sub_593580(*(_DWORD *)(this + 16), v26, v29, 0.0);
    v10 = fabs(atan2(*(float *)(*(_DWORD *)(this + 28) + 24) * 1.2, flt_61C20C));
    v34 = v10 + v10;
    sub_593820(*(_DWORD *)(this + 16), v34, v34, 1);
    v35 = (float)dword_7E8D08;
    sub_593B30(*(_DWORD *)(this + 16), 0.0, 0.0, v35, v35, 1);
    v11 = operator new(0x4Cu);
    if ( v11 )
      v12 = (double *)sub_5AC560(v11);
    else
      v12 = 0;
    *(_DWORD *)(this + 32) = v12;
    sub_5AC5A0(v12, 1);
    v13 = operator new(8u);
    if ( v13 )
      v14 = sub_5B81D0(v13, 384);
    else
      v14 = 0;
    *(_DWORD *)(this + 36) = v14;
LABEL_14:
    *(_DWORD *)(this + 40) |= 1u;
  }
LABEL_15:
  if ( *(_DWORD *)(this + 48) )
    sub_5B8280(a2, 1);
  if ( *(_DWORD *)(this + 56) )
  {
    if ( a3 )
      sub_5B8280(a2, 1);
  }
  return 0;
}
