int __stdcall sub_501610(int a1, int a2, int a3, int a4, int a5, int a6, float a7, float a8)
{
  int result; // eax
  int v9; // esi
  float v10; // ecx
  int v11; // edx
  int v12; // eax
  int v13; // edi
  int v14; // ecx
  float v15; // [esp+8h] [ebp-8h]
  int v16; // [esp+Ch] [ebp-4h]

  result = sub_501810(a6);
  v9 = result;
  if ( result )
  {
    v10 = *(float *)(result + 172);
    v11 = *(_DWORD *)(result + 176);
    v12 = a4;
    *(float *)(v9 + 172) = a7 * v10;
    v15 = v10;
    v16 = v11;
    *(float *)(v9 + 176) = a8 * *(float *)(v9 + 176);
    sub_5A3F10(v12);
    v13 = (__int64)((double)a2 / a7);
    a2 = v13;
    v14 = (__int64)((double)a3 / a8);
    a3 = v14;
    switch ( a5 )
    {
      case 1:
        sub_501770(a1, v13, &a2, a6);
        break;
      case 2:
        sub_501730(a1, v13, &a2, a6);
        break;
      case 3:
        sub_5017B0(a1, v13, &a2, v14, &a3, a6);
        break;
      default:
LABEL_9:
        result = sub_5A3FF0(a1, v13, a3, dword_7E8CDC, 0);
        *(float *)(v9 + 172) = v15;
        *(_DWORD *)(v9 + 176) = v16;
        return result;
    }
    v13 = a2;
    goto LABEL_9;
  }
  return result;
}
