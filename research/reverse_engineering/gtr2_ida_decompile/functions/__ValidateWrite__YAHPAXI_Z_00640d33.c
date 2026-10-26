BOOL __cdecl _ValidateWrite(void *lp, UINT_PTR ucb)
{
  return !IsBadWritePtr(lp, ucb);
}
