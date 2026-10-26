void __thiscall __noreturn sub_5CB21D(EXCEPTION_POINTERS *this)
{
  int v1; // [esp-Ch] [ebp-24h] BYREF
  CPPEH_RECORD ms_exc; // [esp+0h] [ebp-18h]

  ms_exc.registration.ScopeTable = stru_5F7330;
  ms_exc.registration.ExceptionHandler = _except_handler3;
  ms_exc.registration.Next = (struct _EH3_EXCEPTION_REGISTRATION *)NtCurrentTeb()->NtTib.ExceptionList;
  ms_exc.exc_ptr = this;
  ms_exc.old_esp = (DWORD)&v1;
  ms_exc.registration.TryLevel = 0;
  if ( off_626600 )
  {
    ms_exc.registration.TryLevel = 1;
    off_626600();
  }
  ms_exc.registration.TryLevel = -1;
  terminate();
}
