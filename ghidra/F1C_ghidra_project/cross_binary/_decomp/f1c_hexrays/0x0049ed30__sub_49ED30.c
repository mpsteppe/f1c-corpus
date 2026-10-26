// f1c  0x0049ed30  size=520
int __thiscall sub_49ED30(int this)
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
  double v13; // st7
  int v14; // edi
  int v15; // eax
  double v16; // st7
  int v17; // ebx
  int v18; // ebp
  int v19; // eax
  int v20; // edx
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
  int v34; // [esp+34h] [ebp-10h]
  int v35; // [esp+38h] [ebp-Ch]
  int v36; // [esp+3Ch] [ebp-8h]
  int v37; // [esp+40h] [ebp-4h]

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
    v32 = v4 * 0.01745433;
    v30 = sqrt((double)(*(_DWORD *)(this + 68) * (*(_DWORD *)(this + 68) / 2) / 2
                      + *(_DWORD *)(this + 72) * (*(_DWORD *)(this + 72) / 2) / 2));
    v13 = (double)(*(_DWORD *)(this + 68) / 2) / v30;
    sub_588570();
    v14 = sub_587BDC(v13);
    v15 = sub_587BDC(v13);
    v16 = v32 - v13;
    v17 = v15;
    v18 = sub_587BDC(v16);
    v19 = sub_587BDC(sin(v16) * v30);
    v20 = *(_DWORD *)(this + 60);
    v34 = v20 - v18;
    v36 = v20 - v14;
    v21 = *(_DWORD *)(this + 64);
    v33 = v21 + v19;
    v35 = v21 + v17;
    v37 = v20 + v18;
    v31 = v21 - v19;
    v26 = (float)(v21 - v17);
    v22 = (float)(v14 + v20);
    sub_553650(0, v22, v26, 1.0, 0.0, 0.0, -1);
    v27 = (float)v33;
    v23 = (float)v34;
    sub_553650(1, v23, v27, 1.0, 0.0, 1.0, -1);
    v28 = (float)v35;
    v24 = (float)v36;
    sub_553650(2, v24, v28, 1.0, 1.0, 1.0, -1);
    v29 = (float)v31;
    v25 = (float)v37;
    return sub_553650(3, v25, v29, 1.0, 1.0, 0.0, -1);
  }
  return result;
}
