int __thiscall sub_4183B0(_DWORD *this, int a2, float *a3, int a4, int a5, float *a6)
{
  int v6; // eax
  _DWORD *v7; // esi
  int result; // eax

  switch ( a2 )
  {
    case 3:
      v6 = dword_62C820[6326 * a4 + 76 * a5];
      v7 = (_DWORD *)(this[19] + 40 * (a5 + 4 * a4));
      *(float *)(v7[9] + 28) = flt_769230 + *a6;
      break;
    case 4:
      v7 = (_DWORD *)(this[22] + 40 * (a5 + 2 * a4));
      if ( a5 )
        v6 = dword_62CD24[6326 * a4];
      else
        v6 = dword_62CCE0[6326 * a4];
      *(float *)(v7[9] + 28) = flt_769230 + *a6;
      break;
    case 5:
      v6 = dword_62CD68[6326 * a4 + 17 * a5];
      v7 = (_DWORD *)(this[25] + 40 * (a5 + 12 * a4));
      *(float *)(v7[9] + 28) = flt_769230 + *a6;
      break;
    default:
      v7 = (_DWORD *)a5;
      v6 = a5;
      break;
  }
  sub_415860(v7, v6, 1);
  sub_415FB0(v7, a3);
  result = sub_416060(v7, a6);
  v7[3] = 2;
  return result;
}
