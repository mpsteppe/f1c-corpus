Concurrency::details::_ReaderWriterLock *__thiscall Concurrency::details::_ReaderWriterLock::_ReaderWriterLock(
        Concurrency::details::_ReaderWriterLock *this)
{
  Concurrency::details::_ReaderWriterLock *result; // eax

  result = this;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  return result;
}
