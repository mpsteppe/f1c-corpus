int __thiscall sub_4A04EA(int *this, int *a2, int *a3, int *a4, int *a5)
{
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  _DWORD *v9; // eax
  int v10; // ebp
  int v11; // ebx
  int v12; // esi
  int v13; // ebp
  int v14; // ecx
  int *v15; // esi
  int *v16; // ebx
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // edx
  int v21; // eax
  int v23; // [esp+Ch] [ebp-1Ch]
  int v24; // [esp+10h] [ebp-18h] BYREF
  int v25; // [esp+14h] [ebp-14h] BYREF
  int v26; // [esp+18h] [ebp-10h] BYREF
  int v27; // [esp+1Ch] [ebp-Ch] BYREF
  int v28; // [esp+20h] [ebp-8h]
  int v29; // [esp+24h] [ebp-4h]

  v6 = this[1];
  v7 = this[2];
  v28 = v6;
  v8 = this[99];
  v29 = v7;
  if ( v8 > 0 && (v9 = (_DWORD *)sub_49CB60(this, 3)) != 0 )
  {
    v23 = v9[3] - v9[2];
    v10 = v9[1] - *v9;
    v11 = sub_49D770(this, 0);
    v12 = this[95] + sub_49D7F0(this, 0);
    if ( v12 < v28 )
      v12 = v28;
    if ( v12 > v29 - v23 )
      v12 = v29 - v23;
    v13 = v11 + v10;
    v29 = v12 + v23;
    sub_49D330(this, 3, 0, v12, v12 + v23, v11, v13);
    v14 = v12 + v23;
    *a2 = v12;
    v15 = a3;
    *a3 = v14;
    *a4 = v11;
    v16 = a5;
    *a5 = v13;
  }
  else
  {
    v16 = a5;
    v15 = a3;
  }
  v25 = 0;
  v27 = 0;
  v17 = *this;
  v24 = 600;
  v26 = 800;
  (*(void (__thiscall **)(int *, int *, int *, int *, int *))(v17 + 160))(this, &v24, &v25, &v26, &v27);
  v18 = *a2;
  if ( *a2 >= v24 )
    v18 = v24;
  *a2 = v18;
  v19 = *v15;
  if ( *v15 <= v25 )
    v19 = v25;
  v20 = v26;
  *v15 = v19;
  v21 = *a4;
  if ( *a4 >= v20 )
    v21 = v20;
  *a4 = v21;
  if ( *v16 <= v27 )
    *v16 = v27;
  else
    *v16 = *v16;
  return 0;
}
