Concurrency::details::TaskStack *__thiscall Concurrency::details::TaskStack::TaskStack(
        Concurrency::details::TaskStack *this)
{
  Concurrency::details::TaskStack *result; // eax

  result = this;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_BYTE *)this + 12) = 0;
  return result;
}
