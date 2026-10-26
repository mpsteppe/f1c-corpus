int __thiscall sub_4B6250(int this)
{
  int result; // eax
  int v3; // eax
  double v4; // st7
  unsigned __int8 v6; // c0
  unsigned __int8 v7; // c3
  double v8; // st5
  unsigned __int8 v10; // c0
  unsigned __int8 v11; // c3
  double v12; // st5
  double v13; // st6
  long double v14; // st7
  long double v15; // st6
  int v16; // edi
  long double v17; // st7
  int v18; // ebx
  int v19; // ebp
  __int64 v20; // rax
  int v21; // ecx
  float v22; // [esp+0h] [ebp-44h]
  float v23; // [esp+0h] [ebp-44h]
  float v24; // [esp+0h] [ebp-44h]
  float v25; // [esp+0h] [ebp-44h]
  float v26; // [esp+4h] [ebp-40h]
  float v27; // [esp+4h] [ebp-40h]
  float v28; // [esp+4h] [ebp-40h]
  float v29; // [esp+4h] [ebp-40h]
  float v30; // [esp+28h] [ebp-1Ch]
  int v31; // [esp+28h] [ebp-1Ch]
  float v32; // [esp+2Ch] [ebp-18h]
  int v33; // [esp+2Ch] [ebp-18h]
  float v34; // [esp+30h] [ebp-14h]
  int v35; // [esp+34h] [ebp-10h]
  int v36; // [esp+38h] [ebp-Ch]
  int v37; // [esp+3Ch] [ebp-8h]
  int v38; // [esp+40h] [ebp-4h]

  result = *(_DWORD *)(this + 4);
  if ( result )
  {
    v3 = *(_DWORD *)(this + 16);
    v4 = *(float *)(this + 20);
    if ( v3 )
    {
      if ( v3 == 1 )
      {
        if ( v6 | v7 )
          v8 = *(float *)(this + 24) - *(float *)(this + 20);
        else
          v8 = 360.0 - (*(float *)(this + 20) - *(float *)(this + 24));
        v4 = v4 + *(float *)(this + 28) / *(float *)(this + 32) * v8;
      }
    }
    else
    {
      if ( v10 | v11 )
        v12 = 360.0 - (*(float *)(this + 24) - *(float *)(this + 20));
      else
        v12 = *(float *)(this + 20) - *(float *)(this + 24);
      v4 = v4 - *(float *)(this + 28) / *(float *)(this + 32) * v12;
    }
    v34 = v4 * 0.01745433;
    v13 = (double)*(int *)(this + 68);
    v32 = v13;
    v30 = sqrt(v13 * v32 * 0.25 + (double)*(int *)(this + 72) * (double)*(int *)(this + 72) * 0.25);
    v14 = asin(v32 * 0.5 / v30);
    v15 = v34 + v14;
    v16 = (__int64)(cos(v15) * v30);
    v17 = v34 - v14;
    v18 = (__int64)(sin(v15) * v30);
    v19 = (__int64)(cos(v17) * v30);
    v20 = (__int64)(sin(v17) * v30);
    HIDWORD(v20) = *(_DWORD *)(this + 60);
    v35 = HIDWORD(v20) - v19;
    v37 = HIDWORD(v20) - v16;
    v21 = *(_DWORD *)(this + 64);
    v31 = v21 + v20;
    v36 = v21 + v18;
    v26 = (float)(v21 - v18);
    v38 = HIDWORD(v20) + v19;
    v22 = (float)(v16 + HIDWORD(v20));
    v33 = v21 - v20;
    sub_5A16E0(*(_DWORD *)(this + 4), 0, v22, v26, 1.0, 0.0, 0.0, -1);
    v27 = (float)v31;
    v23 = (float)v35;
    sub_5A16E0(*(_DWORD *)(this + 4), 1, v23, v27, 1.0, 0.0, 1.0, -1);
    v28 = (float)v36;
    v24 = (float)v37;
    sub_5A16E0(*(_DWORD *)(this + 4), 2, v24, v28, 1.0, 1.0, 1.0, -1);
    v29 = (float)v33;
    v25 = (float)v38;
    return sub_5A16E0(*(_DWORD *)(this + 4), 3, v25, v29, 1.0, 1.0, 0.0, -1);
  }
  return result;
}
