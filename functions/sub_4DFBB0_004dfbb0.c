int __thiscall sub_4DFBB0(int this)
{
  _DWORD *v2; // edi
  int v3; // ebx
  void *v4; // edx
  int v5; // edi
  int v6; // edx
  _BYTE *v7; // ecx
  int v8; // ecx
  int v9; // edx
  _DWORD *v10; // edi
  int v11; // ebx

  F_17ElementZeroInitLoop((void *)(this + 4));
  *(_DWORD *)(this + 144) = 0;
  *(_DWORD *)(this + 148) = -1;
  v2 = (_DWORD *)(this + 212);
  v3 = 4;
  do
  {
    LargeZeroInit(v2);
    F_17ElementZeroInitLoop(v2 + 28);
    F_17ElementZeroInitLoop(v2 + 45);
    InitWithDualCall(v2);
    v2 += 74;
    --v3;
  }
  while ( v3 );
  LargeZeroInit((_DWORD *)(this + 1396));
  F_17ElementZeroInitLoop((void *)(this + 1508));
  F_17ElementZeroInitLoop((void *)(this + 1576));
  v4 = (void *)(this + 1644);
  v5 = 8;
  do
  {
    F_17ElementZeroInitLoop(v4);
    v4 = (void *)(v6 + 68);
    --v5;
  }
  while ( v5 );
  v7 = (_BYTE *)(this + 2448);
  do
  {
    sub_4DFB90(v7);
    v7 = (_BYTE *)(v8 + 28);
  }
  while ( v9 != 1 );
  v10 = (_DWORD *)(this + 2988);
  v11 = 11;
  do
  {
    F_2FieldInitCall(v10);
    v10 += 187;
    --v11;
  }
  while ( v11 );
  *(_DWORD *)this = 0;
  *(_DWORD *)(this + 2984) = 0;
  *(_DWORD *)(this + 11220) = 0;
  VehicleResetClear((char *)this);
  return this;
}
