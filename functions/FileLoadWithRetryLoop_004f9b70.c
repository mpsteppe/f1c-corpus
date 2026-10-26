int __stdcall sub_4F9B70(const char *a1, char a2)
{
  _DWORD *v2; // eax
  _DWORD *v3; // eax
  int v4; // eax
  int v5; // eax
  int v7; // [esp+8h] [ebp-208h] BYREF
  bool v8; // [esp+Fh] [ebp-201h]
  char v9[512]; // [esp+10h] [ebp-200h] BYREF

  v7 = 0;
  v2 = OneTimeInitializationWithAtexitStyleRegistration();
  ObjectCreationWithRollbackOnFailure(&v7, a1, 1, v2[36]);
  if ( !v7 )
  {
    strcpy(v9, a1);
    StringFormatReplaceOperation(dword_5EC3D0, v9, 512);
    v3 = OneTimeInitializationWithAtexitStyleRegistration();
    ObjectCreationWithRollbackOnFailure(&v7, v9, 1, v3[36]);
    if ( !v7 )
      return 1;
  }
  v8 = VTableMethodGuard();
  if ( v8 )
    VTableDispatchViaGlobal();
  GlobalAccessor();
  sub_5434A0(0.0, 0.0, 1.0, 1.0, 0);
  MultiStepInitSequence();
  GlobalAccessor();
  sub_5434A0(0.0, 0.0, 1.0, 1.0, 0);
  sub_551EB0(flt_7CF2CC);
  v4 = GlobalAccessor();
  if ( !BinkVideoFrameRender(v4, 0, 0, 0) )
  {
    while ( 1 )
    {
      MultiStepInitSequence();
      sub_4537B0((int)&ppvOut, 0.050000001);
      if ( a2 )
      {
        if ( dword_7CB218 > 0 )
          break;
      }
      sub_4A1830();
      v5 = GlobalAccessor();
      if ( BinkVideoFrameRender(v5, 0, 0, 0) )
        goto LABEL_11;
    }
    sub_4537B0((int)&ppvOut, 0.050000001);
  }
LABEL_11:
  ConditionalFreeWithBinkClose(v7);
  GuardedSubsystemRelease();
  if ( v8 )
    NullCheckedVTableCall();
  return 0;
}
