int (__cdecl *_cfltcvt_init_46())(int, void *Src, int, size_t Size, int)
{
  int (__cdecl *result)(int, void *, int, size_t, int); // eax

  result = _cfltcvt;
  off_6253E4[0] = (void (__noreturn *)())_cropzeros;
  off_6253E0[0] = (void (__noreturn *)())_cfltcvt;
  off_6253E8[0] = (void (__noreturn *)())_fassign;
  off_6253EC[0] = (void (__noreturn *)())_forcdecpt;
  off_6253F0[0] = (void (__noreturn *)())_positive;
  off_6253F4 = (void (__noreturn *)())_cfltcvt;
  return result;
}
