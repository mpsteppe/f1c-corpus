int __cdecl _CallSETranslator(
        struct EHExceptionRecord *a1,
        struct EHRegistrationNode *a2,
        void *a3,
        void *a4,
        const struct _s_FuncInfo *a5,
        int a6,
        struct EHRegistrationNode *a7)
{
  int v8; // eax
  int v9; // [esp+0h] [ebp-38h] BYREF
  int v10; // [esp+4h] [ebp-34h]
  _DWORD v11[2]; // [esp+8h] [ebp-30h] BYREF
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+10h] [ebp-28h]
  enum _EXCEPTION_DISPOSITION (__cdecl *v13)(PEXCEPTION_RECORD, PVOID, struct _CONTEXT *, void *); // [esp+14h] [ebp-24h]
  int v14; // [esp+18h] [ebp-20h]
  const struct _s_FuncInfo *v15; // [esp+1Ch] [ebp-1Ch]
  struct EHRegistrationNode *v16; // [esp+20h] [ebp-18h]
  int v17; // [esp+24h] [ebp-14h]
  struct EHRegistrationNode *v18; // [esp+28h] [ebp-10h]
  int *v19; // [esp+2Ch] [ebp-Ch]
  int *v20; // [esp+30h] [ebp-8h]
  int v21; // [esp+34h] [ebp-4h]
  int savedregs; // [esp+38h] [ebp+0h] BYREF

  if ( a1 == (struct EHExceptionRecord *)291 )
  {
    a2->pNext = (EHRegistrationNode *)&loc_630C9B;
    return 1;
  }
  else
  {
    v13 = TranslatorGuardHandler;
    v14 = dword_912B08;
    v15 = a5;
    v16 = a2;
    v17 = a6;
    v18 = a7;
    v21 = 0;
    v19 = &v9;
    v20 = &savedregs;
    ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
    v10 = 1;
    v11[0] = a1;
    v11[1] = a3;
    v8 = _getptd(a1->ExceptionCode, v11);
    (*(void (**)(void))(v8 + 116))();
    v10 = 0;
    if ( v21 )
      ExceptionList->Next = NtCurrentTeb()->NtTib.ExceptionList->Next;
    return v10;
  }
}
