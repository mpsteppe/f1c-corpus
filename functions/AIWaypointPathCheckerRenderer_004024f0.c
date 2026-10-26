int __thiscall sub_4024F0(int this)
{
  int result; // eax
  int v3; // esi
  int v4; // ecx
  int v5; // ebx
  int v6; // eax
  int v7; // [esp+8h] [ebp-74h]
  float v8[7]; // [esp+Ch] [ebp-70h] BYREF
  float v9[7]; // [esp+28h] [ebp-54h] BYREF
  float v10[7]; // [esp+44h] [ebp-38h] BYREF
  float v11[7]; // [esp+60h] [ebp-1Ch] BYREF

  result = *(_DWORD *)(this + 308);
  v3 = *(_DWORD *)(result + 272);
  v4 = 0;
  if ( v3 )
  {
    while ( v3 != result )
    {
      if ( ++v4 > 12000 )
        return result;
      v3 = *(_DWORD *)(v3 + 272);
      if ( !v3 )
        goto LABEL_7;
    }
    ArraySearchByIDWithCleanup(9);
    ArraySearchByIDWithCleanup(10);
    v7 = v3;
    EmptyStubWithFlagCheck(2, 0);
    do
    {
      v5 = 0xFFFFFF - (CRTFtol(*(float *)(v3 + 280) * -254.0) << 24);
      LODWORD(v9[6]) = v5;
      v6 = 0xFFFFFF - (CRTFtol(*(float *)(*(_DWORD *)(v3 + 272) + 280) * -254.0) << 24);
      LODWORD(v8[6]) = v6;
      if ( v5 != 0xFFFFFF || v6 != 0xFFFFFF )
      {
        sub_402220((float *)this, (float *)v3, v9, 0);
        sub_402220((float *)this, *(float **)(v3 + 272), v8, 0);
        sub_4CEFA0(9, v9, v8);
      }
      sub_402220((float *)this, (float *)v3, v11, 1);
      sub_402220((float *)this, *(float **)(v3 + 272), v10, 1);
      v11[6] = 2.3509886e-38;
      v10[6] = 2.3509886e-38;
      sub_4CEFA0(10, v11, v10);
      v3 = *(_DWORD *)(v3 + 272);
    }
    while ( v3 != v7 );
    return EmptyStubWithFlagCheck(1, 0);
  }
  else
  {
LABEL_7:
    result = StringSplitLoop(2, aDDevF119992002_14, 839);
    if ( (_BYTE)result )
      return DebugLogWrite(&dword_8AD25C, aIncompleteWayp);
  }
  return result;
}
