int __usercall sub_593CFD@<eax>(EXCEPTION_POINTERS *a1@<ecx>, int a2@<ebx>, int a3@<edi>, int a4@<esi>, int a5)
{
  int v6[3]; // [esp-Ch] [ebp-24h] BYREF
  CPPEH_RECORD ms_exc; // [esp+0h] [ebp-18h]

  ms_exc.registration.ScopeTable = stru_5B99A0;
  ms_exc.registration.ExceptionHandler = ScriptFrameProcessor;
  ms_exc.registration.Next = (struct _EH3_EXCEPTION_REGISTRATION *)NtCurrentTeb()->NtTib.ExceptionList;
  ms_exc.exc_ptr = a1;
  v6[2] = a2;
  v6[1] = a4;
  v6[0] = a3;
  ms_exc.old_esp = (DWORD)v6;
  ms_exc.registration.TryLevel = 0;
  if ( off_5E7960 )
  {
    ms_exc.registration.TryLevel = 1;
    off_5E7960(v6[0]);
    ms_exc.registration.TryLevel = 0;
  }
  ms_exc.registration.TryLevel = -1;
  return SEHWrapperDispatchingToHandlerFunction(a5);
}
