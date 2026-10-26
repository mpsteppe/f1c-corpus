int *__thiscall sub_47AB30(int *this, int a2, float a3)
{
  int v3; // ebp
  int v5; // edi
  _DWORD *v6; // ecx
  int *result; // eax
  int v8; // edi
  double v9; // st7
  int v10; // ebx
  double v11; // st7
  unsigned __int8 v12; // al
  double v13; // st7
  int *v14; // [esp+Ch] [ebp-4h] BYREF

  v3 = a2;
  v5 = *this;
  v6 = (_DWORD *)(*this + 113304);
  a2 = *(int *)(a2 + 844);
  sub_4796F0(v6, &v14, &a2);
  result = v14;
  if ( v14 != *(int **)(v5 + 113308) )
  {
    v8 = *((unsigned __int8 *)v14 + 16);
    v9 = *(float *)&this[v8 + 215];
    v10 = ((*(_DWORD *)v3 >> 8) & 0x3FF) + 8;
    this[v8 + 7] = 0;
    if ( v9 > 0.5 )
    {
      v11 = a3;
      this[v8 + 2191] = -1082130432;
      *((_WORD *)&this[8 * v8 + 527] + *((unsigned __int8 *)this + v8 + 1900)) = (unsigned __int8)(unsigned __int64)((v11 - *(float *)(v3 + 4)) * 999.99994 + 0.5);
      v12 = *((_BYTE *)this + v8 + 1692);
      if ( v12 < 0x10u )
        *((_BYTE *)this + v8 + 1692) = v12 + 1;
      *((_BYTE *)this + v8 + 1900) = (*((_BYTE *)this + v8 + 1900) + 1) & 0xF;
      this[v8 + 215] = 0;
    }
    if ( sub_479900((__int16 *)this, a2, (float *)&a2) )
      *(float *)(v3 + 4) = *(float *)(v3 + 4) - *(float *)&a2;
    v13 = sub_58F2F0(&unk_FB1E98);
    if ( *(float *)(v3 + 4) > v13 || (v13 = v13 - (*((float *)this + 6) + 1.0), v13 > *(float *)(v3 + 4)) )
      *(float *)(v3 + 4) = v13;
    result = (int *)(this[3] + 1);
    this[2] += v10;
    this[3] = (int)result;
  }
  return result;
}
