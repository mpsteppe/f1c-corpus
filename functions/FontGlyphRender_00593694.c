int __cdecl sub_593694(
        PEXCEPTION_RECORD ExceptionRecord,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        PVOID TargetFrame)
{
  int result; // eax
  int *i; // esi
  int v10; // eax
  int v11; // ecx
  unsigned int v12; // [esp+8h] [ebp-8h] BYREF
  unsigned int v13; // [esp+Ch] [ebp-4h] BYREF

  if ( !TLSValueRetrievalWithInit()[26]
    || (result = SEHExceptionHandlerTrampolineSetup(ExceptionRecord, a2, a3, a4, a5, a7, (int)TargetFrame)) == 0 )
  {
    for ( i = (int *)BinaryIntervalSearchForMatchingRange(a5, a7, a6, &v13, &v12); ; i += 5 )
    {
      result = v13;
      if ( v13 >= v12 )
        break;
      if ( a6 >= *i && a6 <= i[1] )
      {
        v10 = i[4] + 16 * i[3];
        v11 = *(_DWORD *)(v10 - 12);
        if ( !v11 || !*(_BYTE *)(v11 + 8) )
          MultiArgRenderingDispatchWithLayout(ExceptionRecord, a2, a3, a4, a5, v10 - 16, 0, (int)i, a7, TargetFrame);
      }
      ++v13;
    }
  }
  return result;
}
