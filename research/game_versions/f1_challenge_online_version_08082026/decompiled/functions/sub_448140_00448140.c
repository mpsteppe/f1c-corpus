int __thiscall sub_448140(float *this, int a2)
{
  int *v3; // edi
  const char *v4; // eax
  int v5; // eax
  int v6; // eax
  double v7; // st7
  float *v8; // ecx
  double v9; // st6
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // ebp
  int i; // edi
  int result; // eax
  LPVOID v16[2]; // [esp+Ch] [ebp-118h] BYREF
  int v17; // [esp+14h] [ebp-110h]
  int v18; // [esp+18h] [ebp-10Ch]
  char v19; // [esp+1Ch] [ebp-108h]
  float v20; // [esp+20h] [ebp-104h]
  _BYTE v21[256]; // [esp+24h] [ebp-100h] BYREF

  *(_DWORD *)this = a2;
  v3 = (int *)dword_8AC4C4;
  if ( dword_8AC4C4 )
  {
    v16[0] = 0;
    v16[1] = (LPVOID)-1;
    sub_566650(&byte_5EA438);
    v4 = (const char *)dword_5EC3E0;
    v17 = -1;
    v18 = -1;
    v19 = 0;
    if ( !dword_5EC3E0 )
      v4 = &byte_5EA438;
    sub_58969D(v21, 256, "%sAmbient\\helicopter.wav", v4);
    sub_566650(v21);
    v5 = *v3;
    v17 = -1;
    v18 = -1;
    v19 = 0;
    v6 = (*(int (__thiscall **)(int *, LPVOID *, int, _DWORD))(v5 + 92))(v3, v16, 1, 0);
    *((_DWORD *)this + 1) = v6;
    if ( v6 )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 20))(v6);
      v7 = flt_7CF5C0;
      v8 = (float *)*((_DWORD *)this + 1);
      v20 = *(float *)&dword_7CF5E4;
      if ( flt_7CF59C > 0.0 )
        v9 = 1.0 / flt_7CF59C;
      else
        v9 = 1.0;
      v8[7] = v9;
      v8[8] = 1.0 - v9 * v20;
      v8[9] = v7;
    }
    if ( v16[0] )
      sub_587BCF(v16[0]);
  }
  v10 = sub_54C230(0);
  if ( v10 )
  {
    v11 = *(_DWORD *)(v10 + 316);
    *((_DWORD *)this + 3) = v11;
    if ( v11 )
    {
      v12 = *(_DWORD *)(v11 + 28);
      if ( v12 )
        this[2] = *(float *)(v12 + 8);
    }
    v13 = sub_54C210(*(_DWORD *)this);
    for ( i = 0; i < v13; ++i )
    {
      sub_54C230(i);
      sub_551800(*((_DWORD *)this + 3));
    }
  }
  sub_545F40(dword_8AFE88);
  result = sub_548890(aHeli);
  *((_DWORD *)this + 4) = result;
  if ( result )
    return sub_550620(result, 0);
  return result;
}
