int __thiscall sub_44BC50(int *this, const CHAR *a2, int *a3)
{
  int v4; // eax
  int v5; // edi
  int *v6; // eax
  _DWORD *v7; // ebx
  _DWORD *v8; // edx
  int v9; // edx
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  _DWORD *v13; // ecx
  int v14; // eax
  _DWORD *v15; // ecx
  _DWORD *v16; // ebx
  int i; // edi
  int v18; // esi
  int v19; // eax
  int v21; // [esp+0h] [ebp-44h] BYREF
  int v22; // [esp+4h] [ebp-40h] BYREF
  int v23; // [esp+8h] [ebp-3Ch] BYREF
  int v24[10]; // [esp+Ch] [ebp-38h] BYREF
  int v25; // [esp+34h] [ebp-10h]
  int v26; // [esp+38h] [ebp-Ch]
  int v27; // [esp+3Ch] [ebp-8h]
  LPVOID v28; // [esp+40h] [ebp-4h]

  ZeroInitSmallStruct(v24);
  FileAttributesExistenceCheck(a2);
  sub_566940(a2, 4, 0, 1);
  ConditionalDispatch_6bd0(aVer006ThisFile, 46);
  ConditionalDispatch_6bd0(this + 2, 8);
  ConditionalDispatch_6bd0(this + 4, 8);
  ConditionalDispatch_6bd0(this + 6, 8);
  ConditionalDispatch_6bd0(this + 8, 8);
  v21 = *a3;
  ConditionalDispatch_6bd0(&v21, 4);
  v4 = OperatorNewNhMallocWrapper(92 * v21);
  *this = v4;
  v24[9] = v4;
  v24[8] = v21;
  v24[7] = 0;
  v28 = (LPVOID)OperatorNewNhMallocWrapper(16 * v21);
  v23 = RecursiveNodeCount(v21);
  ConditionalDispatch_6bd0(&v23, 4);
  v5 = v23;
  v6 = (int *)OperatorNewNhMallocWrapper(16 * v23 + 4);
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
  v11 = v23;
  this[1] = v10;
  v27 = v10;
  v12 = 0;
  v26 = v11;
  v13 = (_DWORD *)a3[3];
  v25 = 0;
  if ( v13 )
    v12 = DynamicsNodeCountRecursive(v13);
  v22 = v12;
  ConditionalDispatch_6bd0(&v22, 4);
  v14 = OperatorNewNhMallocWrapper(4 * v22);
  v15 = (_DWORD *)a3[3];
  v16 = (_DWORD *)v14;
  if ( v15 )
    BVHTreeLinearize(v15, v14, 0);
  for ( i = 0; i < v22; ++i )
  {
    v18 = v16[i];
    ConditionalDispatch_6bd0(v18, 4);
    ConditionalDispatch_6bd0(v18 + 16, 8);
    ConditionalDispatch_6bd0(v18 + 12, 4);
  }
  v19 = ContactPairLinkedListBuilder(a3);
  if ( v19 )
  {
    v25 = 1;
    sub_44A4B0(v27, *(float *)&v19, (int)v24);
  }
  if ( v16 )
    FreeWrapper_7bcf(v16);
  if ( v28 )
    FreeWrapper_7bcf(v28);
  ConditionalFileHandleCloseWithFlagDispatch(v24);
  SubCallWithConditionalFieldFree(v24);
  return 0;
}
