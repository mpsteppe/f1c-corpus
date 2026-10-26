_DWORD *__cdecl sub_5934E1(
        PEXCEPTION_RECORD ExceptionRecord,
        int a2,
        int a3,
        int a4,
        int a5,
        char a6,
        int a7,
        PVOID TargetFrame)
{
  PEXCEPTION_RECORD v8; // esi
  _DWORD *result; // eax
  int v10; // edi
  int *i; // ebx
  int *v12; // eax
  int *v13; // edi
  _DWORD *v14; // [esp+0h] [ebp-18h] BYREF
  int v15; // [esp+4h] [ebp-14h]
  int v16; // [esp+8h] [ebp-10h]
  int v17; // [esp+Ch] [ebp-Ch]
  int v18; // [esp+10h] [ebp-8h]
  _DWORD *v19; // [esp+14h] [ebp-4h] BYREF
  PEXCEPTION_RECORD ExceptionRecorda; // [esp+20h] [ebp+8h]

  LOBYTE(v15) = 0;
  v16 = *(_DWORD *)(a2 + 8);
  if ( v16 < -1 || v16 >= *(_DWORD *)(a5 + 4) )
    SEHGuardedFunctionPointerCall();
  v8 = ExceptionRecord;
  if ( ExceptionRecord->ExceptionCode != -529697949 )
    goto LABEL_35;
  if ( ExceptionRecord->NumberParameters == 3
    && ExceptionRecord->ExceptionInformation[0] == 429065504
    && !ExceptionRecord->ExceptionInformation[2] )
  {
    result = TLSValueRetrievalWithInit();
    if ( !result[27] )
      return result;
    v8 = (PEXCEPTION_RECORD)TLSValueRetrievalWithInit()[27];
    a3 = TLSValueRetrievalWithInit()[28];
    LOBYTE(v15) = 1;
    if ( !IsBadReadPtrWrapper(v8, 1u) )
      SEHGuardedFunctionPointerCall();
    if ( v8->ExceptionCode != -529697949 )
      goto LABEL_35;
    if ( v8->NumberParameters == 3 && v8->ExceptionInformation[0] == 429065504 && !v8->ExceptionInformation[2] )
      SEHGuardedFunctionPointerCall();
  }
  if ( v8->ExceptionCode != -529697949 || v8->NumberParameters != 3 || v8->ExceptionInformation[0] != 429065504 )
  {
LABEL_35:
    if ( a6 )
      return (_DWORD *)SEHWrapperDispatchingToHandlerFunction(ExceptionRecord, a2, a3);
    else
      return (_DWORD *)FontGlyphRender(v8, a2, a3, a4, a5, v16, a7, TargetFrame);
  }
  v10 = v16;
  for ( i = (int *)BinaryIntervalSearchForMatchingRange(a5, a7, v16, (unsigned int *)&v19, (unsigned int *)&v14); ; i += 5 )
  {
    result = v19;
    if ( v19 >= v14 )
      break;
    if ( *i <= v10 && v10 <= i[1] )
    {
      ExceptionRecorda = (PEXCEPTION_RECORD)i[4];
      v17 = i[3];
      if ( v17 > 0 )
      {
        while ( 1 )
        {
          v12 = *(int **)(v8->ExceptionInformation[2] + 12);
          v13 = v12 + 1;
          v18 = *v12;
          if ( v18 > 0 )
            break;
LABEL_27:
          --v17;
          ExceptionRecorda = (PEXCEPTION_RECORD)((char *)ExceptionRecorda + 16);
          if ( v17 <= 0 )
            goto LABEL_30;
        }
        while ( !StructMatchingWithBitFlagsStrcmp(ExceptionRecorda, *v13, v8->ExceptionInformation[2]) )
        {
          --v18;
          ++v13;
          if ( v18 <= 0 )
            goto LABEL_27;
        }
        MultiArgRenderingDispatchWithLayout(v8, a2, a3, a4, a5, (int)ExceptionRecorda, *v13, (int)i, a7, TargetFrame);
      }
LABEL_30:
      v10 = v16;
    }
    v19 = (_DWORD *)((char *)v19 + 1);
  }
  if ( a6 )
    return (_DWORD *)SEHWrappedRenderDispatchCall(v8, 1);
  return result;
}
