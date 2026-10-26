_DWORD *__thiscall sub_546320(_DWORD *this, float *a2, float *a3, float *a4, float a5, float a6, int a7)
{
  double v7; // st7
  int v8; // esi
  _DWORD *result; // eax
  int v10; // ecx
  int v11; // ecx
  float v12; // [esp+0h] [ebp-24h]
  int v14; // [esp+20h] [ebp-4h]
  float v15; // [esp+38h] [ebp+14h]

  v7 = sqrt(a6);
  v15 = v7;
  switch ( dword_B7129C )
  {
    case 0:
      v7 = v15 * 0.40000001;
      break;
    case 1:
      v7 = v15 * 0.5;
      break;
    case 2:
      v7 = v15 * 0.60000002;
      break;
    case 3:
      v7 = v15 * 0.80000001;
      break;
    default:
      break;
  }
  v8 = this[13];
  v14 = (unsigned __int64)(24.0 * v7);
  if ( v8 )
    sub_543C80(v8, a5, a2, a3, 0.1, 0, (unsigned __int64)(v7 * 8.0), 1);
  result = this;
  v10 = this[14];
  if ( v10 )
  {
    v12 = v15 * 1.5;
    result = (_DWORD *)sub_543E60(v10, a5, a2, a3, a4, v12, v14, a7);
  }
  v11 = this[15];
  if ( v11 )
    return (_DWORD *)sub_543E60(v11, a5, a2, a3, a4, v15, v14, a7);
  return result;
}
