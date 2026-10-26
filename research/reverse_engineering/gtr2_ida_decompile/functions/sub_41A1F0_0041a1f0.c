int __thiscall sub_41A1F0(_DWORD *this, int a2, float *a3, int a4, int a5, float *a6)
{
  int v6; // eax
  _DWORD *v7; // esi
  int result; // eax

  if ( a2 == 3 )
  {
    v6 = dword_921100[5654 * a4 + 74 * a5];
    v7 = (_DWORD *)(this[19] + 40 * (a5 + 4 * a4));
    *(float *)(v7[9] + 32) = flt_B72CF4 + *a6;
  }
  else if ( a2 == 4 )
  {
    v7 = (_DWORD *)(this[22] + 40 * (a5 + 2 * a4));
    if ( a5 )
      v6 = dword_9215E4[5654 * a4];
    else
      v6 = dword_9215A0[5654 * a4];
    *(float *)(v7[9] + 32) = flt_B72CF4 + *a6;
  }
  else
  {
    v6 = a5;
    if ( a2 == 5 )
    {
      v6 = dword_921628[5654 * a4 + 17 * a5];
      v7 = (_DWORD *)(this[25] + 40 * (a5 + 8 * a4));
      *(float *)(v7[9] + 32) = flt_B72CF4 + *a6;
    }
    else
    {
      v7 = (_DWORD *)a5;
    }
  }
  sub_417E90(v7, v6, 1);
  sub_416240(v7, a3);
  result = sub_419950(v7, (int)a6);
  v7[3] = 2;
  return result;
}
