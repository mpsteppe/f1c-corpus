unsigned int __thiscall Concurrency::details::SchedulerBase::GetNumberOfBoundContexts(
        Concurrency::details::SchedulerBase *this)
{
  return *((_DWORD *)this + 57);
}
