int __thiscall sub_419950(_DWORD *this, int a2)
{
  double v3; // st7
  int v4; // eax
  _DWORD *v5; // ecx
  double *v6; // ebx
  double v7; // st7
  int v8; // eax
  _DWORD *v9; // edx
  double v10; // st7
  int v11; // eax
  _DWORD *v12; // eax
  double v13; // st7
  double v14; // st7
  int result; // eax
  double v16; // [esp+18h] [ebp-40h]
  double v17; // [esp+18h] [ebp-40h]
  double v18[3]; // [esp+28h] [ebp-30h] BYREF
  double v19[3]; // [esp+40h] [ebp-18h] BYREF

  switch ( this[8] )
  {
    case 0:
    case 3:
    case 6:
      v3 = *(float *)a2;
      v4 = this[9];
      *(float *)(v4 + 40) = *(float *)a2;
      *(float *)(v4 + 36) = v3 + 100.0;
      v5 = (_DWORD *)(this[9] + 200);
      *v5 = *(_DWORD *)(a2 + 4);
      v5[1] = *(_DWORD *)(a2 + 8);
      v5[2] = *(_DWORD *)(a2 + 12);
      v6 = (double *)(this[9] + 224);
      break;
    case 1:
    case 4:
      v7 = *(float *)a2;
      v8 = this[9];
      *(float *)(v8 + 40) = *(float *)a2;
      *(float *)(v8 + 36) = v7 + 100.0;
      v9 = (_DWORD *)(this[9] + 200);
      *v9 = *(_DWORD *)(a2 + 4);
      v9[1] = *(_DWORD *)(a2 + 8);
      v9[2] = *(_DWORD *)(a2 + 12);
      v6 = (double *)(this[9] + 224);
      break;
    case 2:
    case 5:
      v10 = *(float *)a2;
      v11 = this[9];
      *(float *)(v11 + 40) = *(float *)a2;
      *(float *)(v11 + 36) = v10 + 100.0;
      v12 = (_DWORD *)(this[9] + 200);
      *v12 = *(_DWORD *)(a2 + 4);
      v12[1] = *(_DWORD *)(a2 + 8);
      v12[2] = *(_DWORD *)(a2 + 12);
      v6 = (double *)(this[9] + 224);
      break;
    default:
      v6 = (double *)a2;
      break;
  }
  this[4] = *(_DWORD *)(a2 + 4);
  this[5] = *(_DWORD *)(a2 + 8);
  this[6] = *(_DWORD *)(a2 + 12);
  sub_5DB2B0(
    *(_DWORD *)(a2 + 4),
    *(_DWORD *)(a2 + 8),
    *(_DWORD *)(a2 + 12),
    *(float *)(a2 + 16),
    *(float *)(a2 + 20),
    *(float *)(a2 + 24));
  v16 = *(float *)(a2 + 8);
  v13 = *(float *)(a2 + 12);
  v6[1] = *(float *)(a2 + 4);
  v6[2] = v16;
  v6[3] = v13;
  v18[0] = *(float *)(a2 + 16);
  v18[1] = *(float *)(a2 + 20);
  v18[2] = *(float *)(a2 + 24);
  sub_61B6E0(v18);
  v17 = *(float *)(a2 + 32);
  v14 = *(float *)(a2 + 36);
  v6[13] = *(float *)(a2 + 28);
  v6[14] = v17;
  v6[15] = v14;
  v19[0] = *(float *)(a2 + 40);
  v19[1] = *(float *)(a2 + 44);
  v19[2] = *(float *)(a2 + 48);
  result = sub_61B710(v19);
  if ( *this == -1 )
  {
    *(_DWORD *)(dword_91BF90 + 4 * dword_91BF88) = this;
    *this = dword_91BF88++;
    sub_52F560(this);
    return sub_52FAB0(this);
  }
  return result;
}
