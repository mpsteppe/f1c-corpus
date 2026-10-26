// f1c  0x004389b0  size=597
int __thiscall sub_4389B0(int this, int a2)
{
  int v3; // eax
  int v4; // eax
  int result; // eax
  int v6; // ebx
  char v7; // al
  double v8; // st7
  double v9[3]; // [esp+Ch] [ebp-ACh] BYREF
  int v10; // [esp+24h] [ebp-94h]
  _DWORD v11[6]; // [esp+28h] [ebp-90h] BYREF
  _DWORD v12[6]; // [esp+40h] [ebp-78h] BYREF
  _DWORD v13[6]; // [esp+58h] [ebp-60h] BYREF
  double v14[9]; // [esp+70h] [ebp-48h] BYREF

  if ( *(_BYTE *)(this + 452) )
  {
    memset(v11, 0, sizeof(v11));
    memset(v12, 0, sizeof(v12));
    memset(v13, 0, sizeof(v13));
    memset(v9, 0, sizeof(v9));
    sub_56BD40(v13);
    qmemcpy((void *)(*(_DWORD *)(this + 348) + 4), v11, 0x18u);
    qmemcpy((void *)(*(_DWORD *)(this + 348) + 100), v12, 0x18u);
    v3 = *(_DWORD *)(this + 348);
    qmemcpy((void *)(v3 + 28), v14, 0x48u);
    v10 = v3;
    sub_5692A0(v3);
    v4 = v10;
    qmemcpy((void *)(v10 + 124), v9, 0x18u);
    sub_569410(v4);
    result = *(_DWORD *)(this + 352);
    if ( !result )
      return result;
    qmemcpy((void *)(result + 4), v11, 0x18u);
    qmemcpy((void *)(*(_DWORD *)(this + 352) + 100), v12, 0x18u);
    v6 = *(_DWORD *)(this + 352);
  }
  else
  {
    v7 = *(_BYTE *)(this + 453);
    qmemcpy(v14, (const void *)(a2 + 28), sizeof(v14));
    if ( v7 )
      sub_56BDE0(this + 456, 0);
    sub_56C2D0(*(double *)(this + 172), 0);
    v8 = *(double *)(this + 188);
    v6 = *(_DWORD *)(this + 348);
    v9[1] = v14[3] * v8;
    v9[2] = v14[6] * v8;
    v9[0] = v14[0] * v8 + *(double *)(a2 + 124);
    v9[1] = v9[1] + *(double *)(a2 + 132);
    v9[2] = v9[2] + *(double *)(a2 + 140);
  }
  qmemcpy((void *)(v6 + 28), v14, 0x48u);
  sub_5692A0(v6);
  qmemcpy((void *)(v6 + 124), v9, 0x18u);
  return sub_569410(v6);
}
