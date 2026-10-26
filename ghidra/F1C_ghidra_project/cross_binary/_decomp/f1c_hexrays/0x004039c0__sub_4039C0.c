// f1c  0x004039c0  size=219
int __stdcall sub_4039C0(float *a1, int a2)
{
  int result; // eax
  bool v3; // zf
  int v4; // edx
  double v6; // st7
  double v7; // st6
  double v8; // st5
  double v9; // st7
  int v10; // ecx
  double v11; // st6
  double v12; // st5
  double v13; // st3
  double v14; // st4
  float v15; // [esp+8h] [ebp+4h]
  float v16; // [esp+Ch] [ebp+8h]

  result = a2;
  v3 = a2 == 0;
  v4 = a2;
  v16 = 0.0;
  if ( !v3 )
  {
    v6 = *a1 - *(float *)(result + 148);
    v7 = a1[1] - *(float *)(result + 152);
    v8 = a1[2] - *(float *)(result + 156);
    v15 = v8 * v8 + v7 * v7 + v6 * v6;
    if ( *(_DWORD *)(result + 272) )
    {
      while ( 1 )
      {
        v9 = v16 + *(float *)(v4 + 60);
        v16 = v9;
        if ( v9 > 200.0 )
          break;
        v10 = *(_DWORD *)(v4 + 272);
        if ( !v10 )
          break;
        v11 = a1[1] - *(float *)(v10 + 152);
        v12 = a1[2] - *(float *)(v10 + 156);
        v13 = *a1 - *(float *)(v10 + 148);
        v14 = v12 * v12 + v11 * v11 + v13 * v13;
        if ( v14 >= v15 )
          break;
        v15 = v14;
        v4 = *(_DWORD *)(v4 + 272);
        if ( !*(_DWORD *)(v10 + 272) )
          return v10;
      }
    }
    return v4;
  }
  return result;
}
