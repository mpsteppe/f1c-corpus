int __thiscall sub_560C10(int this, _DWORD *a2, int a3)
{
  int v4; // eax
  bool v5; // zf
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  double *v8; // eax
  _DWORD *v9; // eax
  _DWORD *v10; // eax
  double v11; // st7
  double v12; // st7
  _DWORD *v13; // eax
  double v14; // st7
  int v15; // ecx
  long double v16; // st7
  _DWORD *v17; // eax
  float v19; // [esp+0h] [ebp-124h]
  int v20; // [esp+4h] [ebp-120h]
  float v21; // [esp+4h] [ebp-120h]
  int v22; // [esp+8h] [ebp-11Ch]
  float v23; // [esp+14h] [ebp-110h]
  float v24; // [esp+14h] [ebp-110h]
  float v25; // [esp+18h] [ebp-10Ch] BYREF
  float v26; // [esp+1Ch] [ebp-108h] BYREF
  float v27; // [esp+20h] [ebp-104h] BYREF
  char v28[256]; // [esp+24h] [ebp-100h] BYREF

  v4 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(this + 24) + 312) + 64);
  if ( !v4 || !*(_DWORD *)(v4 + 560) )
  {
    if ( (*(_BYTE *)(this + 36) & 1) != 0 )
      goto LABEL_17;
    sub_58815F(v28, "SHADOWVIEW%.3d", *(_DWORD *)(this + 40));
    v6 = (_DWORD *)sub_587C03(444);
    if ( !v6 )
    {
      v7 = 0;
      goto LABEL_13;
    }
    goto LABEL_11;
  }
  v5 = (*(_BYTE *)(this + 36) & 1) == 0;
  *(_DWORD *)(this + 36) |= 4u;
  if ( !v5 )
    goto LABEL_17;
  sub_58815F(v28, "SHADOWVIEW%.3d", *(_DWORD *)(this + 40));
  v6 = (_DWORD *)sub_587C03(444);
  if ( v6 )
  {
LABEL_11:
    v7 = sub_5418B0(v6);
    goto LABEL_13;
  }
  v7 = 0;
LABEL_13:
  *(_DWORD *)(this + 12) = v7;
  *v7 = a2;
  sub_5418E0(*(_DWORD *)(this + 12), v28);
  v11 = *(float *)(*(_DWORD *)(this + 24) + 24);
  v12 = v11 + v11;
  *(float *)&v22 = flt_5DD848 + v12;
  *(float *)&v20 = flt_5DD848 - v12;
  sub_5423C0(*(_DWORD *)(this + 12), v20, v22);
  sub_5423E0(*(_DWORD **)(this + 12), 0, 0, 0);
  v13 = (_DWORD *)sub_5457C0(a2, 0);
  sub_55D590(v13, &v25, &v26, &v27);
  v21 = atan2(-v25, v27);
  v14 = v26;
  sub_588570(v15);
  v19 = v14;
  sub_541DB0(*(_DWORD *)(this + 12), v19, v21, 0.0);
  v16 = fabs(atan2(*(float *)(*(_DWORD *)(this + 24) + 24) * 1.2, flt_5DD848));
  v23 = v16 + v16;
  sub_542050(*(_DWORD *)(this + 12), v23, v23, 1);
  v24 = (float)dword_8B8DF4;
  sub_542200(*(_DWORD *)(this + 12), 0.0, 0.0, v24, v24, 1);
  v17 = (_DWORD *)sub_587C03(76);
  if ( v17 )
    v8 = (double *)sub_556220(v17);
  else
    v8 = 0;
  *(_DWORD *)(this + 28) = v8;
  sub_556260(v8, 1u);
  v9 = (_DWORD *)sub_587C03(8);
  if ( v9 )
    v10 = sub_560B60(v9, 1024);
  else
    v10 = 0;
  *(_DWORD *)(this + 32) = v10;
  *(_DWORD *)(this + 36) |= 1u;
LABEL_17:
  if ( *(_DWORD *)(this + 44) )
    sub_560C10(a2, 1);
  if ( *(_DWORD *)(this + 52) && a3 )
    sub_560C10(a2, 1);
  return 0;
}
