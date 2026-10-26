int __thiscall UIScreenLoad(_DWORD *this, LPVOID **a2)
{
  const char *v3; // eax
  const char *v4; // ecx
  int v5; // esi
  int v6; // edi
  LPVOID *v7; // esi
  _BYTE *v8; // eax
  LPVOID *v9; // edi
  char v11[8]; // [esp+8h] [ebp-228h] BYREF
  int v12[7]; // [esp+10h] [ebp-220h] BYREF
  char v13[4]; // [esp+2Ch] [ebp-204h] BYREF
  _BYTE v14[509]; // [esp+30h] [ebp-200h] BYREF
  __int16 v15; // [esp+22Dh] [ebp-3h]
  char v16; // [esp+22Fh] [ebp-1h]

  v14[0] = byte_5EA438[0];
  memset(&v14[1], 0, 0x1FCu);
  v15 = 0;
  v16 = 0;
  ZeroInitSmallStruct(v12);
  v3 = (const char *)this[44];
  if ( !v3 )
    v3 = byte_5EA438;
  v4 = (const char *)dword_5EC408;
  if ( !dword_5EC408 )
    v4 = byte_5EA438;
  StringFormatWithBufferOverflowCheck(v14, (int)"%s%s", v4, v3);
  if ( AudioStreamOpen(v12, (int)v14, 1) )
  {
    sub_566DB0(v12, 2);
    v5 = ResourceLookupDispatcher(v12);
    sub_566DB0(v12, 0);
    v6 = v5 - ResourceLookupDispatcher(v12);
    v7 = (LPVOID *)OperatorNewNhMallocWrapper(8);
    if ( v7 )
    {
      v8 = (_BYTE *)OperatorNewNhMallocWrapper(v6);
      *v7 = v8;
      *v8 = 0;
      v7[1] = (LPVOID)v6;
    }
    else
    {
      v7 = 0;
    }
    ConditionalDispatchBasedOnFlag(v12, v13, 1);
    while ( ConditionalDispatchBasedOnFlag(v12, v11, 2) )
      sub_5665B0((int)v7, v11);
    v9 = *a2;
    if ( *a2 )
    {
      if ( *v9 )
        FreeWrapper_7bcf(*v9);
      FreeWrapper_7bcf(v9);
      *a2 = 0;
    }
    *a2 = v7;
  }
  return SubCallWithConditionalFieldFree(v12);
}

