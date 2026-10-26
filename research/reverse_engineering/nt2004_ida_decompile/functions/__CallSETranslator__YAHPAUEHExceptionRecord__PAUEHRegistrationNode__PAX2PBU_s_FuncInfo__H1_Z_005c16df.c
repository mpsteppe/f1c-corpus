int __cdecl _CallSETranslator(
        struct EHExceptionRecord *a1,
        struct EHRegistrationNode *a2,
        void *a3,
        void *a4,
        const struct _s_FuncInfo *a5,
        int a6,
        struct EHRegistrationNode *a7)
{
  int v7; // eax
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // ebx
  int v10; // [esp+0h] [ebp-40h] BYREF
  int v11; // [esp+Ch] [ebp-34h]
  _DWORD v12[11]; // [esp+10h] [ebp-30h] BYREF
  int v13; // [esp+3Ch] [ebp-4h]
  int savedregs; // [esp+40h] [ebp+0h] BYREF

  v12[3] = TranslatorGuardHandler;
  v12[4] = a5;
  v12[5] = a2;
  v12[6] = a6;
  v12[7] = a7;
  v13 = 0;
  v12[8] = &_ExceptionContinuation_16750;
  v12[9] = &v10;
  v12[10] = &savedregs;
  v12[2] = NtCurrentTeb()->NtTib.ExceptionList;
  v11 = 1;
  v12[0] = a1;
  v12[1] = a3;
  v7 = _getptd(a1->ExceptionCode, v12);
  (*(void (**)(void))(v7 + 104))();
  v11 = 0;
  if ( v13 )
  {
    ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
    ExceptionList->Next = ExceptionList->Next;
  }
  return v11;
}
