void __thiscall Concurrency::details::ExternalStatistics::MarkInactive(Concurrency::details::ExternalStatistics *this)
{
  *((_DWORD *)this + 6) = 0;
}
