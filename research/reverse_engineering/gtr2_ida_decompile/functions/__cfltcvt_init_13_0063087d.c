int (__cdecl *_cfltcvt_init_13())(int, int, int, size_t Size, int)
{
  int (__cdecl *result)(int, int, int, size_t, int); // eax

  result = _cfltcvt;
  off_912C80[0] = (void (__noreturn *)())_cfltcvt;
  off_912C84[0] = (void (__noreturn *)())_cropzeros;
  off_912C88[0] = (void (__noreturn *)())_fassign;
  off_912C8C[0] = (void (__noreturn *)())_forcdecpt;
  off_912C90[0] = (void (__noreturn *)())_positive;
  off_912C94[0] = (void (__noreturn *)())_cfltcvt;
  return result;
}
