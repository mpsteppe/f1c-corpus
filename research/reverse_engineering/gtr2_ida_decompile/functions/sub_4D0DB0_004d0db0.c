int __thiscall sub_4D0DB0(_DWORD *this, int *a2, int *a3, int *a4, _DWORD *a5)
{
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int *v9; // eax
  int v10; // edi
  int v11; // ebp
  int v12; // ebp
  int v13; // ebx
  int v14; // edi
  int v15; // ecx
  int *v16; // edi
  _DWORD *v17; // ebx
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // edx
  int v22; // eax
  int v24; // [esp+Ch] [ebp-30h]
  int v25; // [esp+20h] [ebp-1Ch] BYREF
  int v26; // [esp+24h] [ebp-18h] BYREF
  int v27; // [esp+28h] [ebp-14h] BYREF
  int v28; // [esp+2Ch] [ebp-10h] BYREF
  int v29; // [esp+30h] [ebp-Ch]
  int v30; // [esp+34h] [ebp-8h]
  int v31; // [esp+38h] [ebp-4h]

  v6 = this[1];
  v7 = this[2];
  v30 = v6;
  v8 = this[144];
  v31 = v7;
  if ( v8 > 0 && this[61] && (v9 = (int *)sub_4E29F0(3)) != 0 )
  {
    v10 = *v9;
    v11 = v9[1];
    v29 = v9[3] - v9[2];
    v12 = v11 - v10;
    v13 = sub_4CFCC0(this, 0);
    v14 = this[140] + sub_4CFD30(this, 0);
    if ( v14 < v30 )
      v14 = v30;
    if ( v14 > v31 - v29 )
      v14 = v31 - v29;
    v24 = v13 + v12;
    v31 = v14 + v29;
    sub_4CFB20();
    v15 = v14 + v29;
    *a2 = v14;
    v16 = a3;
    *a3 = v15;
    *a4 = v13;
    v17 = a5;
    *a5 = v24;
  }
  else
  {
    v17 = a5;
    v16 = a3;
  }
  v26 = 0;
  v28 = 0;
  v18 = *this;
  v25 = 600;
  v27 = 800;
  (*(void (__thiscall **)(_DWORD *, int *, int *, int *, int *))(v18 + 168))(this, &v25, &v26, &v27, &v28);
  (*(void (__thiscall **)(_DWORD *, int *, int *, int *, int *))(*this + 160))(this, &v25, &v26, &v27, &v28);
  v19 = *a2;
  if ( *a2 >= v25 )
    v19 = v25;
  *a2 = v19;
  v20 = *v16;
  if ( *v16 <= v26 )
    v20 = v26;
  v21 = v27;
  *v16 = v20;
  v22 = *a4;
  if ( *a4 >= v21 )
    v22 = v21;
  *a4 = v22;
  if ( *v17 <= v28 )
    *v17 = v28;
  else
    *v17 = *v17;
  return 0;
}
