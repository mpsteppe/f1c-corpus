_DWORD *__thiscall sub_459830(int this, _DWORD *a2)
{
  _DWORD *v3; // ebp
  int v4; // ecx
  int v5; // edx
  _DWORD *v6; // ebx
  _DWORD *result; // eax
  int v8; // ecx
  _DWORD v9[6]; // [esp+10h] [ebp-48h] BYREF
  double v10[3]; // [esp+28h] [ebp-30h] BYREF
  double v11[3]; // [esp+40h] [ebp-18h] BYREF

  if ( *(_DWORD *)(this + 208) )
  {
    sub_54B4D0(
      *(_DWORD *)(this + 4),
      *(_DWORD *)(this + 8),
      *(_DWORD *)(this + 12),
      *(float *)(this + 16),
      *(float *)(this + 20),
      *(float *)(this + 24));
    BufferEntryClear(0x8000000);
  }
  v3 = (_DWORD *)(this + 4);
  v10[0] = *(float *)(this + 4);
  v10[1] = *(float *)(this + 8);
  v10[2] = *(float *)(this + 12);
  qmemcpy((void *)(this + 216), v10, 0x18u);
  v11[0] = *(float *)(this + 16);
  v11[1] = *(float *)(this + 20);
  v11[2] = *(float *)(this + 24);
  memset(v9, 0, sizeof(v9));
  F_3x3RotationTensorMatrixTransform(v11);
  qmemcpy((void *)(this + 312), v9, 0x18u);
  Copy6DwordsToStructCall(v9);
  v4 = *(_DWORD *)(this + 8);
  v5 = *(_DWORD *)(this + 12);
  v6 = (_DWORD *)(this + 192);
  *v6 = *v3;
  result = a2;
  v6[1] = v4;
  v8 = *v3;
  v6[2] = v5;
  *a2 = v8;
  a2[1] = v3[1];
  a2[2] = v3[2];
  return result;
}
