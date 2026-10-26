int __thiscall sub_44BE70(_DWORD *this, int a2)
{
  int v3; // eax
  int v4; // edx
  int v5; // esi
  int *v6; // eax
  _DWORD *v7; // edi
  _DWORD *v8; // edx
  int v9; // edx
  int v10; // eax
  int v11; // ecx
  int v12; // ebx
  int v13; // edi
  char *v14; // esi
  int v16; // [esp+Ch] [ebp-78h] BYREF
  int v17; // [esp+10h] [ebp-74h] BYREF
  int v18; // [esp+14h] [ebp-70h] BYREF
  char v19[48]; // [esp+18h] [ebp-6Ch] BYREF
  _DWORD v20[10]; // [esp+48h] [ebp-3Ch] BYREF
  int v21; // [esp+70h] [ebp-14h]
  int v22; // [esp+74h] [ebp-10h]
  int v23; // [esp+78h] [ebp-Ch]
  int v24; // [esp+7Ch] [ebp-8h]
  char *v25; // [esp+80h] [ebp-4h]

  ZeroInitSmallStruct(v20);
  AudioStreamOpen(a2, 0);
  if ( !v20[0]
    || FileWriteWithBackendDispatch(v19, 46) != 46
    || strcmp(v19, aVer006ThisFile)
    || FileWriteWithBackendDispatch(this + 2, 8) != 8
    || FileWriteWithBackendDispatch(this + 4, 8) != 8
    || FileWriteWithBackendDispatch(this + 6, 8) != 8
    || FileWriteWithBackendDispatch(this + 8, 8) != 8
    || FileWriteWithBackendDispatch(&v18, 4) != 4
    || FileWriteWithBackendDispatch(&v17, 4) != 4
    || FileWriteWithBackendDispatch(&v16, 4) != 4 )
  {
    goto LABEL_26;
  }
  v3 = OperatorNewNhMallocWrapper(92 * v18);
  v4 = v18;
  *this = v3;
  v20[9] = v3;
  v5 = v17;
  v20[7] = 0;
  v20[8] = v4;
  v6 = (int *)OperatorNewNhMallocWrapper(16 * v17 + 4);
  if ( v6 )
  {
    v7 = v6 + 1;
    *v6 = v5;
    v8 = v6 + 1;
    if ( v5 - 1 >= 0 )
    {
      do
      {
        CollisionObjectInit(v8);
        v8 = (_DWORD *)(v9 + 16);
        --v5;
      }
      while ( v5 );
    }
    v10 = (int)v7;
  }
  else
  {
    v10 = 0;
  }
  v11 = v16;
  this[1] = v10;
  v23 = v10;
  v21 = 0;
  v22 = v17;
  v25 = (char *)OperatorNewNhMallocWrapper(16 * v11);
  v12 = 0;
  v24 = v16;
  if ( v16 > 0 )
  {
    v13 = 0;
    do
    {
      v14 = &v25[v13];
      if ( FileWriteWithBackendDispatch(&v25[v13], 4) != 4
        || FileWriteWithBackendDispatch(v14 + 4, 8) != 8
        || FileWriteWithBackendDispatch(v14 + 12, 4) != 4 )
      {
        goto LABEL_24;
      }
      ++v12;
      v13 += 16;
    }
    while ( v12 < v16 );
  }
  if ( v17 > 0 )
  {
    v21 = 1;
    if ( CollisionTreeNodeDeserializer(v23, v20) )
    {
LABEL_24:
      if ( v25 )
        FreeWrapper_7bcf(v25);
LABEL_26:
      SubCallWithConditionalFieldFree(v20);
      return -1;
    }
  }
  if ( v25 )
    FreeWrapper_7bcf(v25);
  ConditionalFileHandleCloseWithFlagDispatch(v20);
  SubCallWithConditionalFieldFree(v20);
  return 0;
}
