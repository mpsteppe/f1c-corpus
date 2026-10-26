int __thiscall sub_48FEE0(_DWORD *this, int *a2, int *a3, int *a4, int *a5)
{
  const char *v6; // eax
  int v7; // ebx
  int v8; // ebp
  int v9; // edi
  char *v10; // eax
  char *v11; // eax
  int v12; // eax
  int v13; // edx
  int v14; // eax
  int v15; // eax
  int v16; // eax
  char *v17; // eax
  int v18; // eax
  char *v19; // eax
  int v20; // eax
  int v21; // eax
  char *v23; // eax
  int v24; // eax
  int v25; // edx
  int v26; // eax
  int v27; // [esp+10h] [ebp-Ch] BYREF
  int v28; // [esp+14h] [ebp-8h] BYREF
  int v29; // [esp+18h] [ebp-4h]

  v6 = (const char *)this[44];
  if ( !v6 )
    v6 = byte_5EA438;
  if ( !strlen(v6) )
    return 0;
  v27 = 0;
  v28 = 0;
  v7 = sub_487060(this, 2);
  v8 = sub_487060(this, 3);
  v9 = sub_4870E0(this, 2);
  v29 = sub_4870E0(this, 3);
  v10 = UIStringAccessor_62c0(this);
  if ( v10 )
    sub_498560(v10);
  v11 = (char *)this[44];
  if ( !v11 )
    v11 = byte_5EA438;
  TextRenderToSurface(v11, &v27, &v28, 1);
  v12 = *a2;
  if ( *a2 >= v9 )
    v12 = v9;
  v13 = v29;
  *a2 = v12;
  v14 = *a3;
  if ( *a3 <= v13 )
    v14 = v13;
  *a3 = v14;
  v15 = this[57];
  if ( !v15 )
  {
    v23 = (char *)this[44];
    if ( !v23 )
      v23 = byte_5EA438;
    BitmapDraw_81f0(v23, v9, v9 + v28, v7, v7 + v27, 1);
    v24 = *a4;
    if ( *a4 >= v7 )
      v24 = v7;
    v25 = v27;
    *a4 = v24;
    v26 = v7 + v25;
    if ( *a5 > v7 + v25 )
      v26 = *a5;
    *a5 = v26;
    return 0;
  }
  v16 = v15 - 1;
  if ( !v16 )
  {
    v19 = (char *)this[44];
    if ( !v19 )
      v19 = byte_5EA438;
    BitmapDraw(v19, v9, v9 + v28, v7, v8, 1);
    v20 = *a4;
    if ( *a4 >= v7 )
      v20 = v7;
    *a4 = v20;
    goto LABEL_25;
  }
  if ( v16 != 1 )
    return 0;
  v17 = (char *)this[44];
  if ( !v17 )
    v17 = byte_5EA438;
  BitmapDraw_81f0(v17, v9, v9 + v28, v8 - v27, v8, 1);
  v18 = v8 - v27;
  if ( *a4 < v8 - v27 )
    v18 = *a4;
  *a4 = v18;
LABEL_25:
  v21 = *a5;
  if ( *a5 <= v8 )
    v21 = v8;
  *a5 = v21;
  return 0;
}

