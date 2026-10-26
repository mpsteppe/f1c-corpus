int __thiscall sub_5E66A0(int *this, _DWORD *a2)
{
  _DWORD *v3; // eax
  int *v4; // ecx
  int result; // eax
  _DWORD *v6; // ecx
  int v7; // eax
  void *v8; // eax
  int v9; // eax
  int v10; // [esp-20h] [ebp-4Ch]
  float v11; // [esp-14h] [ebp-40h]
  int v12; // [esp-Ch] [ebp-38h]
  int v13; // [esp-8h] [ebp-34h]
  int v14; // [esp+8h] [ebp-24h] BYREF
  int v15; // [esp+Ch] [ebp-20h] BYREF
  int v16; // [esp+10h] [ebp-1Ch] BYREF
  int v17; // [esp+14h] [ebp-18h] BYREF
  int v18; // [esp+18h] [ebp-14h] BYREF
  int v19; // [esp+1Ch] [ebp-10h] BYREF
  int v20; // [esp+28h] [ebp-4h]

  v3 = (_DWORD *)this[17];
  v4 = this + 17;
  if ( v3 )
  {
    while ( !*v3 || (_DWORD *)*v3 != a2 )
    {
      v3 = (_DWORD *)v3[1];
      if ( !v3 )
        goto LABEL_8;
    }
    if ( *v3 )
      sub_5DB630(v4, (int)a2, 0);
  }
LABEL_8:
  if ( a2[12] )
    sub_5EB310(this[12]);
  sub_5FDFB0(a2, 1);
  result = a2[11];
  *a2 &= ~4u;
  if ( !result )
  {
    v6 = (_DWORD *)this[13];
    v17 = 0;
    v18 = 0;
    v19 = 0;
    v14 = 0;
    v15 = -1082130432;
    v16 = 0;
    if ( v6 )
      sub_5DCE20(v6, &v14, &v15, &v16);
    v7 = this[12];
    if ( v7 )
      sub_5DA7A0(*(_DWORD **)(v7 + 392), &v17, &v18, &v19);
    v8 = operator new(0x140u);
    v20 = 0;
    if ( v8 )
      v9 = sub_6002C0(v8);
    else
      v9 = 0;
    a2[11] = v9;
    v13 = this[3];
    v12 = this[2];
    v11 = *(float *)(a2[12] + 20);
    v10 = this[15];
    v20 = -1;
    result = sub_5FFAF0(v9, v10, (int)&v17, (int)&v14, v11, 1167867904, v12, v13, 0);
    if ( !result )
    {
      *(_DWORD *)(a2[11] + 292) = 1022739087;
      result = *(_DWORD *)(a2[12] + 244);
      *(_DWORD *)(a2[11] + 236) = result;
    }
  }
  return result;
}
