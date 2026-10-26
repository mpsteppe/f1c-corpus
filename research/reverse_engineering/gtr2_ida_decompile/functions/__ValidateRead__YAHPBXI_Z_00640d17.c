BOOL __cdecl _ValidateRead(void *lp, UINT_PTR ucb)
{
  return !IsBadReadPtr(lp, ucb);
}
