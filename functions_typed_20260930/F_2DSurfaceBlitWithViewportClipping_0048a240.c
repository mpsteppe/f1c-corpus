int __thiscall F_2DSurfaceBlitWithViewportClipping(_DWORD *this, int a2, int *a3, int *a4, int a5)
{
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  _DWORD *v9; // eax
  int v10; // ebp
  int v11; // ebp
  int v12; // ebx
  int v13; // esi
  int **v14; // eax
  int *v15; // ebp
  int v16; // ecx
  int *v17; // edx
  int v18; // eax
  int *v19; // esi
  _DWORD *v20; // ebx
  int v21; // eax
  int *v22; // ecx
  int *v23; // eax
  int *v24; // ecx
  int v25; // edx
  int v26; // eax
  int v28; // [esp+10h] [ebp-Ch] BYREF
  int v29; // [esp+14h] [ebp-8h]
  int v30; // [esp+18h] [ebp-4h]

  v6 = this[1];
  v7 = this[2];
  v29 = v6;
  v8 = this[88];
  v30 = v7;
  if ( v8 > 0 && (v9 = (_DWORD *)ConditionalDelegation_6460(this, 3)) != 0 )
  {
    v10 = v9[3];
    v28 = v9[1] - *v9;
    v11 = v10 - v9[2];
    v12 = sub_487060(this, 0);
    v13 = this[84] + sub_4870E0(this, 0);
    if ( v13 < v29 )
      v13 = v29;
    if ( v13 > v30 - v11 )
      v13 = v30 - v11;
    v30 = v13 + v11;
    v29 = v12 + v28;
    ScrollbarAreaRendering(this, 3, 0, v13, v13 + v11, v12, v12 + v28);
    v14 = (int **)Accessor();
    RenderSurfaceFillCopy(v14, v12, v13, v28, v11);
    v15 = (int *)a2;
    v16 = v30;
    v17 = a4;
    v18 = v12 + v28;
    *(_DWORD *)a2 = v13;
    v19 = a3;
    *a3 = v16;
    *v17 = v12;
    v20 = (_DWORD *)a5;
    *(_DWORD *)a5 = v18;
  }
  else
  {
    v20 = (_DWORD *)a5;
    v19 = a3;
    v15 = (int *)a2;
  }
  a3 = 0;
  v28 = 0;
  a5 = 600;
  a2 = 800;
  UICustomRenderDispatch((int)this, v15, &a5, (int *)&a3, &a2, &v28);
  v21 = *v15;
  if ( *v15 >= a5 )
    v21 = a5;
  v22 = a3;
  *v15 = v21;
  v23 = (int *)*v19;
  if ( *v19 <= (int)v22 )
    v23 = v22;
  v24 = a4;
  v25 = a2;
  *v19 = (int)v23;
  v26 = *v24;
  if ( *v24 >= v25 )
    v26 = v25;
  *v24 = v26;
  if ( *v20 <= v28 )
    *v20 = v28;
  else
    *v20 = *v20;
  return 0;
}

