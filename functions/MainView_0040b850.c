int __thiscall MainView(_DWORD *this, int a2)
{
  int v3; // edi
  _BYTE *v4; // esi
  int v5; // ebx
  int v6; // esi
  int v7; // eax
  _DWORD *v8; // esi
  int v9; // edi
  _BYTE *v10; // ebx
  int *v11; // eax
  _DWORD *v12; // edi
  int v13; // ebx
  _DWORD *v14; // eax
  int v15; // esi
  _DWORD *v16; // esi
  int v17; // edi
  _DWORD *v19; // esi
  int v20; // edi
  int v21; // [esp+10h] [ebp-6C38h]
  int v22[7]; // [esp+14h] [ebp-6C34h] BYREF
  char v23[384]; // [esp+30h] [ebp-6C18h] BYREF
  int v24; // [esp+1B0h] [ebp-6A98h]
  char v25; // [esp+1B4h] [ebp-6A94h]
  int v26; // [esp+1BCh] [ebp-6A8Ch]
  int v27; // [esp+1C0h] [ebp-6A88h]
  int v28; // [esp+1C4h] [ebp-6A84h]
  char v29[384]; // [esp+1C8h] [ebp-6A80h] BYREF
  CHAR v30[256]; // [esp+348h] [ebp-6900h] BYREF
  _BYTE v31[26624]; // [esp+448h] [ebp-6800h] BYREF
  _UNKNOWN *retaddr; // [esp+6C48h] [ebp+0h] BYREF

  ZeroInitSmallStruct(v22);
  memset(v29, 0, sizeof(v29));
  v3 = 0;
  v24 = 0;
  v28 = 0;
  v26 = 0;
  v27 = 0;
  v25 = 1;
  v4 = v31;
  v5 = 128;
  do
  {
    F_3DTransformObjectInit_83b0((int)v4);
    v4 += 208;
    --v5;
  }
  while ( v5 );
  v6 = 0;
  v7 = TwoLevelWideStringSearch((_DWORD *)dword_8AFE88, aMainview);
  if ( v7 )
    this[1] = v7;
  if ( !AudioStreamOpen(v22, a2, 1) )
  {
    v8 = &retaddr;
    v9 = 128;
    do
    {
      v8 -= 52;
      VTableInitCallChain(v8);
      --v9;
    }
    while ( v9 );
LABEL_30:
    SubCallWithConditionalFieldFree(v22);
    return 1;
  }
  if ( !ConditionalDispatchBasedOnFlag(v22, v29, 384) )
    goto LABEL_28;
  v10 = v31;
  do
  {
    if ( !sub_5651B0(v23) && sub_565520((int)v23, (int)aTrackingcam, v30, 0) && v6 < 128 )
    {
      sub_4585E0((int)v10, (int)v22, (int)v30);
      ++v6;
      v10 += 208;
    }
  }
  while ( ConditionalDispatchBasedOnFlag(v22, v29, 384) );
  if ( v6 <= 0 )
  {
LABEL_28:
    v19 = &retaddr;
    v20 = 128;
    do
    {
      v19 -= 52;
      VTableInitCallChain(v19);
      --v20;
    }
    while ( v20 );
    goto LABEL_30;
  }
  v11 = (int *)OperatorNewNhMallocWrapper(208 * v6 + 4);
  if ( v11 )
  {
    v12 = v11 + 1;
    *v11 = v6;
    v13 = (int)(v11 + 1);
    if ( v6 - 1 >= 0 )
    {
      v21 = v6;
      do
      {
        F_3DTransformObjectInit_83b0(v13);
        v13 += 208;
        --v21;
      }
      while ( v21 );
    }
    v14 = v12;
    v3 = 0;
  }
  else
  {
    v14 = 0;
  }
  this[3] = v14;
  this[4] = v6;
  this[5] = 0;
  v15 = 0;
  do
  {
    sub_459330(v15 + this[3], COERCE_FLOAT(&v31[v15]));
    ++v3;
    v15 += 208;
  }
  while ( v3 < this[4] );
  v16 = &retaddr;
  v17 = 128;
  do
  {
    v16 -= 52;
    VTableInitCallChain(v16);
    --v17;
  }
  while ( v17 );
  SubCallWithConditionalFieldFree(v22);
  return 0;
}
